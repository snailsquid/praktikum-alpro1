#include <stdio.h>

void ShiftArray(int *arr, int size, int shift)
{
  for(int j = 0; j<shift; j++)
  {
    int last = arr[size-1];
    for(int i = 0; i<size; i++)
    {
      int _ = arr[i];
      arr[i] = last;

      last = _;
    }
  }
}

void ResetArray(int *arr1, int *arr2, int size)
{
  for(int i = 0; i<size; i++)
  {
    arr2[i] = arr1[i];
  }
}

void PrintArray(int *arr, int size)
{
  printf("[");
  for(int i = 0; i<size; i++)
  {
    printf("%d", arr[i]);
  }
  printf("]\n");
}

int main(void)
{
  int elements, rotations;
  scanf("%d %d", &elements, &rotations);
  int initial[elements],steps[rotations];
  for (int i =0; i<elements; i++)
  {
    int _;
    scanf("%d", &_);
    initial[i] = _;
  }
  for (int i = 0; i<rotations; i++)
  {
    int _;
    scanf("%d", &_);
    steps[i] = _;
  }
  int working[elements];
  for(int i = 0; i<rotations; i++)
  {
    ResetArray(initial, working, elements);
    ShiftArray(working, elements, steps[i]);
    PrintArray(working, elements);
  }
  return 0;
}
