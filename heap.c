#include<stdio.h>
#define MAX 20
void read(int arr[],int n)
{
  for(int i=0;i<n;i++)
  {
    printf("Enter the node value:");
    scanf("%d",&arr[i]);
  }
}
void display(int arr[],int n)
{
  for(int i=0;i<n;i++)
    printf("%d\t",arr[i]);
  printf("\n");
}
void heapify(int arr[],int n)
{
  int j;
  int k;
  int v;
  int heap;
  for(int i=(n-1)/2;i>=0;--i)
  {
    k=i;
    v=arr[k];
    j=2*k+1;
    heap=0;
    while(!heap && j<=n)
    {
      if((j+1)<=n)
      {
        if(arr[j]<arr[j+1])
          ++j;
      }
      if(v>=arr[j])
        heap=1;
      else
      {
        arr[k]=arr[j];
        k=j;
        j=2*k+1;
      }
    }
    arr[k]=v;
  }
}
int main()
{
  int arr[MAX];
  int n;
  printf("Enter no of elements in in the heap:");
  scanf("%d",&n);
  read(arr,n);
  display(arr,n);
  printf("\n");
  heapify(arr,n);
  printf("\n");
  display(arr,n);
  return 0;
}
