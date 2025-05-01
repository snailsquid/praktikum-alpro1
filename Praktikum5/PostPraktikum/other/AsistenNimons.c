#include "AsistenNimons.h"
#include <stdio.h>

void MakeEmpty(ListNilaiNimons *L){
    ((*L).Neff) = 0;
}

int NbElmt(ListNilaiNimons L){
    return L.Neff;
}

int MaxNbEl(ListNilaiNimons L){
    return MAX_CAPACITY;
}

IdxType GetFirstIdx(ListNilaiNimons L){
    return 0;
}

IdxType GetLastIdx(ListNilaiNimons L){
    return L.Neff-1;
}

ElType GetElmt(ListNilaiNimons L, IdxType i){
    return L.daftar[i];
}

void SetTab(ListNilaiNimons Lin, ListNilaiNimons *Lout){
    (*Lout).Neff = Lin.Neff;
    for(int i = 0; i < Lin.Neff; i++){
        (*Lout).daftar[i] = Lin.daftar[i];
    }
}

void SetEl(ListNilaiNimons *L, IdxType i, ElType v){
    (*L).daftar[i] = v;
    if ((*L).Neff < i+1){
        (*L).Neff = i+1;
    }
}

void SetNeff(ListNilaiNimons *L, IdxType N){
    (*L).Neff = N;
}

boolean IsIdxValid(ListNilaiNimons L, IdxType i){
    return i >= GetFirstIdx(L) && i < MAX_CAPACITY;
}

boolean IsIdxEff(ListNilaiNimons L, IdxType i){
    return i >= GetFirstIdx(L) && i <= GetLastIdx(L);
}

boolean IsEmpty(ListNilaiNimons L){
    return L.Neff == 0;
}

boolean IsFull(ListNilaiNimons L){
    return L.Neff == MAX_CAPACITY;
}

void PrintIsi(ListNilaiNimons L){
    if(L.Neff == 0){
        printf("List kosong\n");
    }
    else{
        for (int i = 0; i < L.Neff; i++)
        {
            printf("%s - %d - %d\n", L.daftar[i].nama, L.daftar[i].praktikum, L.daftar[i].nilai);
        }
    }

}

ElType MakeNilai(char *nama, int prakke, int nilai) {
    ElType bebas;
    strcpy(bebas.nama, nama);
    bebas.praktikum = prakke;
    bebas.nilai = nilai;
    return bebas;
}

float AvgNilaiNama(ListNilaiNimons L, char *nama){
    int total = 0;
    int count = 0;
    float avg;
    for (int i = 0; i < L.Neff; i++)
    {
        if(strcmp(nama, L.daftar[i].nama) == 0){
            total += L.daftar[i].nilai;
            count++;
        }
    }
    if(count == 0){
        return 0;
    }
    else{
        avg = (float)total / count;
    }
    return avg;
}

int MaxNilaiNama(ListNilaiNimons L, char *nama){
    int maks = -1;
    for (int i = 0; i < L.Neff; i++)
    {
        if(strcmp(nama, L.daftar[i].nama) == 0){
            if(L.daftar[i].nilai > maks){
                maks = L.daftar[i].nilai;
            }
        }
    }
    return maks;
}

int MinNilaiNama(ListNilaiNimons L, char *nama){
    int min = 101;
    for (int i = 0; i < L.Neff; i++)
    {
        if(strcmp(nama, L.daftar[i].nama) == 0){
            if(L.daftar[i].nilai < min){
                min = L.daftar[i].nilai;
            }
        }
    }
    return min;
}

float AvgNilai(ListNilaiNimons L){
    int total = 0;
    int count = 0;
    float avg;
    if(L.Neff == 0){
        return 0;
    }
    else{
        for (int i = 0; i < L.Neff; i++)
        {
            total += L.daftar[i].nilai;
            count++;
        }
        
    }
    if(count == 0){
        return 0;
    }
    else{
        avg = (float)total / count;
    }

}

int MaxNilai(ListNilaiNimons L){
    int maks = -1;
    for (int i = 0; i < L.Neff; i++)
    {
        if(L.daftar[i].nilai > maks){
            maks = L.daftar[i].nilai;
        }
    }
    return maks;
}

int MinNilai(ListNilaiNimons L){
    int min = 101;
    for (int i = 0; i < L.Neff; i++)
    {
        if(L.daftar[i].nilai < min){
            min = L.daftar[i].nilai;
        }
    }
    return min;
}

int CountTotalPraktikum(ListNilaiNimons L){
    int count = 0;
    int list_temp[MAX_CAPACITY] = {0};
    for (int i = 0; i < L.Neff; i++)
    {
        if (list_temp[L.daftar[i].praktikum - 1] != 1)
        {
            list_temp[L.daftar[i].praktikum - 1]++;
        }
        
    }
    for (int i = 0; i < MAX_CAPACITY; i++)
    {
        if(list_temp[i] == 1){
            count++;
        }
    }
    return count;
}

void DisplayStatistic(ListNilaiNimons L){
    printf("Total praktikum: %d\n", CountTotalPraktikum(L));
    printf("Rata-rata: %.2f\n", AvgNilai(L));
    printf("Nilai maksimum: %d\n", MaxNilai(L));
    printf("Nilai minimum: %d\n", MinNilai(L));
}

void DisplayStatisticNimons(ListNilaiNimons L, char *nama) {
    printf("Nama: %s\n", nama);
    for (int i = 0; i < L.Neff; i++)
    {
        if (strcmp(nama, L.daftar[i].nama) == 0)
        {
            printf("Praktikum %d: %d\n", L.daftar[i].praktikum, L.daftar[i].nilai);
        }
        
    }
    printf("Rata-rata: %.2f\n", AvgNilaiNama(L, nama));
    printf("Nilai maksimum: %d\n", MaxNilaiNama(L, nama));
    printf("Nilai minimum: %d\n", MinNilaiNama(L, nama));
    printf("Nilai akhir: %c\n", KonversiNilai((int)AvgNilaiNama(L, nama)));
}

char KonversiNilai(int nilai) {
    if (nilai >= 80)
    {
        return 'A';
    } else if (nilai >= 65)
    {
        return 'B';
    } else if (nilai >= 50)
    {
        return 'C';
    } else if (nilai >= 35)
    {
        return 'D';
    } else if (nilai >= 0)
    {
        return 'E';
    } else {
        return 'I';
    }
    
}