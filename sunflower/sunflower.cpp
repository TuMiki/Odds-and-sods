/*
 * Sunflower
 * 出典：数学セミナー 07-85 ISSN 0386-4960 pp.34 「ひまわりのたね」東川和夫
 *       の「球面にたねがついたら」N88-BASIC
 */
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

void display(void);

int main(int argc, char** argv) {
	glutInit(&argc, argv);

	// チラツキを防ぐためダブルバッファリングモードを指定
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);

	// ウィンドのタイトルを指定
	glutCreateWindow("Sunflower");

	// 表示用のハンドラを通知
	glutDisplayFunc(display);

	// イベント待受ループ
	glutMainLoop();

	return 0;
}

void beginLine() {
    glBegin(GL_LINE_STRIP);
    glColor3d(1.0, 1.0, 1.0);
}

void endLine() {
    glEnd();
}

void move(double x, double y) {
    double XX = 0.001*4;
    glVertex2d((0.0 + x) * XX, (y) * XX);
}

void display(void) {
  double dp;
  double gs;
  double c;
  double i;
  double v1, v2;
  int    n1;
  double sa;

  // ウィンドウをクリアする
  glClear(GL_COLOR_BUFFER_BIT);

  dp = M_PI * 2.0;
  gs = (sqrt(5.0) - 1.0) / 2.0;
  c = 1.0 / 4.0;
  i = 6;
  v1 = 1.0 / 48.0;
  v2 = 0.0;
  n1 = (int)(360 / c); // TODO 関数が用意されているならそちらを使う
  sa = sqrt(360.0 * c);
  for(int n = 0; n <= n1; n++) {
    double xn, yn, zn;
    double vv1, vv2;

    vv1 = gs * n + v1;
    vv2 = gs * n + v2;
    xn = sqrt(c * n * (360.0 - c * n)) * cos(dp * vv1);
    yn = -180.0 + c * n;
    if(sin(dp * vv2) <= 0.0) {
      double rn;
      double un, vn;

      // たねの中心での法線単位ベクトルを求める（球面の中心＝原点）
      rn = sqrt(xn * xn + yn * yn);
      if(rn>0) {
        un = xn / rn;
        vn = yn / rn;
      } else {
        un = 1;
        vn = 0;
      }

      // たねの周りに円を描く
      beginLine();
        move(xn + vn * sa, yn - un * sa);
        for(int k = 0; k <= i - 1; k++) {
          double xxk, yyk;
          double pn;
          double w;

          w = dp * (k + 1) / i;
          pn = rn / 180;
          zn = sqrt(1.0001 - pn * pn);
	  // 法線の傾きにあわせて円を傾けて平面に写像する
          xxk =  vn * sa * cos(w) + un * zn * sa * sin(w);
          yyk = -un * sa * cos(w) + vn * zn * sa * sin(w);
          move(xn + xxk, yn + yyk);
        }
      endLine();
    }
  }

  // バッファを切り替えて表示する
  glutSwapBuffers();
}
