#include <stdlib.h>
#include <iostream>
#include <vector>

#include <GL/glut.h>

#include "gline.h"

using std::cout;
using std::endl;
using std::vector;

double  d = 0.95;
double  m_size = 0.01;

// 点表示用のマーク
vector<vector<gvector> > mark;

// 表示境界
vector<gline> bounds;

// 表示用の初期設定を行う
void initializeDraw() {
  // 乱数の種を変える。
  // 毎回変わるとテストにならないけど、初期値だとちょっとテストに不向きなので
  // 固定で値を試す。
  srand(3);

  // 点表示用のマーク。とりあえず、四角だけ
  vector<gvector> points;

  points.clear();
  points.push_back(gvector ( 0, 0));

  mark.push_back(points);

  points.clear();
  points.push_back(gvector ( m_size*d, m_size*d));
  points.push_back(gvector (-m_size*d, m_size*d));
  points.push_back(gvector (-m_size*d,-m_size*d));
  points.push_back(gvector ( m_size*d,-m_size*d));

  mark.push_back(points);

  points.clear();
  points.push_back(gvector ( m_size*d*1.5, m_size*d*1.5));
  points.push_back(gvector (-m_size*d*1.5, m_size*d*1.5));
  points.push_back(gvector (-m_size*d*1.5,-m_size*d*1.5));
  points.push_back(gvector ( m_size*d*1.5,-m_size*d*1.5));

  mark.push_back(points);

  // 領域の境界定義
  gvector bound1( 1, 1);
  gvector bound2(-1, 1);
  gvector bound3(-1,-1);
  gvector bound4( 1,-1);

  bounds.push_back(gline(bound1, bound2 - bound1));
  bounds.push_back(gline(bound2, bound3 - bound2));
  bounds.push_back(gline(bound3, bound4 - bound3));
  bounds.push_back(gline(bound4, bound1 - bound4));

  // 境界はそれぞれ線分
  for(int i = 0; i < bounds.size(); i++) {
    bounds[i].setS(true);
    bounds[i].setE(true);
  }
}

void drawPoint(gvector pos, int m) {
  glBegin(GL_LINE_LOOP);
    glColor3d(1.0, 1.0, 1.0);
    for(int i=0; i<mark[m].size(); i++) {
      glVertex2dv(((pos + mark[m][i]) * d).get());
    }
  glEnd();
}

void drawPoint(gvector pos) {
  drawPoint(pos, 1);
}

bool onLine(gvector& pos, gline& lin) {
  double eps = 1.0e-10;
  double l = (pos - lin.getPos()).dot(lin.getVec())/lin.getVec().length();

  // 始点と一致？
  if((pos - lin.getPos()).length()<eps) {
    return true;
  }

  // 終点と一致？
  if((pos - (lin.getPos() + lin.getVec())).length()<eps) {
    return true;
  }

  // 始点側の延長上？
  if(l<0) {
    // 始点側は有界？
    if(lin.getS()) {
      return false;
    }
    return true;
  }
  // 終点側の延長上？
  if(l > lin.getVec().length()) {
    // 終点側は有界？
    if(lin.getE()) {
      return false;
    }
    return true;
  }

  // 線分上なら乗っている
  return true;
}

void drawLine(gline& lin) {
  // 有界で無い側は境界と交点を求める

    // 交点無いときあるよなぁ。
    // とりあえずグローバル変数にでもステータスセットするかな
    gvector ps;
    vector<gvector> p;
    for(int i=0; i<bounds.size(); i++) {
      ps = intersect(lin, bounds[i]);
      // 境界線の線分上？
      if(onLine(ps, bounds[i])) {
        // 線分から見た判定
        if(onLine(ps, lin)) {
          p.push_back(ps);
          // 境界と直線との交点はたかだか2つ
          if(p.size()>=2) {
            break;
          }
        }
      }
    }

  // TODO: ちょっと強引な気がする。リファクタリング必須！
  glBegin(GL_LINE_STRIP);
    glColor3d(1.0, 1.0, 1.0);
    glVertex2dv((p[0] * d).get());
    if(p.size()==2) {
      glVertex2dv((p[1] * d).get());
    } else {
      if(lin.getS()) {
        glVertex2dv((lin.getPos() * d).get());
      } else {
        glVertex2dv(((lin.getPos() + lin.getVec()) * d).get());
      }
    }
//    glVertex2dv((lin.getPos() * d).get());
//    glVertex2dv(((lin.getPos() + lin.getVec()) * d).get());
  glEnd();
  drawPoint(lin.getPos());
}

