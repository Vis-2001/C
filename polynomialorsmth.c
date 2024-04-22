#include<stdio.h>
#include<stdlib.h>
struct poly
{
    int coeff;
    int px;
    int py;
    struct poly *next;
};
typedef struct poly POLY;
struct list
{
    POLY *head;
};
typedef struct list LL;
void init(LL*);
void accept(LL*);
POLY* res(LL*,LL*,LL*);
void display(LL*);
int main()
{
    LL q1,q2,q;
    init(&q1);
    init(&q2);
    init(&q);
    printf("Enter the first polynomial:\n");
    accept(&q1);
    printf("---------------------------\n");
    printf("Enter the second polynomial:\n");
    accept(&q2);
    q.head=res(&q1,&q2,&q);
    display(&q);
    return 0;
}
void init(LL *q)
{
    q->head=NULL;
}
void accept(LL *q)
{
    POLY *temp;
    char c;
    do
    {
        temp=(POLY *)malloc(sizeof(POLY));
        printf("Enter the coefficient:\n");
        scanf("%d",&(temp->coeff));
        printf("Enter the power of x:\n");
        scanf("%d",&(temp->px));
        printf("Enter the power of y:\n");
        scanf("%d",&(temp->py));
        temp->next=q->head;
        q->head=temp;
        fflush(stdin);
        printf("Do you want to enter more values\n");
        printf("Enter Y for yes N for No:\n");
        c=getchar();
        fflush(stdin);
    }
    while(c=='Y');
}
POLY* res(LL *q1,LL *q2,LL *q)
{
    POLY *p1=q1->head;
    POLY *p2=q2->head;
    POLY *p3=q->head;
    POLY *t=(POLY *)malloc(sizeof(POLY));
    while(p1!=NULL && p2!=NULL)
    {
        if((p1->px == p2->px) && (p1->py == p2->py))
        {
            t->coeff=(p1->coeff)+(p2->coeff);
            t->px=p1->px;
            t->py=p1->py;
            t->next=p3;
            p3=t;
            p1=p1->next;
            p2=p2->next;
        }
        else if((p1->px + p1->py)<=(p2->px + p2->py))
        {
            t->coeff=(p1->coeff);
            t->px=p1->px;
            t->py=p1->py;
            t->next=p3;
            p3=t;
            p1=p1->next;
        }
        else if((p1->px + p1->py)>(p2->px + p2->py))
        {
            t->coeff=(p2->coeff);
            t->px=p2->px;
            t->py=p2->py;
            t->next=p3;
            p3=t;
            p2=p2->next;
        }
        t=(POLY *)malloc(sizeof(POLY));
    }
    while(p1!=NULL)
    {
        t->coeff=(p1->coeff);
        t->px=p1->px;
        t->py=p1->py;
        t->next=p3;
        p3=t;
        p1=p1->next;
        t=(POLY *)malloc(sizeof(POLY));
    }
    while(p2!=NULL)
    {
        t->coeff=(p2->coeff);
        t->px=p2->px;
        t->py=p2->py;
        t->next=p3;
        p3=t;
        p2=p2->next;
        t=(POLY *)malloc(sizeof(POLY));
    }
    return p3;
}
void display(LL *q)
{
    POLY *p=q->head;
    while(p!=NULL)
    {
        if(p->next==NULL)
            printf("%dx(%d)y(%d)",p->coeff,p->px,p->py);
        else
            printf("%dx(%d)y(%d) +",p->coeff,p->px,p->py);
        p=p->next;
    }
}