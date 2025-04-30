#include <stdio.h>

void CreateArray(int arr[], int size)
{
//    printf("%d\n", size);
  for(int i = 0; i<size; i++)
  {
    arr[i] = i+1;
  }
}
void PrintArray(int arr[], int size)
{
  //printf("[");
  for(int i = 0; i<size; i++)
  {
  //  printf("%d", arr[i]);
  }
 // printf("]\n");
}
int GetRealIndex(long prev , long hop, int size, int a[])
{
  long current = prev, count = 0;
  int result;
  int i = prev;
  while(count<hop)
  {
    if(i>size-1)
    {
      i = i-size;
    }
    if(a[i]!=0)
    {
      count++;
   //   printf("%d %d\n",a[i],  count);
    }
    i++;
  }
  result = i-1;
//  printf("result %d\n", result);

  return result;
}

int FindLast(int a[], int size)
{
  for (int i =0; i<size; i++)
  {
    if(a[i]!=0)
    {
      printf("%d\n", a[i]);
    }
  }
}

int main(void)
{
  int n,i;
  long k;
  scanf("%d %d %ld", &n, &i, &k);
  int countN = n;

  int arr[n];
  CreateArray(arr, n);
  int currentValue;
  int prevI = i;
  while(countN>1)
  {
    int currentIndex = GetRealIndex(prevI,k,n,arr);
    currentValue = arr[currentIndex];
    arr[currentIndex] = 0;
    PrintArray(arr, n);
    countN-=1;
    prevI = currentIndex;
  }
  FindLast(arr, n);
  return 0;
}
