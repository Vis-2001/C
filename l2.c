#include <stdio.h>
#include <stdlib.h>
typedef struct list{
  int coeff;
  int px;
  int py;
  struct list *next;
}li;
typedef struct heading{
  li *head;
}h1;
void sum(h1 *header);
void init(h1 *header);
void read(h1 *header);
void display(h1 *header);
int main()
{
  h1 start;
  init(&start);
  printf("Enter no of values to be added:");
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    read(&start);
  }
  display(&start);
  sum(&start);
  //li *end=sum(&start);

  // while(end!=NULL)
  // {
  //   printf("The sum of coeff of power %d of x and %d of y is \n",end->px,end->py,end->coeff);
  //   end=end->next;
  // }
  return 0;
}
void sum(h1 *header)
{
  h1 *fi;
  fi->head=NULL;
  li*temp=header->head;
  while(temp!=NULL)
  {
    printf("in while of sum\n");
    li *temp1=fi->head;
    int val=0;
    while(temp1!=NULL)
    {
      printf("in while of sume 2\n");
      if(temp1->px==temp->px && temp1->py==temp->py)
      {
        printf("in if of sume 2\n");
        temp1->coeff=temp1->coeff+temp->coeff;
        val=1;
        break;
      }
      temp1=temp1->next;
    }
    if(val==0)
    {
      printf("in if of sume val=0\n");
      li *temp2=(li*)malloc(sizeof(li));
      temp2->coeff=temp->coeff;
      temp2->px=temp->px;
      temp2->py=temp->py;
      temp2->next=fi->head;
      fi->head=temp;
    }
    temp=temp->next;
  }
  while(fi->head!=NULL)
  {
    printf("The sum of coeff of power %d of x and %d of y is \n",fi->head->px,fi->head->py,fi->head->coeff);
    fi->head=fi->head->next;
  }
}
void init(h1 *header)
{
  (*header).head=NULL;
}
void read(h1 *header)
{
  li *temp=(li*)malloc(sizeof(li));
  printf("Enter coeff,power of x,power of y:");
  int n,m,l;
  scanf("%d %d %d",&n,&m,&l);
  temp->coeff=n;
  temp->px=m;
  temp->py=l;
  temp->next=header->head;
  header->head=temp;
}
void display(h1 *header)
{
  li *temp=header->head;
  while(temp!=NULL)
  {
    printf("Coefficient:%d\nPower of X:%d\nPower of Y:%d\n\n",temp->coeff,temp->px,temp->py);
    temp=temp->next;
  }
}
