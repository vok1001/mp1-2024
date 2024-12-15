#include "stdio.h"
#include "stdlib.h"

int main() {
    int i, j;
    int n, m;
    int** arr;
    printf("seat empty = 0\n");
    printf("seat taken = 1");
    scanf_s("VAGON %d\nMESTA %d", n, m);
    arr = (int**)malloc(sizeof(int*) * n);
    for (i = 0; i < n; i++) {
        arr[i] = (int*)malloc(sizeof(int) * m);
        for (j = 0; j < m; j++) {
            scanf_s("%d", arr[i][j]);
        }
    }


    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
}