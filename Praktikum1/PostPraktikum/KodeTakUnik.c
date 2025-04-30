// Online C compiler to run C program online
#include <stdio.h>

int main() {
    long N;
    scanf("%ld", &N);
    long count = 10;
    long current = N;
    long sum = 0;
    while(1)
    {
        while(current/10>0){
            int sisa = current%10;
            current -=sisa;
            // printf("%ld %ld\n",current, sisa);

            current /=10;
            sum+=sisa;
        }
        sum += current;
        if(sum/10<=0){
            break;
        }
        current = sum;
        sum=0;
    }
    
    printf("%ld\n",sum);
    return 0;
}