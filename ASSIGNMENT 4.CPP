
/*
	Problem Statement: 
	Write C++ program to draw 2-D object and perform
	following basic transformations :  Scaling , Translation, Rotation. Apply the
	concept of operator overloading.
*/


//============================================================================

// Name        : Assignment_4.cpp

// Author      : Gujrathi Siddhant

//============================================================================


#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

class trans
{
public:
	float transco[3][3];
	float scalco[3][3];
	float rotco[3][3];
	void drawtri(float [3][3]);
	void translation(int,int,float [3][3]);
	void scaling(float,float,float [3][3]);
	void rotation(float,float [3][3]);
};

void trans::drawtri(float co[3][3])
{
	line(co[0][0],co[0][1],co[1][0],co[1][1]);
	line(co[1][0],co[1][1],co[2][0],co[2][1]);
	line(co[2][0],co[2][1],co[0][0],co[0][1]);
}

void trans::translation(int tx,int ty,float orico[3][3])
{
	cout<<"Enter Translation Factor"<<endl;
	cin>>tx>>ty;
	int i,j;
	for(i=0;i<3;i++)
	{
		transco[i][0]=orico[i][0]+tx;
		transco[i][1]=orico[i][1]+ty;
		transco[i][2]=1;
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<transco[i][j]<<" ";
		}
		cout<<endl;
	}
}


void trans::scaling(float sx,float sy,float orico[3][3])
{
	cout<<"Enter Scaling Factor: "<<endl;
	cin>>sx>>sy;
	int i,j;
	for(i=0;i<3;i++)
	{
		scalco[i][0]=orico[i][0]*sx;
		scalco[i][1]=orico[i][1]*sy;
		scalco[i][2]=1;
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<scalco[i][j]<<" ";
		}
		cout<<endl;
	}
}


void trans::rotation(float theta,float orico[3][3])
{
	cout<<"Enter Rotation Angle"<<endl;
	cin>>theta;
	cout<<theta<<endl;
	theta= theta*(3.14/180);
	cout<<"Theta in radian: "<<theta<<endl;
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			rotco[i][j]=0;
		}
	}
	
	for(i=0;i<3;i++)
	{
		rotco[i][0]=orico[i][0]*cos(theta)-orico[i][1]*sin(theta);
		rotco[i][1]=orico[i][1]*(sin(theta))+orico[i][1]*cos(theta);
		rotco[i][2]=orico[i][0]+orico[i][1]+1;
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<"rotco"<<" "<<i<<" "<<j<<"->"<<rotco[i][j]<<" ";
		}
		cout<<endl;
	}
}


int main()
{
	int c;
	int gd= DETECT, gm;
	initgraph(&gd,&gm,"");
	trans t;
	int tx,ty;
	float sx,sy;
	float theta;
	float orico[3][3] ={{200,100,1},{100,200,1},{300,200,1}};   //original co-ordinates
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
	{
		cout<<"ori"<<" "<<i<<" "<<j<<"->"<<orico[i][j]<<"";
	}
	cout<<endl;
	}
	t.drawtri(orico);
	cout<<"Enter your choice"<<endl;
	cout<<"1. Translation"<<endl;
	cout<<"2. Scaling"<<endl;
	cout<<"3. Rotation"<<endl;
	cin>>c;
	switch(c)
	{
		case 1:
			t.translation(tx,ty,orico);
			t.drawtri(t.transco);
			break;
		case 2:
			t.scaling(sx,sy,orico);
			t.drawtri(t.scalco);
			break;
		case 3:
			t.rotation(theta,orico);
			t.drawtri(t.rotco);
			break;
		default:
			cout<<("You have written wrong Choice");
	}
	getch();
	return 0;
}


