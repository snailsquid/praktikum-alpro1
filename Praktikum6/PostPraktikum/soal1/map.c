#include "map.h"
#include <stdio.h>

Map *create_map(int capacity)
{
  Map *m = malloc(sizeof(Map));
  if (m == NULL)
    return NULL;
  m->entries = (MapEntry *)malloc(sizeof(MapEntry) * capacity);
  if (m->entries == NULL)
    return false;
  m->capacity = capacity;
  m->size = 0;
  return m;
}
// bool map_insert(Map *map, int key, const char *value)
// {
//   if (map == NULL || value == NULL)
//     return false;

//   for (int i = 0; i < map->size; i++)
//   {
//     if (map->entries[i].key == key)
//     {
//       free(map->entries[i].value);
//       map->entries[i].value = malloc(strlen(value) + 1);
//       if (map->entries[i].value == NULL)
//         return false;
//       strcpy(map->entries[i].value, value);
//       return true;
//     }
//   }

//   if (map->size >= map->capacity)
//     return false;

//   int index = map->size;
//   map->entries[index].key = key;
//   map->entries[index].value = malloc(strlen(value) + 1);
//   if (map->entries[map->size].value == NULL)
//     return false;
//   strcpy(map->entries[index].value, value);
//   map->size++;
//   return true;
// }

int binary_search(const Map *map, int key)
{
  int high = map->size - 1, low = 0;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (map->entries[mid].key == key)
      return mid;
    if (map->entries[mid].key < key)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

char *map_get(const Map *map, int key)
{
  int index = binary_search(map, key);
  if (index != -1)
    return map->entries[index].value;
  return NULL;
}

bool shift_insert(Map *map, int key, int index, const char *value)
{
  // printf("inserting %s with key '%d' into [%d]\n", value, key, index);
  if (map->size + 1 > map->capacity)
    return false;
  int size = map->size;
  for (int i = size - 1; i > index; i--)
  {
    map->entries[i + 1].key = map->entries[i].key;
    free(map->entries[i + 1].value);
    map->entries[i + 1].value = malloc(strlen(map->entries[i].value) + 1);
    if (map->entries[i + 1].value == NULL)
      return false;
    strcpy(map->entries[i + 1].value, map->entries[i].value);
  }
  map->entries[index].key = key;
  free(map->entries[index].value);
  map->entries[index].value = malloc(strlen(value) + 1);
  if (map->entries[index].value == NULL)
    return false;
  strcpy(map->entries[index].value, value);
  map->size++;
  return true;
}

bool map_insert(Map *map, int key, const char *value)
{
  int high = map->size - 1, low = 0, mid = 0, last = mid;
  while (low <= high)
  {
    mid = low + (high - low) / 2;

    if (map->entries[mid].key == key)
    {
      free(map->entries[key].value);
      map->entries[key].value = malloc(strlen(value) + 1);
      if (map->entries[key].value == NULL)
        return false;
      strcpy(map->entries[key].value, value);
      return true;
    }
    if (map->entries[mid].key < key)
    {
      low = mid + 1;
      last = low;
    }
    else
    {
      high = mid - 1;
      last = high;
    }
    // printf("mid : %d\nhigh : %d\nlow : %d\n---------\n", mid, high, low);
  }
  // printf("key not found, inserting new\n");
  return shift_insert(map, key, last, value);
}
// char *map_get(const Map *map, int key)
// {
//   for (int i = 0; i < map->size; i++)
//   {
//     MapEntry entry = map->entries[i];
//     if (entry.key == key)
//     {
//       return map->entries[i].value;
//     }
//   }
//   return NULL;
// }
bool map_delete(Map *map, int key)
{
  int index = binary_search(map, key);
  if (index == -1)
    return false;
  free(map->entries[key].value);
  for (int j = index + 1; j < map->size; j++)
  {
    map->entries[j - 1] = map->entries[j];
  }
  map->size--;
  return true;
}

// bool map_delete(Map *map, int key)
// {
//   for (int i = 0; i < map->size; i++)
//   {
//     MapEntry entry = map->entries[i];
//     if (entry.key == key)
//     {
//       free(map->entries[i].value);
//       for (int j = i + 1; j < map->size; j++)
//       {
//         map->entries[j - 1] = map->entries[j];
//       }
//       map->size--;
//       return true;
//     }
//   }
//   return false;
// }
int map_size(const Map *map)
{
  return map->size;
}
bool map_contains_key(const Map *map, int key)
{
  for (int i = 0; i < map->size; i++)
  {
    if (map->entries[i].key == key)
      return true;
  }
  return false;
}