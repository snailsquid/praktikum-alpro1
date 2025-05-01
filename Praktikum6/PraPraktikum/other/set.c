#include <stdio.h>
#include "set.h"

void CreateEmpty(Set *S) {
    S->Count = Nil;
}

boolean IsEmpty(Set S) {
    return (S.Count == Nil);
}

boolean IsFull(Set S) {
    return (S.Count == MaxEl);
}

void Insert(Set *S, int Elmt) {
    if (IsMember(*S, Elmt) == false) {
        int idx = 0;
        while (idx < S->Count && S->Elements[idx] < Elmt) {
            idx++;
        }
        for (int i = S->Count; i > idx; i--) {
            S->Elements[i] = S->Elements[i-1];
        }
        S->Elements[idx] = Elmt;
        S->Count++;
    }
}

void Delete(Set *S, int Elmt) {
    if (IsMember(*S, Elmt) == true) {
        int idx = 0;
        while (idx < S->Count && S->Elements[idx] != Elmt) {
            idx++;
        }
        if (idx != S->Count) {
            for (int i = idx; i < S->Count - 1; i++) {
                S->Elements[i] = S->Elements[i+1];
            }
            S->Count--;
        }
    }
}

boolean IsMember(Set S, int Elmt) {
    boolean found = false;
    int i = 0;
    while (i < S.Count && found == false) {
        if (S.Elements[i] == Elmt) {
            found = true;
        }
        i++;
    }
    return found;
}