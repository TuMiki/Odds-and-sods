/*
 * Sunflower
 * �o�T�F���w�Z�~�i�[ 07-85 ISSN 0386-4960 pp.34 �u�Ђ܂��̂��ˁv����a�v
 *       �́u���ʂɂ��˂�������vN88-BASIC
 */
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

void display(void);

int main(int argc, char** argv) {
	glutInit(&argc, argv);

	// �`���c�L��h�����߃_�u���o�b�t�@�����O���[�h���w��
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);

	// �E�B���h�̃^�C�g�����w��
	glutCreateWindow("Sunflower");

	// �\���p�̃n���h����ʒm
	glutDisplayFunc(display);

	// �C�x���g�Ҏ󃋁[�v
	glutMainLoop();

	return 0;
}

void display(void) {
	double dp;
	double gs;
	double c;
	double i;
	double v1, v2;
	double vv1, vv2;
	int    n1;
	double sa;
	int    n;
	int    k;
	double rn;
	double un;
	double vn;
	double pn;
	double xn;
	double yn;
	double zn;
	double xxk;
	double yyk;
	double w;
	double XX = 0.001*2;

	// �E�B���h�E���N���A����
	glClear(GL_COLOR_BUFFER_BIT);

	dp = M_PI * 2.0;
	gs = (sqrt(5.0) - 1.0) / 2.0;
	c = 1.0 / 4.0;
	i = 6;
	v1 = 1.0 / 48.0;
	v2 = 0.0;
	n1 = (int)(360 / c); // TODO �֐����p�ӂ���Ă���Ȃ炻������g��
	sa = sqrt(360.0 * c);
	for(n = 0; n <= n1; n++) {
	  vv1 = gs * n + v1;
	  vv2 = gs * n + v2;
	  xn = sqrt(c * n * (360 - c * n)) * cos(dp * vv1);
	  yn = -180 + c * n;
	  if(sin(dp * vv2) <= 2.0) {
	    rn = sqrt(xn * xn + yn * yn);
	    if(rn>0) {
		    un = xn / rn;
		    vn = yn / rn;
	    } else {
		    un = 1;
		    vn = 0;
	    }
	    glBegin(GL_LINE_STRIP);
	      glColor3d(1.0, 1.0, 1.0);
	      glVertex2d((320.0 + xn + vn * sa)*XX, (200.0 - yn + un * sa)*XX);
	      // printf("\n(%lf, %lf)\n", 320.0 + xn + vn * sa, 200.0 - yn + un * sa);
	      for(k = 0; k <= i - 1; k++) {
	        w = dp * (k + 1) / i;
	        pn = rn / 180;
	        zn = sqrt(1.0001 - pn * pn);
	        xxk =  vn * sa * cos(w) + un * zn * sa * sin(w);
	        yyk = -un * sa * cos(w) + vn * zn * sa * sin(w);
	        glColor3d(1.0, 1.0, 1.0);
	        glVertex2d((320.0 + xn + xxk)*XX, (200.0 - yn - yyk)*XX);
	        // printf("(%lf, %lf)\n", 320.0 + xn + xxk, 200.0 - yn - yyk);
	      }
	    glEnd();
	  }
	}

	// �o�b�t�@��؂�ւ��ĕ\������
	glutSwapBuffers();
}
