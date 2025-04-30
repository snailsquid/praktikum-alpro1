#include <stdio.h>
int FindTargetIndex(int target, int a[], int size)
{
  int hasil =0;
  for(int i=0; i<size; i++)
  {
    if(a[i] == target)
    {
      hasil = 1;
    }
  }
  return hasil;
}
int main(void)
{
  int total, target;
  scanf("%d %d", &total, &target);
  int arr[total];
  for(int i=0; i<total; i++)
  {
    int input;
    scanf("%d", &input);
    
    arr[total-i-1] = input;
  }
  int targetIndex = FindTargetIndex(target, arr, total);
  if(targetIndex==0)
  {
    arr[targetIndex] = arr[targetIndex+1];
  }
  else if (targetIndex==total-1){
    arr[targetIndex] = arr[0];
  }else{
    arr[targetIndex] = arr[targetIndex+1] + arr[targetIndex-1];
  }
  
  int arr2[total];
  for(int i = targetIndex; i<total; i++)
  {
    arr2[i]=arr[total-i];
  }
  for(int i = targetIndex; i<total; i++)
  {
    arr[i]=arr2[i];
  }
  for(int i=0; i<total;i++)
  {
    printf("%d", arr[i]);
  }
  printf("\n");

  return 0;
}
