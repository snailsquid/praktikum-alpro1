#include <stdio.h>
int main(void)
{
  int input;
  int current;
  int count, result;
  scanf("%d", &input);
  result = 0;
  count = 1;
  while(count<=input)
  {
    current = count;
    while(current%5 == 0)
    {
      result++;
      current = current/5;
    }
    count++;
  }
  printf("%d\n", result);
  return 0;
}
