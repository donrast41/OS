#include<stdio.h>
#include<stdlib.h>
void bubble_sort(int array[],int size);
void main()
{
  int array[100],n,i;
  printf("\n Enter the size of the array ");
  scanf("%d",&n);
  if(n>100)
  {
    printf("\n error");
    exit(0);
  }

 printf("\n Enter the array elements: \n");

 for(i=0;i<n;i++)
  scanf("%d",&array[i]);
  bubble_sort(array,n);
  printf("\n The sorted array is\n");
  for(i=0;i<n;i++)
  printf("%d\t",array[i]);
}
void bubble_sort(int array[],int size)
{
  int temp,i,j;
  for(i=0;i<size;i++)
  {
   for(j=0;j<size-1;j++)
   {
    if(array[j]>array[j+1])
    {
     temp=array[j];
     array[j]=array[j+1];
     array[j+1]=temp;
    }
  }
 }
}
