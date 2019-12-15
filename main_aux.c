
#include <stdio.h>
/* just print heaps status */
int print_heap( int *whole_array_pointer, int heaps_size_input,int turn ) {
    int  i = 0 ;
    printf("In turn %d heap sizes are:", turn) ;
    for (i = 0; i < heaps_size_input;i++) {
        printf(" h%d=%d",i+1,whole_array_pointer[i]);
    }
    printf(".\n");
    return 0;
}

/* helper function to determine if move is legal - input wise (EOF, input type..) and game status (cannot take more than current heap size) */
int check_validity( int *whole_array_pointer,int heap_size_input, int heap_number, int reduce, int scan_result) {
    if (scan_result == EOF || feof(stdin)){
        printf("ERROR: Invalid input.\nPlease enter again the heap index and the number of removed objects:\n");
        return 0;
    }
    else if ((heap_number < 0) || (heap_number > heap_size_input) || (reduce <= 0) || (reduce > whole_array_pointer[heap_number-1])) {
        printf("ERROR: Invalid input.\nPlease enter again the heap index and the number of removed objects:\n");
        return 0;
    }
    else { return 1 ;}

}





