// Online C compiler to run C program online
#include <stdio.h>

int toBinary(int input)
{
    int current = input;
    int binary =  0;
    while(current/2>0){
        binary = binary*10 + current%2;
        current = current/2;
        
    }
    binary = binary*10 + current%2;
    current = current/2;
    return binary;
}

int countUp(int count)
{
    int total = 0;
    while(count/10!=0)
    {
        int sisa = count%10;
        total = total+sisa;
        
        count = count/10;
    }
    int sisa = count%10;
        total = total+sisa;
    //printf("count up : %d\n", total);
    return total;
}

int isThisPrime(int input)
{
    int isPrime = 1;
        if(input==1)
        {
            isPrime = 0;
        }
        else{
            for (int divider = 2;divider*divider<=input;divider++){
            if(input%divider==0 )
            {
                isPrime = 0;
                break;
            }
        }
        }
        
        return isPrime;
}

void countPrime(int A, int B, int *total)
{
    for(int i = A; i<=B; i++)
    {
        
        int isPrime = 1;
        if(i==1)
        {
            isPrime = 0;
            continue;
        }
        for (int divider = 2;divider*divider<=i;divider++){
            if(i%divider==0 )
            {
                isPrime = 0;
                
                break;
            }
        }
        if(isPrime == 1)
        {
            //printf("this is prime : %d\n",i);
            if(isThisPrime(countUp(i)))
            {
                *total +=1;
            }
        }
    }
    // TODO: Implementasi prosedur untuk menghitung jumlah bilangan prima dalam rentang [A, B]
    // Saat ini, total tidak bisa diperbarui karena hanya merupakan salinan dari nilai di main()
}

int main()
{
    int A, B, total=0;
    scanf("%d %d", &A, &B);
    // TODO: Baca dua bilangan integer A dan B dalam satu baris
    // Input harus dalam format: "A B"

    // TODO: Perbaiki pemanggilan prosedur dengan menggunakan alamat variabel total
    // Agar perubahan nilai di dalam prosedur juga mempengaruhi nilai di main()
    countPrime(A, B, &total);
    int final = toBinary(total);
    printf("%d\n", final);

    return 0;
}