#include "circular_queue.h"
#include <stdio.h>

boolean IsEmpty(Queue Q)
{
  return (IDX_HEAD(Q) == IDX_UNDEF || IDX_TAIL(Q) == IDX_UNDEF);
}

boolean IsFull(Queue Q)
{
  boolean out;
  if (IDX_HEAD(Q) >= IDX_TAIL(Q))
    out = (IDX_HEAD(Q) == IDX_TAIL(Q) + 1);
  else
    out = (IDX_HEAD(Q) == 0 && IDX_TAIL(Q) == IDX_MAX);
  return (out);
}

int Length(Queue Q)
{
  int count = 0;
  if (!IsEmpty(Q))
  {
    int idxHead = IDX_HEAD(Q);
    int idxTail = IDX_TAIL(Q);
    // printf("idxTail %d\nidxHead %d\n", idxTail, idxHead);
    if (idxHead > idxTail)
    {
      count = IDX_MAX - idxHead + 2 + idxTail;
    }
    else
    {
      count = idxTail + 1;
    }
  }
  return (count);
}
void CreateQueue(Queue *Q)
{
  Q->idxHead = IDX_UNDEF;
  Q->idxTail = IDX_UNDEF;
}
void enqueue(Queue *Q, ElType X)
{
  int index;
  if (IsEmpty(*Q))
  {
    Q->idxHead = 0;
  }
  if (Q->idxTail == IDX_MAX)
  {
    index = 0;
  }
  else
  {
    index = Q->idxTail + 1;
  }
  Q->Tab[index] = X;
  Q->idxTail = index;
  // printf("--out--\nhead: %d\ntail: %d\n", Q->idxHead, Q->idxTail);
}

ElType dequeue(Queue *Q)
{
  ElType out = Q->Tab[Q->idxHead];

  if (Q->idxHead == Q->idxTail)
  {
    Q->idxHead = IDX_UNDEF;
    Q->idxTail = IDX_UNDEF;
  }
  else
  {
    if (Q->idxHead == IDX_MAX)
      Q->idxHead = 0;
    else
      Q->idxHead = Q->idxHead + 1;
  }
  // printf("--out--\nhead: %d\ntail: %d\n", Q->idxHead, Q->idxTail);
  return out;
}

ElType peek(Queue Q)
{
  return Q.Tab[Q.idxHead];
}

void displayQueue(Queue q)
{
  if (IsEmpty(q))
    printf("[]\n");
  else
  {
    printf("[");
    int idxHead = IDX_HEAD(q), idxTail = IDX_TAIL(q);
    // printf("index head : %d\n", idxHead);
    int i = idxHead;
    while (true)
    {
      printf("%s", q.Tab[i].namaTim);
      if (idxTail == i)
        break;
      if (i == IDX_MAX)
        i = 0;
      else
        i = i + 1;
      printf(", ");
    }
    printf("]\n");
  }
}