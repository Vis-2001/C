#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef struct stack
{
    int a[MAX];
    int beg;
    int end;
} s;

void init(s *p)
{
    p->beg=MAX;
    p->end=0;
}

void push(s *p, int key, int code)
{
    if((p->end)>=(p->beg))
    {
        printf("Array is full. Insertion to either stack is not possible.\n");
    }
    else
    {
        if(code==1)
        {
            p->end++;
            p->a[p->end]=key;
        }
        else if(code==2)
        {
            p->beg--;
            p->a[p->beg]=key;
        }
        else
        {
            printf("Invalid type");
        }
    }
}

int pop(s *p, int code)
{
    int ele;
    if(code==1)
    {
        if(p->end==-1)
        {
            printf("This stack is empty\n");
            return -1;
        }
        else
        {
            p->end--;
            ele=p->a[p->end];
        }
    }
    else if(code==2)
    {
        if(p->beg==MAX)
        {
            printf("This stack is empty\n");
            return -1;
        }
        else
        {
            ele=p->a[p->beg];
            p->beg++;
        }
    }
    else
    {
        printf("Invalid type");
        return -1;
    }
    return ele;
}

int main()
{
    s s;
    init(&s);
    int choice,key;
    printf("Enter the number of your choice:\n1. Add to Container 1\n2.  Add to Container 2\n3. Remove from Container 1\n4. Remove from Container 2\nOr 0 to exit:\n");
    scanf("%d", &choice);
    while(choice)
    {
        switch(choice)
        {
            case 1:
                    printf("Enter the element to push:\n");
                    scanf("%d", &key);
                    push(&s, key,1);
                    break;
            case 2:
                    printf("Enter the element to push:\n");
                    scanf("%d", &key);
                    push(&s, key, 2);
                    break;
            case 3:
                    key=pop(&s,1);
                    if(key!=-1)
                        printf("Element is: %d\n", key);
                    break;
             case 4:
                    key=pop(&s,2);
                    if(key!=-1)
                        printf("Element is: %d\n", key);
                    break;
            default:
                    printf("Invalid choice\n");
                    break;

        }
        printf("Enter the number of your choice:\n1. Push to Stack 1\n2. Push to stack 2\n3. Pop from stack 1\n4. Pop from stack 2\nOr 0 to exit:\n");
        scanf("%d", &choice);
    }
    return 0;
}
