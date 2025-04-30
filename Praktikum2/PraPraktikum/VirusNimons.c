#include <stdio.h>

int main()
{
  int N, T, X;
  scanf("%d %d %d", &N, &T, &X);
  int result = N;
  int prev = 0;
  for(int i = 0; i<T; i++)
  {
    int _ = result;
    result += (result-prev)*X;
    prev = _;
  }
  printf("Terdapat %d Virus Nimons Gila pada jam ke-%d\n", result, T);
}
