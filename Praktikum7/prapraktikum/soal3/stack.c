#include "stack.h"

void CreateStack(Stack *s)
{
  s->idxTop = IDX_UNDEF;
}

boolean isEmpty(Stack s)
{
  return (s.idxTop == IDX_UNDEF);
}

boolean isFull(Stack s)
{
  return (s.idxTop == CAPACITY - 1);
}
int length(Stack s)
{
  return s.idxTop + 1;
}
void push(Stack *s, ElType val)
{
  s->buffer[s->idxTop + 1] = val;
  s->idxTop++;
}
void pop(Stack *s, ElType *val)
{
  *val = s->buffer[s->idxTop];
  s->idxTop--;
}