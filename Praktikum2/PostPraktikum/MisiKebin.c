#include <stdio.h>
long double rata(double total, double jumlah)
{
  return total/jumlah;
}
int main()
{
  double total = 0;
  for(int i = 0; i<5; i++)
  {
    double a;
    scanf("%lf",&a);
    total+=a;
  }
  printf("%:0lf\n", total);
  long double pesta = rata(total,5);
  printf("%lf\n",pesta);
  if(pesta>=10)
  {
    printf("Pesta Nimons Sukses!");
  }
  else{

    printf("Pesta Nimons Gagal!");
  }
  return 0;
}
