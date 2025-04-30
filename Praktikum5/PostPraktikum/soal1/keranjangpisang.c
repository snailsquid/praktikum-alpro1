/* MODUL KERANJANG PISANG - LIST STATIK TANPA SORTING/SEARCHING/ARITMATIKA */
/* Berisi definisi dan semua primitif pemrosesan list statik integer dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit dengan nilai MARK */

#include "Boolean.h"
#include "keranjangpisang.h"
#include <stdio.h>
/* Indeks yang digunakan [0..CAPACITY-1] */

/* ********** KONSTRUKTOR ********** */
void CreateKeranjang(KeranjangPisang *k)
{
    for(int i = 0; i<CAPACITY; i++)
    {
        k->contents[i] = MARK;
    }
}
/* I.S. k sembarang */
/* F.S. Terbentuk keranjang kosong dengan semua elemen bernilai MARK */

/* ********** SELEKTOR TAMBAHAN ********** */
int lengthKeranjang(KeranjangPisang k)
{
    int count = 0;
    for(int i = IDX_MIN; i<CAPACITY; i++)
    {
        
        if(k.contents[i]!=MARK)
        {
            count+=1;
        } else
        {
            break;
        }
    }
    return count;
}
/* Mengirimkan banyaknya elemen efektif keranjang */

IdxType getFirstIdx(KeranjangPisang k)
{
    if(isEmpty(k)) 
    {
        return IDX_UNDEF;
    }
    return IDX_MIN;
}
/* Prekondisi : k tidak kosong */
/* Mengirimkan indeks elemen pertama */

IdxType getLastIdx(KeranjangPisang k)
{
    if(isEmpty(k))
        return IDX_UNDEF;
    return lengthKeranjang(k)-1;
}
/* Prekondisi : k tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* ********** TEST INDEKS ********** */
boolean isIdxValid(KeranjangPisang k, IdxType i)
{
    if(i<0 || i>CAPACITY-1)
        return FALSE;
    return TRUE;
}
/* Mengirimkan true jika i adalah indeks valid untuk container */

boolean isIdxEff(KeranjangPisang k, IdxType i)
{
    int length = lengthKeranjang(k);
    int max = length - 1;
    if(i>max || i<0)
        return FALSE;
    return TRUE;
}
/* Mengirimkan true jika i adalah indeks efektif dalam keranjang */

/* ********** TEST KOSONG / PENUH ********** */
boolean isEmpty(KeranjangPisang k){
    if(lengthKeranjang(k)==0) 
    {
        return TRUE;
        }
    return FALSE;
}
/* Mengirimkan true jika keranjang kosong */

boolean isFull(KeranjangPisang k)
{
    if(lengthKeranjang(k) == CAPACITY)
        return TRUE;
    return FALSE;
}
/* Mengirimkan true jika keranjang penuh */

/* ********** BACA / TULIS ********** */
void readKeranjang(KeranjangPisang *k)
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i<n; i++)
    {
        int _;
        scanf("%d", &_);
        k->contents[i] = _;
    }
}
/* I.S. Sembarang */
/* F.S. Keranjang berisi n elemen hasil input (0 <= n <= CAPACITY) */
/* Format input: n diikuti n buah elemen */
/* Contoh: 3 10 20 30*/
/* n = 3 dengan elemen keranjang adalah 10,20,dan 30*/

void printKeranjang(KeranjangPisang k)
{
    int length = lengthKeranjang(k);
    printf("[");
    for(int i = 0; i<length-1;i++)
    {
        printf("%d,",k.contents[i]);
    }    
    if(length!=0)
    printf("%d",k.contents[length-1]);

    printf("]\n");

}
/* Menampilkan isi keranjang dalam format [x1,x2,...,xn] */
/* Contoh : */
/* [10,20,30] */
/* Jika kosong : []*/

/* ********** OPERASI PENAMBAHAN ELEMEN ********** */
void insertFirst(KeranjangPisang *k, ElType val)
{
    int length = lengthKeranjang(*k);
    int lastIdx = getLastIdx(*k);
    for(int i = lastIdx; i>=getFirstIdx(*k) ; i--)
    {
        k->contents[i+1] = k->contents[i];
    }
    k->contents[getFirstIdx(*k)] = val;
}
/* Menambahkan val sebagai elemen pertama */

void insertAt(KeranjangPisang *k, ElType val, IdxType idx)
{
    int length = lengthKeranjang(*k);
    int lastIdx = getLastIdx(*k);
    for(int i = lastIdx; i>=idx ; i--)
    {
        k->contents[i+1] = k->contents[i];
    }
    k->contents[idx] = val;
}
/* Menambahkan val di indeks tertentu */

void insertLast(KeranjangPisang *k, ElType val)
{
    int length = lengthKeranjang(*k);
    int lastIdx = getLastIdx(*k);
    k->contents[lastIdx+1] = val;
}
/* Menambahkan val sebagai elemen terakhir */

/* ********** OPERASI PENGHAPUSAN ELEMEN ********** */
void deleteFirst(KeranjangPisang *k, ElType *val)
{
    int length = lengthKeranjang(*k);
    int lastIdx = getLastIdx(*k);
    int firstIdx = getFirstIdx(*k);
    *val = k->contents[firstIdx];
    for(int i = firstIdx+1; i<=lastIdx ; i++)
    {
        // printf("replacing : %d with %d", k->contents[i-1], k->contents[i]);
        k->contents[i-1] = k->contents[i];
    }
    k->contents[lastIdx] = MARK;
}
/* Menghapus elemen pertama */

void deleteAt(KeranjangPisang *k, ElType *val, IdxType idx)
{
    int length = lengthKeranjang(*k);
    int lastIdx = getLastIdx(*k);
    *val = k->contents[idx];
    for(int i = idx+1; i<=lastIdx ; i++)
    {
        k->contents[i-1] = k->contents[i];
    }
    k->contents[lastIdx] = MARK;
}
/* Menghapus elemen di indeks tertentu */

void deleteLast(KeranjangPisang *k, ElType *val)
{
    int length = lengthKeranjang(*k);
    int lastIdx = getLastIdx(*k);
    *val = k->contents[lastIdx];
    k->contents[lastIdx] = MARK;
}
/* Menghapus elemen terakhir */

// int main()
// {
//     KeranjangPisang k;
//     CreateKeranjang(&k);
//     readKeranjang(&k);
//     // printf("%d %d\n",getFirstIdx(k), getLastIdx(k));
//     // if(isFull(k))
//     //     printf("its full\n");
//     // if(isEmpty(k)==1)
//     //     printf("its empty\n");
    
//     // int n;
//     // scanf("%d", &n);
//     // if(isIdxEff(k,n))
//     //     printf("%d is effective\n", n);
//     // if(isIdxValid(k, n))
//     // {
//     //     printf("%d is valid\n", n);
//     // }
//     printKeranjang(k);
//     int n, m;
//     scanf("%d %d", &n, &m);
//     deleteLast(&k, &n);
//     printKeranjang(k);
// }
