#include<stdio.h>
#include<graphics.h>
//#include<dos.h>
 
void floodFill(int x,int y,int oldcolor,int newcolor)
{
    if(getpixel(x,y) == oldcolor)
    {
        putpixel(x,y,newcolor);
        floodFill(x+1,y,oldcolor+5,newcolor+10);
        floodFill(x,y+1,oldcolor+5,newcolor+10);
        floodFill(x-1,y,oldcolor+5,newcolor+10);
        floodFill(x,y-1,oldcolor+5,newcolor+10);
    }
}
//getpixel(x,y) gives the color of specified pixel 
 
int main()
{
    int gm,gd=DETECT,radius;
    int x,y;
    
    printf("Enter x y\n");
    scanf("%d%d",&x,&y);
    printf("Enter radius\n");
    scanf("%d",&radius);
    
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    circle(x,y,radius);
    floodFill(x,y,0,4);
    delay(5000);
    closegraph();
    
    return 0;
}
