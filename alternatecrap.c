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
void rem(LL*);
void display(LL*);
int main()
{
    LL q;
    init(&q);
    insert(&q);
    printf("List before deleting\n");
    display(&q);
    rem(&q);
    printf("List after deleting\n");
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
void rem(LL *q)
{
    int i=0;
    NODE *p=q->head;
    while(p!=NULL)
    {
        i++;
        p=p->next;
    }
    p=q->head;
    //printf("i value %d",i);
    NODE *f=p;
    NODE *prev=p->next;
    p=p->next->next;
    NODE *t=prev;
    printf("Deleted %d\n",f->data);
    free(f);
    if(p==NULL || p->next==NULL)
    {
        printf("Can't delete not sufficient data present\n");
        exit(1);
    }
    int count=0;
    while(p!=NULL)
    {
        if(count%2==0)
        {
            //printf("Hello");
            f=p;
            prev->next=p->next;
            prev=prev->next;
        }
        //printf("%d\n",p->data);
        p=p->next;
        if(count%2==0)
        {   
            printf("Deleted %d\n",f->data);
            free(f);
        }
        if(i%2==0 && prev->next==NULL)
        {   
            break;
        }
        if(i%2!=0 && count==i-2)
            prev->next=NULL;
        count++;
    }
    q->head=t;

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