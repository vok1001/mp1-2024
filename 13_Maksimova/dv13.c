#include <stdio.h>
#include <locale.h>


void mat(int m[100][100], int* a, int* b) {
    setlocale(LC_ALL, "Rus");
    printf("Введите количество строк: ");
    scanf_s("%d", a);
    printf("Введите количество столбцов: ");
    scanf_s("%d", b);

    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < *a; i++) {
        for (int j = 0; j < *b; j++) {
            scanf_s("%d", &m[i][j]);
        }
    }
}

void minrow(int m[100][100], int* a, int b) {
    int minRow = 0;
    int minel = m[0][0];

    // Находим минимальный элемент и его строку
    for (int i = 0; i < *a; i++) {
        for (int j = 0; j < b; j++) {
            if (m[i][j] < minel) {
                minel = m[i][j];
                minRow = i;
            }
        }
    }

    // Удаляем строку с минимальным элементом
    for (int i = minRow; i < *a - 1; i++) {
        for (int j = 0; j < b; j++) {
            m[i][j] = m[i + 1][j];
        }
    }
    (*a)--; // Уменьшаем количество строк
}

void vivod(int m[100][100], int a, int b) {
    printf("Матрица после удаления:\n");
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m[100][100];
    int a, b;

    mat(m, &a, &b);
    minrow(m, &a, b);
    vivod(m, a, b);

    return 0;
}