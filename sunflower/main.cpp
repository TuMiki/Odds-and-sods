#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

void drawSunflower(void);

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

void display(void) {
  // ウィンドウをクリアする
  glClear(GL_COLOR_BUFFER_BIT);

  drawSunflower();

  // バッファを切り替えて表示する
  glutSwapBuffers();
}

