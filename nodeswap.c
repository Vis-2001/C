#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
struct llist
{
    NODE *head;
};
typedef struct llist LL;
void init(LL*);
void insert(LL*);
void swap(LL*,int,int);
void display(LL*);
int main()
{
    LL q;
    init(&q);
    insert(&q);
    printf("List before swaping\n");
    display(&q);
    int a,b;
    printf("Enter the data values you want to be swapped\n");
    scanf("%d %d",&a,&b);
    swap(&q,a,b);
    printf("List after swapping\n");
    display(&q);

}
void init(LL *q)
{
    q->head=NULL;
}
void insert(LL *q)
{
    NODE *temp;
    int wish=1;
    do
    {
        temp=(NODE *)malloc(sizeof(NODE));
        printf("Enter data\n");
        scanf("%d",&(temp->data));
        temp->next=q->head;
        q->head=temp;
        printf("Do you want to enter more values\n");
        printf("Enter 1 for YES 0 for No\n");
        scanf("%d",&wish);
    }
    while(wish);
}
void swap(LL *q,int a,int b)
{
    NODE *prev1=NULL;
    NODE *prev2=NULL;
    NODE *prev=NULL;
    NODE *p=q->head;
    NODE *t;
    NODE *pres1;
    NODE *pres2;
    while(p!=NULL)
    {
        if(p->data==a)
            prev1=prev;
        if(p->data==b)
            prev2=prev;
        prev=p;
        p=p->next;
    }

    if(prev1==NULL && q->head->data==a)
    {
        prev1=q->head;
        pres1=prev1->next;
        pres2=prev2->next;
        t=pres2->next;
        q->head=pres2;
        pres2->next=pres1;
        prev2->next=prev1;
        prev1->next=t;
    }        
    else if(prev2==NULL && q->head->data==b)
    {
        prev2=q->head;
        pres2=prev2->next;
        pres1=prev1->next;
        t=pres1->next;
        q->head=pres1;
        pres1->next=pres2;
        prev1->next=prev2;
        prev2->next=t;
    }
    else if(prev2!=NULL && prev1!=NULL)
    {
        pres1=prev1->next;
        pres2=prev2->next;
        t=pres2->next;
        prev1->next=pres2;
        pres2->next=pres1->next;
        prev2->next=pres1;
        pres1->next=t;                                                    
    }
    else
    {
        printf("Entered value doesnt exist ");
        exit(0);
    }

}
void display(LL *q)
{
    NODE *p=q->head;
    if(p==NULL)
    {
        printf("Empty list\n");
    }
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}