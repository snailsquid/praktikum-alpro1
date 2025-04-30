#include "hashmap.h"
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

valuetype Value(HashMap M, int key)
{
  for (int i = 0; i < M.Count; i++)
  {
    if (M.Elements[i].key == key)
    {
      return M.Elements[i].value;
    }
  }
  return Undefined;
}
address Hash(keytype K)
{
  return &K;
}
void Insert(HashMap *M, keytype key, valuetype value)
{
  int Count = M->Count;
  infotype infotype;
  infotype.key = key;
  infotype.value = value;
  M->Elements[Count + 1] = infotype;
  M->Count++;
}

void printHashMap(HashMap M)
{
  for (int i = 0; i < MaxEl; i++)
  {
    infotype it = M.Elements[i];
    printf("%d:\n  Key: %d\n  Value: %d\n", i, it.key, it.value);
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