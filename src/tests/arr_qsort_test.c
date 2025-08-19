#include "../camp.h"
#include "tests.h"

int arr_qsort_test(void) {
    camp_rand_init();
    
    CampArray* my_arr = camp_array_new(sizeof(int));

    for (int i = 10; i > 0; --i) {
        int x = camp_rand_range(0, 100);
        camp_array_append(my_arr, &x);
    }

    camp_array_dump(my_arr);

    camp_qsort(my_arr, camp_qsort_compare_ints_asc);

    camp_array_dump(my_arr);

    return 0; 
}


