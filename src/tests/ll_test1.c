#include "../camp.h"
#include "tests.h"

int ll_test1(void) {
    CampLL* list = camp_ll_new(sizeof(int));
    
    int i = 5;
    camp_ll_insert_at_head(list, &i);

    for (i = 6; i < 10; ++i) {
        camp_ll_insert_at_head(list, &i);
    }

    camp_ll_dump(list);    
    camp_ll_destroy(list);
    return 0;
}
