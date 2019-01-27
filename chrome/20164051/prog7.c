// Scaling then Translation.

#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<graphics.h>
void main()
{
	int graphdriver=DETECT,graphmode;
	int x,y,x1,y1,x2,y2,nx,ny;
	double r11,r12,r21,r22,th;

	printf("Enter the 2 line end co-ordinets:");
	printf("x1,y1,x2,y2");
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	printf("Enter scaling co-ordinates ");
	printf("x,y");
	scanf("%d%d",&nx,&ny);
	printf("Enter translation co-ordinates ");
	printf("x,y");
	scanf("%d%d",&x,&y);
	
	initgraph(&graphdriver,&graphmode,"c:\\tc\\bgi");
	outtextxy(x1, y1, "The original line");
	line(x1,y1,x2,y2);
	x1=(x1*nx);
	y1=(y1*ny);
	x2=(x2*nx);
	y2=(y2*ny);
	line(x1,y1,x2,y2);
	outtextxy(x2, y2, "The line after scaling ");
	x1=x1+x;	
	y1=y1+y;
	x2=x2+x;
	y2=y2+y;
	outtextxy(x1, y1, "The line after translation ");
	line(x1,y1,x2,y2);

	getch();
	closegraph();
}
