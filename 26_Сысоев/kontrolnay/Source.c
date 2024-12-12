#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

bool contains(int *arr, int value, int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

void sum_dioganals(int matrix[3][3], int n, int *sums) {
    for (int i = 0; i < 2*n-1; i++) {
        sums[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int di = n - 1 + (i - j);
            sums[di] += matrix[i][j];
        }
    }

}

int main3() {
    //задача 5.1
  
    int n = 3;
    int matrix[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
    int *sums = malloc((2 * n - 1) * sizeof(int));
    
    sum_dioganals(matrix, n, sums);

    
    for (int i = 0; i < (2 * n - 1); i++) {
        printf("%d\n", sums[i]);
    }

    free(sums);

    return 0;
}

int main2() {
    // задача 4.3
    int arr1[] = { 2, 5, 8 };
    int arr2[] = { 8, 5, 7 };
    int size = sizeof(arr2) / sizeof(arr2[0]);
    int arr12[sizeof(arr1) / sizeof(arr1[0])];
    int c = 0;

    for (int i = 0; i < size; ++i) {
        if (contains(arr2, arr1[i], size)) {
            arr12[c++] = arr1[i];
        }
    }

    for (int i = 0; i < c; ++i) {
        printf("%d\n", arr12[i]);
    }

    return 0;
}


int main() {
    // задача 4.2
    
    int arr1[] = { 2, 5, 8 };
    int arr2[] = { 8, 5, 7 };

    int size_arr1 = sizeof(arr1) / sizeof(arr1[0]);
    int size_arr2 = sizeof(arr2) / sizeof(arr2[0]);

    int* arr12 = (int*)malloc((size_arr1 + size_arr2) * sizeof(int));
    int size_arr12 = 0;

    for (int i = 0; i < size_arr1; i++) {
        if (!contains(arr12, arr1[i], size_arr12)) {
            arr12[size_arr12] = arr1[i];
            size_arr12 += 1;

        }
    }

    for (int i = 0; i < size_arr2; i++) {
        if (!contains(arr12, arr2[i],size_arr12 )) {
            arr12[size_arr12] = arr2[i];
            size_arr12 += 1;

        }
    }

    for (int i = 0; i < size_arr12; i++) {
        printf("%d\n", arr12[i]);
    }

    free(arr12);
    
    return 0;
}

