#include <stdio.h>

// this is just for consistency sake
#include "../src/camp.h"

int main(void) {
    CampArray* my_arr = camp_array_new(sizeof(int));
    
    for (size_t i = 0; i < 100; i++) {
        camp_array_append(my_arr, &i);
    }

    camp_array_dump(my_arr);

    camp_array_destroy(my_arr);
    return 0;
}
