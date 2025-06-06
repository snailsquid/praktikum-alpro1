#include "set.h"
#include "boolean.h"
void CreateEmpty(Set *S)
{
  S->Count = 0;
}
boolean IsEmpty(Set S)
{
  return (S.Count == 0);
}
void Insert(Set *S, int Elmt)
{
  if (IsMember(*S, Elmt))
  {
    return;
  }
  S->Elements[S->Count] = Elmt;
  S->Count++;
}

void Delete(Set *S, int Elmt)
{
  int index = -1;
  for (int i = 0; i < S->Count; i++)
  {
    if (S->Elements[i] == Elmt)
    {
      index = i;
      break;
    }
  }
  if (index == -1)
    return;

  for (int i = index + 1; i < S->Count; i++)
  {
    S->Elements[i - 1] = S->Elements[i];
  }
  S->Count--;
}

boolean IsFull(Set S)
{
  return (S.Count >= MaxEl);
}
boolean IsMember(Set S, int Elmt)
{
  for (int i = 0; i < S.Count; i++)
  {
    if (S.Elements[i] == Elmt)
    {
      return true;
    }
  }
  return false;
}

void printSet(Set *s)
{
  for (int i = 0; i < s->Count; i++)
  {
    printf("[%d] %d\n", i, s->Elements[i]);
  }
}
// int main()
// {
//   Set s;
//   CreateEmpty(&s);
//   Insert(&s, 2);
//   Insert(&s, 2);
//   Insert(&s, 5);
//   Insert(&s, 3);
//   Insert(&s, 4);
//   Insert(&s, 4);
//   Delete(&s, 2);
//   Insert(&s, 3);
//   printSet(&s);
//   Insert(&s, 9);
//   printSet(&s);
//   Delete(&s, 3);
//   printSet(&s);
//   Insert(&s, 3);
//   Insert(&s, 3);
//   printSet(&s);
// }