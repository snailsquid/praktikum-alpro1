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
void copyStack(Stack *sres, Stack s)
{
  CreateStack(sres);
  for (int i = 0; i < s.idxTop + 1; i++)
  {
    push(sres, s.buffer[i]);
  }
}
void reverseStack(Stack *s)
{
  Stack s1;
  CreateStack(&s1);
  int top = s->idxTop;
  for (int i = 0; i < top + 1; i++)
  {
    ElType val;
    pop(s, &val);
    push(&s1, val);
  }
  for (int i = 0; i < top + 1; i++)
  {
    push(s, s1.buffer[i]);
  }
}
void mergeStack(Stack *sres, Stack *s1, Stack *s2)
{
  CreateStack(sres);
  int s1top = s1->idxTop;
  int s2top = s2->idxTop;
  for (int i = 0; i < s1top + 1; i++)
  {
    push(sres, s1->buffer[i]);
  }
  for (int i = 0; i < s2top + 1; i++)
  {
    push(sres, s2->buffer[i]);
  }
}
void printStack(Stack s)
{
  if (isEmpty(s))
  {
    printf("Stack: EMPTY\n");
  }
  else
  {
    printf("Stack: ");
    for (int i = 0; i <= s.idxTop; i++)
    {
      printf("%d", s.buffer[i]);
      if (i < s.idxTop)
      {
        printf(" ");
      }
    }
    printf("\n");
  }
}