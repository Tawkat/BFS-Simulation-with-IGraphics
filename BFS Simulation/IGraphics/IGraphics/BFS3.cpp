#include<stdio.h>
#include <stdlib.h>
#include "iGraphics.h"
#include<conio.h>
#include"gl.h"

int mouseX, mouseY,node=0,a=0,i=0,j=0,z,y,switch_node=0,edge_node=0,process=0,mX[50],mY[50],eX[50],eY[50],c[50],edge,verte3x[50],parent[50],lev,per ;
char clear=0;
struct Edge {
    int vertex;
    struct Edge * next;
};

// Inserts Node to the Linked List by Head Insertion - O(1)
// Returns address of head which is the newly created node.
struct Edge * AddEdge(struct Edge * currentHead, int newVertex)
{
    struct Edge * newHead
                 = (struct Edge *) malloc(sizeof(struct Edge));

    newHead->vertex = newVertex;
    newHead->next = currentHead;

    return newHead;
}

void BreadthFirstSearch(
                        struct Edge * adjacencyList[],
                        int vertices,
                        int parent[],
                        int level[],
                        int startVertex
                       )
{
    struct Edge * traverse;
    int i, par, lev, flag = 1;
    // 'lev' represents the level to be assigned
    // 'par' represents the parent to be assigned
    // 'flag' used to indicate if graph is exhausted

    lev = 0;
    level[startVertex] = lev;
    // We start at startVertex

    while (flag) {
        flag = 0;
        for (i = 1; i <= vertices; ++i) {
            if (level[i] == lev) {
                flag = 1;
                traverse = adjacencyList[i];
                par = i;

                /*while (traverse != NULL) {
                    if (level[traverse->vertex] != -1) {
                        traverse = traverse->next;
                        continue;
                    }

                    level[traverse->vertex] = lev + 1;
                    parent[traverse->vertex] = par;
                    traverse = traverse->next;
                }*/
            }
        }

        ++lev;
    }
}

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
		//printf("p");
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
	//new implementation
    if(process==1)
	{
		//printf("p");
		iSetColor(0,255,200);
			//==========  ========== ========== ========= */
//         Breadth First Search (BFS)          //
//               Algorithm in C                //
//                                             //
//         Functions follow Pascal Case        //
//           Convention and Variables          //
//         follow Camel Case Convention        //
//                                             //
//            Author - Vamsi Sangam            //
//            Theory of Programming            //
/* ========== ========== ========== ========== */

/*struct Edge {
    int vertex;
    struct Edge * next;
};

// Inserts Node to the Linked List by Head Insertion - O(1)
// Returns address of head which is the newly created node.
struct Edge * AddEdge(struct Edge * currentHead, int newVertex)
{
    struct Edge * newHead
                 = (struct Edge *) malloc(sizeof(struct Edge));

    newHead->vertex = newVertex;
    newHead->next = currentHead;

    return newHead;
}

void BreadthFirstSearch(
                        struct Edge * adjacencyList[],
                        int vertices,
                        int parent[],
                        int level[],
                        int startVertex
                       )
{
    struct Edge * traverse;
    int i, par, lev, flag = 1;
    // 'lev' represents the level to be assigned
    // 'par' represents the parent to be assigned
    // 'flag' used to indicate if graph is exhausted

    lev = 0;
    level[startVertex] = lev;
    // We start at startVertex

    while (flag) {
        flag = 0;
        for (i = 1; i <= vertices; ++i) {
            if (level[i] == lev) {
                flag = 1;
                traverse = adjacencyList[i];
                par = i;

                /*while (traverse != NULL) {
                    if (level[traverse->vertex] != -1) {
                        traverse = traverse->next;
                        continue;
                    }

                    level[traverse->vertex] = lev + 1;
                    parent[traverse->vertex] = par;
                    traverse = traverse->next;
                }
            }
        }

        ++lev;
    }
}*/
    int vertices, edges, i, v1, v2;

    /*printf("Enter the Number of Vertices -\n");
    scanf("%d", &vertices);*/
	vertices=node;

    /*printf("\nEnter the Number of Edges -\n");
    scanf("%d", &edges);*/
	edges=edge;

    struct Edge * adjacencyList[100];
    // Size is made (vertices + 1) to use the
    // array as 1-indexed, for simplicity

    int parent[100];
    // Each element holds the Node value of its parent
    int level[100];
    // Each element holds the Level value of that node

    // Must initialize your array
    for (i = 0; i <= vertices; ++i) {
        adjacencyList[i] = NULL;
        parent[i] = 0;
        level[i] = -1;
    }

    for (i = 1; i <= edges; ++i) {
        //scanf("%d%d", &v1, &v2);
		v1=c[z],v2=c[z+1];

        // Adding edge v1 --> v2
        adjacencyList[v1] = AddEdge(adjacencyList[v1], v2);

        // Adding edge v2 --> v1
        // Remove this if you want a Directed Graph
        adjacencyList[v2] = AddEdge(adjacencyList[v2], v1);
    }

    // Printing Adjacency List
   /* printf("\nAdjacency List -\n\n");
    for (i = 1; i <= vertices; ++i) {
        printf("adjacencyList[%d] -> ", i);

        struct Edge * traverse = adjacencyList[i];

        while (traverse != NULL) {
            printf("%d -> ", traverse->vertex);
            traverse = traverse->next;
        }

        printf("NULL\n");
    }*/

    //printf("\nEnter a Start Vertex - ");
    //scanf("%d", &v1);
	//v1=1;

    BreadthFirstSearch(adjacencyList, vertices, parent, level,1);

    // Printing Level and Parent Arrays
    //printf("\nLevel and Parent Arrays -\n");
    for (i = 1; i <= vertices; ++i) {
        /*printf("Level of Vertex %d is %d, Parent is %d\n",
                                  i, level[i], parent[i]);*/
		printf("p");
		iSetColor(0,255,200);
		iLine(mX[level[i]],mY[level[i]],mX[parent[i]],mY[parent[i]]);
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