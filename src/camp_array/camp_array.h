#pragma once
#include "../config.h"
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    void* data;
    size_t size;
    size_t capacity;

    size_t type_size;
} CampArray;

CampArray* camp_array_new(size_t type_size);

void camp_array_dump(CampArray* array);

void camp_array_append(CampArray* array, void* item);

void camp_array_insert(CampArray* array, size_t index, void* item);

void* camp_array_get(CampArray* array, size_t index);

void camp_array_set(CampArray* array, size_t index, void* item);

void camp_array_remove(CampArray* array, size_t index);

size_t camp_array_get_size(CampArray* array);

bool camp_array_is_empty(CampArray* array);

void camp_array_clear(CampArray* array);

void camp_array_reset(CampArray* array);

void camp_array_destroy(CampArray* array);

