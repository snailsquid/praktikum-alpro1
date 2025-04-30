// Online C compiler to run C program online
#include <stdio.h>

int main() {
    long N;
    scanf("%ld", &N);
    long count = 10;
    long current = N;
    long final = 0;
        while(current/10>0){
            int sisa = current%10;
            current -=sisa;
            // printf("%ld %ld\n",current, sisa);

            current /=10;
            final*=10;
            final+=sisa;
        }
        final*=10;
        final+=current;
    if(final==N){
        printf("%d\n", 1);
    }else
    {printf("%d\n",0);}
    
    return 0;
}