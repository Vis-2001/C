#include<stdio.h>

int visit[100];
int a[100][100];
int n;


void dfs(int v)
{
	int i;
	visit[v]=1;
	for (i=1;i<=n;i++)
	{
		if((a[v][i]==1) &&(visit[i]==0))
			dfs(i);
	}
}
int check(int v)
{
  if(n==v)
  return 1;
  if(visit[v]==0)
  return 0;
  check(v+1);
}
void create_graph()
{
    int i;int j;
    while(1)
    {
      printf("Enter the source and the destination vertex of the edge\n");
      scanf("%d %d",&i,&j);
      if(i==0 && j==0) //to stop taking input
       break;
      a[i][j]=1;	//for undirected graph: Its should be a[i][j]=a[j][i]=1;
    }
}


int main()
{
	int i;int v;int k;

	printf("Enter the number of vertices\n");
	scanf("%d",&n);

	create_graph();
	printf("Enter the source vertex\n");
	scanf("%d",&v);
	dfs(v);
  int success=check(0);
  if(success)
  printf("%s\n","All nodes are reachable");
  else
  printf("%s\n","Nodes arnt reachable");
	return 0;
  }
