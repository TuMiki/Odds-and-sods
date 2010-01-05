#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

void display(void);

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
	glutCreateWindow("Line1");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);
	glColor3d(1.0, 1.0, 1.0);	 glVertex2d( 0.0,	0.7);
	glColor3d(1.0, 1.0, 1.0);	 glVertex2d( 0.7,	0.0);
	glEnd();
	glutSwapBuffers();
}
