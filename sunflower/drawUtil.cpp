#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

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
