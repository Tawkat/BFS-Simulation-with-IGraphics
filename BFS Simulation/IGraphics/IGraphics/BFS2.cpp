#include<stdio.h>
#include "iGraphics.h"
#include<conio.h>
#include"gl.h"

int mouseX, mouseY,node=0,a=0,i=0,j=0,z,y,switch_node=0,edge_node=0,process=0,mX[50],mY[50],eX[50],eY[50],c[50],edge,verte3x[50],parent[50] ;
char clear=0;

void iDraw()
{
	if(switch_node)
	{
		iSetColor(250,0,0);
		iFilledCircle(mX[i], mY[i], 20);
		node=i;
	}
	//printf("%d",node);
	if(edge_node)
	{
		if(j%2==0)
		{
			iLine(eX[j-1],eY[j-1],eX[j],eY[j]);
		}
		edge=j/2;
	}
	for(z=1;z<=j;z++)
	{
		for(y=1;y<=node;y++)
		{
			if((mX[y]-20<=eX[z] && mX[y]+20>=eX[z]) && (mY[y]-20<=eY[z] && mY[y]+20>=eY[z]))
			{
				c[z]=y;
				break;
			}
		}
	}
	/*if (clear)
	{
		iSetColor(0,0,0);
		iFilledCircle(mouseX,mouseY,20);
		//clear = 0;
		iSetColor(0,180,240);
	}*/
	
}

void iKeyboard(unsigned char key)
{
	if(key == 'n')
	{
		switch_node =1;
	}
	if(key == 'e')
	{
		switch_node=0;
		edge_node=1;
	}
		if(key == 'p')
	{
		switch_node=0;
		edge_node=0;
		process=1;
	}
		/*	if(key == 'e')
	{
		
	}*/
	//place your codes for other keys here
}

void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	//place your codes for other keys here
}
void iMouseMove(int mx, int my)
{
	//place your codes here
}
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(switch_node)
		{
			i++;
			mX[i]=mx;
			mY[i]=my;
		}
		if(edge_node)
		{
			j++;
			eX[j]=mx;
			eY[j]=my;
		}
	}

}



int main()
{
	iInitialize(1200, 700, "Ball Demo");

	return 0;


}