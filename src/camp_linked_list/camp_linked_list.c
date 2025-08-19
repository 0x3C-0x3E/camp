#include "camp_linked_list.h"

static bool check_index(CampLL* list, size_t index);

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

void camp_ll_remove_at_index(CampLL* list, size_t index) {
    if (!check_index(list, index)) {
        return;
    }

    if (index == list->list_size - 1) {
        camp_ll_remove_tail(list);
        return;
    } else if (index == 0) {
        camp_ll_remove_head(list);
        return;
    }
    
    CampLLNode* target = camp_ll_get_node_at_index(list, index);

    CampLLNode* prev = camp_ll_get_node_at_index(list, index - 1);
    CampLLNode* next = camp_ll_get_node_at_index(list, index + 1);

    // is this really that simple?
    prev->next = next;

    free(target);

    list->list_size --;
}

void camp_ll_remove_head(CampLL* list) {
    if (list->head_node == NULL) {
        return;
    }

    if (list->head_node == list->tail_node) {
        list->head_node = NULL;
        list->tail_node = NULL;
        list->list_size --;
        return;
    }

    CampLLNode* head = list->head_node;
    CampLLNode* next = list->head_node->next;
    
    list->head_node = next;

    free(head);

    list->list_size --;
}

void camp_ll_remove_tail(CampLL* list) {
    if (list->tail_node == NULL) {
        return;
    }

    if (list->head_node == list->tail_node) {
        list->head_node = NULL;
        list->tail_node = NULL;
        list->list_size --;
        return;
    }

    CampLLNode* tail = list->tail_node;
    CampLLNode* prev = camp_ll_get_node_at_index(list, list->list_size - 2);

    prev->next = NULL;
    list->tail_node = prev;

    free(tail);
    
    list->list_size --;
}

void* camp_ll_get_at_index(CampLL* list, size_t index) {
    CampLLNode* node = camp_ll_get_node_at_index(list, index);

    return node->data;
}

CampLLNode* camp_ll_get_node_at_index(CampLL* list, size_t index) {
    if (index > list->list_size) {
        printf("[Error] index is %zu but list size is %zu", index, list->list_size);
    }
    
    CampLLNode* node = list->head_node;
    for (size_t i = 0; i < index; ++i) {
        if (node == NULL) {
            return NULL;
        }
        node = node->next;
    }

    return node;
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

size_t camp_ll_get_list_size(CampLL* list) {
    return list->list_size;
}

static bool check_index(CampLL* list, size_t index) {
    return (list->list_size < index) ? false : true;
}
