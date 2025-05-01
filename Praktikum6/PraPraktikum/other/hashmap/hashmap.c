#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"

void CreateEmpty(HashMap *M) {
    M->Count = Nil;
    for (int i = 0; i < MaxEl; i++) {
        M->Elements[i].key = Undefined;
        M->Elements[i].value = (valuetype*)malloc(sizeof(valuetype));
        *(M->Elements[i].value) = Undefined;
    }
}

address Hash(keytype K) {
    return (K % MaxEl);
}

valuetype Value(HashMap M, keytype K) {
    address h = Hash(K);
    if (M.Elements[h].key == K) {
        return *(M.Elements[h].value);
    } else {
        for (int i = 0; i < MaxEl; i++) {
            if (M.Elements[i].key == K) {
                return *(M.Elements[i].value);
            }
        }
        return Undefined;
    }
}

void Insert(HashMap *M, keytype K, valuetype V) {
    address h = Hash(K);
    if (M->Elements[h].key == K) {
        *(M->Elements[h].value) = V;
        return;
    }
    if (M->Elements[h].key == Undefined) {
        M->Elements[h].key = K;
        *(M->Elements[h].value) = V;
        M->Count++;
        return;
    }
    for (int i = 0; i < MaxEl; i++) {
        address idx = (h + i) % MaxEl;
        if (M->Elements[idx].key == K) {
            *(M->Elements[idx].value) = V;
            return;
        }
        if (M->Elements[idx].key == Undefined) {
            M->Elements[idx].key = K;
            *(M->Elements[idx].value) = V;
            M->Count++;
            return;
        }
    }
}

void printHashMap(HashMap M) {
    for (int i = 0; i < MaxEl; i++) {
        printf("%d:\n", i);
        printf("  Key: %d\n", M.Elements[i].key);
        printf("  Value: %d\n", *(M.Elements[i].value));
    }
}
