#include "queue.h"

void initQueue(struct Queue *q)
{
  q->count = 0;
}

bool isEmpty(struct Queue *q)
{
  return (q->count == 0);
}

bool isFull(struct Queue *q)
{
  return (q->count == MAX_SIZE);
}

void enqueue(struct Queue *q, int value)
{
  if (isFull(q))
  {
    printf("Queue penuh!\n");
    return;
  }

  q->items[q->count] = value;
  q->count++;
}

int dequeue(struct Queue *q)
{
  if (isEmpty(q))
  {
    printf("Queue kosong!\n");
    return SENTINEL;
  }

  int out = q->items[0];
  for (int i = 0; i < q->count; i++)
  {
    q->items[i] = q->items[i + 1];
  }
  q->count--;
  return out;
}

int front(struct Queue *q)
{
  if (isEmpty(q))
  {
    printf("Queue kosong!\n");
    return SENTINEL;
  }

  return q->items[0];
}

int size(struct Queue *q)
{
  return q->count;
}
