
#include<stdio.h>
#include "iGraphics.h"
#include<conio.h>
#include"gl.h"

int G[1000][1000]={0},P[1000]={0},R[1000]={0};
int Q[1000]={0};
int xn[1000],flag1=0,src,yp[1000]={0},ax[1000],ay[1000],bx[1000],by[1000],fx,fy,final=0,check,u,desx[1000],desy[1000];//,yn[1000]={0};
int cx,cy,cz;

int mouseX, mouseY,node=0,a=0,i=0,j=0,z,y,switch_node=0,edge_node=0,source_node=0,des_node=0,process=0,bfs_path=0,mX[50],mY[50],eX[50],eY[50],c1[50],sx,sy,edge,vertex[50],parent[100],level[100],v1,v2,flag=0,w=1,flag2=0;
char clear=0;
//*********
double diff_x, diff_y;
double mx,my,nx,ny;
double x1,k1,x2,y2,p,c;
double dx,dy;//dy=my;
int i1=1,flag3=1,flag4=1,flag6;

void bfs(int n,int s)
{
	int p=1,q=1,r=1,t=0;
    int Q[1000];
    Q[r]=s;
    int visited[100]={0};//,level[100];
    //int parent[100];
    visited[s]=1;
    level[s]=0;
    do
    {
		flag=0;
        int u=Q[r];
		//printf("%d ",u);
		q=r;
		r++;
        for(int i=1;i<=xn[u];i++,w++)
        {
            int v=G[u][i];
			//printf("%d\n ",w);
            if(!visited[v])
            {
                level[v]=level[u]+1;
                parent[v]=u;
				P[w]=v;
				//Q[w]=v;
				ax[w]=mX[u];
				ay[w]=mY[u];
				bx[w]=mX[v];
				by[w]=mY[v];
                visited[v]=1;
				p++;
                Q[p]=v;
            }
		/*	if(v==G[n][xn[n]])
		{
			break;
		}*/
        }
			if(Q[r]==G[n][xn[n]] && Q[r]==0)
		{
			printf("p");
			break;
		}
		//printf("p");
        Q[q]=0;
		//q++;
		for(t=1;t<=p;t++)
		{
			if(Q[t]!=0)
			{
				flag=1;
				break;
			}
		}
        }while(flag);
	//printf("p");
		/*iSetColor(180,180,180);
        for(int i=1;i<=n;i++)
        {
            if(i==src)
            {
                continue;
               // parent[i]=0;
            }
			//printf("%d ",parent[2]);
            iLine(mX[parent[i]],mY[parent[i]],mX[i],mY[i]);
        }*/
}
//****************************
void bfs2(int f)
{
	//source_node=1;
	//bfs(node,src);
	desx[1]=f;
			for(int u=2;;u++)
			{
				desx[u]=parent[check];
				printf("%d\n",u);
				
				check=parent[check];
				if(check==src)
				{
					printf("%d\n",src);
					break;
				}
			}
}
//************************
void ballChange(){
	//if(ball_x > 500 || ball_x < 0)dx = -dx;
	//if(ball_y > 500 || ball_y < 0)dy = -dy;
	
	if(mx<nx)
	{
		dx=dx+1;
		//diff_x=(nx-mx+0.00);
	}
	if(mx>nx)
	{
		dx=dx-1;
		//diff_x=(mx-nx+0.00);
	}diff_x=(nx-mx+0.00);
	diff_y=(ny-my);
	/*if(mx>nx)
	{
		diff_y=diff_y*2;
	}*/
	dy=((diff_y*dx)/(diff_x+0.00))+c;

}

