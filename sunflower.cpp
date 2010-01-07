/*
 * Sunflower
 * 出典：数学セミナー 07-85 ISSN 0386-4960 pp.34 「ひまわりのたね」東川和夫
 *       の「球面にたねがついたら」N88-BASIC
 */
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

void display(void);

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
	glutCreateWindow("Sunflower");
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
/*
110 WIDTH 80,25:SCREEN 3,1: CONSOLE ,,0,1
120 COLOR 7,0:CLS 3
130 PI=3.141592653589793#:DP=PI*2:GS=(SQR(5#)-1)/2
140 C=1/4:I=6: V1=1/48 : V2=0
150 N1=INT(360/C)
160 SA=SQR(360*C)
170 FOR N=0 TO N1
180 VV1=GS*N+V1:VV2=GS*N+V2
190 XN=SQR(C*N*(360-C*N))*COS(DP*VV1):YN=-180+C*N
200 IF SIN(DP*VV2)>2 THEN 310
210 RN=SQR(XN*XN+YN*YN)
220 IF RN>0 THEN UN=XN/RN:VN=YN/RN ELSE UN=1:VN=0
230 PSET(320+XN+VN*SA, 200-YN+UN*SA)
240 FOR K=0 TO I-1
250 W=DP*(K+1)/I
260 PN=RN/180:ZN=SQR(1.0001-PN*PN)
270 XXK=VN*SA+COS(W)+UN+ZN+SA+SIN(W)
280 YYK=-UN*SA*COS(W)+VN*ZN*SA*SIN(W)
290 LINE -(320+XN+XXK,200-YN-YYK),2
300 NEXT K
310 NEXT N
*/
