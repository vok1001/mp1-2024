#include "stdio.h"
#include <stdlib.h>

void Sort_vstavkami(int a[], int n)
{
	int val, k;

	for (int i = 1; i < n; i++)
	{
		val = a[i];
		k = i - 1;
		while (k >= 0 && a[k] > val)
		{
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = val;
	}
}

void bublsort_2(int a[], int n) {
	int A[n];
	int i, j, f = 1, r, k, l, k2, temp;
	l = 0;
	r = n - 2;
	for (i = 0; i < n; i++) {
		A[i] = a[i];
	}
	while (l < r) {
		k = -1;
		for (i = l; i <= r; i++) {
			if (A[i] > A[i + 1]) {
				temp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = temp;
				k = 1;

			}
		}
		r = k;
		k = n;
		for (i = (r - 1); j > l; j--) {
			if (A[j] > A[j + 1]) {
				temp = A[j];
				A[j] = A[j + 1];
				A[i + 1] = temp;
				k = j;
			}
		}
		l = k + 1;
	}
	for (i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}

}


int bublsort(int a[], int n) {
	int val;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				val = a[i];
				a[i] = a[j];
				a[j] = val;
			}
		}

	}
	return n;
}




void sort_vuborom(int a[], int n) {
	int min_index;
	for (int i = 1; i < n; i++) {
		min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (a[min_index] > a[j]) {
				min_index = j;
			}
		}
		if (min_index != i)
		{
			int temp = a[i];
			a[i] = a[min_index];
			a[min_index] = temp;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);

	}
	printf("\n");
}


void Quick_Sort(int a[], int l, int p) {
	int i, j, tmp;
	int mid = (l + p) / 2;
	int val = a[mid];
	i = l;
	j = p;
	while (i <= j) {
		while (a[i] < val) i++;
		while (a[j] > val) j--;
		if (i <= j) { tmp = a[i]; a[i] = a[j]; a[j] = tmp; i++; j--; }
	}

	if (j > l) Quick_Sort(a, l, j);
	if (i < p) Quick_Sort(a, i, p);
	printf("\n");
}





static void vubor_vvoda_massive() {
	printf("1.Vvedu sam\n");
	printf("2.Random massive\n");
}
void random_massive(int a[], int n) {
	srand(100);
	int i;
	for (i = 0; i < n; i++) {
		a[i] = rand();
	}
}

void linpoisk(int a[], int n) {
	int i, x, flag = 0;
	printf("Vvedite x\n");
	scanf("%d", &x);
	for (i = 0; i < n; i++) {
		if (a[i] == x) {
			flag = i;
			break;
		}
	}
	if (flag != 0) {
		printf("chislo naydeno, index - %d", flag);
	}
	else {
		printf("chisla net v massive");
	}
}


void b_poisk(int a[], int n) {
	int x, flag = 0;
	int l = 0, r = n - 1, c;
	printf("Vvedite x\n");
	scanf("%d", &x);
	flag = 0;
	while (l <= r) {
		c = (l + r) / 2;
		if (a[c] > x) {
			r = c - 1;
		}
		else if (a[c] < x) {
			l = c + 1;
		}
		else {
			flag = c;
			break;
		}
	}
	if (flag != 0) {
		printf("chislo naydeno, index - %d\n", flag);
	}
	else {
		printf("chisla net v massive\n");
	}

}




void menu()
{
	printf("1. b_poisk \n");
	printf("2. linpoisk\n");
	printf("3. sort_vuborom\n");
	printf("4. Quick_Sort\n");
	printf("5. Sort_vstavkami\n");
	printf("6. bublsort\n");
	printf("7. Exit\n");
	printf("8. Exit\n");
}


void genmassiva_sam(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
}

void vivodmassive(int a[], int n) {

	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}



int main() {
	int c, n, g = 1;
	int a[10];
	vubor_vvoda_massive();

	scanf("%d", &c);
	if ((c == 1) || (c == 2)) {
		if (c == 1) {
			printf("Vvedite dliny massiva\n");
			scanf("%d", &n);
			genmassiva_sam(a, n);
			vivodmassive(a, n);
		}
		if (c == 2) {
			printf("Vvedite dliny massiva\n");
			scanf("%d", &n);
			random_massive(a, n);
			vivodmassive(a, n);

		}
		printf("\n");

		while (g != 8) {
			printf("Vuberite sortirovky ili poisk\n");
			menu();
			scanf("%d", &g);
			switch (g)
			{
			case 1: {


				b_poisk(a, n);
				break;
			}
			case 2: {


				linpoisk(a, n);
				break;
			}
			case 3: {
				sort_vuborom(a, n);
				break;

			}
			case 4: {
				Quick_Sort(a, 0, n - 1);
				vivodmassive(a, n);
				printf("\n");
				break;
			}
			case 5: {
				Sort_vstavkami(a, n);
				vivodmassive(a, n);
				printf("\n");
				break;

			}
			case 6: {
				bublsort(a, n);
				vivodmassive(a, n);
				printf("\n");
				break;
			}
			case 7: {
				bublsort_2(a, n);
				printf("\n");
				break;
			}


			}
		}

	}

	printf("Programma zavershena");
}
