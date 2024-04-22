#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
        char name[50];
        int phone_number;
        char address[500];
        char area[50];
        struct Node *next, *prev;
} Node;

typedef struct CustomerDetails
{
        Node *head;
} CustomerDetails;

void init(CustomerDetails *p);
void disp(CustomerDetails *p);
void ordered_insert(CustomerDetails *p,char *name, int p_no,char *address, char *area);
int main()
{
	CustomerDetails l;
	init(&l);
	int choice;
	printf("1: Enter details\n2: Display details\n");
	scanf("%d",&choice);
	char name[50];
	int p_no;
	char address[500];
	char area[50];

	while(choice)
	{
		switch(choice)
		{
			case 1:
			        printf("Enter the Name\n");
			        scanf("%s",name);
			        printf("Enter the Phone Number\n");
			        scanf("%d",  &(p_no));
			        printf("Enter the Address\n");
			        scanf("%s", address);
			        printf("Enter the Area\n");
			        scanf("%s", area);
				ordered_insert(&l,name, p_no,address,area);
				break;
			case 2:
				disp(&l);
				break;

			default:
			        printf("INVALID CHOICE!!! Retry!!!");
			        //exit(0);
		}
		printf("1: Enter details\n2: Display details\n");
		scanf("%d",&choice);
	}

	return 0;
}
void init(CustomerDetails *p)
{
	p->head=NULL;
}

void disp(CustomerDetails *p)
{
	Node *pres=p->head;
	if(p->head==NULL)
	{
		printf("Empty list\n");
	}
	else{
	printf("NAME\tPHONE NUMBER\t\tADDRESS\t\tAREA\n");
	while(pres!=NULL)
	{
		printf("%s \t%d \t%s  \t%s ",pres->name, pres->phone_number,pres->address,pres->area);
		printf("\n");
		pres=pres->next;
	}
	printf("\n");
	}

}
Node* create_node(char *name, int p_no,char *address,char *area)
{
	Node *temp=(Node*)malloc(sizeof(Node));
	strcpy(temp->name, name);
	temp->phone_number=p_no;
	strcpy(temp->address, address);
	strcpy(temp->area, area);
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}

void ordered_insert(CustomerDetails *p,char *name, int p_no,char *address, char *area)
{
    Node *temp=create_node(name,p_no,address,area);

    if(p->head==NULL) //when list is empty
        p->head=temp;

    else //list is not empty
    {
        Node *present=p->head;
        Node *previous=NULL;

        while(present!=NULL && strcmp(present->name, name)<0)
        {
            previous=present;
            present=present->next;
        }
        if(previous==NULL) //front insertion
        {
            p->head=temp;
            temp->next=present;
            present->prev = temp;
        }
        else //middle and end insertion
        {
            temp->next=present;
            present->prev=temp;
            previous->next=temp;
            temp->prev = previous;
        }
    }
}
