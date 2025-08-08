#pragma once
#include "camp_array.h"

typedef struct {
    CampArray* queue; 
} CampQueue;

CampQueue* camp_queue_new(size_t type_size);

// dumps the queue
void camp_queue_dump(CampQueue* queue);

// pushes item onto the queue
void camp_queue_push(CampQueue* queue, void* item);

// memcpy into item and frees the first one one the queue
void camp_queue_pop(CampQueue* queue, void* item);

// free the queue
void camp_queue_destroy(CampQueue* queue);
