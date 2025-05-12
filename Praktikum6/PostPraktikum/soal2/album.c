
#include "album.h"
void CreateEmptyAlbum(Album *A)
{
  A->Count = 0;
}
boolean IsEmptyAlbum(Album A)
{
  return (A.Count == 0);
}
boolean IsFullAlbum(Album A)
{
  return (A.Count == MaxElSong);
}

boolean IsSongInAlbum(Album A, char SongTitle[])
{
  for (int i = 0; i < A.Count; i++)
  {
    if (!strcmp(A.Songs[i], SongTitle))
    {
      return true;
    }
  }
  return false;
}

int cmpstr(const void *a, const void *b)
{
  const char *sa = (const char *)a;
  const char *sb = (const char *)b;
  return strcmp(sa, sb);
}
void SortAlbum(Album *A)
{
  qsort((*A).Songs, (*A).Count, sizeof((*A).Songs[0]), cmpstr);
}
void InsertSong(Album *A, char SongTitle[])
{
  if (IsSongInAlbum(*A, SongTitle))
    return;
  strcpy(A->Songs[A->Count], SongTitle);
  A->Count++;
  SortAlbum(A);
}
void DeleteSong(Album *A, char SongTitle[])
{
  for (int i = 0; i < A->Count; i++)
  {
    if (strcmp(A->Songs[i], SongTitle) == 0)
    {
      for (int j = i + 1; j < A->Count; j++)
      {
        strcpy(A->Songs[j - 1], A->Songs[j]);
      }
      A->Count--;
      break;
    }
  }
}
Album UnionAlbum(Album A1, Album A2)
{
  Album A;
  CreateEmptyAlbum(&A);
  Album highA = A1.Count > A2.Count ? A1 : A2;
  Album lowA = A1.Count <= A2.Count ? A1 : A2;
  for (int i = 0; i < highA.Count; i++)
  {
    strcpy(A.Songs[i], highA.Songs[i]);
    A.Count++;
  }
  for (int i = 0; i < lowA.Count; i++)
  {
    int same = 0;
    for (int j = 0; j < highA.Count; j++)
    {
      if (strcmp(highA.Songs[j], lowA.Songs[i]) == 0)
      {
        same = 1;
        break;
      }
    }
    if (same)
    {
      continue;
    }
    strcpy(A.Songs[A.Count], lowA.Songs[i]);
    A.Count++;
  }
  return A;
}
Album IntersectionAlbum(Album A1, Album A2)
{
  Album A;
  CreateEmptyAlbum(&A);
  for (int i = 0; i < A1.Count; i++)
  {
    for (int j = 0; j < A2.Count; j++)
    {
      if (strcmp(A2.Songs[j], A1.Songs[i]) == 0)
      {
        strcpy(A.Songs[A.Count], A1.Songs[i]);
        A.Count++;
        break;
      }
    }
  }
  return A;
}
Album DifferenceAlbum(Album A1, Album A2)
{
  Album A;
  CreateEmptyAlbum(&A);
  for (int i = 0; i < A1.Count; i++)
  {
    int same = 0;
    for (int j = 0; j < A2.Count; j++)
    {
      if (strcmp(A2.Songs[j], A1.Songs[i]) == 0)
      {
        same = 1;
        break;
      }
    }
    if (!same)
    {
      strcpy(A.Songs[A.Count], A1.Songs[i]);
      A.Count++;
    }
  }
  return A;
}
void PrintAlbum(Album A)
{
  printf("{");
  for (int i = 0; i < A.Count - 1; i++)
  {
    printf("%s, ", A.Songs[i]);
  }
  printf("%s", A.Songs[A.Count - 1]);
  printf("}\n");
}