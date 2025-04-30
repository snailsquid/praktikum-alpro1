#include <stdio.h>

int main() {
    long jumlah;
    scanf("%d", &jumlah);
    long pisang = 0, jelly = 0;
    long berhenti = 0;
    for(long i = 0; i<jumlah; i++)
    {
        long _;
        scanf("%ld",&_);
        if((_==0 && berhenti == 0)||berhenti==1){
            berhenti = 1;
            continue;
        }
        if(_%2==0)
        {
            pisang += _;
        }else
        {
            jelly += _;
        }
    }
    printf("%ld %ld\n", pisang, jelly);
    
    
    return 0;
}
