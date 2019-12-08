
#ifndef HW2_SP_NIM_H
#define HW2_SP_NIM_H



int is_empty(int *whole_array_pointer , int heaps_number) ;

int calculate_nim_sum(int *whole_array_pointer , int heaps_number) ;

int calculate_heap_nim_sum (int *whole_array_pointer, int heap_index, int heaps_number);

int check_winning_heap(int *whole_array_pointer,int heap_index,int nim_sum, int heap_nim_sum) ;

int find_min_winning_heap(int *whole_array_pointer,int heaps_number) ;

int computer_move(int *whole_array_pointer,int heaps_number) ;

int find_min_positive_heap(int *whole_array_pointer,int heaps_number) ;

int user_move(int *whole_array_pointer, int heap_index, int reduce) ;

int user_turn(int *whole_array_pointer,int heaps_number) ;

#endif /* HW2_SP_NIM_H */
