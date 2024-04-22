#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct node{
  long int phno;
  struct node *next;
}nod;
typedef struct table{
  nod *tab[MAX];
}table;
void init(table *p)
{
  nod *temp=p->tab[0];
  for(int i=0;i<MAX;i++)
  {
    temp=NULL;
    temp++;
  }
}
void insert(table *p,long int num)
{
  nod *temp=(nod*)malloc(sizeof(nod));
  temp->phno=num;
  temp->next=NULL;
  int i=num%100;
  nod *q=p->tab[i];
  if(q==NULL)
  {
    p->tab[i]=temp;
  }
  else
  {
    temp->next=p->tab[i];
    p->tab[i]=temp;
  }
}
void delete(table *p,long int num)
{
  int i=num%100;
  nod *temp=p->tab[i];
  nod *temp1=NULL;
  if(temp==NULL)
  printf("NUMber not found\n");
  else
  {
    while(temp->phno!=num || temp!=NULL)
    {
      temp1=temp;
      temp=temp->next;
    }
    if(temp==NULL)
    printf("NUMber not found\n");
    else if(p->tab[i]==temp)
    {
      p->tab[i]=temp->next;
      free(temp);
      printf("%s\n","Phone number deleted" );
    }
    else
    {
      temp1->next=temp->next;
      free(temp);
      printf("Phone number deleted\n");
    }
  }
}
void search(table *p,long int num)
{
  int i=num%100;
  nod *temp=p->tab[i];
  while(temp->phno!=num || temp!=NULL)
  {
    temp=temp->next;
  }
  if(temp==NULL)
  printf("%s\n","Phone number not der");
  else
  {
    printf("The phone number has been found at array index %d",i);
  }
}
int main()
{
  table head;
  init(&head);
  int ch;
  long int num;
  while(1)
  {
    printf("Enter 1 for inserting numbers\n2 for searching a particular number\n3 for deleting a particular number\n4 for exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
      printf("%s\n","Enter phone number to be inserted");
      scanf("%ld",&num);
      insert(&head,num);
      break;
      case 2:
      printf("%s\n","Enter phone number to be searched");
      scanf("%ld",&num);
      search(&head,num);
      break;
      case 3:
      printf("%s\n","Enter phone number to be deleted");
      scanf("%ld",&num);
      delete(&head,num);
      break;
      default:
      exit(0);
    }
  }
}
