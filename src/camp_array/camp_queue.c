#include "camp_queue.h"
#include "camp_array.h"
#include <string.h>

CampQueue* camp_queue_new(size_t type_size) {
    CampQueue* new_queue = (CampQueue*) malloc(sizeof(CampQueue));
    new_queue->queue = camp_array_new(type_size);

    return new_queue;
}

// dumps the queue
void camp_queue_dump(CampQueue* queue) {
    camp_array_dump(queue->queue);
}

// pushes item onto the queue
void camp_queue_push(CampQueue* queue, void* item) {
    camp_array_append(queue->queue, item);
}

// memcpy into item and frees the first one one the queue
void camp_queue_pop(CampQueue* queue, void* item) {
    void* target = camp_array_get(queue->queue, 0);
    memcpy(item, target, queue->queue->type_size);
    camp_array_remove(queue->queue, 0);
}

// free the queue
void camp_queue_destroy(CampQueue* queue) {
    camp_array_destroy(queue->queue);
    free(queue);
}
