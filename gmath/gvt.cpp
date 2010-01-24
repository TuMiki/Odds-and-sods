#include <iostream>
#include <GL/glut.h>
#include "gvector.h"

using std::cout;
using std::endl;

void initGVector(void) {
  gvector pos(1, 3);
  gvector posA(1, 4);
  gvector vecA(3, 2);
  gvector vecB(3, 2);
  gvector vecC(3, 2);
  double    d = 1./10;

  gvector posB(3);

  posB = footOfAPerpendicular(pos, posA, vecA);

  cout << "posB" << posB << endl;

  glBegin(GL_LINE_STRIP);
    glColor3d(1.0, 1.0, 1.0);
    glVertex2dv((posA * d).get());
    glVertex2dv(((posA+vecA) * d).get());
  glEnd();

  glBegin(GL_LINE_STRIP);
    glColor3d(1.0, 1.0, 1.0);
    glVertex2dv((posB * d).get());
    glVertex2dv((pos * d).get());
  glEnd();
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

