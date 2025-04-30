#include "map.h"
#include <stdio.h>

Map *create_map(int capacity)
{
  Map *m = malloc(sizeof(Map));
  if (m == NULL)
    return NULL;
  m->entries = (MapEntry *)malloc(sizeof(MapEntry) * capacity);
  m->capacity = capacity;
  m->size = 0;
  return m;
}
bool map_insert(Map *map, int key, const char *value)
{
  if (map->size >= map->capacity)
  {
    return false;
  }
  int index = map->size;
  map->entries[index].key = key;

  map->entries[index].value = malloc(strlen(value) + 1);
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
  int index = -1;
  for (int i = 0; i < map->size; i++)
  {
    MapEntry entry = map->entries[i];
    if (entry.key == key)
    {
      index = i;
      break;
    }
  }
  if (index != -1)
  {
    for (int i = index + 1; i < map->size; i++)
    {
      map->entries[i - 1] = map->entries[i];
    }
    map->size--;
    return true;
  }
  else
  {
    return false;
  }
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