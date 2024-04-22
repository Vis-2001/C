#include<stdio.h>
typedef struct tree_node
{
int info;
int used;
}TREE;
#define MAXNODES 50
void init(TREE t[MAXNODES])
{
for(int i=0;i<MAXNODES;i++)
t[i].used=0;
}
int create(TREE *bst)
{
int ele, wish;
printf("Enter the root element\n");
scanf("%d",&bst[0].info);
bst[0].used=1;
int cnt=1;
do{
printf("Enter an element\n");
scanf("%d",&ele);
int p=0;

while(p<MAXNODES && bst[p].used)
{
if(ele<bst[p].info)
p=2*p+1;
else
p=2*p+2;
}
if(p>=MAXNODES)
printf("Insertion not possible\n");
else
{
bst[p].info=ele;
bst[p].used=1;
cnt++;
}
printf("Do you wish to add another\n");
scanf("%d",&wish);
}while(wish);
return cnt/2;
}
void preorder(TREE* bst, int r)
{
if(bst[r].used)
{
printf("%d ",bst[r].info);
preorder(bst,2*r+1);
preorder(bst,2*r+2);
}
}
int main()
{
TREE bst[MAXNODES];
init(bst);
int height=create(bst);
printf("The height of the tree is %d and the level is %d\n",height+1,height);
preorder(bst,0);
return 0;
}
