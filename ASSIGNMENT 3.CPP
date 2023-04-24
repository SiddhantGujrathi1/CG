/* 
	Problem Statement: 
	Write C++ program to draw the following pattern. Use
	DDA line and Bresenham‘s circle drawing algorithm. Apply the concept of
	encapsulation.
*/
//============================================================================

// Name        : Assignment_3.cpp

// Author      : Gujrathi Siddhant

//============================================================================

#include<conio.h>
#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;
class drawpattern
{
private:
	float dx,dy,i ,length;
public:
	int x1,y1,x2,y2;
	int xmid,ymid;
	
	void getdata()
	{
		cout<<"Enter x1: ";
		cin>>x1;
		cout<<"Enter y1: ";
		cin>>y1;
		cout<<"Enter x2: ";
		cin>>x2;
		cout<<"Enter y2: ";
		cin>>y2;
	}
	
	void ddaline(int x1,int x2,int y1, int y2)
	{
		float x,y;
		dx = (x2-x1);
		dy = (y2-y1);
		if(abs(dx)>=abs(dy)) 
			length = abs(dx);
		else
			length = abs(dy);

		dx = dx/length;
		dy = dy/length;
		x=x1;
		y=y1;
		i=1;

		while(i<=length)
		{
			x = x + dx;
			y = y + dy;
			putpixel(x,y,15);
			i++;
		}
	}
	
	void bdrawcircle(int xc,int yc,int r)
	{
		int x,y,d;
		x=0;
		y=r;
		// initialize the decision variable
		d=3-2*r;
		do
		{
			putpixel(xc+x,yc+y,15);
			putpixel(xc-x,yc-y,15);
			putpixel(xc+x,yc-y,15);
			putpixel(xc-x,yc+y,15);
			putpixel(xc+y,yc-x,15);
			putpixel(xc-y,yc-x,15);
			putpixel(xc+y,yc+x,15);
			putpixel(xc-y,yc+x,15);
			if(d<0)
			{
				y=y;
				d=d+4*x+6;
			}
			else
			{
				d=d+4*(x-y)+10;
				y=y-1;
			}
			x=x+1;
		}while(x<=y);
	}
};


int main()
{
	int gd= DETECT, gm;
	initgraph(&gd,&gm,"c://Turboc3//BGI");
	cleardevice();
	drawpattern d;
	d.getdata();
	
	//To draw the outer rectangle...
	d.ddaline(d.x1,d.y1,d.x2,d.y1);// (x1,y1) and (x2,y1)
	d.ddaline(d.x2,d.y1,d.x2,d.y2);
	d.ddaline(d.x2,d.y2,d.x1,d.y2);
	d.ddaline(d.x1,d.y2,d.x1,d.y1);
	
	//To draw the inner rectangle...
	d.xmid=(d.x1+d.x2)/2;
	d.ymid=(d.y1+d.y2)/2;
	
	d.ddaline(d.xmid,d.y1,d.x2,d.ymid);// (x1,y1) and (x2,y1)
	d.ddaline(d.x2,d.ymid,d.xmid,d.y2);
	d.ddaline(d.xmid,d.y2,d.x1,d.ymid);
	d.ddaline(d.x1,d.ymid,d.xmid,d.y1);
	
	
	float rad,cal,sidex,sidey;
	sidex=abs(d.x2-d.x1);
	sidey=abs(d.y2-d.y1);
	cal=pow(sidex,2)+pow(sidey,2);
	cal=2*sqrt(cal);
	rad=(sidex*sidey)/cal;
	cout<<sidex<<" "<<sidey<<" "<<rad;
	
	//To draw the circle....
	d.bdrawcircle(d.xmid,d.ymid,rad);
	
	getch();
	closegraph();
	// getch();
	return 0;
}
