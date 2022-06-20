#include <stdio.h>

int * sort_array(int * array, int array_len){
    for (int j = 0; j < array_len - 1; j++) {
        int current_min = array[j];
        int stored_val = array[j];
        int stored_index = j;
        for (int i = j + 1; i < array_len; i++) {
            if (array[i] < current_min) {
                current_min = array[i];
                stored_index = i;
            }
        }
        array[j] = current_min;
        array[stored_index] = stored_val;
    }

    return array;
}


int main(int argc, char* argv[]) {
    if (argc == 1) {
        printf("Pass some number arguments\n");
        return 1;
    }
    int array_len = argc - 1;
    int array_to_sort[array_len];
    
    for (int i = 0; i < array_len; i++){
        sscanf(argv[i+1], "%d", &array_to_sort[i]);
    }

    int * sorted_array = sort_array(array_to_sort, array_len);
    
    printf("Sorted array: ");
    for (int i = 0; i < array_len; i++){
        printf("%d ", sorted_array[i]);
    }
    printf("\n");
    return 0;
}