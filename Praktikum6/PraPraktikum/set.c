#include "set.h"
#include "boolean.h"
void CreateEmpty(Set *S)
{
  S->Count = 0;
}
boolean IsEmpty(Set S)
{
  if (S.Count == 0)
    return true;
  return false;
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
  if (S.Count >= MaxEl)
    return true;
  return false;
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

int main()
{
  Set s;
  CreateEmpty(&s);
  Insert(&s, 2);
  Insert(&s, 2);
  Insert(&s, 5);
  Insert(&s, 3);
  Insert(&s, 4);
  Insert(&s, 4);
  Delete(&s, 2);
  Insert(&s, 3);
  for (int i = 0; i < s.Count; i++)
  {
    printf("[%d] %d\n", i, s.Elements[i]);
  }
  if (IsFull(s))
  {
    printf("full");
  }
  else
    printf("not full");
  if (IsMember(s, 5))
    printf("5 is member");
  else
    printf("5 is not member");
}