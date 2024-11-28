#include <stdio.h>
#include <locale.h>



void Grades(int grades[100][3], int* n) {
    setlocale(LC_ALL, "Rus");
    printf("Введите количество студентов: ");
    scanf_s("%d", n);

    printf("Введите оценки студентов (1 - неявка, 2 - неудовлетворительная, 3 - удовлетворительная, 4 - хорошая, 5 - отличная):\n");
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < 3; j++) {
            scanf_s("%d", &grades[i][j]);
        }
    }
}

void Statistics(int grades[100][3], int n) {
    int absence_count[3] = { 0 };
    int unsatisfactory_count[3] = { 0 };
    int satisfactory_count[3] = { 0 };
    int good_count[3] = { 0 };
    int excellent_count[3] = { 0 };

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < n; i++) {
            switch (grades[i][j]) {
            case 1:
                absence_count[j]++;
                break;
            case 2:
                unsatisfactory_count[j]++;
                break;
            case 3:
                satisfactory_count[j]++;
                break;
            case 4:
                good_count[j]++;
                break;
            case 5:
                excellent_count[j]++;
                break;
            default:
                printf("Некорректная оценка: %d\n", grades[i][j]);
                break;
            }
        }
    }

    // Вывод результатов
    printf("\nРезультаты по экзаменам:\n");
    for (int j = 0; j < 3; j++) {
        printf("Экзамен %d:\n", j + 1);
        printf("Неявки: %d\n", absence_count[j]);
        printf("Неудовлетворительных: %d\n", unsatisfactory_count[j]);
        printf("Удовлетворительных: %d\n", satisfactory_count[j]);
        printf("Хороших: %d\n", good_count[j]);
        printf("Отличных: %d\n", excellent_count[j]);
    }
}

int main() {
    int grades[100][3];
    int n;

    Grades(grades, &n);
    Statistics(grades, n);

    return 0;
}