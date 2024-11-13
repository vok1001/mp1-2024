#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <locale.h>
#include <windows.h>


#define and && 
#define or ||
#define pi 3.1415
int copy_massive(int a[], int b[], int n) {
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
	}
	return b;
}

int min1(int a, int b) {
	if (a < b) {
		return a;

	}
	return b;
}
int max1(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}
void print_menu() {
	printf("1. Buble sort\n");
	printf("2. Insertion sort \n");
	printf("3. Selection sort\n");
	printf("4. Merge sort\n");
	printf("5. Couting sort \n");
	printf("6. Quick sort\n ");
	printf("7. Shell sort\n");
	printf("8. Piramyd sort\n");
	printf("9. Radix sort\n");
	printf("10. Quick sort(not recursion)\n");
	printf("11. Merge sort(not recursion\n");
	printf("12. Binary search\n");
	printf("13. Linear search\n");
	printf("14. Поменять массив\n");
	printf("0. Exit\n");
}

void proverka(int a[], int n) {
	int f = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) {
			f = 0;
		}
	}
	if (f == 0) {
		printf("Массив не отсортирован!");
	}
	else {
		printf("Массив отсортирован!");
	}
}
void Selection_sort(int a[], int n) {
	clock_t start = clock();
	long long iteration = 0; 
	for (int i = 0; i < n - 1; i++) {
		int min_idx = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min_idx]) {
				min_idx = j;
				iteration++;
			}
		}
		if (min_idx != i) {
			int t = a[i];
			a[i] = a[min_idx];
			a[min_idx] = t;
			iteration++;
		}
	}
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	printf("Время работы вашей программы: %f \n", time_spent);
	printf("kolichestvo iteracii: %d \n", iteration);

	printf("\n");
}



void Buble_sort(int a[], int n) {
	int l = 1;
	int r = n - 1;
	int k;
	long long iteration = 0; 
	int f = 1;
	clock_t start = clock();
	while (l < r and f == 1) {
		f = 0;
		for (int i = r; i >= l; i--) {
			if (a[i] < a[i - 1]) {
				k = a[i];
				a[i] = a[i - 1];
				a[i - 1] = k;
				f = 1;
				iteration++;
			}
		}
		l++;
		for (int i = l; i <= r; i++) {
			if (a[i - 1] > a[i]) {
				k = a[i];
				a[i] = a[i - 1];
				a[i - 1] = k;
				f = 1;
				iteration++;
			}
		}
		r--;
	}
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("~~~~~~~~~~~~~~~~~~ \n");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("~~~~~~~~~~~~~~~~~~ \n");
	printf("Время работы вашей программы: %f \n", time_spent);
	printf("kolichestvo iteracii: %d \n", iteration);

	printf("\n");
}

void Insertion_sort(int a[], int n) {
	clock_t start = clock();
	long long iteration = 0; 
	for (int i = 1; i < n; i++) {
		int k = a[i];
		int j = i - 1;
		while (j >= 0 and a[j] > k) {
			a[j + 1] = a[j];
			j--;
			iteration++;
		}
		a[j + 1] = k;
		iteration++;
	}
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	printf("\n");
	printf("Время работы вашей программы: %f \n", time_spent);
	printf("kolichestvo iteracii: %d \n", iteration);

	printf("\n");

}
void merge(int arr[], int l, int mid, int r) {
	int i, j, k;
	int n1 = mid - l + 1;
	int n2 = r - mid;
	int L[10000], R[10000];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];
	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}
void Merge_sort(int arr[], int l, int r) {
	clock_t start = clock();
	if (l < r) {
		int mid = l + (r - l) / 2;
		Merge_sort(arr, l, mid);
		Merge_sort(arr, mid + 1, r);
		merge(arr, l, mid, r);
	}
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Время работы вашей программы: %f \n", time_spent);
	printf("\n");
}
void Counting_sort(int a[], int n) {
	int s[20000], mx = -1000000, mn = 1000000, g = 0;
	clock_t start = clock();
	long long iteration = 0;
	for (int i = 0; i < n; i++) {
		s[a[i]]++;
		mx = max1(mx, a[i]);
		mn = min1(mn, a[i]);
		iteration++; 
	}
	for (int i = mn - 2; i < mx + 2; i++) {
		if (s[i] >= 1) {
			for (int j = 0; j < s[i] + 1; j++) {
				printf("%d ", i);
				iteration++;
			}
		}
	}
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\n");
	printf("Время работы вашей программы: %f \n", time_spent);
	printf("kolichestvo iteracii: %d \n", iteration);
	printf("\n");
}

int partition(int arr[], int low, int high) {
	int k;
	int mid = low + (high - low) / 2;
	int pivot = arr[mid];

	k = arr[mid];
	arr[mid] = arr[high];
	arr[high] = k;
	int i = low;

	for (int j = low; j < high; j++) {
		if (arr[j] < pivot) {
			k = arr[i];
			arr[i] = arr[j];
			arr[j] = k;
			i++; 
		}
	}

	k = arr[i];
	arr[i] = arr[high];
	arr[high] = k;
	return i;
}

void Quick_sort(int arr[], int low, int high) {
	clock_t start = clock();
	if (low < high) {
		int pivotIndex = partition(arr, low, high);
		Quick_sort(arr, low, pivotIndex - 1);
		Quick_sort(arr, pivotIndex + 1, high);
	}
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Время работы вашей программы: %f \n", time_spent);
	printf("\n");
}

