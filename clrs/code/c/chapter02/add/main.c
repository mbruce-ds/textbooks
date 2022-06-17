#include <stdio.h>

int * add(int* A, int* B, int length) {
    int S[length + 1];
    int carry = 0;
    for (int i = length; i > 0; i--) {
        int sum = A[i] + B[i] + carry;
        if (sum % 2 == 1) {
            S[i+1] = 1;
        }
        if (sum >= 2) {
            carry = 1;
        } else {
            carry = 0;
        }
    }
    S[0] = carry;
    return S;
}


int main(int argc, char* argv[]) {
    int A[] = {0, 1, 1, 0, 0, 1, 0, 0};
    int B[] = {0, 1, 1, 1, 0, 0, 0, 1};

    int length_a = sizeof(A) / sizeof(A[0]);
    int length_b = sizeof(B) / sizeof(B[0]);

    if (length_a != length_b) {
        printf("Both arrays must be same length\n");
        return 1;
    }

    int * S = add(A, B, length_a);
    
    for (int i = 0; i <= length_a; i++) {
        printf("%d ", S[i]);
    }
    printf("\n");

    return 0;
}