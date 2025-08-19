#include "stdio.h"
#include "tests/tests.h"

int main(void) {
    printf("-- Starting LL test 1--\n");

    if (arr_qsort_test() == 1) {
        printf("FAILED TEST!\n");
        return 1;
    }
    return 0;
}
