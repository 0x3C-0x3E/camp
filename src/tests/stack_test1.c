#include "../camp.h"
#include "tests.h"

int stack_test1(void) {
    CampStack* stack = camp_stack_new(sizeof(char));
    
    for (size_t i = 0; i < 26; ++i) {
        char new_char = 'a' + i;
        camp_stack_push(stack, &new_char);
    }
    
    printf("Stack size: %zu\n", camp_stack_get_size(stack));

    for (size_t i = 0; i < camp_stack_get_size(stack); ++i) {
        char c = '.';
        camp_stack_pop(stack, &c);
        printf("%zu: %c\n", i, c);
    }

    printf("\n");

    return 0;
}
