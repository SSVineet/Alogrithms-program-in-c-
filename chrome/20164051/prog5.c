// Rotation then scaling 
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
void main()
{
	int graphdriver=DETECT,graphmode;
	int x,y,x1,y1,x2,y2,xn,yn,i;
	double r11,r12,r21,r22,th;
	
	printf("Enter the 2 line end co-ordinates:");
	printf("x1,y1,x2,y2");
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	printf("\n\n\nEnter the angle");
	scanf("%lf",&th);
	printf("Enter scaling co-ordinates ");
	printf("x,y");
	scanf("%d%d",&x,&y);
	
	initgraph(&graphdriver,&graphmode,"c:\\tc\\bgi");
	line(x1,y1,x2,y2);
	outtextxy(x1,y1,"The original Line");
	
	r11=cos((th*3.1428)/180);
	r12=sin((th*3.1428)/180);
	r21=(-sin((th*3.1428)/180));
	r22=cos((th*3.1428)/180);

	xn=((x2*r11)-(y2*r12));
	yn=((x2*r12)+(y2*r11));

	outtextxy(xn, yn, "The line after rotation theta ");
	line(x1,y1,xn,yn);
	x2=xn;
	y2=yn;
	x1=(x1*x);
	y1=(y1*y);
	x2=(x2*x);
	y2=(y2*y);
	
	printf("Line after scaling");
	line(x1,y1,x2,y2);
	outtextxy(x2, y2, "The line after scaling");
	
	getch();
	closegraph();
}
