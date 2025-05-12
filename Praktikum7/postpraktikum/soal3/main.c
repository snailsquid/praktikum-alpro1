#include <stdio.h>
#include "stack.h"

int main()
{
  Stack s;
  ElType val;

  CreateStack(&s);
  if (isEmpty(s))
  {
    printf("Stack is empty\n");
  }

  push(&s, 5);
  push(&s, 3);
  push(&s, 8);
  push(&s, 3);
  printStack(s);

  reverseStack(&s);
  printStack(s);

  Stack sres;
  copyStack(&sres, s);
  push(&sres, 9);
  push(&sres, 69);
  printStack(sres);

  Stack merge;
  mergeStack(&merge, &sres, &s);
  printStack(merge);
  // printf("Top element: %d\n", TOP(s));

  // printf("Length: %d\n", length(s));

  // pop(&s, &val);
  // printf("Popped: %d\n", val);
  // printStack(s);

  // if (isFull(s))
  // {
  //   printf("Stack is full\n");
  // }
  // else
  // {
  //   printf("Stack is not full\n");
  // }

  // while (!isFull(s))
  // {
  //   push(&s, 1);
  // }
  // printf("Filled the stack.\n");
  // printf("Length after filling: %d\n", length(s));
  // printf("Is full: %s\n", isFull(s) ? "true" : "false");

  return 0;
}
