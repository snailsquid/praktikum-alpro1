#include "NimonsBalap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getKode(kendaraan k)
{
  return k.kode; // Return local variabel ??
}
int getJumlahKursi(kendaraan k)
{
  return k.jumlahKursi;
}
int getJumlahRoda(kendaraan k)
{
  return k.jumlahRoda;
}
int getKecepatan(kendaraan k)
{
  return k.kecepatan;
}
int getPanjang(kendaraan k)
{
  return k.dim.panjang;
}
int getLebar(kendaraan k)
{
  return k.dim.lebar;
}
int getTinggi(kendaraan k)
{
  return k.dim.tinggi;
}
int getBerat(kendaraan k)
{
  return k.berat;
}
int getHargaJual(kendaraan k)
{
  return k.hargaJual;
}

kendaraan buatKendaraan(char *kode, int jumlahKursi, int jumlahRoda, int kecepatan, dimensi d, int berat, int hargaJual){
  kendaraan k;
  strcpy(k.kode, kode);
  k.jumlahKursi = jumlahKursi;
  k.jumlahRoda = jumlahRoda;
  k.kecepatan = kecepatan;
  k.dim = d;
  k.berat = berat;
  k.hargaJual = hargaJual;
  return k;
}

void buatKendaraanDefault(kendaraan *k)
{
  dimensi d;
  d.panjang = 10;
  d.lebar = 10;
  d.tinggi = 10;
  *k = buatKendaraan("XXX", 4, 4, 10,  d, 100, 100000);
  //printf("%s\n", k->kode);
}

void buatKendaraanInput(kendaraan *k)
{
  dimensi d;
  kendaraan k1;
  scanf("%s", &k1.kode);
  scanf("%d", &k1.jumlahRoda);
  scanf("%d", &k1.jumlahKursi);
  scanf("%d", &k1.kecepatan);
  
  scanf("%d", &d.panjang);
  scanf("%d", &d.lebar);
  scanf("%d", &d.tinggi);
  k1.dim = d;

  scanf("%d", &k1.berat);
  scanf("%d", &k1.hargaJual);
  *k = buatKendaraan(k1.kode, k1.jumlahKursi, k1.jumlahRoda, k1.kecepatan, k1.dim, k1.berat, k1.hargaJual);
}

void printDetailKendaraan(kendaraan k){
  printf("%s ", k.kode);
  printf("%d ", getJumlahKursi(k));
  printf("%d ", getJumlahRoda(k));
}

void printJenisKendaraanBerdasarkanRoda(kendaraan k)
{
  const int NIMORIDE = 2;
  const int NIMOCAR = 4;
  const int NIMOTRUCK = 6;
  int jumlahRoda = getJumlahRoda(k);
  if(jumlahRoda<= NIMORIDE){
    printf("NimoRide");
  } else if(jumlahRoda <= NIMOCAR){
    printf("NimoCar");
  } else if(jumlahRoda <= NIMOTRUCK){
    printf("NimoTruck");
  } else {
    printf("NimoTanker");
  }
}
void printJenisKendaraanBerdasarkanKecepatan(kendaraan k)
{
  const int NIMOSLOW = 10;
  const int NIMOFAST = 20;
  const int NIMOSUPERFAST = 30;
  int kecepatan = getKecepatan(k);

  if(kecepatan<=NIMOSLOW){
    printf("NimoSlow");
  } else if (kecepatan<=NIMOSLOW){
    printf("NimoSlow");
  } else if (kecepatan<=NIMOFAST){
    printf("NimoFast");
  } else if (kecepatan<=NIMOSUPERFAST){
    printf("NimoSuperFast");
  } else {
    printf("NimoSpeedy");
  }
}
void printJenisKendaraanBerdasarkanBerat(kendaraan k)
{
  const int NIMOLIGHT = 100;
  const int NIMOMEDIUM = 200;
  const int NIMOHEAVY = 300;
  int berat = getBerat(k);
  
  if(berat<=NIMOLIGHT)
  {
    printf("NimoLight");
  }
  else if(berat<=NIMOLIGHT)
  {
    printf("NimoLight");
  }
  else if(berat<=NIMOHEAVY)
  {
    printf("NimoHeavy");
  }
  else {
    printf("NimoSuperHeavy");
  }
}

void jualKendaraan(kendaraan *k)
{
  const int RODA = 1000;
  const int KURSI = 10000;
  const int PANJANG = 100;
  const int LEBAR = 100;
  const int TINGGI = 100;
  const int BERAT = 100;
  
  int hargaJual = k->hargaJual;
  int hargaBeli = k->jumlahRoda*RODA+k->jumlahKursi*KURSI+k->dim.panjang*PANJANG+k->dim.lebar*LEBAR+k->dim.tinggi*TINGGI+k->berat*BERAT;
  if(hargaBeli>hargaJual)
  {
    printf("Nimons Rugi! Harga rakit mobil %s lebih mahal dari harga jual\n", k->kode);
  }
  else if(hargaBeli<hargaJual)
  {
    printf("Nimons Kaya hehe! Harga rakit mobil %s lebih murah dari harga jual\n", k->kode);
  }else if(hargaJual==hargaBeli)
  {
    printf("Nimons Pas! Harga rakit mobil %s sama dengan harga jual\n", k->kode);
  }
}

// int main()
// {
//   kendaraan k;
//   buatKendaraanDefault(&k);
//   //buatKendaraanInput(&k);
//   //printf("getKode %s\n", getKode(k));
//   jualKendaraan(&k);
//   printf("k.kode %s\n", k.kode);
//   return 0;
// }

