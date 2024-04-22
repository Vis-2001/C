#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PES1UG20CS507_H.h"
int main()
{
  st head;
  init(&head);
  FILE *fp=fopen("input.txt","r");
  int r[2];
  int c[2];
  read(r,2,fp);
  read(c,2,fp);
  create(&head,c[0]-r[0]+1,c[1]-r[1]+1,r[0],r[1],fp);
  del(&head,c[0]-r[0],c[1]-r[1]);
  path(&head,c[0]-r[0],c[1]-r[1]);
  return 0;
}
