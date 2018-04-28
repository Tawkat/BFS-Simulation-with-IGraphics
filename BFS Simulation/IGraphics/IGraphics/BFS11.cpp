
#include<stdio.h>
#include "iGraphics.h"
#include<conio.h>
#include"gl.h"

int G[1000][1000]={0},P[1000]={0},R[1000]={0},dx[1000],dy[1000],px[1000],py[1000];
int Q[1000]={0};
int xn[1000],flag1=0,src,yp[1000]={0},ax[1000],ay[1000],bx[1000],by[1000];//,yn[1000]={0};
int cx,cy,cz;

int mouseX, mouseY,node=0,a=0,i=0,j=0,z,y,switch_node=0,edge_node=0,source_node=0,process=0,bfs_path=0,mX[50],mY[50],eX[50],eY[50],c[50],sx,sy,edge,vertex[50],parent[100],v1,v2,flag=0,w,flag2=0;
char clear=0;



void bfs(int n,int s)
{
	int p=1,q=1,r=1,t=0;
    int Q[1000];
    Q[r]=s;
    int visited[100]={0},level[100];
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
        for(int i=1,w=1;i<=xn[u];i++,w++)
        {
            int v=G[u][i];
			//printf("%d ",G[u]);
            if(!visited[v])
            {
                level[v]=level[u]+1;
                parent[v]=u;
				P[w]=u;
				Q[w]=v;
				ax[w]=mX[u];
				px[w]=ax[w];
				dx[w]=ax[w]+1;
				ay[w]=mY[u];
				py[w]=ay[w];
				dy[w]=((by[w]-ay[w])/(bx[w]-ax[w]))*dx[w];
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

/*int main ()
{
    int n,e,x,y,i,j;
    scanf("%d %d",&n,&e);
    for(i=1;i<=e;i++)
    {
        scanf("%d %d",&x,&y);
       
    }
    bfs(n,1);
}*/


void iDraw()
{
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
				c[z]=y;
				
				//printf("%d ",c[z]);
				if(z%2==0)
				{
					//flag1=1;
					v1=c[z-1];
					v2=c[z];
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
	if(process && source_node)
	{
		if(flag1==0)
		{
			bfs(node,src);
			flag1=1;
		}
		iSetColor(180,180,180);
		//line;
		printf("%d\n",ax[i]);
		for(i=1;i<=w;i++){
			iLine(ax[i],ay[i],bx[i],by[i]);}
        for(int i=1;i<=w;i++)
        {
			//flag2=0;
           
			iLine(px[i],py[i],dx[i],dy[i]);
			
			/*cx=30+50*parent[i];
			cy=250-25*parent[i];
			cz=100+30*parent[i];
			if(cx>255)
			{
				cx=80+10*parent[i];
			}
			if(cx<0)
			{
				cx=255-10*parent[i];
			}
			if(cy>255)
			{
				cy=80+10*parent[i];
			}
			if(cy<0)
			{
				cy=255-10*parent[i];
			}
			if(cz>255)
			{
				cz=80+10*parent[i];
			}
			if(cz<0)
			{
				cz=255-10*parent[i];
			}
			//printf("%d ",parent[2]);
			iSetColor(cx,cy,cz);
            iLine(mX[parent[i]],mY[parent[i]],mX[i],mY[i]);
			//********************
		/*	if(bfs_path)
	{
		if(edge_node)
		{
			printf("p");
			iSetColor(0,0,0);
		for(i=1;i<=edge;i++)
		{
			iLine(eX[i],eY[i],eX[i+1],eY[i+1]);
		}
		edge_node=0;
		}*/
			/*iSetColor(0,0,255);
			for(i=1;i<=node;i++)
			{
				iFilledCircle(mX[i],mY[i],20);
			}//****
        }*/
		}
	}
}
void line()
{
	if(dx[w]<bx[w])
	{
		dx[w]=dx[w]+1;
	dy[w]=((by[w]-ay[w])/(bx[w]-ax[w]))*dx[w];
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
	//	edge_node=1;
		source_node=1;
	}
		if(key == 'p')
	{
		switch_node=0;
		edge_node=0;
		//source_node=0;
		process=1;
	}
		if(key == 'b')
		{
			//edge_node=1;
			
			bfs_path=1;
			source_node=0;
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
	}

}



int main()
{
	//int G[1000][1000]={0};
	//int flag1=0;//,
	iSetTimer(5,line);
	iInitialize(1200, 700, "BFS");

	return 0;


}