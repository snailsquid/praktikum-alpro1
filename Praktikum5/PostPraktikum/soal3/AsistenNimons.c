
#include "Boolean.h"
#include <stdio.h>
#include <string.h>
#include "AsistenNimons.h"

/* Indeks yang digunakan [0..MAX_CAPACITY-1]
 * Jika L adalah ListNilaiNimons, cara deklarasi dan akses:
 *
 * Deklarasi:  ListNilaiNimons L;
 *
 * Maka cara akses:
 * L.Neff untuk mengetahui banyaknya elemen
 * L.daftar untuk mengakses seluruh nilai elemen tabel
 * L.daftar[i] untuk mengakses elemen ke-i
 *
 * Definisi:
 * Tabel kosong: L.Neff = 0
 * Definisi elemen pertama : L.daftar[i] dengan i=0
 * Definisi elemen terakhir yang terdefinisi: L.daftar[i] dengan i=L.Neff
 *
 * Notes:
 * - Praktikum dapat dipastikan terurut membesar dan selalu berurutan (1, 2, 3, 4, dst) tidak ada praktikum yang tidak berurutan (misal 1, 2, 4, 7, dst)
 **/

/* ********** KONSTRUKTOR ARRAY ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty(ListNilaiNimons *L)
{
    L->Neff = 0;
}
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MAX_CAPACITY */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// (*L).Neff = 0;

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt(ListNilaiNimons L)
{
    return L.Neff;
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */

/* *** Daya tampung container *** */
int MaxNbEl(ListNilaiNimons L)
{
    return MAX_CAPACITY;
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh list */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(ListNilaiNimons L)
{
    return 0;
}
/* Prekondisi : List L tidak kosong */
/* Mengirimkan indeks elemen pertama */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// return 0;

IdxType GetLastIdx(ListNilaiNimons L)
{
    return L.Neff - 1;
}
/* Prekondisi : List L tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// return L.Neff-1;

/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt(ListNilaiNimons L, IdxType i)
{
    return L.daftar[i];
}
/* Prekondisi : List tidak kosong, i antara FirstIdx(L)..LastIdx(L) */
/* Mengirimkan elemen list yang ke-i */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
// return L.daftar[i];

/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab(ListNilaiNimons Lin, ListNilaiNimons *Lout)
{
    Lout->Neff = Lin.Neff;
    for (int i = 0; i < Lin.Neff; i++)
    {
        (*Lout).daftar[i] = Lin.daftar[i];
    }
}
/* I.S. Lin terdefinisi, sembarang */
/* F.S. Lout berisi salinan Lin */
/* Assignment Lout = Lin */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */

void SetEl(ListNilaiNimons *L, IdxType i, ElType v)
{
    (*L).daftar[i] = v;
    if ((*L).Neff < i + 1)
    {
        (*L).Neff = i + 1;
    }
}
/* I.S. L terdefinisi, sembarang */
/* F.S. Elemen L yang ke-i bernilai v */
/* Mengeset nilai elemen list yang ke-i sehingga bernilai v */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */

void SetNeff(ListNilaiNimons *L, IdxType N)
{
    (*L).Neff = N;
}
/* I.S. L terdefinisi, sembarang */
/* F.S. Nilai indeks efektif L bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(ListNilaiNimons L, IdxType i)
{
    return i >= GetFirstIdx(L) && i < MAX_CAPACITY;
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi utk container */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */

boolean IsIdxEff(ListNilaiNimons L, IdxType i)
{
    return i >= GetFirstIdx(L) && i <= GetLastIdx(L);
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara GetFirstIdx(L)..GetLastIdx(L) */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(ListNilaiNimons L)
{

    return L.Neff == 0;
}
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */

/* *** Test tabel penuh *** */
boolean IsFull(ListNilaiNimons L)
{

    return L.Neff == MAX_CAPACITY;
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void PrintIsi(ListNilaiNimons L)
{
    if (IsEmpty(L))
        printf("List kosong");
    else
    {
        for (int i = 0; i < L.Neff; i++)
        {
            ElType el = L.daftar[i];
            printf("%s - %d - %d\n", el.nama, el.praktikum, el.nilai);
        }
    }
}
/* Proses : Menuliskan isi list dengan traversal */
/* I.S. L boleh kosong */
/* F.S. Jika L tidak kosong : elemen tabel ditulis berderet ke bawah dengan format */
/* <Nama> - <Prak ke-n> - <Nilai> */
/* Contoh:
Dave - 1 - 89
Bokem - 2 - 30
PalePale - 1 - 70
PuluPulu - 9 - 59
*/
/* Jika L kosong : Hanya menulis "List kosong" */

/* ********** KONSTRUKTOR NILAI NIMONS ********** */
ElType MakeNilai(char *nama, int prakke, int nilai)
{
    ElType el;
    strcpy(el.nama, nama);
    el.nilai = nilai;
    el.praktikum = prakke;
    return el;
}
/* Membentuk sebuah Nilai Nimons dari komponen-komponennya */
/* Prekondisi (tidak perlu dicek): */
/* Nama terdiri atas maksimal 10 huruf. Contoh: NimonsUwu */
/* Prak ke-n terdiri dari angka 1-100 (karena praktikum kalian akan sebanyak itu 🥰) */
/* Nilai hanya terdiri dari angka range 0 - 100 */
/* I.S. nama dan nilai terdefinisi */
/* F.S. Nilai Nimons terbentuk dengan nama dan nilai yang sesuai */

/* ********** OPERATOR STATISTIK NILAI NIMONS ********** */
float AvgNilaiNama(ListNilaiNimons L, char *nama)
{
    float total = 0;
    float count = 0;
    for (int i = 0; i < L.Neff; i++)
    {
        if (strcmp(L.daftar[i].nama, nama) == 0)
        {
            float _ = (float)L.daftar[i].nilai;
            total += _;
            count++;
        }
    }
    if (count == 0)
        return 0;
    return total / count;
}
/* Prekondisi : List L tidak kosong */
/* Mengembalikan rata-rata nilai nimon dengan nama = <nama> dari semua praktikum */
/* Jumlahkan semua nilai nimon dengan nama = <nama> lalu bagi dengan jumlahnya */
/* Keluarkan 0 apabila tidak ada nama dalam list */
/* HINT:
 * - Gunakan strcmp untuk membandingkan value 2 string -> strcmp(str1, str2) == 0 <- artinya: perbedaan character antara str1 dan str2 = 0
 * - Ingat pembagian 0
 * - lakukan casting integer ke float sebelum melakukan pembagian -> (float)total / count */

int MaxNilaiNama(ListNilaiNimons L, char *nama)
{
    int max = -1;
    for (int i = 0; i < L.Neff; i++)
    {
        if (strcmp(L.daftar[i].nama, nama) == 0)
        {
            if (L.daftar[i].nilai > max)
            {
                max = L.daftar[i].nilai;
            }
        }
    }
    return max;
}
/* Prekondisi : List L tidak kosong */
/* Mengembalikan nilai maksimum dari nimon dengan nama = <nama> dari semua praktikum */
/* Cari nilai maksimum dari nimon dengan nama = <nama> */
/* Keluarkan -1 apabila tidak ada nama dalam list */
/* HINT: Gunakan strcmp untuk membandingkan value 2 string */

int MinNilaiNama(ListNilaiNimons L, char *nama)
{
    int min = 101;
    for (int i = 0; i < L.Neff; i++)
    {
        if (strcmp(L.daftar[i].nama, nama) == 0)
        {
            if (L.daftar[i].nilai < min)
            {
                min = L.daftar[i].nilai;
            }
        }
    }
    return min;
}
/* Prekondisi : List L tidak kosong */
/* Mengembalikan nilai minimum dari nimon dengan nama = <nama> dari semua praktikum */
/* Cari nilai minimum dari nimon dengan nama = <nama> */
/* Keluarkan 101 apabila tidak ada nama dalam list */
/* HINT: Gunakan strcmp untuk membandingkan value 2 string */

float AvgNilai(ListNilaiNimons L)
{
    float total = 0;
    float count = 0;
    if (L.Neff != 0)
    {
        for (int i = 0; i < L.Neff; i++)
        {
            float _ = (float)L.daftar[i].nilai;
            total += _;
            count++;
        }
        if (count == 0)
            return 0;
        return total / count;
    }
    return 0;
}
/* Mengembalikan rata-rata nilai nimon di semua praktikum */
/* Jumlahkan semua nilai nimon lalu bagi dengan jumlahnya */
/* Keluarkan 0 apabila list kosong */
/* HINT:
 * - Gunakan strcmp untuk membandingkan value 2 string -> strcmp(str1, str2) == 0 <- artinya: perbedaan character antara str1 dan str2 = 0
 * - Ingat pembagian 0
 * - lakukan casting integer ke float sebelum melakukan pembagian -> (float)total / count */

int MaxNilai(ListNilaiNimons L)
{
    int max = -1;
    for (int i = 0; i < L.Neff; i++)
    {
        if (L.daftar[i].nilai > max)
        {
            max = L.daftar[i].nilai;
        }
    }
    return max;
}
/* Mengembalikan nilai maksimum dari nimon di semua praktikum */
/* Cari nilai maksimum dari nimon */
/* Keluarkan -1 apabila list kosong */

int MinNilai(ListNilaiNimons L)
{

    int min = 101;
    for (int i = 0; i < L.Neff; i++)
    {
        if (L.daftar[i].nilai < min)
        {
            min = L.daftar[i].nilai;
        }
    }
    return min;
}
/* Mengembalikan nilai minimum dari nimon di semua praktikum */
/* Cari nilai minimum dari nimon */
/* Keluarkan 101 apabila list kosong */

int CountTotalPraktikum(ListNilaiNimons L)
{
    int count = 0;
    for (int i = 0; i < L.Neff; i++)
    {
        boolean isUnique = TRUE;
        for (int j = 0; j < L.Neff; j++)
        {
            if (L.daftar[i].praktikum == L.daftar[j].praktikum)
            {
                isUnique = FALSE;
                break;
            }
        }
        if (isUnique)
            count++;
    }
    return count;
}
/* Prekondisi : List L tidak kosong */
/* Menghitung jumlah praktikum yang telah terdaftar pada daftar nilai */
/* Hitung jumlah praktikum unik yang ada pada list */
/* HINT:
- Gunakan list sementara dengan size MAX_CAPACITY untuk menyimpan daftar praktikum yang sudah pernah dicek
- Inisialisasi semua elemen list sementara dengan 0 -> int list_temp[MAX_CAPACITY] = {0};
- Beri tanda pada elemen list sementara yang sudah dicek (misal: menandai dengan 1)
*/
void DisplayStatistic(ListNilaiNimons L)
{
    printf("- Total praktikum: %d\n", CountTotalPraktikum(L));
    printf("- Rata-rata: %.2f\n", AvgNilai(L));
    printf("- Nilai maksimum: %d\n", MaxNilai(L));
    printf("- Nilai minimum: %d\n", MinNilai(L));
}
/* I.S. List L DIPASTIKAN tidak kosong */
/* F.S. Mencetak statistik ke layar, desimal dicetak dengan 2 angka di belakang koma */
/* Contoh: */
/*
- Total praktikum: 100
- Rata-rata: 75.00
- Nilai maksimum: 100
- Nilai minimum: 40
*/
/* HINT: Hitung jumlah praktikum terlebih dahulu */

void DisplayStatisticNimons(ListNilaiNimons L, char *nama)
{
    printf("Nama: %s\n", nama);
    for (int i = 0; i < L.Neff; i++)
    {
        if (strcmp(L.daftar[i].nama, nama) == 0)
        {
            printf("Praktikum %d: %d\n", L.daftar[i].praktikum, L.daftar[i].nilai);
        }
    }

    float rata = AvgNilaiNama(L, nama);
    printf("Rata-rata: %.2f\n", rata);
    printf("Nilai maksimum: %d\n", MaxNilaiNama(L, nama));
    printf("Nilai minimum: %d\n", MinNilaiNama(L, nama));
    printf("Nilai akhir: %c\n", KonversiNilai(rata));
}
/* I.S. List L DIPASTIKAN tidak kosong */
/* F.S. Mencetak statistik ke layar, desimal dicetak dengan 2 angka di belakang koma */
/* Contoh: */
/*
Nama: Dave
Praktikum 1: 89
Praktikum 2: 70
...
Praktikum 100: 60

Rata-rata: 73.00
Nilai maksimum: 89
Nilai minimum: 60
Nilai akhir: B
*/

/* ********** UTILS ********** */
char KonversiNilai(int nilai)
{
    if (nilai >= 80)
        return 'A';
    else if (nilai >= 65)
        return 'B';
    else if (nilai >= 50)
        return 'C';
    else if (nilai >= 35)
        return 'D';
    else if (nilai >= 0)
        return 'E';
    else
        return 'I';
}
/* Prekondisi : Nilai memiliki nilai integer dengan range 0-100 */
/* Mengembalikan indeks dengan aturan berikut */
/**
 * Nilai >= 80 -> A
 * Nilai >= 65 -> B
 * Nilai >= 50 -> C
 * Nilai >= 35 -> D
 * Nilai >= 0  -> E
 * Nilai < 0  -> I
 */
/* HINT: Konversi aturan diatas menjadi bentuk if else */

int main()
{
    ListNilaiNimons L;
    MakeEmpty(&L);
    SetEl(&L, GetLastIdx(L) + 1, MakeNilai("John Doe", 2, 20));
    SetEl(&L, GetLastIdx(L) + 1, MakeNilai("John Doe", 1, 90));
    SetEl(&L, GetLastIdx(L) + 1, MakeNilai("John Die", 1, 50));
    DisplayStatisticNimons(L, "John Doe");
    PrintIsi(L);
}