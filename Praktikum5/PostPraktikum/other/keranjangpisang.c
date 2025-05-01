#include <stdio.h>
#include "keranjangpisang.h"

void CreateKeranjang(KeranjangPisang *k) {
    for ( int i = 0; i < CAPACITY; i++)
    {
        k->contents[i] = MARK;
    }
    
}

int lengthKeranjang(KeranjangPisang k) {
    int i = 0;

    while (k.contents[i] != MARK && i < CAPACITY)
    {
        i++;
    }
    return i;
}

IdxType getFirstIdx(KeranjangPisang k) {
    return IDX_MIN;
}

IdxType getLastIdx(KeranjangPisang k) {
    return (lengthKeranjang(k) - 1);
}

boolean isIdxValid(KeranjangPisang k, IdxType i) {
    return (i >= IDX_MIN && i < CAPACITY);
}

boolean isIdxEff(KeranjangPisang k, IdxType i) {
    return (i >= IDX_MIN && i < lengthKeranjang(k));
}

boolean isEmpty(KeranjangPisang k) {
    return (lengthKeranjang(k) == 0);
}

boolean isFull(KeranjangPisang k) {
    return (lengthKeranjang(k) == CAPACITY);
}

void readKeranjang(KeranjangPisang *k) {
    int n;

    scanf("%d", &n);
    if (n < 0 || n > CAPACITY) {
        return;
    } else {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &k->contents[i]);
        }
    }
    
}

void printKeranjang(KeranjangPisang k) {
    if (lengthKeranjang(k) == 0)
    {
        printf("[]\n");
    } else {
        printf("[");
        for (int i = 0; i < lengthKeranjang(k); i++) {
            printf("%d", k.contents[i]);
            if (i < lengthKeranjang(k) - 1) printf(",");
        }
        printf("]\n");
    }
    
}

void insertFirst(KeranjangPisang *k, ElType val) {
    insertAt(k, val, 0);
}

void insertAt(KeranjangPisang *k, ElType val, IdxType idx) {
    if (lengthKeranjang(*k) < CAPACITY) {
        for (int i = lengthKeranjang(*k); i > idx; i--)
        {
            k->contents[i] = k->contents[i - 1];
        }
        k->contents[idx] = val;
    }
}

void insertLast(KeranjangPisang *k, ElType val) {
    if (lengthKeranjang(*k) < CAPACITY) {
        k->contents[lengthKeranjang(*k)] = val;
    }
}

void deleteFirst(KeranjangPisang *k, ElType *val) {
    deleteAt(k, val, 0);
}

void deleteAt(KeranjangPisang *k, ElType *val, IdxType idx) {
    int len = lengthKeranjang(*k);
    *val = k->contents[idx];
    for (int i = idx; i < len - 1; i++)
    {
        k->contents[i] = k->contents[i + 1];
    }
    k->contents[len - 1] = MARK;
}

void deleteLast(KeranjangPisang *k, ElType *val) {
    if (lengthKeranjang(*k) > 0)
    {
        *val = k->contents[lengthKeranjang(*k) - 1];
        k->contents[lengthKeranjang(*k) - 1] = MARK;
    }
    
}

