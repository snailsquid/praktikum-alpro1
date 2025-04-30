#include <math.h>
#include <stdio.h>

double CF(double c)
{
  return c*9/5+32;
}
double CK(double c)
{
  return c+273.15;
}
double FC(double f)
{
  return (f-32)*5/9;
}
double FK(double f)
{
  return (f-32)*5/9+273.15;
}
double KC(double k)
{
  return k-273.15;
}
double KF(double k)
{
  return (k-273.15)*9/5+32;
}
int main()
{
  int loopTimes;
  int current;
  scanf("%d", &loopTimes);
  double result[loopTimes];

  for(int i = 0; i<loopTimes; i++)
  {
    double input;
    char init, res;
    double _;
    scanf("%lf %c %c",&input, &init, &res);
    if(init == 'C' && res == 'F')
      _ = floor(CF(input));
    else if(init == 'C' && res == 'K')
      _ = floor(CK(input));
    else if(init == 'F' && res == 'C')
      _ = floor(FC(input));
    else if(init == 'F' && res == 'K')
      _ = floor(FK(input));
    else if(init == 'K' && res == 'C')
      _ = floor(KC(input));
    else if(init == 'K' && res == 'F')
      _ = floor(KF(input));
    result[i] = _;
  }
  for(int i = 0; i<loopTimes; i++)
  {
    printf("%.2lf\n", result[i]);
  }
  return 0;
}

