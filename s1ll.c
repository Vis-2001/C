#include <stdlib.h>
#include <stdio.h>
typedef struct node{
  int key;
  struct node *next;
}node_t;
node_t *head=NULL;
node_t *head1=NULL;
// void order(node_t *a,int key);
// void ins_end(int key);
void display(node_t *a);
int main() {
  // order(head,5);
  // printf("main\n" );
  // order(head,6);
  // order(head,7);
  // display(head);
  // order(head1,0);
  // order(head1,-1);
  // order(head1,-2);
  // ins_end(5);
  display(head);
  return 0;
}
void display(node_t *a)
{
  node_t *temp=a;
  if(temp==NULL)
  printf("Empty list\n");
  else{
  do
  {
    printf("%d,",temp->key);
    temp=temp->next;
  }while(temp->next!=NULL);
  printf("%d\n",temp->key);
}
}