void Shell_sort(int arr[], int n) {
	printf("Ещё не реализовано!!!");
}
void Piramyd_sort(int arr[], int n) {
	printf("Ещё не реализовано!!!");
}
void Radix_sort(int arr[], int n) {
	printf("Ещё не реализовано!!!");
}
void Quick_sort_nr(int arr[], int n) {
	printf("Ещё не реализовано!!!");
}
void Merge_sort_nr(int arr[], int n) {
	printf("Ещё не реализовано!!!");
}
int Binary_search(int arr[], int n, int e) {
	int l = 0, r = n - 1, f = 0, mid, k, pos = -1;
	long long iteration = 0; 
	clock_t start = clock();
	while (l <= r) {
		mid = (l + r) / 2;
		if (arr[mid] < e) {
			l = mid + 1;
		}
		else if (arr[mid] > e) {
			r = mid - 1;
		}
		else {
			f = 1;
			pos = mid;
			break;
		}
	}
	if (f == 1) {
		printf("~~~~~~~~~~~~~~~~ \nЧисло найдено  %d\n~~~~~~~~~~~~~~~~ \n", pos);
	}
	else {
		printf("~~~~~~~~~~~~~~~~ \n Число не найдено \n~~~~~~~~~~~~~~~~ \n");
	}
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Время работы вашей программы: %f \n", time_spent);
	printf("kolichestvo iteracii: %d \n", iteration);
	printf("\n");
	return pos;
}
void Linear_search(int a[], int n, int e) {
	int f = 0;
	long long iteration = 0; 
	clock_t start = clock();
	for (int i = 0; i < n; i++) {
		if (a[i] == e) {
			f = 1;
		}
		iteration++; 
	}
	if (f == 1) {
		printf("~~~~~~~~~~~~~~~~ \nЧисло найдено \n~~~~~~~~~~~~~~~~ \n");
	}
	else {
		printf("~~~~~~~~~~~~~~~~ \n Число не найдено \n~~~~~~~~~~~~~~~~ \n");
	}
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Время работы вашей программы: %f \n", time_spent);
	printf("kolichestvo iteracii: %d \n", iteration);
	printf("\n");

}
void printa(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}


int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int a[1000];
	int n, e, g = 1;
	int c;
	int ac[1000];
	int iter;
	LARGE_INTEGER freq, start, finish;
	double time;
	int vibor;
	printf("Выберите размер массива:");
	scanf_s("%d", &n);
	printf("Выберите способ задания массива: \n 1.Вручную \n 2.Случайная генерация элеменов массива \n");
	scanf_s("%d", &vibor);
	if (vibor == 2) {
		for (int i = 0; i < n; i++) {
			a[i] = (rand() % 20001) - 10000;
		}
		printf("Массив сгенерирован: \n");
		printa(a, n);
	}
	else {
		printf("Введите числа в массив через пробел: \n");
		for (int i = 0; i < n; i++) {
			scanf_s("%d", &a[i]);
		}
	}
	while (true) {
		print_menu();
		printf("Выберите вариант: ");
		scanf_s("%d", &c);
		switch (c) {
		case 0: printf("Работа программы завершена");  return 0; break;
		case 1: copy_massive(a, ac, n); Buble_sort(ac, n); break;
		case 2: copy_massive(a, ac, n); Insertion_sort(ac, n); break;
		case 3: copy_massive(a, ac, n); Selection_sort(ac, n); break;
		case 4: copy_massive(a, ac, n); Merge_sort(ac, 0, n - 1); printa(ac, n); break;
		case 5: copy_massive(a, ac, n); Counting_sort(ac, n); break;
		case 6: copy_massive(a, ac, n); Quick_sort(ac, 0, n - 1); printa(ac, n);  break;
		case 7: copy_massive(a, ac, n); Shell_sort(ac, n); break;
		case 8: copy_massive(a, ac, n); Piramyd_sort(ac, n); break;
		case 9: copy_massive(a, ac, n); Radix_sort(ac, n); break;
		case 10: copy_massive(a, ac, n); Quick_sort_nr(ac, n); break;
		case 11: copy_massive(a, ac, n); Merge_sort_nr(ac, n); break;
		case 12: copy_massive(a, ac, n);
			printf("Введите элемент который ищем: \n");
			scanf_s("%d", &e);
			Binary_search(ac, n, e);
			break;
		case 13: copy_massive(a, ac, n);
			printf("Введите элемент который ищем: \n");
			scanf_s("%d", &e);
			Linear_search(ac, n, e);
			break;
		case 14:
			printf("Выберите размер массива:");
			scanf_s("%d", &n);
			printf("Выберите способ задания массива: \n 1.Вручную \n 2.Случайная генерация элеменов массива \n");
			scanf_s("%d", &vibor);
			if (vibor == 2) {
				for (int i = 0; i < n; i++) {
					a[i] = (rand() % 20001) - 10000;
				}
				printf("Массив сгенерирован: \n");
				printa(a, n);
			}
			else {
				printf("Введите числа в массив через пробел: \n");
				for (int i = 0; i < n; i++) {
					scanf_s("%d", &a[i]);
				}
			}
		}
	}

	return 0;
}