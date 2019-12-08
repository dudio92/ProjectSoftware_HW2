
#include <stdio.h>
int is_empty(int *whole_array_pointer , int heaps_number) {
    int i = 0 ;
    for ( i = 0; i <heaps_number ; i++) {
        if (whole_array_pointer[i] != 0 ) {
            return 0;
        }
    }
    return 1;
}

int calculate_nim_sum(int *whole_array_pointer , int heaps_number) {
    int i = 0 ;
    int xor = 0 ;
    for (i = 0; i <heaps_number ; i++) {
        xor = xor ^ (whole_array_pointer[i]) ;
    }
    return xor;
}

int calculate_heap_nim_sum (int *whole_array_pointer, int heap_index, int heaps_number) {
    int nim_sum = calculate_nim_sum(whole_array_pointer,heaps_number) ;
    int heap_nim_sum =  whole_array_pointer[heap_index] ^ nim_sum ;
    return heap_nim_sum ;
}

int check_winning_heap(int *whole_array_pointer,int heap_index, int heaps_number) {
    int heap_nim_sum = calculate_heap_nim_sum(whole_array_pointer,heap_index,heaps_number) ;
    if (heap_nim_sum < whole_array_pointer[heap_index]) { return 1;}
    else { return 0;}
}

int find_min_winning_heap(int *whole_array_pointer,int heaps_number) {
    int min = 100 ; /* Using in as "+inifinity" - want to iterate and save the minimum index at the same time */
    int i = 0 ;
    for (i = 0; i <heaps_number ; i++) {
        if (check_winning_heap(whole_array_pointer,i,heaps_number) == 1 ) {
            min = i ;
            return min ;
        }
    }
    return -1;
}

int find_min_positive_heap(int *whole_array_pointer,int heaps_number) {
    int min = 100 ;
    int i = 0 ;
    for (i = 0; i <heaps_number ; i++) {
        if (whole_array_pointer[i] > 0) {
            min = i ;
            return min ;
        }
    }
    return -1;
}


int computer_move(int *whole_array_pointer,int heaps_number) {
    int nim_sum = calculate_nim_sum(whole_array_pointer,heaps_number) ;
    if (nim_sum != 0) {
        int min_heap_index = find_min_winning_heap(whole_array_pointer,heaps_number);
        int to_remove = whole_array_pointer [min_heap_index]  - calculate_heap_nim_sum(whole_array_pointer,min_heap_index,heaps_number);
        whole_array_pointer [min_heap_index] = whole_array_pointer [min_heap_index] - to_remove ;
        printf("Computer takes %d objects from heap %d.\n",to_remove,min_heap_index+1);

    }
    else {
        int min_positive_heap = find_min_positive_heap(whole_array_pointer,heaps_number) ;
        whole_array_pointer[min_positive_heap] = whole_array_pointer[min_positive_heap] -1 ;
        printf("Computer takes %d objects from heap %d.\n",1,min_positive_heap+1);
    }
    return 1;
}

int user_move(int *whole_array_pointer, int heap_index, int reduce) {
    whole_array_pointer[heap_index-1] = whole_array_pointer[heap_index-1] - reduce ;
    printf("You take %d objects from heap %d.\n",reduce,heap_index) ;
    return 1;
}

int user_turn(int *whole_array_pointer,int heaps_number) {

}






