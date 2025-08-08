#include "../camp.h"
#include "tests.h"

int ll_test1(void) {
    CampLL* list = camp_ll_new(sizeof(int));
    
    int i = 0;
    camp_ll_insert_at_head(list, &i);

    for (i = 1; i < 10; ++i) {
        camp_ll_insert_at_tail(list, &i);
    }
    
    camp_ll_remove_tail(list);
    camp_ll_remove_head(list);

    for (size_t j = 0; j < 10; ++j) {
        if (j%2 == 0) {
            camp_ll_remove_at_index(list, j);
        }
    }

    int* x = (int*) camp_ll_get_at_index(list, 3);
    printf("x at index 3 is %d\n", *x);

    size_t list_size = camp_ll_get_list_size(list);
    printf("List size: %zu\n", list_size);


    camp_ll_dump(list);    
    camp_ll_destroy(list);
    return 0;
}
