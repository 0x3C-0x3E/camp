#include "camp_stack.h"
#include "camp_array.h"
#include <string.h>

CampStack* camp_stack_new(size_t type_size) {
    CampStack* new_stack = (CampStack*) malloc(sizeof(CampStack));
    new_stack->stack = camp_array_new(type_size);

    return new_stack;
}

// dumps the stack
void camp_stack_dump(CampStack* stack) {
    camp_array_dump(stack->stack);
}

// pushes item onto the stack
void camp_stack_push(CampStack* stack, void* item) {
    camp_array_append(stack->stack, item);
}

// memcpy into item and frees the last one one the stack
void camp_stack_pop(CampStack* stack, void* item) {
    void* target = camp_array_get(stack->stack, stack->stack->size - 1);
    memcpy(item, target, stack->stack->type_size);
    camp_array_remove(stack->stack, stack->stack->size - 1);
}

// free the stack
void camp_stack_destroy(CampStack* stack) {
    camp_array_destroy(stack->stack);
    free(stack);
}
