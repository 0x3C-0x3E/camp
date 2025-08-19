#pragma once
#include "../camp_array.h"

// Note this currently only works on camp_array
// not even on those cause i didnt implement it yet! 


int camp_qsort_compare_ints_asc(void* item1, void* item2);

int camp_qsort_compare_ints_des(void* item1, void* item2);

// Note comparison_func should return -1 if item1 < item2, 0 if equal, and 1 if item1 > item2 IF sorting from lowest to highest
// see camp_qsort_compare_ints() for refrence
void camp_qsort(CampArray* array, int (comparison_func)(void* item1, void* item2));
