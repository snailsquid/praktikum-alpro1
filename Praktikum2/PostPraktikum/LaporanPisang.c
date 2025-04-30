#include <stdio.h>

int main()
{
  int keranjang;
  scanf("%d", &keranjang);
  int count = 0;
  long m1 = 0, m2 = 0, m3 = 0;
  while(count<keranjang)
  {
    int input;
    scanf("%d", &input);
    if(input==1)
    {
      long input2;
      scanf("%d", &input2);
      if(input2<0)
      {
        printf("Input salah. Masukkan kembali input yang benar.\n");
        continue;
      }
      if(input2>=0 && input2<=2)
      {
        m1+=1;
        printf("Kategori: Mentah\n");
      }
      else if(input2>=3 && input2<=5)
      {
        m2+=1;
        printf("Kategori: Matang\n");
      }
      else if(input2>5)
      {
        m3+=1;
        printf("Kategori: Terlalu matang\n");
      }
      count+=1;
    }
    else if(input==2)
    {
      printf("Laporan Kematangan Pisang\n");
        printf("Mentah: %d\n", m1);
        printf("Matang: %d\n", m2);
        printf("Terlalu matang: %d\n", m3);
    }
    else {
      printf("Input salah. Masukkan kembali input yang benar.\n");
    }
  }
  printf("Program selesai\n");
  return 0;
}
