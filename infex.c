#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct mat{
  int a[MAX];
  int top;
}m;
void init(m *s)
{
  s->top=-1;
}
void empty(m **s)
{
  return *(s->top)==-1;
}
void full(m **s)
{
  return *(s->top)==(MAX-1);
}
void push(m *s, int no)
{
  if(full(&s))
  {
    printf("%s\n","Stack overflowing" );
    return;
  }
  s->top=s->top+1;
  s->a[s->top]=no;
}
void pop(m *s)
{
  if(empty(&s))
  {
    printf("%s\n","If u pop it will erect" );
    return;
  }
  s->top--;
}
void pep(m *s)
{
  printf("%d\n",s->a[s->top]);
}
void main()
{
  
  return 0;
}
