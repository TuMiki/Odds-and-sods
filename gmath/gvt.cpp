#include <iostream>
#include <GL/glut.h>

#include "gline.h"

using std::cout;
using std::endl;

double  d = 1./10;
double  m_size = 0.1;
gvector offset1( m_size, m_size);
gvector offset2(-m_size, m_size);
gvector offset3(-m_size,-m_size);
gvector offset4( m_size,-m_size);

void drawPoint(gvector pos) {
  glBegin(GL_LINE_LOOP);
    glColor3d(1.0, 1.0, 1.0);
    glVertex2dv(((pos + offset1) * d).get());
    glVertex2dv(((pos + offset2) * d).get());
    glVertex2dv(((pos + offset3) * d).get());
    glVertex2dv(((pos + offset4) * d).get());
  glEnd();
}

void drawLine(gline& lin) {
  glBegin(GL_LINE_STRIP);
    glColor3d(1.0, 1.0, 1.0);
    glVertex2dv((lin.getPos() * d).get());
    glVertex2dv(((lin.getPos() + lin.getVec()) * d).get());
  glEnd();
  drawPoint(lin.getPos());
}

void initGVector(void) {
  gvector posA(2, 4);
  gvector lineA_pos(1, 4);
  gvector lineA_vec(3, 2);
  gvector retPos1(3);

  gline   linA(lineA_pos, lineA_vec);

  retPos1 = footOfAPerpendicular(posA, linA);

  drawLine(linA);
  drawPoint(posA);
  drawPoint(retPos1);

  gvector lineB_pos(4, 5);
  gvector lineB_vec(-3, 3);
  gline   linB(lineB_pos, lineB_vec);

  gvector retPos2(3);

  retPos2 = intersect(linA, linB);

  cout << "retPos2" << retPos2 << endl;

  drawLine(linB);
  drawPoint(retPos2);
}

void drawGVector(void) {
  if(!glIsList(1)) {
    glNewList(1, GL_COMPILE);
      initGVector();
    glEndList();
  }

  glCallList(1);
}

void display(void) {
  // ウィンドウをクリアする
  glClear(GL_COLOR_BUFFER_BIT);

  drawGVector();

  // バッファを切り替えて表示する
  glutSwapBuffers();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);

  // チラツキを防ぐためダブルバッファリングモードを指定
  glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);

  // ウィンドのタイトルを指定
  glutCreateWindow("GVectorTest");

  // 表示用のハンドラを通知
  glutDisplayFunc(display);

  // イベント待受ループ
  glutMainLoop();

  return 0;
}

