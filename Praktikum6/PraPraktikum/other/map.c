#include <stdio.h>
#include "map.h"

Map *create_map(int capacity) {
    Map *map = malloc(sizeof(Map));
    if (map == NULL) return NULL;
    map->size = 0;
    map->capacity = capacity;
    map->entries = malloc(capacity * sizeof(MapEntry));
    if (map->entries == NULL) {
        free(map);
        return NULL;
    }
    return map;
}

bool map_insert(Map *map, int key, const char *value) {
    if (map == NULL || value == NULL) return false;

    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            free(map->entries[i].value);
            map->entries[i].value = malloc(strlen(value) + 1);
            if (map->entries[i].value == NULL) return false;
            strcpy(map->entries[i].value, value);
            return true;
        }
    }

    if (map->size >= map->capacity) return false;

    map->entries[map->size].key = key;
    map->entries[map->size].value = malloc(strlen(value) + 1);
    if (map->entries[map->size].value == NULL) return false;
    strcpy(map->entries[map->size].value, value);
    map->size++;
    return true;
}

char *map_get(const Map *map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            return map->entries[i].value;
        }
    }
    return NULL;
}

bool map_delete(Map *map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            free(map->entries[i].value);
            for (int j = i; j < map->size - 1; j++) {
                map->entries[j] = map->entries[j + 1];
            }
            map->size--;
            return true;
        }
    }
    return false;
}

int map_size(const Map *map) {
    return map->size;
}

bool map_contains_key(const Map *map, int key) {
    return (map_get(map, key) != NULL);
}
