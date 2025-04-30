#include "molecule.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Implementasi Fungsi ADT Molekul ---

void createMolecule(Molecule *m) {
  Molecule m1;
  m1.numAtomTypes = 0;
  *m = m1;
}

void addAtom(Molecule *m, const char *symbol, int count) {
  const int numAtomTypes = m->numAtomTypes;
  for(int i =0; i<numAtomTypes; i++)
  {
    if(strcmp(m->atoms[i].symbol,symbol)==0)
    {
      m->atoms[i].count += count;
      return;
    }
  }

  if(numAtomTypes>=MAX_ATOM_TYPES)
    return;
  AtomInfo atom;
  strcpy(atom.symbol, symbol);
  atom.count = count;
  m->atoms[numAtomTypes] = atom;
  m->numAtomTypes = numAtomTypes+1;
}

double getAtomicWeight(const char *symbol) {
    if (strcmp(symbol, "H") == 0)
        return 1.008;
    else if (strcmp(symbol, "He") == 0)
        return 4.0026;
    else if (strcmp(symbol, "Li") == 0)
        return 6.94;
    else if (strcmp(symbol, "C") == 0)
        return 12.011;
    else if (strcmp(symbol, "N") == 0)
        return 14.007;
    else if (strcmp(symbol, "O") == 0)
        return 15.999;
    else if (strcmp(symbol, "F") == 0)
        return 18.998;
    else if (strcmp(symbol, "Ne") == 0)
        return 20.180;
    else if (strcmp(symbol, "Na") == 0)
        return 22.990;
    else if (strcmp(symbol, "Mg") == 0)
        return 24.305;
    else if (strcmp(symbol, "Al") == 0)
        return 26.982;
    else if (strcmp(symbol, "Si") == 0)
        return 28.085;
    else if (strcmp(symbol, "P") == 0)
        return 30.974;
    else if (strcmp(symbol, "S") == 0)
        return 32.06;
    else if (strcmp(symbol, "Cl") == 0)
        return 35.45;
    else if (strcmp(symbol, "Ar") == 0)
        return 39.948;
    else if (strcmp(symbol, "K") == 0)
        return 39.098;
    else if (strcmp(symbol, "Ca") == 0)
        return 40.078;
    else if (strcmp(symbol, "Fe") == 0)
        return 55.845;
    else if (strcmp(symbol, "Au") == 0)
        return 196.967;
    else if (strcmp(symbol, "Br") == 0)
        return 79.904;
    else if (strcmp(symbol, "I") == 0)
        return 126.904;
    return 0.0;
}

double calculateMolecularWeight(const Molecule *m) {
  int numAtomTypes = m->numAtomTypes;
  double weight = 0.0;
  for (int i = 0; i<numAtomTypes;i++) {
    weight+=getAtomicWeight(m->atoms[i].symbol)*m->atoms[i].count;
  }
  return weight; // Placeholder
}

int getAtomCount(const Molecule *m, const char *symbol) {
  int count = 0;
  for (int i = 0; i<m->numAtomTypes;i++) {
    if(strcmp(m->atoms[i].symbol, symbol)==0)
    {
      count = m->atoms[i].count;
      break;
    }
  }
  return count;
}

// --- Fungsi Bantuan untuk qsort jika diperlukan ---
int compareAtomInfo(const void *a, const void *b) {
    AtomInfo *atomA = (AtomInfo *)a;
    AtomInfo *atomB = (AtomInfo *)b;
    return strcmp(atomA->symbol, atomB->symbol);
}

void sortMolecule(Molecule *m) {
    if (m->numAtomTypes > 1) {
        qsort(m->atoms, m->numAtomTypes, sizeof(AtomInfo), compareAtomInfo);
    }
}

bool areEqual(const Molecule *m1, const Molecule *m2) {
  bool isEqual = true;
  Molecule mm1 = *m1;
  Molecule mm2 = *m2;
  sortMolecule(&mm1);
  sortMolecule(&mm2);
  if(mm1.numAtomTypes==mm2.numAtomTypes)
  {
    for (int i = 0; i<mm1.numAtomTypes;i++) {
      AtomInfo atom1 = mm1.atoms[i];
      AtomInfo atom2 = mm2.atoms[i];

      if(strcmp(atom1.symbol, atom2.symbol)!=0 || atom1.count != atom2.count)
      {
        isEqual = false;
      }
    }
  }
  else {
    isEqual = false;
  }
  return isEqual;
}

Molecule combineMolecules(const Molecule *m1, const Molecule *m2) {
  Molecule result;
  createMolecule(&result);

  for (int i = 0; i<m1->numAtomTypes;i++) {
    AtomInfo atom = m1->atoms[i];
    addAtom(&result, atom.symbol, atom.count);
  }
  for (int i = 0; i<m2->numAtomTypes;i++) {
    AtomInfo atom = m2->atoms[i];
    addAtom(&result, atom.symbol, atom.count);
  }
  return result;
}

bool canSubtract(const Molecule *m_total, const Molecule *m_sub) {
  // TODO: Implementasikan logika pengecekan
  bool able = true;
  
  for (int i = 0; i<m_sub->numAtomTypes; i++) {
    AtomInfo atom = m_sub->atoms[i];
    if(atom.count>getAtomCount(m_total, atom.symbol))
    {
      able=false;
      break;
    }
  }
  return able;
}

Molecule subtractMolecule(const Molecule *m_total, const Molecule *m_sub) {

  Molecule result;
  createMolecule(&result);

  if(!canSubtract(m_total, m_sub))
    return result;

  result = *m_total;
  
  for (int i = 0; i<m_sub->numAtomTypes; i++) 
  {
    for(int j = 0; j<result.numAtomTypes; j++)
    {
      if(strcmp(result.atoms[j].symbol, m_sub->atoms[i].symbol))
      {
        result.atoms[j].count = result.atoms[j].count - m_sub->atoms[i].count;
      }
    }
  }

  return result;
}

void printMoleculeFormula(const Molecule *m) {
  // TODO: Implementasikan fungsi ini
  // 1. Jika m->numAtomTypes == 0, cetak "(Kosong)".
  // 2. Urutkan atom berdasarkan simbol untuk output (gunakan fungsi sorting
  // yang sudah diberikan)
  // 3. Cetak formula molekul
  // Contoh output: C6H12O6, H2O, NaCl

  if (m->numAtomTypes == 0) {
      printf("(Kosong)\n");
      return;
  }

  Molecule m1 = *m;
  sortMolecule(&m1);

  for (int i = 0; i<m1.numAtomTypes;i++) {
    AtomInfo atom = m1.atoms[i];

    if(atom.count==0)
      continue;

    if(atom.count==1)
      printf("%s", atom.symbol);
    else
      printf("%s%d", atom.symbol, atom.count);
  }
  printf("\n");
}

// int main()
// {
//   Molecule m1,m2;
//   createMolecule(&m1);
//   addAtom(&m1, "H", 2);
//   addAtom(&m1, "Se", 3);
// 
//   addAtom(&m2, "H", 2);
//   addAtom(&m2, "Se", 2);
// 
//   if(canSubtract(&m1,&m2)){
//     printf("can \n");
//   }
//   else {
//     printf("cant\n");
//   }
//   //Molecule m = combineMolecules(&m1, &m2);
//   //printf("%d\n",getAtomCount(&m, "Se"));
//   Molecule m = combineMolecules(&m1, &m2);
//   printMoleculeFormula(&m);
//   return 0;
// }
