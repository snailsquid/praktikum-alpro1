#include "hashmap.h"
#include <stdio.h>
void CreateEmpty(HashMap *hm)
{
  hm->Count = Nil;
  for (int i = 0; i < MaxEl; i++)
  {
    infotype it;
    it.key = Undefined;
    it.value = Undefined;
    hm->Elements[i] = it;
  }
}

address Hash(keytype K)
{
  return (K % MaxEl);
}

valuetype Value(HashMap M, int key)
{
  address h = Hash(key);
  if (M.Elements[h].key == key)
    return M.Elements[h].value;
  for (int i = 0; i < MaxEl; i++)
  {
    if (M.Elements[i].key == key)
    {
      return M.Elements[i].value;
    }
  }
  return Undefined;
}
void Insert(HashMap *M, keytype key, valuetype value)
{
  address h = Hash(key);
  if (M->Elements[h].key == key)
  {
    M->Elements[h].value = value;
    return;
  }
  if (M->Elements[h].key == Undefined)
  {
    M->Elements[h].key = key;
    M->Elements[h].value = value;
    M->Count++;
    return;
  }
  for (int i = 0; i < MaxEl; i++)
  {
    address a = Hash(i + h);

    if (M->Elements[a].key == key)
    {
      M->Elements[a].value = value;
      return;
    }
    if (M->Elements[a].key == Undefined)
    {
      M->Elements[a].key = key;
      M->Elements[a].value = value;
      M->Count++;
      return;
    }
  }
}

void printHashMap(HashMap M)
{
  for (int i = 0; i < MaxEl; i++)
  {
    infotype it = M.Elements[i];
    printf("%d:\n  Key: %d\n  Value: %d\n", i, it.key, it.value);
  }
}
void Delete(HashMap *M, keytype k)
{
  address h = Hash(k);
  if (M->Elements[h].key == k)
  {
    M->Elements[h].key = Undefined;
    return;
  }
  if (M->Elements[h].key == Undefined)
  {
    return;
  }
  for (int i = 0; i < MaxEl; i++)
  {
    address a = Hash(i + h);

    if (M->Elements[a].key == k)
    {
      M->Elements[a].key = Undefined;
      return;
    }
    if (M->Elements[a].key == Undefined)
    {
      return;
    }
  }
}
// int main()
// {
//   HashMap M;
//   CreateEmpty(&M);  // init with undefined values
//   Insert(&M, 1, 2); // map, key, value
//   Insert(&M, 2, 3);
//   Insert(&M, 3, 4);
//   Insert(&M, 123, 123);
//   printf("%d\n", Value(M, 1)); // get value with key 1
//   printf("%d\n", Value(M, 2));
//   printHashMap(M); // print all elements in the map

//   return 0;
// }