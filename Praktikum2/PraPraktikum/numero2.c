#include <stdio.h>

int main()
{
  long unsigned N, T, X;
  scanf("%ld %ld %ld", &N, &T, &X);
  long unsigned result = N;
  long unsigned prev = 0;
  for(long unsigned i = 0; i<T; i++)
  {
    long unsigned _ = result;
    result += (result-prev)*X;
    prev = _;
  }
  printf("Terdapat %ld Virus Nimons Gila pada jam ke-%ld\n", result, T);
}
