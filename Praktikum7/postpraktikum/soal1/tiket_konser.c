#include "tiket_konser.h"
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
boolean isDuplicateSN(Queue Q, int sn)
{
  int i = Q.idxHead;
  // printf("%d %d\n", Q->idxHead, Q->idxTail);
  if (Q.idxHead == Q.idxTail)
  {
    return (Q.Tab[Q.idxHead].seatNumber == sn);
  }
  else
  {

    while (i != Q.idxTail)
    {
      if (i == IDX_MAX)
      {
        // printf("%d == %d\n",Q->Tab[i].seatNumber, X.seatNumber);
        if (Q.Tab[i].seatNumber == sn)
          return true;
        i = 0;
      }
      else
      {
        // printf("%d == %d\n",Q->Tab[i].seatNumber, X.seatNumber);

        if (Q.Tab[i].seatNumber == sn)
          return true;
        i++;
      }
    }

    return false;
  }
}
// boolean isUnique(Queue *Q, ElType X)
// {
//   int i = Q->idxHead;
//   // printf("%d %d\n", Q->idxHead, Q->idxTail);
//   if (Q->idxHead == Q->idxTail)
//   {
//     return (Q->Tab[Q->idxHead].seatNumber != X.seatNumber);
//   }
//   else
//   {

//     while (i != Q->idxTail)
//     {
//       if (i == IDX_MAX)
//       {
//         // printf("%d == %d\n",Q->Tab[i].seatNumber, X.seatNumber);
//         if (Q->Tab[i].seatNumber == X.seatNumber)
//           return false;
//         i = 0;
//       }
//       else
//       {
//         // printf("%d == %d\n",Q->Tab[i].seatNumber, X.seatNumber);

//         if (Q->Tab[i].seatNumber == X.seatNumber)
//           return false;
//         i++;
//       }
//     }

//     return true;
//   }
// }

void enqueue(Queue *Q, ElType X)
{
  //   if (Q->idxTail == IDX_MAX)
  //   {
  //     index = 0;
  //   }
  //   else
  //   {
  //     index = Q->idxTail + 1;
  //   }
  //   Q->Tab[index] = X;
  //   Q->idxTail = index;
  // printf("--out--\nhead: %d\ntail: %d\n", Q->idxHead, Q->idxTail);

  int index = 0;
  int QN = X.queueNumber;
  if (IsEmpty(*Q))
  {
    Q->idxHead = 0;
    Q->idxTail = 0;
  }
  else
  {
    if (isDuplicateSN(*Q, X.seatNumber))
      return;
    int i = IDX_TAIL(*Q);
    // if(IDX_HEAD(*Q)==IDX_TAIL(*Q))
    // {
    //     i++;
    // }
    while (QN < Q->Tab[i].queueNumber)
    {
      // printf(
      //     "QN : %d, Tab[%d]: %d\n", QN, i, Q->Tab[i].queueNumber
      // );
      if (i == 0 && Q->idxHead == 0)
      {
        i--;
        break;
      }
      if (i == 0)
      {
        i = IDX_MAX;
      }
      else
      {
        i--;
      }
    }
    i++;
    int j = IDX_TAIL(*Q);
    while (j >= i)
    {
      if (j == IDX_MAX)
      {
        Q->Tab[0] = Q->Tab[j];
        j = 0;
      }
      else
      {
        Q->Tab[j + 1] = Q->Tab[j];
        j--;
      }
    }
    if (Q->idxTail == IDX_MAX)
    {
      Q->idxTail = 0;
    }
    else
    {
      Q->idxTail++;
    }
    index = i;
  }
  // printf("index : %d\n", index);
  Q->Tab[index] = X;
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
      printf("(%s-%d-%d)", q.Tab[i].nama, q.Tab[i].seatNumber, q.Tab[i].queueNumber);
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