double frand(double min, double max) {
  return min + rand() * (max - min) / RAND_MAX;
}

gvector randomPoint() {
  gvector tmp(frand(-1,1), frand(-1,1));
  return tmp;
}

// 境界を描く
void drawBounds(vector<gline> bounds) {
  for(int i=0; i< bounds.size(); i++) {
    glBegin(GL_LINE_STRIP);
      glColor3d(1.0, 1.0, 1.0);
      glVertex2dv((bounds[i].getPos() * d).get());
      glVertex2dv(((bounds[i].getPos() + bounds[i].getVec()) * d).get());
    glEnd();
  }
}

// 逐次追加する点列
vector<gvector> points;
// 逐次計算する線列
// TODO: 多分点列にリンクする必要がある
vector<gline> lines;

void calcVoronoi(void) {
  // 次に点をどんどん加えてながら、逐次添加法により順次点を足していく

  // 1点目は何もしない
  if(points.size()==3) {
    // 3点目なら、垂直二等分線を追加して交点から先を削除
    // 後は同じように既存線分を編集していく．．．
    // 今のところここで終了
    gline lin = perpendicularBisectorOnXY(points[1], points[2]);
    gvector w = intersect(lines[0], lin); 
    // 交点でトリムして直線を再生成するときにどちら側にするかの判定が必要
    gline linB = gline(w, lin.getVec());
    linB.setS(true);
    lines.push_back(linB);
    lines[0] = gline(w, lines[0].getVec());
    lines[0].setS(true);
    linB = perpendicularBisectorOnXY(points[0], points[2]);
    // ベクトルを反転している
    linB = gline(w, -linB.getVec());
    linB.setS(true);
    lines.push_back(linB);
    //drawLine(lin);
  } else if(points.size() == 2) {
    // 2点目なら、間に垂直二等分線を作る
    gline lin = perpendicularBisectorOnXY(points[0], points[1]);
    lines.push_back(lin);
  }
}

void drawVoronoi(void) {
  if(!glIsList(1)) {
    glNewList(1, GL_COMPILE);
      // 境界を表示
      drawBounds(bounds);
      for(int i=0; i < points.size(); i++) {
        drawPoint(points[i]);
      }
      for(int i=0; i < lines.size(); i++) {
        drawLine(lines[i]);
      }
    glEndList();
  }

  glCallList(1);
}

void display(void) {
  // ウィンドウをクリアする
  glClear(GL_COLOR_BUFFER_BIT);

  drawVoronoi();

  // バッファを切り替えて表示する
  glutSwapBuffers();
}

void resize(int w, int h) {
  // 幅と高さは同じ
  int s = w;
  if(s>h) {
    // 小さい方に合わせる
    s = h;
  }
  glViewport(0, 0, s, s);
}

void mouse(int button, int state, int x, int y) {
}

void keyboard(unsigned char key, int x, int y) {
  switch(key) {
    case 'h':
    case 'H':
      // ヘルプメッセージを出す
      break;
    case 'q':
    case 'Q':
    case '\033':
      // 終了する
      exit(0);
    case 'r':
    case 'R':
      // 初期状態にする
      initializeDraw();
      glDeleteLists(1,1);
      glutPostRedisplay();
      break;
    case 's':
    case 'S':
    case ' ':
      // 頂点を1つ足す
      points.push_back(randomPoint());
      calcVoronoi();
      glDeleteLists(1,1);
      glutPostRedisplay();
      break;
    case 'g':
    case 'G':
      // 自動で進む
      break;
    default:
      break;
  }
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);

  // チラツキを防ぐためダブルバッファリングモードを指定
  glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);

  // ウィンドのタイトルを指定
  glutCreateWindow(argv[0]);

  // 表示用のハンドラを通知
  glutDisplayFunc(display);
  glutReshapeFunc(resize);
  glutMouseFunc(mouse);
  glutKeyboardFunc(keyboard);

  // 準備
  initializeDraw();

  // イベント待受ループ
  glutMainLoop();

  return 0;
}

