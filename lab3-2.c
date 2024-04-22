#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct Department{
  char name[25];
  int number;
} Dep;
typedef struct Node{
  char ssn[15];
  char name[25];
  Dep department;
  char designations[20];
  int salary;
  int phone_number;
  int age;
  struct Node *next, *prev;
} Node;
typedef struct Employees {
  Node *head;
} Emp;
void init(Emp *li);
void insert(Emp *p,char *name, char *ssn,char *dep,char *des,int age,int sal,int p_n,int code);
void del(Emp *p);
void display(Emp *p,char des[]);
int main()
{
  Emp list;
  init(&list);
  int choice=2;
  while (choice) {
    printf("Enter SSN, Employee name,Department,designations,department code,salary,phone number and age\n");
    int s,p,a,c;
    char n[15],m[25],d[20],dp[25];
    scanf("%s",n );
    fflush(stdout);
    scanf("%s",m );
    fflush(stdout);
    scanf("%s",dp);
    fflush(stdout);
    scanf("%s",d);
    fflush(stdout);
    scanf("%d",&c);
    scanf("%d",&s);
    scanf("%d",&p);
    scanf("%d",&a);
    insert(&list,n,m,dp,d,a,s,p,c);
    printf("Enter 0 to exit");
    scanf("%d",&choice);
  }
  del(&list);
  choice=1;
  while (choice) {
    printf("Enter department of which u want details:");
    char dep[20];
    scanf("%s",dep);
    display(&list,dep);
    printf("Enter 0 to exit");
    scanf("%d",&choice);
  }
  return 0;
}
void init(Emp *li)
{
  li->head=NULL;
}
Node* create_node(char *name, char *ssn,char *dep,char *des,int age,int sal,int p_n,int code)
{
	Node *temp=(Node*)malloc(sizeof(Node));
	strcpy(temp->name, name);
	temp->phone_number=p_n;
	strcpy(temp->ssn, ssn);
	strcpy(temp->designations, des);
  strcpy(temp->department.name, dep);
  temp->salary=sal;
  temp->age=age;
  temp->department.number=code;
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}
void insert(Emp *p,char *ssn, char *name,char *dep,char *des,int age,int sal,int p_n,int code)
{
    Node *temp=create_node(name,ssn,dep,des,age,sal,p_n,code);
    if(p->head==NULL)
        p->head=temp;
    else
    {
        temp->next=p->head;
        p->head->prev=temp;
        p->head=temp;
    }
}
void del(Emp *p)
{
  Node *temp=p->head;
  while(temp!=NULL)
  {
    if(temp->age>58)
    {
      if(temp->prev==NULL)
      {
        temp=temp->next;
        p->head=temp;
        free(temp->prev);
        temp->prev=NULL;
      }
      else if(temp->next==NULL)
      {
        temp->prev->next=NULL;
        free(temp);
      }
      else{
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
      }
    }
    temp=temp->next;
  }
}
void display(Emp *p,char des[])
{
  printf("display\n");
  Node *temp=p->head;
  while(temp!=NULL)
  {
    printf("%s\n",temp->department.name);
    if(strcmp(temp->department.name,des)==0)
    {
      printf("\nSSN:%s\nName:%s\nDesignation:%s\nSalary:%d\nPhone Number:%d\nage:%d\n\n",temp->ssn,temp->name,temp->designations,temp->salary,temp->phone_number,temp->age );
    }
    temp=temp->next;
  }
}
