#include <stdio.h>
#include <stdlib.h>
typedef struct node{
  int val;
  struct node *l;
  struct node *r;
}n;
void init(n *p)
{
  p=NULL;
}
void insert(n *p,int val)
{
  if(p==NULL)
  {
    n *temp=(n*)malloc(sizeof(n));
    temp->val=val;
    temp->l=NULL;
    temp->r=NULL;
    p=temp;
  }
  else if(p->val>=val)
  {
    if(p->l==NULL)
    {
    n *temp=(n*)malloc(sizeof(n));
    temp->val=val;
    temp->l=NULL;
    temp->r=NULL;
    p->l=temp;
    }
    else
    insert(p->l,val);
  }
  else
  {
    if(p->r==NULL)
    {
      n *temp=(n*)malloc(sizeof(n));
      temp->val=val;
      temp->l=NULL;
      temp->r=NULL;
      p->r=temp;
    }
    else
    insert(p->r,val);
  }
}
void inorder(n *p)
{
  if(p==NULL)
  return;
  inorder(p->l);
  printf("%d\t",p->val);
  inorder(p->r);
}
void preorder(n *p)
{
  if(p==NULL)
  return;
  printf("%d\t",p->val);
  inorder(p->l);
  inorder(p->r);
}
void postorder(n *p)
{
  if(p==NULL)
  return;
  inorder(p->l);
  inorder(p->r);
  printf("%d\t",p->val);
}
int min(n *p)
{
  if(p->l==NULL)
  return p->val;
  min(p->l);
}
int max(n *p)
{
  if(p->r==NULL)
  return p->val;
  max(p->r);
}
char* search(n *p,int val)
{
  if(p==NULL)
  return "Not found";
  else if(p->val==val)
  return "Found";
  else if(val<p->val)
  search(p->l,val);
  else
  search(p->r,val);
}
int depth(n *p,int d)
{
  if(p==NULL)
  return d;
  int dl=depth(p->l,d+1);
  int dr=depth(p->r,d+1);
  if(dl>=dr)
  return dl;
  else
  return dr;
}
int height(n *p,int val,int h)
{
  if(p==NULL)
  return -1;
  if(p->val==val)
  return h;
  if(p->val>val)
  return height(p->l,val,h+1);
  else
  return height(p->r,val,h+1);
}
int nodes(n *p)
{
  if(p==NULL)
  return 0;
  return 1+nodes(p->l)+nodes(p->r);
}
int l_nodes(n *p)
{
  if(p->l==NULL && p->r==NULL)
  return 1;
  else if(p->l==NULL)
  return l_nodes(p->r);
  else if(p->r==NULL)
  return l_nodes(p->l);
  return l_nodes(p->l)+l_nodes(p->r);
}
n *f_gc(n *p)
{
  if(p->l==NULL && p->r==NULL)
  return p;
  else
  f_gc(p->l);
}
int delete(n *p,n *p1,int value, n **head)
{
  if(p==NULL)
  return -1;
  else if(p->val>value)
  {
    return delete(p->l,p,value,head);
  }
  else if(p->val<value)
  {
    return delete(p->r,p,value,head);
  }
  else
  {
    if(p->l==NULL && p->r==NULL)
    {
      if(p1->l==p)
        p1->l=NULL;
      else
        p1->r=NULL;
    }
    else if(p->l==NULL)
    {
      if(p1->l=p)
        p1->l=p->r;
      else
        p1->r=p->r;
      }
      else if(p->r==NULL)
      {
        if(p1->l=p)
          p1->l=p->l;
        else
          p1->r=p->l;
        }
      else
      {
        n *temp=f_gc(p->r);
        temp->l=p->l;
        if(p1->l==p)
          p1->l=p->r;
        if(p1->r==p)
          p1->r=p->r;
      }
      int v=p->val;
      free(p);
      return v;
  }
}
int nodes_2(n *p)
{
  if(p==NULL)
  return 0;
  if(p->l!=NULL && p->r!=NULL)
  return 1+nodes_2(p->l)+nodes_2(p->r);
}

int main()
{
  n *head;
  n *temp=(n*)malloc(sizeof(n));
  temp->val=100;
  temp->l=NULL;
  temp->r=NULL;
  head=temp;
  init(head);
  insert(head,10);
  insert(head,9);
  insert(head,102);
  printf("%s\n","Inorder");
  inorder(head);
  insert(head,50);
  insert(head,25);
  insert(head,150);
  printf("%s\n","Preorder");
  preorder(head);
  insert(head,35);
  insert(head,90);
  insert(head,200);
  printf("%s\n","Postorder");
  postorder(head);
  printf("Minimum valur:%d\n",min(head));
  printf("Maximum valur:%d\n",max(head));
  printf("We have searched 11 in the tree %s\n",search(head,11));
  printf("We have searched 50 in the tree %s\n",search(head,50));
  printf("The depth of the tree is %d\n",depth(head,0));
  printf("The height of 25 is %d\n",height(head,25,1));
  printf("The height of 151 is %d\n",height(head,151,1));
  printf("Ascending order:\n");
  inorder(head);
  printf("\nTotal no of nodes in the binary tree are %d\n",nodes(head));
  printf("Total no of leaf nodes are %d\n",l_nodes(head));
  printf("Total no of interior nodes are %d\n",nodes(head)-l_nodes(head)-1);
  printf("No of nodes with 2 children are %d\n",nodes_2(head));
  printf("No of nodes with 1 children are %d\n",nodes(head)-nodes_2(head)-l_nodes(head));
  printf("We are trying to delete 15 %d\n",delete(head,NULL,15,&head));
  printf("%s\n","Inorder");
  inorder(head);
  printf("\nWe are trying to delete 200 %d\n",delete(head,NULL,200,&head));
  printf("%s\n","Inorder");
  inorder(head);
  printf("\nWe are trying to delete 50 %d\n",delete(head,NULL,50,&head));
  printf("%s\n","Inorder");
  inorder(head);
  if(head->val==100)
  {
    n *temp=f_gc(head->r);
    temp->l=head->l;
    n *temp1=head;
    head=head->r;
    free(temp);
  }
  printf("\n100 has been deleted\n");
  printf("%s\n","Inorder");
  inorder(head);
}
