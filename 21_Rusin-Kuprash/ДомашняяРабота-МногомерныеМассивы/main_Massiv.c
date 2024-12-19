#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


void generateArray(float*** array, float** arrayMem, int m, int n) {
	float val;
	*arrayMem = (float*)malloc(sizeof(float) * 5 * n);
	*array = (float**)malloc(sizeof(float*) * n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			val = (float)(rand()) / (float)RAND_MAX * 255;
			(*arrayMem)[i * 5 + j] = val;
		}
		(*array)[i] = arrayMem[i * 5];
	}
}


void printLine(float* line) {
	for (int j = 0; j < 5; j++) {
		printf("%.2f ", line[j]);
	}
	printf("\n");
}


void printArray(float** arrayMem, float* array, int n) {
	/*
	printf("Ориг\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%.2f ", array[5 * i + j]);
		}
		printf("\n");
	}
	*/
	//printf("\nНеориг\n");
	for (int i = 0; i < n; i++) {
		printLine(arrayMem[i]);
		//printf("\n");
	}
}


int checkLine(int lineId, int maxLineId[5], int minLineId[5]) {
	int mins = 0;
	int maxs = 0;
	for (int i = 0; i < 5; i++) {
		if (lineId == minLineId[i]) {
			mins++;
		}
		if (lineId == maxLineId[i]) {
			maxs++;
		}
	}

	if (maxs > 2){
		return 1;
	}
	if (mins > 2) {
		return 2;
	}
	return 0;
}


int prog1() {
	int n;
	unsigned int seed;
	float** insects;
	float* insectsMem;

	float maxLine[5] = {-1, -1, -1, -1, -1};
	int maxLineId[5];
	float minLine[5] = { 256, 256, 256, 256, 256 };
	int minLineId[5];
	float averLine[5] = {0, 0, 0, 0, 0};

	float val;

	float addfl1 = 0;
	float addfl2 = 0;
	int addNum1 = 0;
	int addNum2 = 0;
	int addNum3 = 0;

	printf("Задача по многомерным массивам 21:\nВведите кол-во элементов.\n");
	printf("Случайный генератор:\n");
	scanf_s("%u", &seed);
	srand(seed);
	printf("Сколько элементов:\n");
	scanf_s("%d", &n);
	
	insectsMem = (float*)malloc(sizeof(float) * 5 * n);
	insects = (float**)malloc(sizeof(float*) * n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			val = (float)(rand()) / (float)RAND_MAX * 255;
			insectsMem[i * 5 + j] = val;
			averLine[j] += val;
			if (maxLine[j] < val) {
				maxLine[j] = val;
				maxLineId[j] = i;
			}
			if (minLine[j] > val) {
				minLine[j] = val;
				minLineId[j] = i;
			}
		}
		insects[i] = &insectsMem[i * 5];
	}

	for (int j = 0; j < 5; j++) {
		averLine[j] /= n;
	}

	printArray(insects, insectsMem, n);

	
	printf("\n наибольшие хар-и и их насекомое:\n");
	for (int i = 0; i < 5; i++) {
		printf("%f %d |", maxLine[i], maxLineId[i]);
	}
	printf("\n наименьшие хар-и и их насекомое:\n");
	for (int i = 0; i < 5; i++) {
		printf("%f %d |", minLine[i], minLineId[i]);
	}
	printf("\n");
	
	printf("Уникальные жучары:\n");
	for (int i = 0; i < n; i++) {
		addNum3 = checkLine(i, maxLineId, minLineId);
		if (addNum3 == 1) {
			printf("Самый лучший!! (имеющий более двух характеристик с максимальными значениями) - \n");
			addNum1 = 1;
			printf("%d - ", i);
			printLine(insects[i]);
		}
		if (addNum3 == 2) {
			printf("Самый худший!! (имеющий более двух характеристик с минимальными значениями) - \n");
			addNum2 = 1;
			printf("%d - ", i);
			printLine(insects[i]);
		}
	}
	if (!addNum1) {
		printf("Нету лучших!!\n");
	}
	if (!addNum2) {
		printf("Нету худших!!\n");
	}
	printf("\nсредние зн-ия характеристик: ");
	printLine(averLine);
	printf("Посредственный жучара:\n");
	
	addNum3 = 0;

	for (int j = 0; j < 5; j++) addfl1 += fabs(insects[0][j] - averLine[j]);

	for (int i = 1; i < n; i++) {
		addfl2 = 0;
		for (int j = 0; j < 5; j++) addfl2 += fabs(insects[0][j] - averLine[j]);
		if (addfl2 < addfl1) {
			addfl1 = addfl2;
			addNum3 = i;
		};
	}
	printf("%d - %f - ", addNum3, addfl1);
	printLine(insects[addNum3]);
	
	//free(insectsMem);
	
	printArray(insects, insectsMem, n);
	printf("Программа окончила работу:");
	scanf_s("%d", &n);
	return 1;
}


int prog2() {
	float* arrayMem;
	float** array;
	int n, m;
	scanf_s("%d %d", &m, &n);
	generateArray(&array, &arrayMem, m, n);


	free(arrayMem);
	return 1;
}


int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	int ans;
	printf("Выберите задачу (1/2): ");
	scanf_s("%d", &ans);
	printf("\n");
	if (ans < 2) return prog1();
	return prog2();
}