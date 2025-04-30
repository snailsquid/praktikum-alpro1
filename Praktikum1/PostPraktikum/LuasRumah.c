#include <stdio.h>

int main()
{
	int awal;
	int tahun;
	scanf("%d",&awal);
	scanf("%d",&tahun);

	int sekarang=awal;
	for(int i = 1; i<=tahun; i++)
	{
		sekarang=sekarang+9;
		printf("tahun ke-%d = %d\n",i,sekarang);
	}

	return 0;
}

