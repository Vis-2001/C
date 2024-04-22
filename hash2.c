#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
typedef struct {
  long int *table;
  int size;
} HashTable;
HashTable *init()
{
  HashTable *temp = malloc(sizeof(HashTable));
  temp->table = calloc(SIZE, sizeof(int));
  for (int i = 0; i < SIZE; ++i) {
  temp->table[i] = -1;
  }
  temp->size = SIZE;
  return temp;
}
void destroy_table(HashTable *htable)
{
  htable->size = 0;
  free(htable->table);
}
void insert(HashTable *htable,long int phno)
{
  int hash = phno % htable->size;
  int count = 0;
  while (count < htable->size)
  {
    if (htable->table[hash] == -1)
    {
      htable->table[hash] = phno;
      break;
    }
    ++hash;
    ++count;
    if (hash == htable->size)
    {
      hash = 0;
    }
  }
}
int search(HashTable *htable, long int phno)
{
  int hash = phno % htable->size;
  int count = 0;
  while (count < htable->size)
  {
    if (htable->table[hash] == phno)
    {
      return 1;
    }
    ++hash;
    ++count;
  }
  return 0;
}
void delete (HashTable *htable, long int phno)
{
  int hash = phno % htable->size;
  int count = 0;
  while (count < htable->size)
  {
    if (htable->table[hash] == phno)
    {
      htable->table[hash] = -1;
      printf("%s\n","Number deleted" );
      return;
    }
    ++hash;
    ++count;
  }
  printf("%s\n","Number not found" );
}
int main()
{
  HashTable *p=init();
  int ch;
  long int num;
  while(1)
  {
    printf("Enter 1 for inserting numbers\n2 for deleting a particular number\n3 for searching a phone number in the hash table\n4 for deleting the hash table\n5 for exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
      printf("%s\n","Enter phone number to be inserted");
      scanf("%ld",&num);
      insert(p,num);
      break;
      case 2:
      printf("%s\n","Enter phone number to be deleted");
      scanf("%ld",&num);
      delete(p,num);
      break;
      case 3:
      printf("%s\n","Enter phone number to be searched");
      scanf("%ld",&num);
      int j=search(p,num);
      if(j==1)
      printf("%s\n","Number found");
      else
      printf("%s\n","Number not found");
      break;
      case 4:
      destroy_table(p);
      default:
      exit(0);
    }
  }
}
