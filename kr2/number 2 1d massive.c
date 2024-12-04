#include <stdio.h>
#include <stdlib.h>



int proverka(int a[], int n, int index) {
    for (int i = 0; i < n; i++) {
        if (a[i] == index) {
            return 0;
        }
    }
    return 1;
}

void Sort_vstavkami(int a[], int n)
{
    int i;
    for (i = 1; i < n; i++) {
        int x = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > x) {
            a[j] = a[j - 1];
            j--;

        }
        a[j] = x;
    }

}



int main() {
    int n, m, chislo;
    scanf_s("%d %d", &n, &m);
    int* a;
    int* b;
    int* c;


    a = (int*)malloc(sizeof(int) * n);
    b = (int*)malloc(sizeof(int) * m);
    c = (int*)malloc(sizeof(int) * (n + m));
    chislo = n;
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &a[i]);
    }
    printf("Vvedu 2 massive:\n");
    for (int i = 0; i < m; i++) {
        scanf_s("%d", &b[i]);
    }
    for (int i = 0; i < n; i++) {
        c[i] = a[i];
    }
    for (int i = 0; i < m; i++) {
        if (proverka(a, n, b[i])) {
            c[chislo] = b[i];
            chislo++;
        }
    }
    printf("%d\n", chislo);
    Sort_vstavkami(c, chislo);
    for (int i = 0; i < chislo; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");
}