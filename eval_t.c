#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct NODE {
	char info;
	struct NODE* lnode;
	struct NODE* rnode;
}node;

typedef struct TREE {
	node* root;
}tree;

typedef struct STACK {
	node* s[MAX];
	int top;
}stack;

void init(tree* t) {
	t->root = NULL;
}

void init_s(stack* ps) {
	ps->top = -1;
}

node* create_node(char info) {
	node* temp = (node*)malloc(sizeof(node));
	temp->info = info;
	temp->lnode = NULL;
	temp->rnode = NULL;

	return temp;
}

int isOp(char ch) {
	if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
		return 1;

	return 0;
}

void push(stack *ps,node *ele) {
	if(ps->top == MAX-1)
		printf("Stack is full\n");
	else
		ps->s[++(ps->top)]=ele;
}

node* pop(stack *ps) {
	if(ps->top == -1)
		return 0;
	else {
		node *t=ps->s[ps->top--];
		return t;
	}
}

void display(node* pres) {
	if(pres != NULL) {
		display(pres->lnode);
		printf("%c ",pres->info);
		display(pres->rnode);
	}
}


float eval_expr(node *r) {
	float res;
	switch(r->info) {
		case '+':
		        res=eval_expr(r->lnode)+eval_expr(r->rnode);
			break;
		case '-':
		        res=eval_expr(r->lnode)-eval_expr(r->rnode);
			break;
		case '*':
		        res=eval_expr(r->lnode)*eval_expr(r->rnode);
			break;
		case '/':
		        res=eval_expr(r->lnode)/eval_expr(r->rnode);
			break;
		default:
		        return r->info - '0';
	}

	return res;
}

int main()
{
	node *temp;
	tree t;
	init(&t);
	stack s;
	init_s(&s);
	char postfix[MAX];
	printf("Enter the postfix expr\n");
	scanf("%s",postfix);
	int i=0;
	while(postfix[i]!='\0') {
		temp = create_node(postfix[i]);
		if(!isOp(postfix[i])) {
			push(&s,temp);
		}
		else {
			temp->rnode = pop(&s);
			temp->lnode = pop(&s);
			push(&s,temp);
		}
		++i;
	}
	t.root=pop(&s);
	display(t.root);
	printf("\nres=%f\n",eval_expr(t.root));
	return 0;
}
