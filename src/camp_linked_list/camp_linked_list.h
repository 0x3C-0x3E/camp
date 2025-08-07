#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// NOTE: ll stands for linked list

typedef struct CampLLNode CampLLNode;

struct CampLLNode{
    void* data;

    // CampLLNode* prev; // TODO: maybe do this?
    CampLLNode* next;
};

typedef struct {
    size_t list_size;

    size_t data_size;

    CampLLNode* head_node;
    CampLLNode* tail_node;
} CampLL;

// returns a ptr to the new linked list
CampLL* camp_ll_new(size_t data_size);

// inserts as the first element, O(1)
void camp_ll_insert_at_head(CampLL* list, void* data);

// inserts as the last element, O(1)
void camp_ll_insert_at_tail(CampLL* list, void* data);

// dumps the linked list
void camp_ll_dump(CampLL* list);

// returns the data from the node at the given index, O(n)
void* camp_ll_get_at_index(CampLL* list, size_t index);

// free the list and all the nodes
void camp_ll_destroy(CampLL* list);
