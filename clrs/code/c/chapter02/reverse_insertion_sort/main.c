#include <stdio.h>

int * sort_array(int * array, int array_len){
    for (int j = 1; j < array_len; j++){
        int key = array[j];
        int i = j - 1;
        while (i >= 0 && array[i] < key){
            array[i + 1] = array[i];
            --i;
        }
        array[i + 1] = key;
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

    for (int i = 0; i < array_len; i++){
        printf("%d\n", array_to_sort[i]);
    } 

    int * sorted_array = sort_array(array_to_sort, array_len);
    
    printf("Sorted array: ");
    for (int i = 0; i < array_len; i++){
        printf("%d ", sorted_array[i]);
    }
    printf("\n");
    return 0;
}