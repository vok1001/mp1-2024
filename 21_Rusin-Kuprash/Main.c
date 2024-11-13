#include "locale.h"
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


void check(float a, float b, int *h) {
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


//state = 0: База - изменение массива
void showBaseScreen(float list[1000], int n) {
	int input;
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

	//Панель выбора.
	printf("\n1) Заполнить массив (только при n < 11).\n");
	printf("2) Случайно заполнить массив.\n");
	printf("3) Изменить размер массива.\n");
	printf("\n4) Отсортировать массив.\n");
	printf("\n25) Выйти.\n");

	input = 0;
	scanf_s("%d", &input);
	switch (input) {
	case(1): state = 1; break;
	case(2): fillRandList(list, n); printf("Массив случайно сгенерирован;)\n"); break;
	case(3): state = 2; break;
	case(4): state = 3; break;
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



int main() {
	//int checks = 5;
	srand(time(NULL));
	float list[1000];
	int n = 10;
	fillRandList(list, n);

	setlocale(LC_ALL, "Russian");
	printf("Для выхода введите 25\n\n");

	while (state != 255) {
		if (state > 2) {
			state = 0;
		}
		switch (state) {
		case(0): showBaseScreen(list, n); break;
		case(1): manualFillScreen(list, n); break;
		case(2): listSizeChangeScreen(list, &n); break;
		}
	}
}