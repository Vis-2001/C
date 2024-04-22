#include <stdio.h>
#include <stdlib.h>
typedef struct node{
  int key;
  struct node *next;
}node_t;
node_t *head=NULL;
void ins_beg(int key);
void ins_end(int key);
void ins_n(int key,int pos);
void ins_af(int key,int pos);
void del_beg();
void del_end();
void del_n(int n);
void del_af(int n);
int nodes();
void search(int k);
void display();
int main()
{
  int value;
  scanf("%d",&value);
  ins_beg(value);
  scanf("%d",&value);
  ins_end(value);
  ins_n(7,2);
  ins_af(8,2);
  display();
  search(6);
  display();
  int len=nodes();
  printf("The no of nodes in the list is %d\n",len);
  del_beg();
  display();
  del_end();
  search(6);
  display();
  del_af(1);
  display();
  del_n(1);
  display();
  return 0;
}
void ins_beg(int key)
{
  node_t *temp=(node_t*)malloc(sizeof(node_t));
  temp->key=key;
  temp->next=head;
  head=temp;
}
void ins_end(int key) {
  node_t *temp=(node_t*)malloc(sizeof(node_t));
  temp->key=key;
  node_t *end=head;
  while(end->next!=NULL)
  end=end->next;
  temp->next=end->next;
  end->next=temp;
}
void ins_n(int key,int pos)
{
  node_t *temp=(node_t*)malloc(sizeof(node_t));
  temp->key=key;
  node_t *mid=head;
  for(int i=1;i<pos-1;i++)
  {
    mid=mid->next;
  }
  temp->next=mid->next;
  mid->next=temp;
}
void ins_af(int key,int pos)
{
  node_t *temp=(node_t*)malloc(sizeof(node_t));
  temp->key=key;
  node_t *mid=head;
  for(int i=1;i<pos;i++)
  {
    mid=mid->next;
  }
  temp->next=mid->next;
  mid->next=temp;
}
void del_beg()
{
  node_t *temp=head;
  head=temp->next;
  printf("Element delete is%d\n",temp->key);
  free(temp);
}
void del_end() {
  node_t *present=head;
  node_t *past=NULL;
  while(present->next!=NULL)
  {
    past=present;
    present=present->next;
  }
  printf("Element delete is%d\n",present->key);
  past->next=NULL;
  free(present);
}
void del_n(int n)
{
  node_t *present=head;
  node_t *past=NULL;
  if(n==1)
  {
    head=present->next;
    printf("Element delete is%d\n",present->key);
    free(present);
  }
  else
  {
  for(int i=1;i<n;i++)
  {
    past=present;
    present=present->next;
  }
  printf("Element delete is%d\n",present->key);
  past->next=present->next;
  free(present);
  }
}
void del_af(int n)
{
  node_t *present=head->next;
  node_t *past=head;
  if(n==1)
  {
    head=present->next;
    printf("Element delete is%d\n",present->key);
    free(present);
  }
  else
  {
  for(int i=1;i<n;i++)
  {
    past=present;
    present=present->next;
  }
  printf("Element delete is%d\n",present->key);
  past->next=present->next;
  free(present);
}
}
int nodes() {
  node_t *temp=head;
  int n=0;
  while(temp!=NULL)
  {
    temp=temp->next;
    n++;
  }
  return n;
}
void search(int k)
{
  int f=0;
  node_t *temp=head;
  while (temp!=NULL) {
    if(temp->key==k)
    {
      f=1;
      break;
    }
    temp=temp->next;
  }
  if(f==0)
  printf("Key is not present in list\n");
  else
  printf("Key found\n");
}
void display()
{
  node_t *temp=head;
  if(temp==NULL)
  printf("Empty list\n");
  else{
  do
  {
    printf("%d,",temp->key);
    temp=temp->next;
  }while(temp->next!=NULL);
  printf("%d\n",temp->key);
}
}
