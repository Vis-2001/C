// #include<stdlib.h>
// #include<stdio.h>
// #include<string.h>
// typedef struct node{
//     char srn[15];
//     struct node *l;
//     struct node *r;
// }n;
// n *newNode(char sr[])
// {
//     n *temp=(n*)malloc(sizeof(n));
//     strcpy(temp->srn,sr);
//     temp->l=NULL;
//     temp->r=NULL;
// }
// n *insert(n *p,char sr[])
// {
//     if(p==NULL)
//     return newNode(sr);
//     if(strcmp(sr,p->srn)<0)
//     p->l=insert(p->l,sr);
//     else if(strcmp(sr,p->srn)>0)
//     p->r=insert(p->r,sr);
//     return p;
// }
// int pre(n *p)
// {
//     if(p==NULL)
//     return 1;
//     printf("%s\n",p->srn);
//     pre(p->l);
//     pre(p->r);
//     return 0;
// }
// int search(n *tree, char sr[])
// {
//     if(!(tree))
//     {
//         return 0;
//     }
//
//     if(strcmp(sr,tree->srn)<0)
//     {
//         search(((tree)->l), sr);
//     }
//     else if(strcmp(sr,tree->srn)>0)
//     {
//         search(((tree)->r), sr);
//     }
//     else if(strcmp(sr,tree->srn)==0)
//     {
//         return 1;
//     }
// }
// // void post(n *myNode) {
// //         if (myNode) {
// //
// //                 post(myNode->l);
// //                 post(myNode->r);
// //                 printf("%s\n", myNode->srn);
// //         }
// //         return;
// // }
// // void in(n *myNode) {
// //         if (myNode) {
// //
// //                 in(myNode->l);
// //                 printf("%s\n", myNode->srn);
// //                 in(myNode->r);
// //         }
// //         return;
// // }
// int main()
// {
//     int no;
//     scanf("%d",&no);
//     n *head;
//     head=NULL;
//     char s[15];
//     scanf("%s",s);
//     head=insert(head,s);
//     for(int i=1;i<no;i++){
//         scanf("%s",s);
//         insert(head,s);
//     }
//     printf("%s\n","Preorder" );
//     pre(head);
//     // printf("%s\n","Postorder" );
//     // post(head);
//     // printf("%s\n","Inorder" );
//     // in(head);
//     char str[15];
//     printf("%s\n","Enter the string to be searched");
//     scanf("%s",str);
//     int c=search(head,str);
//     if (c==1)
//     printf("%s\n","Found");
//     else
//     printf("%s\n","Not found");
//     return 0;
// }
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct node
{
    char srn[13];
    struct node*llink;
    struct node*rlink;

}node_t;

typedef struct tree
{
    node_t* root;
}tree_t;

void init(tree_t*pt)
{
    pt->root=NULL;

}

void create(tree_t*pt,int n)
{

    node_t*temp;
    node_t*pres;
    node_t*prev;
   printf("Enter root node: ");
    pt->root=(node_t*)malloc(sizeof(node_t));
    scanf("%s",(pt->root->srn));
    pt->root->llink=pt->root->rlink=NULL;

    do
    {
        printf("Enter node value: ");
        temp=(node_t*)malloc(sizeof(node_t));
        scanf("%s",(temp->srn));
        temp->llink=temp->rlink=NULL;
        prev=NULL;
        pres=pt->root;

        while(pres!=NULL)
        {
            prev=pres;
            if(strcmp(temp->srn,pres->srn)<0)
                pres=pres->llink;
            else
                pres=pres->rlink;
        }
        if(strcmp(temp->srn,prev->srn)<0)
            prev->llink=temp;
        else
            prev->rlink=temp;
         --n;
    } while(n>0);

}

void inorder_traversal(node_t*p)
{
    if(p!=NULL)
    {


        inorder_traversal(p->llink);
        printf("%s\n",p->srn);
        inorder_traversal(p->rlink);
    }
}


  int search(node_t*p,char* ele)
{
    int found=0;
    if(p!=NULL)
    {


        search(p->llink,ele);
        if(strcmp(p->srn,ele)==0)
        {

            found=1;
            return(found);
        }
        search(p->rlink,ele);
    }
    return(found);

}

int main()
{
    tree_t t;
    init(&t);
    printf("Enter number of nodes: ");
    int len;
    scanf("%d",&len);
    create(&t,len-1);
    inorder_traversal(t.root);
    printf("\n Enter srn to search for: ");
    char ele[13];
    scanf("%s",ele);
    int res=search(t.root,ele);
    if(res==1)
        printf("\n %s is found \t",ele);
    else
        printf("\n Node not found");

   return 0;

}
