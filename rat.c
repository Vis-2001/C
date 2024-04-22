#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
  int val;
  int row,col;
  struct node *r;
  struct node *d;
}no;//node definition
typedef struct start{
  no *head;
}st;//multilist definition
void init(st *p)//initialisation the starting of multilist
{
  p->head=NULL;
}

no *nod(int val)//creating of node
{
  no *temp=(no*)malloc(sizeof(no));
  temp->val=val;
  temp->r=NULL;
  temp->d=NULL;
  return temp;
}
void read(int *a,int n,FILE *fp)//reading a line of inputs that are seperated by space
{
  for(int i=0;i<n;i++)
  {
    fscanf(fp,"%d",a+i);
  }
}
void create(st *p,int row,int col,int rs,int cs,FILE *fp)//creating a multilist from starting point to ending point
{
  int arr[col+cs];
  for(int i=0;i<=rs;i++)
  read(arr,col+cs,fp);
  for(int i=0;i<col;i++)
  {
    no *q=p->head;
    no *temp=nod(arr[i+cs]);
    temp->row=1+rs;
    temp->col=i+1+cs;
    if(q==NULL)
    {
      p->head=temp;
    }
    else
    {
      while(q->r!=NULL)
      {
        q=q->r;
      }
      q->r=temp;
    }
  }
  for(int i=0;i<(row-1);i++)
  {
    no *q=p->head;
    for(int j=0;j<i;j++)
    {
      q=q->d;
    }
    no *m=NULL;
    int c=1;
    read(arr,col+cs,fp);
    while(q!=NULL)
    {
      no *temp=nod(arr[c-1+cs]);
      temp->row=i+2+rs;
      temp->col=c+cs;
      c++;
      q->d=temp;
      if(m!=NULL)
      {
        m->d->r=temp;
      }
      m=q;
      q=q->r;
    }
  }
}
void del(st *p,int row,int col)//deleting all nodes that cannot be reached
{
  for(int i=0;i<row;i++)
  {
    no *q=p->head;
    no *prevcol=NULL;
    no *prevrow=NULL;
    for(int j=0;j<(row-i-1);j++)
    {
      prevrow=q;
      q=q->d;
    }
    for(int j=0;j<col;j++)
    {
      if(q->val==1)
      {
        if(prevrow==NULL)
        {
          prevcol->r=NULL;
        }
        if(prevcol==NULL)
        {
          prevrow->d=NULL;
        }
        if(prevcol!=NULL && prevrow!=NULL)
        {
          prevcol->r=NULL;
          prevrow->d=NULL;
        }
      }
      prevcol=q;
      q=q->r;
    }
  }
}
int check(no *p)//checks if the bot can move down if it goes right
{
  if(p==NULL)
  return 0;
  if(p->val==0)
  return 1;
  else
  return check(p->r);
}
void path(st *p)//prints the output in the output file
{
  FILE *fp=fopen("out.txt","w");
  no *q=p->head;
  while(1)
  {
    int x=1;
    fprintf(fp,"%d,%d\n",q->row-1,q->col-1);
    if(q->d!=NULL)
    x=check(q->d->r);
    if(q->r!=NULL && ~x)
    q=q->r;
    else if(q->d!=NULL)
    q=q->d;
    else
    break;
  }
  fclose(fp);
}
int main()
{
  st head;
  init(&head);
  FILE *fp=fopen("input.txt","r");
  int r[2];
  int c[2];
  read(r,2,fp);
  read(c,2,fp);
  create(&head,c[0]-r[0]+1,c[1]-r[1]+1,r[0],r[1],fp);
  del(&head,c[0]-r[0],c[1]-r[1]);
  path(&head);
  return 0;
}
