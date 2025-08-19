#include "camp_qsort.h"

int camp_qsort_compare_ints_asc(void* item1, void* item2) {
    int int1 = *(int*) item1;
    int int2 = *(int*) item2;

    if (int1 < int2) {
        return -1;
    } else if (int1 > int2) {
        return 1;
    }

    return 0;
}

int camp_qsort_compare_ints_des(void* item1, void* item2) {
    int int1 = *(int*) item1;
    int int2 = *(int*) item2;

    if (int1 > int2) {
        return -1;
    } else if (int1 < int2) {
        return 1;
    }

    return 0;
}

static void qsort_step() {

}

void camp_qsort(CampArray* array, int (comparison_func)(void* item1, void* item2)) {
    printf("\nSTARTING QSORT!\n\n");
    // pivot is the rightmost because computerphile said so :P
    void* pivot = camp_array_get(array, camp_array_get_size(array) - 1);

    void* left[camp_array_get_size(array)];
    size_t left_size = 0;
    void* right[camp_array_get_size(array)];
    size_t right_size = 0;


    for (size_t i = 0; i < camp_array_get_size(array) - 2; ++i) {
        int result = comparison_func(camp_array_get(array, i), pivot);

        if (result <= 0) {
            left[left_size] = camp_array_get(array, i);
            left_size ++;
        } else {
            right[right_size] = camp_array_get(array, i);
            right_size ++;
        }
    }

}
