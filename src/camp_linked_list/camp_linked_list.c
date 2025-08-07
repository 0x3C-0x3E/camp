#include "camp_linked_list.h"

CampLL* camp_ll_new(size_t data_size) {
    CampLL* list = (CampLL*) malloc(sizeof(CampLL));
    
    *list = (CampLL) {
        .list_size = 0,
        .data_size = data_size,

        .head_node = NULL,
        .tail_node = NULL,
    };

    return list;
}

void camp_ll_destroy(CampLL* list) {
    if (list->head_node == NULL) {free(list); return;}

    CampLLNode* next_node = list->head_node->next;
    CampLLNode* curr_node = list->head_node;

    while (curr_node != NULL) {
        next_node = curr_node->next;
        free(curr_node);
        curr_node = next_node;
    }

    free(list);
}

void camp_ll_insert_at_head(CampLL* list, void* data) {
    CampLLNode* new_node = (CampLLNode*) malloc(sizeof(CampLLNode));
    if (new_node == NULL) {printf("malloc failed!\n"); return;}

    *new_node = (CampLLNode) {
        .next = list->head_node, 
        .data = malloc(list->data_size),
    };

    if (new_node->data == NULL) {printf("malloc failed!\n"); return;}

    memcpy(new_node->data, data, list->data_size);

    list->head_node = new_node;
    if (list->tail_node == NULL) {
        list->tail_node = new_node;
    }

    list->list_size ++;
}

void camp_ll_insert_at_tail(CampLL* list, void* data) {
    CampLLNode* new_node = (CampLLNode*) malloc(sizeof(CampLLNode));
    if (new_node == NULL) {printf("malloc failed!\n"); return;}

    *new_node = (CampLLNode) {
        .next = NULL,
        .data = malloc(list->data_size),
    };

    if (new_node->data == NULL) {printf("malloc failed!\n"); return;}

    memcpy(new_node->data, data, list->list_size);

    if (list->head_node == NULL) {
        list->head_node = new_node;
        list->tail_node = new_node;
    } else {
        list->tail_node->next = new_node;
        list->tail_node = new_node;
    }

    list->list_size ++;
}

void* camp_ll_get_at_index(CampLL* list, size_t index) {
    if (index > list->list_size) {
        printf("[Error] index is %zu but list size is %zu", index, list->list_size);
    }
    
    CampLLNode* node = list->head_node;
    for (int i = 0; i < index; ++i) {
        if (node == NULL) {
            return NULL;
        }
        node = node->next;
    }

    void* final_node_data = node->data;

    return final_node_data;
}

void camp_ll_dump(CampLL* list) {
    CampLLNode* node = list->head_node;
    for (size_t i = 0; i < list->list_size; ++i) {
        if (node == NULL) {
            return;
        }
        printf("%p: %d, -> %p\n", node, *(int*) node->data, node->next);
        node = node->next;
    }
    printf("\n");
}
