#include "listnimons.h"
#include <stdio.h>
#include <string.h>

void CreateListNimons(ListNimons *l) {
    for (int i = 0; i < NIMONS_CAPACITY; i++) {
        l->contents[i].age = -1;
        l->contents[i].height = 0;
        strcpy(l->contents[i].name, "");
    }
}

int listNimonsLength(ListNimons l) {
    int i = 0;
    while (i < NIMONS_CAPACITY && l.contents[i].age != -1) {
        i++;
    }
    return i;
}

boolean isIdxValidNimons(ListNimons l, int i) {
    return (i >= IDX_MIN && i < NIMONS_CAPACITY);
}

boolean isIdxEffNimons(ListNimons l, int i) {
    return (i >= IDX_MIN && i < listNimonsLength(l));
}

boolean isNimonsEmpty(ListNimons l) {
    return listNimonsLength(l) == 0;
}

boolean isNimonsFull(ListNimons l) {
    return listNimonsLength(l) == NIMONS_CAPACITY;
}

void readNimonsList(ListNimons *l) {
    int n;
    scanf("%d", &n);

    CreateListNimons(l); 

    for (int i = 0; i < n; i++) {
        if (isNimonsFull(*l)) {
            return;
        }
        scanf("%s %d %d", l->contents[i].name, &l->contents[i].age, &l->contents[i].height);
    }
}

void printNimonsList(ListNimons l) {
    int len = listNimonsLength(l);
    if (len == 0) {
        printf("[]\n");
        return;
    }

    printf("[");
    for (int i = 0; i < len; i++) {
        printf("%s-%d-%d", l.contents[i].name, l.contents[i].age, l.contents[i].height);
        if (i < len - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void insertNimonsLast(ListNimons *l, Nimons m) {
    int len = listNimonsLength(*l);
    if (isNimonsFull(*l)) {
        return;
    }
    l->contents[len] = m;
}

void deleteNimonsLast(ListNimons *l, Nimons *m) {
    int len = listNimonsLength(*l);
    if (isNimonsEmpty(*l)) {
        return;
    }
    *m = l->contents[len - 1];
    l->contents[len - 1].age = -1;
}

int indexOfNimons(ListNimons l, char *name) {
    int len = listNimonsLength(l);
    for (int i = 0; i < len; i++) {
        if (strcmp(l.contents[i].name, name) == 0) {
            return i;
        }
    }
    return IDX_UNDEF;
}

void findTallestShortest(ListNimons l, Nimons *tallest, Nimons *shortest) {
    int len = listNimonsLength(l);
    if (len == 0) {
        *tallest = (Nimons){.age = -1, .height = 0, .name = ""};
        *shortest = (Nimons){.age = -1, .height = 0, .name = ""};
        return;
    }

    *tallest = l.contents[0];
    *shortest = l.contents[0];

    for (int i = 1; i < len; i++) {
        if (l.contents[i].height > tallest->height) {
            *tallest = l.contents[i];
        }
        if (l.contents[i].height < shortest->height) {
            *shortest = l.contents[i];
        }
    }
}