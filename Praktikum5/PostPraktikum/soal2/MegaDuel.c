// NIM    : <Tulis NIM Anda>
// Nama   : <Tulis Nama Anda>
// Tanggal: <Tulis tanggal pengerjaan>

#include "MegaNimons.h"
#include <stdio.h>
#include <string.h>

/**
 * Anda boleh menambahkan fungsi/prosedur tambahan jika diperlukan
 */

/**
 * Menjalankan turnamen pertarungan antar MegaNimons dalam LabTrack.
 * Pertarungan dilakukan secara berpasangan dari ujung list:
 *   - MegaNimons pertama vs terakhir
 *   - Pemenang tetap, yang kalah dieliminasi dari list
 *   - Proses berlanjut dengan MegaNimons berikutnya di sisi yang masih hidup
 *   - Berlangsung hingga hanya tersisa satu MegaNimons sebagai pemenang
 *
 * Aturan penentuan pemenang diatur oleh fungsi resolveDuel.
 *
 * I.S. LabTrack L berisi ≥ 1 MegaNimons
 * F.S. Semua MegaNimons tersingkir kecuali satu pemenang.
 *      Ditampilkan log setiap duel dan pemenang akhir.
 *
 * Contoh:
 *
 * Input List (nEff = 3):
 *   0: Kevzilla (800.0)
 *   1: Bobzilla (850.0)
 *   2: Melatron (780.0)
 *
 * Output:
 *   <endline>
 *   == DUEL ROUND ==
 *   Duel: Kevzilla (800.0) vs Melatron (780.0)
 *   Winner: Kevzilla
 *   <endline>
 *   == DUEL ROUND ==
 *   Duel: Kevzilla (800.0) vs Bobzilla (850.0)
 *   Winner: Bobzilla
 *   <endline>
 *   == The Champion: Bobzilla ==
 */
MegaNimons getFirst(LabTrack *L)
{
  return getElmt(*L, firstIdx(*L));
}

MegaNimons getLast(LabTrack *L)
{
  return getElmt(*L, lastIdx(*L));
}

void duelRound(LabTrack *L)
{

  printf("\n== DUEL ROUND ==\n");
  MegaNimons m1 = getFirst(L);
  MegaNimons m2 = getLast(L);
  MegaNimons winner = resolveDuel(m1, m2);
  duelOnce(m1, m2);
  if (m1.id == winner.id)
  {
    deleteLast(L, &m2);
  }
  else
  {
    deleteFirst(L, &m1);
  }
  // printLabTrack(*L);
}

void runMegaDuel(LabTrack *L)
{
  while (L->nEff > 1)
  {
    duelRound(L);
  }
  MegaNimons winner = L->contents[0];
  printf("\n== The Champion: %s ==\n", winner.name);
}

void createNimons(MegaNimons *m, int id, float power, char *name, char *mut, boolean isStable)
{
  m->id = id;
  strcpy(m->name, name);
  m->powerLevel = power;
  strcpy(m->mutationType, mut);
  m->isStable = isStable;
}

// int main()
// {
//   LabTrack L;
//   createLabTrack(&L);
//   MegaNimons m1;
//   createNimons(&m1, 1, 2.1, "a", "s", TRUE);
//   insertLast(&L, m1);
//   MegaNimons m2;
//   createNimons(&m2, 2, 2.2, "b", "s", TRUE);
//   insertLast(&L, m2);
//   MegaNimons m3;
//   createNimons(&m3, 3, 2.4, "c", "s", TRUE);
//   insertLast(&L, m3);
//   MegaNimons m4;
//   createNimons(&m4, 4, 1.4, "d", "s", TRUE);
//   insertLast(&L, m4);

//   runMegaDuel(&L);
// }