void iDraw()
{
	//ax[0]=100,ay[0]=100,bx[0]=100,by[0]=300;
	iSetColor(0,250,0);
	iText(200,80,"press 'n' for node :: 'e' for edge :: 's' for starting node :: 'p' for process :: 'b' for BFS path");
	//flag1=0;
	if(switch_node)
	{
		if(i!=0)
		{
		iSetColor(255,0,0);
		iFilledCircle(mX[i], mY[i], 20);
		node=i;
		}
	}
	//printf("%d",node);
	if(edge_node)
	{
		iSetColor(255,0,0);
		if(j%2==0)
		{
			for(z=j-1;z<=j;z++)
	{
		for(y=1;y<=node;y++)
		{
			//flag1=0;
			if((mX[y]-20<=eX[z] && mX[y]+20>=eX[z]) && (mY[y]-20<=eY[z] && mY[y]+20>=eY[z]))
			{
				eX[z]=mX[y];
				eY[z]=mY[y];
				
			}
		}
	}
			iLine(eX[j-1],eY[j-1],eX[j],eY[j]);
		}
		edge=j/2;
	}
	if(edge_node==0)
	{
	for(z=1;z<=j;z++)
	{
		for(y=1;y<=node;y++)
		{
			//flag1=0;
			if((mX[y]-20<=eX[z] && mX[y]+20>=eX[z]) && (mY[y]-20<=eY[z] && mY[y]+20>=eY[z]))
			{
				c1[z]=y;
				
				//printf("%d ",c[z]);
				if(z%2==0)
				{
					//flag1=1;
					v1=c1[z-1];
					v2=c1[z];
					//printf("%d %d\n",v1,v2);
					//xn[v1];
					//xn[v2];
					//printf("%d %d\n",xn[v1],xn[v2]);
					/*if(G[2][2]==3)
					{
					printf("%d",G[2][2]);
						//printf("%d %d\n",xn[v1],xn[v2]);
					}*/
					G[v1][++xn[v1]]=v2;
					G[v2][++xn[v2]]=v1;
					//printf("%d\n",xn[2]);
					//printf("%d",G[3][2]);
					break;
					
				}
				break;
			}
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
	/*if(bfs_path)
	{
		if(edge_node)
		{iSetColor(0,0,0);
		for(i=1;i<=edge;i++)
		{
			iLine(eX[i],eY[i],eX[i+1],eY[i+1]);
		}
		edge_node=0;
		}
		/*iSetColor(0,0,255);
			for(i=1;i<=node;i++)
			{
				iFilledCircle(mX[i],mY[i],20);
			//}
	}*/
	if(process)
	{
		if(flag1==0)
		{
			bfs(node,src);
			flag1=1;
			//source_node=0;
		}
		//iSetColor(180,180,180);
		//line;
		//*************
		if(final==0)
		{
			if(flag3==1)
	{
		mx=ax[i1],my=ay[i1],nx=bx[i1],ny=by[i1];
			x1=mx,k1=my,x2=nx,y2=ny,p,c=(ny-((ny-my)/(nx-mx+0.00))*nx)+0.00;
			/*if(mx>nx)
			{
				c=c*(-1);
			}*/
			dx=x1;
			dy=k1;
			flag3=0;
				i1++;
	}
		//*****
		/*switch(level[P[i1]])   //coloring according to level
		{
		case 1:
			iSetColor(0,128,128);
			break;
		case 2:
			iSetColor(255,255,0);
			break;
		case 3:
			iSetColor(0,128,128);
			break;
		case 4:
			iSetColor(0,128,128);
			break;
		case 5:
			iSetColor(0,128,128);
			break;
		case 6:
			iSetColor(0,128,128);
			break;
		default:
			iSetColor(0,128,128);
			break;

		}*/
		//****
	if(dx<nx)
	{
		//iResumeTimer(0);
		iSetColor(0,0,210);
		iLine(x1,k1,dx,dy);
		//iSetColor(255,0,0);
		x1=dx;
		k1=dy;
	}
	
		else if(dx>nx)
	{
		//iResumeTimer(0);
		iSetColor(0,0,210);
		iLine(x1,k1,dx,dy);
		x1=dx;
		k1=dy;
	}
	if((mx!=0 || my!=0)&&(nx!=0 || ny!=0))
	{
		iSetColor(255,0,0);
		iFilledCircle(mx,my, 20);
		iSetColor(255,0,0);
		iFilledCircle(nx,ny, 20);
	}
	if(dx==nx && i1<=w){
		//	iPauseTimer(0);
		/*iSetColor(0,0,0);
		iFilledRectangle(0,0,500,500);
		iSetColor(255,0,0);
		iLine(x1,k1,x2,y2);*/
		flag3=1;
	}
		}
		//*********************************************
		if(final>0)
		{
			if(flag6==1)
			{
				des_node=0;
				source_node=0;
				process=0;
				//bfs(node,src);
				bfs2(final);
				flag6=0;
			}
			//*************
			iSetColor(0,210,210);
				if(flag4==1)
	{
		mx=mX[desx[u]],my=mY[desx[u]],nx=mX[desx[u-1]],ny=mY[desx[u-1]];
			x1=mx,k1=my,x2=nx,y2=ny,p,c=(ny-((ny-my)/(nx-mx+0.00))*nx)+0.00;
			/*if(mx>nx)
			{
				c=c*(-1);
			}*/
			dx=x1;
			dy=k1;
			flag4=0;
				u--;
		
			//des_node=0;
			//break;
		
	}
		
	if(dx<nx)
	{
		//iResumeTimer(0);
	//	iSetColor(0,0,210);
		if(mx!=mX[0] || my!=mY[0])
		{
			iLine(x1,k1,dx,dy);
		}
		//iSetColor(255,0,0);
		x1=dx;
		k1=dy;
	}
	
		else if(dx>nx)
	{
		//iResumeTimer(0);
	//	iSetColor(0,0,210);
		if(mx!=mX[0] || my!=mY[0])
		{
			iLine(x1,k1,dx,dy);
		}
		x1=dx;
		k1=dy;
	}
	if((mx!=0 || my!=0)&&(nx!=0 || ny!=0))
	{
		iSetColor(255,0,0);
		iFilledCircle(mx,my, 20);
		iSetColor(255,0,0);
		iFilledCircle(nx,ny, 20);
	}
	if(dx==nx && parent[check]!=src){
		//	iPauseTimer(0);
		/*iSetColor(0,0,0);
		iFilledRectangle(0,0,500,500);
		iSetColor(255,0,0);
		iLine(x1,k1,x2,y2);*/
		flag4=1;
	}
		
			}
		}
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
	if(key == 's')
	{
		switch_node=0;
		edge_node=1;
		source_node=1;
	}
	if(key == 'd')
	{
		switch_node=0;
		edge_node=0;
		des_node=1;
		source_node=1;
	}
		if(key == 'p')
	{
		//switch_node=1;
		edge_node=0;
		//source_node=0;
		process=1;
	}
		if(key == 'b')
		{
			//edge_node=1;
			
			bfs_path=1;
			source_node=1;
			//process=0;
			//switch_node=1;
		}
			/*if(key == 'e')
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
		if(source_node)
		{
			sx=mx;
			sy=my;
			for(y=1;y<=node;y++)
		{
			//flag1=0;
			if((mX[y]-20<=sx && mX[y]+20>=sx) && (mY[y]-20<=sy && mY[y]+20>=sy))
			{
				src=y;
				

				
			}
		}
		}
		if(des_node)
		{
			edge_node=1;
			fx=mx;
			fy=my;
			for(y=1;y<=node;y++)
		{
			//flag1=0;
			if((mX[y]-20<=fx && mX[y]+20>=fx) && (mY[y]-20<=fy && mY[y]+20>=fy))
			{
				final=y;
				check=final;
				flag6=1;
				break;
				

				
			}
		}
			
		}
	}

}



int main()
{
	//int G[1000][1000]={0};
	//int flag1=0;//,
	iSetTimer(5,ballChange);
	iInitialize(1200, 700, "BFS");

	return 0;


}