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

CampLL* camp_ll_new(size_t data_size);

void camp_ll_insert_at_head(CampLL* list, void* data);

void camp_ll_insert_at_tail(CampLL* list, void* data);

void camp_ll_dump(CampLL* list);

void camp_ll_destroy(CampLL* list);
