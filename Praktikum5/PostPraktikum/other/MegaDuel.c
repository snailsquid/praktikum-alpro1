#include <stdio.h>
#include "MegaDuel.h"

void runMegaDuel(LabTrack *L) {
    printf("\n");
    while (length(*L) > 1) {
        printf("== DUEL ROUND ==\n");

        MegaNimons first = getElmt(*L, firstIdx(*L));
        MegaNimons last = getElmt(*L, lastIdx(*L));

        duelOnce(first, last);

        MegaNimons winner = resolveDuel(first, last);

        if (winner.id == first.id) {
            MegaNimons removed;
            deleteLast(L, &removed);
        } else {
            MegaNimons removed;
            deleteFirst(L, &removed);
        }

        printf("\n");
    }

    MegaNimons champion = getElmt(*L, firstIdx(*L));
    printf("== The Champion: %s ==\n", champion.name);
}