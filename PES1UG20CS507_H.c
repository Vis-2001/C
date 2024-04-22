#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PES1UG20CS507_H.h"
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
int rowdel(no *p,int up,int col)//deleting nodes if they are usless or unreachable in row form
{
  no *q=NULL;
  for(int i=0;i<col;i++)
  {
    if(i<up)
    {
      q=p;
      p=p->r;
    }
    else
    {
      if(p->val==0)
      {
        up=i;
        q=p;
        p=p->r;
      }
      else
      {
        q->r=NULL;
        return up;
      }
    }
  }
  return up;
}
void del(st *p,int row,int col)//deleting all nodes that cannot be reached
{
  int up=0;
  for(int i=0;i<row;i++)
  {
    no *q=p->head;
    for(int j=0;j<i;j++)
    {
      q=q->d;
    }
    up=rowdel(q,up,col);
  }
}
int check(no *p,int row,int col)//checks if by going to the next node they can reach the destination
{
  int right=0;
  int down=0;
  if(p->r!=NULL && p->d!=NULL)
  {
    if(p->r->val==1 && p->d->val==1)
    return 0;
  }
  if(p->row==row && p->col==col)
  return 1;
  if(p->r!=NULL)
  {
    if(p->val==0)
    {
      if(p->r->val==0)
      right=check(p->r,row,col);
    }
  }
  if(p->d!=NULL)
  {
    if(p->val==0)
    {
      if(p->d->val==0)
      down=check(p->d,row,col);
    }
  }
  if(right==1 || down==1)
  return 1;
  return 0;
}

void path(st *p,int row,int col)//prints the output in the output file
{
  FILE *fp=fopen("out.txt","w");
  no *q=p->head;
  while(1)
  {
    fprintf(fp,"%d,%d\n",q->row-1,q->col-1);
    int ctr=0;
    if(q->r!=NULL)
    {
      if(check(q->r,row,col))
      {
        q=q->r;
        ctr=1;
      }
    }
    if(q->d!=NULL && ctr==0)
    {
      if(check(q->d,row,col))
      {
        q=q->d;
        ctr=1;
      }
    }
    if(ctr==0)
    break;
  }
  if(q->row==row && q->col==col)
  {
    if(q->r->val==0)
    {
      fprintf(fp,"%d,%d\n%d,%d\n",q->r->row-1,q->r->col-1,row,col);
    }
    else if(q->d->val==0)
    {
      fprintf(fp,"%d,%d\n%d,%d\n",q->d->row-1,q->d->col-1,row,col);
    }
    else
    printf("No path to reach\n");
  }
  fclose(fp);
}
