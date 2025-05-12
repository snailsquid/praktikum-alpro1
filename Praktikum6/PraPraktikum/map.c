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
bool map_insert(Map *map, int key, const char *value)
{
  if (map == NULL || value == NULL)
    return false;

  for (int i = 0; i < map->size; i++)
  {
    if (map->entries[i].key == key)
    {
      free(map->entries[i].value);
      map->entries[i].value = malloc(strlen(value) + 1);
      if (map->entries[i].value == NULL)
        return false;
      strcpy(map->entries[i].value, value);
      return true;
    }
  }

  if (map->size >= map->capacity)
    return false;

  int index = map->size;
  map->entries[index].key = key;
  map->entries[index].value = malloc(strlen(value) + 1);
  if (map->entries[map->size].value == NULL)
    return false;
  strcpy(map->entries[index].value, value);
  map->size++;
  return true;
}

char *map_get(const Map *map, int key)
{
  for (int i = 0; i < map->size; i++)
  {
    MapEntry entry = map->entries[i];
    if (entry.key == key)
    {
      return map->entries[i].value;
    }
  }
  return NULL;
}
bool map_delete(Map *map, int key)
{
  for (int i = 0; i < map->size; i++)
  {
    MapEntry entry = map->entries[i];
    if (entry.key == key)
    {
      free(map->entries[i].value);
      for (int j = i + 1; j < map->size; j++)
      {
        map->entries[j - 1] = map->entries[j];
      }
      map->size--;
      return true;
    }
  }
  return false;
}
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