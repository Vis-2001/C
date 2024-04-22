typedef struct node{
    int val;
    int row,col;
    struct node *r;
    struct node *d;
}no;//node definition

typedef struct start{
    no *head;
}st;//multilist definition

void init(st *p);
no *nod(int val);
void read(int *a,int n,FILE *fp);
void create(st *p,int row,int col,int rs,int cs,FILE *fp);
int rowdel(no *p,int up,int col);
void del(st *p,int row,int col);
int check(no *p,int row,int col);
void path(st *p,int row,int col);
