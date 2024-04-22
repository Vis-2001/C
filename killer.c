#include <stdio.h>
#include <stdlib.h>
typedef struct cir{
  int key;
  struct cir *next;
}c;
typedef struct header{
  c *head;
}h;
void init(h *p)
{
  p->head=NULL;
}
void circle(h *p,int n)
{
  if(n<=0)
  printf("%s\n","bro greater than 1");
  else
  {
    c *temp=(c*)malloc(sizeof(c));
    temp->key=n;
    temp->next=temp;
    p->head=temp;
    c *pres=p->head;
    for(int i=1;i<n;i++)
    {
      c *temp1=(c*)malloc(sizeof(c));
      temp1->key=n-i;
      temp1->next=pres->next;
      pres->next=temp1;
    }
    p->head=p->head->next;
  }
}
void del(h *p,int k)
{
  c *pres=p->head;
  c *past=NULL;
  while(p->head!=p->head->next)
  {
      for(int i=1;i<k;i++)
      {
        past=pres;
        pres=pres->next;
      }
      if(p->head==pres)
      {
        p->head=pres->next;
        past->next=p->head;
        free(pres);
        pres=p->head;
      }
      else
      {
        past->next=pres->next;
        free(pres);
        pres=past->next;
      }
  }
}
void check(h *p)
{
  printf("The suvivor is %d\n",p->head->key);
}
void one(h *p)
{
  c *pres=p->head;
  c *temp=p->head;
  while(pres->next!=temp)
  {
    p->head=pres->next;
    free(pres);
    pres=p->head;
  }
}
int main()
{
  h p;
  init(&p);
  printf("Enter No of ppl in the circle:");
  int no;
  scanf("%d",&no);
  circle(&p,no);
  printf("Enter k value:");
  scanf("%d",&no);
  if(no>0)
  {
    if(no>1)
    del(&p,no);
    else if(no==1)
    one(&p);
    check(&p);
  }
  else
  printf("Positive no broo!!!!\n");
  return 0;
}
