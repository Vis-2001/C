#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 100
typedef struct node
{
    int vid;
    int loci;
    int locj;
    struct node *link;
}NODE;
typedef struct nodedemo
{

    int loci[100];
    int locj[100];
    int vid[100];
}node_demo;

typedef struct queue
{
    int from[MAX];
    int to[MAX];    
    int front;
    int rear;
}QUEUE;
typedef struct Graph 
{
  int numVertices;
  NODE *h[100];
  int visited[100];
}GRAPH;
int er,ec,sr,sc;
int pathdfs[MAX];
int len;
int read(int a[10][10]);
int create_matrix(int a[10][10],node_demo* info,int adj_mat[MAX][MAX],int n);
void initgraph(GRAPH *g,int n);
void convert_list(int a[MAX][MAX],GRAPH* g,node_demo* info);
int pathtraversalbfs(GRAPH *g, int startVertex,int destination,int pathbfs[MAX]);
int pathtraversaldfs(GRAPH *g, int startvertex,int destinationvertex);
void displaybfs(node_demo* info,int pathbfs[MAX],int n);
void displaydfs(node_demo* info);