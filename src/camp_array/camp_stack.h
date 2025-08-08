#pragma once
#include "camp_array.h"

// NOTE: this is just a wrapper class for CampArray 
// specifically for stacks

typedef struct {
    CampArray* stack;
} CampStack;

CampStack* camp_stack_new(size_t type_size);

// dumps the stack
void camp_stack_dump(CampStack* stack);

// pushes item onto the stack
void camp_stack_push(CampStack* stack, void* item);

// memcpy into item and frees the last one one the stack
void camp_stack_pop(CampStack* stack, void* item);

// free the stack
void camp_stack_destroy(CampStack* stack);
