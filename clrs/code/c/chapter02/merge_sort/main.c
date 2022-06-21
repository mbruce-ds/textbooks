#include <stdio.h>
#include <limits.h>

int * merge(int * array, int p, int q, int r) {
    int n_1 = q - p + 1;
    int n_2 = r - q;
    int L[n_1 + 1];
    int R[n_2 + 1];

    // Populate left, right arrays with subarray values
    // from array
    for (int i = 0; i < n_1; i++) {
        L[i] = array[p + i];
    }

    for (int i = 0; i < n_2; i++) {
        R[i] = array[q + i + 1];
    }

    // Sentinel values
    L[n_1] = INT_MAX; 
    R[n_2] = INT_MAX;

    int i = 0;
    int j = 0;

    // Merge together L, R into array
    for (int k = p; k <= r; k++) {
        if (L[i] < R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
    }

    return array;
}

int * merge_sort(int * array, unsigned int p, unsigned int r) {
    if (p < r) {
        int q = (p + r) / 2; // p, r unsigned, guaranteed to be floor div
        array = merge_sort(array, p, q);
        array = merge_sort(array, q + 1, r);
        array = merge(array, p, q, r);
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

    int * sorted_array = merge_sort(array_to_sort, 0, array_len-1);
    
    printf("Sorted array: ");
    for (int i = 0; i < array_len; i++){
        printf("%d ", sorted_array[i]);
    }
    printf("\n");
    return 0;
}