#include <stdio.h>
#include <ctype.h>
#define  HEAPS_ARRAY_SIZE 32
#include "main_aux.h"
#include "sp_nim.h"
/* this is msg */

int main() {
    int HEAPS_ARRAY[HEAPS_ARRAY_SIZE];
    int *whole_array_pointer = HEAPS_ARRAY;
    int j = 0;
    int heaps_size_input, single_heap_size, heap_index, reduce, user_input;
    int turn = 1;
    printf("Enter the number of heaps:\n");
    scanf("%d", &heaps_size_input);
    if (!(heaps_size_input >= 1) && (heaps_size_input <= 32)) {
        printf("Error: the number of heaps must be between 1 and 32.\n");
        return -1;
    } else if (heaps_size_input == EOF) { return -1; }

    printf("Enter the heap sizes:\n");
    for (j = 0; j < heaps_size_input; j++) {
        if ((scanf("%d", &single_heap_size) < 1) || (single_heap_size < 0)) {
            printf("Error: the size of heap %d should be positive.\n", j + 1);
            return -1;
        }
        HEAPS_ARRAY[j] = single_heap_size;
    }

    while (is_empty(whole_array_pointer, heaps_size_input) != 1) {
        print_heap(whole_array_pointer, heaps_size_input, turn);
        printf("Your turn: please enter the heap index and the number of removed objects:\n");
        user_input = scanf("%d%d", &heap_index, &reduce);
        while (check_validity(whole_array_pointer, heaps_size_input, heap_index, reduce, user_input) != 1) {
            user_input = scanf("%d%d", &heap_index, &reduce);
        }
        user_move(whole_array_pointer, heap_index, reduce);
        if (is_empty(whole_array_pointer, heaps_size_input) == 1) {
            printf("You win!\n");
            return 0;
        }
        turn++;

        print_heap(whole_array_pointer, heaps_size_input, turn);
        computer_move(whole_array_pointer, heaps_size_input);
        turn++;
        if (is_empty(whole_array_pointer, heaps_size_input) == 1) {
            printf("Computer wins!\n");
            return 0;
        }
    }
    return -1;
}








