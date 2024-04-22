#include "PES1UG20CS268_H.h"
int main()
{
    node_demo info;
    GRAPH g;
    int adj_mat[MAX][MAX]={0};
    int a[10][10];
    int pathbfs[MAX]={0};
    int pathdfs[MAX]={0};
    int n=read(a)+1;
    int c = create_matrix(a,&info,adj_mat,n);
    initgraph(&g,c);
    convert_list(adj_mat,&g,&info);
    n=pathtraversalbfs(&g,0,c-1,pathbfs);
    if(n)
    {
        displaybfs(&info,pathbfs,n);  
    }
    else
    {
        FILE* ptr = fopen("outbfs.txt","w");
		fprintf(ptr,"-1");
	    fclose(ptr);
    }
    c=pathtraversaldfs(&g,0,c-1);
    if(n)
    {
        displaydfs(&info);  
    }
    else
    {
        FILE* ptr = fopen("outdfs.txt","w");
		fprintf(ptr,"-1");
	    fclose(ptr);
    }
}