#include "../camp.h"
#include "tests.h"

int arr_test1(void) {
    CampArray* my_arr = camp_array_new(sizeof(int));
    
    for (size_t i = 0; i < 10; i++) {
        camp_array_append(my_arr, &i);
    }

    for (size_t i = 9; i > 0; --i) {
        if (i % 2 == 0) {
            camp_array_remove(my_arr, i);
        }
    }

    int item = 5;
    camp_array_insert(my_arr, 0, &item);

    printf("%d\n", *(int*)camp_array_get(my_arr, 0));
    
    item = 99;
    camp_array_set(my_arr, 1, &item);

    camp_array_dump(my_arr);

    camp_array_destroy(my_arr);
    
    return 0;
}
