#include "locale.h"
#include "windows.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>


int state;


float genRand() {
	return (float)rand();
}


void fillRandList(float list[1000], int n) {
	for (int i = 0; i < n; i++) list[i] = genRand(); /*list[i] = 4;*/
}


int check(float a, float b, int *h) {
	(*h)++;
	return (a > b);
}


void swap(float *a, float *b, int *h) {
	float c;
	c = *a;
	*a = *b;
	*b = c;
	(*h)++;
}


int checkListSorted(float list[], int n) {
	int ch = 1;
	int i = 0;
	while ((i < n - 1) || ch == 0) ch = list[i] > list[i++ + 1];
	return ch;
}


void DoubleBubble(float* const list, int n, int* checks, int* swaps) {
	int l = 0, r = 0;
	int dlt = 0;
	for (int i = 0; (i < n) || (l + r) < n; i++) {
		//Тянем вправо.
		if (i % 2) {
			dlt = 1;
			for (int j = l; j + r + 1 < n; j++) {
				if (check(list[j], list[j + 1], checks)) {
					swap(&list[j], &list[j + 1], swaps);
					dlt = 1;
				}
				else dlt++;
			}
			r += dlt;
		}
		//Тянем влево.
		else {
			dlt = 1;
			for (int j = n - r - 1; j> l; j--) {
				if (check(list[j - 1], list[j], checks)) {
					swap(&list[j - 1], &list[j], swaps);
					dlt = 1;
				}
				else dlt++;
			}
			l += dlt;
		}
	}
}


void listPrint(float list[1000], int n) {
	int np;
	//Вывод 10<= эл-ов массива.
	np = min(n, 10);
	printf("%.2f", list[0]);
	for (int i = 1; i < np; i++) {
		printf(" %.2f", list[i]);
	}
	if (n > 10) {
		printf("...");
	}
}


//state = 0: База - изменение массива
void showBaseScreen(float list[1000], int *n) {
	int input;
	float cop[9] = {5, 4, 1, 2, 5, 6, 9, 7, 8};
	listPrint(list, *n);

	//Панель выбора.
	printf("\n1) Заполнить массив (только при n < 11).\n");
	printf("2) Случайно заполнить массив.\n");
	printf("3) Изменить размер массива.\n");
	printf("4) Выбрать заготовленный массив.\n");
	printf("\n5) Отсортировать массив.\n");
	printf("\n25) Выйти.\n");

	input = 0;
	scanf_s("%d", &input);
	switch (input) {
	case(1): state = 1; break;
	case(2): fillRandList(list, *n); printf("Массив случайно сгенерирован;)\n"); break;
	case(3): state = 2; break;
	case(4): memcpy(list, cop, (sizeof(float) * 9)); *n = 9; break;
	case(5): state = 3; break;
	case(25): state = 255; break;
	}
}


//state = 1: Самостоятельный набор массива.
void manualFillScreen(float list[10], int n) {
	if (n > 10) {
		printf("\nМассив слишком большой: Сначала измените размер массива.\n");
	}
	else {
		printf("\nПо одному вводите элементы массива.\n");
		for (int i = 0; i < n; i++) scanf_s("%f", &list[i]);
	}
	state = 0;
}


//state = 2: Изменение размера массива.
void listSizeChangeScreen(float list[1000], int *n) {
	int input = 0;
	printf("\nРазмер массива ограничен от 2 - 1000 элементов,\n на данный момент размер массива - %d\n", *n);
	scanf_s("%d", &input);
	while ((input < 2) || (input > 1000)) {
		printf("Недопустимый размер массива.\n");
		scanf_s("%d", &input);
	}
	if (input > *n) {
		for (int i = *n; i < input; i++) list[i] = genRand();
	}
	*n = input;
	state = 0;
}

//state = 3: Сортировки
void sortScreen(float list[], int n, LARGE_INTEGER freq) {
	int input;
	LARGE_INTEGER start, finish;
	int checks = 0, swaps = 0;
	float* sr_list = (float*)malloc(sizeof(float) * n);
	state = 0;
	
	if (sr_list == NULL) printf("Нет памяти((.\n\n");
	else {
		listPrint(list, n);

		memcpy(sr_list, list, sizeof(float) * n);

		printf("\n1) Двунаправленный пузывёк.\n");
		//printf("2) Случайно заполнить массив.\n");
		//printf("3) Изменить размер массива.\n");
		//printf("\n4) Отсортировать массив.\n");
		scanf_s("%d", &input);

		
		QueryPerformanceCounter(&start);
		switch (input) {
		case(1): 
			DoubleBubble(sr_list, n, &checks, &swaps);
			break;
		}
		QueryPerformanceCounter(&finish);
		printf("%d\n\n", checkListSorted(sr_list, n));

		listPrint(sr_list, n);
		printf("\nВремя выполнения: %lf\n", (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart);
		printf("Кол-во проверок: %d, Кол-во перемен: %d\n\n", checks, swaps);
		free(sr_list);
	}
	
}



int main() {
	LARGE_INTEGER freq;
	float list[1000];
	int n = 10;
	//для таймера:
	QueryPerformanceFrequency(&freq);
	//для языка:
	setlocale(LC_ALL, "Russian");
	//рандом + рандомный лист:
	srand(time(NULL));
	fillRandList(list, n);

	while (state != 255) {
		if (state > 3) {
			state = 0;
		}
		switch (state) {
		case(0): showBaseScreen(list, &n); break;
		case(1): manualFillScreen(list, n); break;
		case(2): listSizeChangeScreen(list, &n); break;
		case(3): sortScreen(list, n, freq); break;
		}
	}
}