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

	// バッファを切り替えて表示する
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
270 XXK=VN*SA*COS(W)+UN*ZN*SA*SIN(W)
280 YYK=-UN*SA*COS(W)+VN*ZN*SA*SIN(W)
290 LINE -(320+XN+XXK,200-YN-YYK),2
300 NEXT K
310 NEXT N
*/
