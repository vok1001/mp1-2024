#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//#define RAND_MIN = pow(10, n - 1)
int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	int n, i;
	scanf_s("%d", &n);
	int** res = (int**)malloc(sizeof(int*) * n); // = { {1, 2, 3, 4},  {4,3, 4, 21} };
	
	for (i = 0; i < n; i++)
		res[i] = (int*)malloc(sizeof(int) * n);


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			int f;
			scanf_s("%d", &f);

			res[i][j] = f;
		}
	}

	hw13(res, n, n);
	
	return 0;

}


int hw13(int **arr, int k1, int k2) {
	int m, mM1, mM2;
	m = mM1 = mM2 = 10000000;
	for (int i = 0; i < k1; i++)
	{
		for (int j = 0; j < k2; j++) {
			if (m > arr[i][j]) {
				m = arr[i][j];
				mM1 = i;
				mM2 = j;
			}
		}
	}
	printf("%d %d %d ", m, mM1, mM2);
	return 0;
}








