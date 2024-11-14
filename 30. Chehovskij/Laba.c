#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void Sort_vstavkami(int a[], int n)
{
	int val, k, count = 0;
	clock_t start, finish;
	start = clock();

	for (int i = 1; i < n; i++)
	{
		val = a[i];
		k = i - 1;
		while (k >= 0 && a[k] > val)
		{
			a[k + 1] = a[k];
			k--;
		}
		count++;
		a[k + 1] = val;
	}
	count++;
	printf("Kol-vo operaciy: %d\n", count);

}


void bubblesort2(int a[], int n) {
	int l = 0, r = n - 1, i, k, count = 0;
	while (l <= r) {
		for (i = r; i > l; i--) {
			if (a[i - 1] > a[i]) {
				k = a[i - 1];
				a[i - 1] = a[i];
				a[i] = k;
			}
			count++;
		}
		++l;
		count++;
		for (i = l; i < r; i++) {
			if (a[i] > a[i + 1]) {
				k = a[i + 1];
				a[i + 1] = a[i];
				a[i] = k;
			}
			count++;
		}
		--r;
		count++;
	}
	printf("Kol-vo operaciy: %d\n", count);
}

int bubblsort(int a[], int n) {
	int val, count = 0;
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
			count++;
		}
		count++;

	}
	count++;
	printf("Kol-vo operaciy: %d\n", count);
	return n;
}




void sort_vuborom(int a[], int n) {
	int min_index, count = 0;
	for (int i = 1; i < n; i++) {
		min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (a[min_index] > a[j]) {
				min_index = j;
			}
			count++;
		}
		count++;
		if (min_index != i)
		{
			int temp = a[i];
			a[i] = a[min_index];
			a[min_index] = temp;
		}
		count++;
	}
	count++;
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);

	}
	printf("\n");
	count++;
	printf("Kol-vo operaciy: %d\n", count);
	printf("\n");
}


void Quick_Sort(int a[], int l, int p) {
	int i, j, tmp, count = 0;
	int mid = (l + p) / 2;
	int val = a[mid];
	i = l;
	j = p;
	while (i <= j) {
		count++;
		while (a[i] < val) i++;
		while (a[j] > val) j--;
		if (i <= j) { tmp = a[i]; a[i] = a[j]; a[j] = tmp; i++; j--; }
		count++;
	}

	if (j > l) Quick_Sort(a, l, j);
	count++;
	if (i < p) Quick_Sort(a, i, p);
	count++;
	printf("Kol-vo operaciy: %d\n", count);

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
	int i, x, flag = 0, count = 0;
	printf("Vvedite x\n");
	scanf_s("%d", &x);
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
	int x, flag = 0, count = 0;
	int l = 0, r = n - 1, c;
	printf("Vvedite x\n");
	scanf_s("%d", &x);
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
	printf("7. bubblesort2\n");
	printf("8. Exit\n");
}


void genmassiva_sam(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
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
	clock_t start, finish;
	int count = 0;
	vubor_vvoda_massive();

	scanf_s("%d", &c);
	if ((c == 1) || (c == 2)) {
		if (c == 1) {
			printf("Vvedite dliny massiva\n");
			scanf_s("%d", &n);
			genmassiva_sam(a, n);
			vivodmassive(a, n);
		}
		if (c == 2) {
			printf("Vvedite dliny massiva\n");
			scanf_s("%d", &n);
			random_massive(a, n);
			vivodmassive(a, n);

		}
		printf("\n");

		while (g != 8) {
			printf("Vubrite sortirovky ili poisk\n");
			menu();
			scanf_s("%d", &g);
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
				start = clock();
				sort_vuborom(a, n);
				printf("\n");
				finish = clock();
				double duration = (double)(finish - start) / CLOCKS_PER_SEC;
				printf("Vremya: %f sec\n ", duration);
				printf("\n");
				break;

			}
			case 4: {
				start = clock();
				Quick_Sort(a, 0, n - 1);
				finish = clock();
				double duration = (double)(finish - start) / CLOCKS_PER_SEC;
				printf("Vremya: %f sec\n ", duration);
				vivodmassive(a, n);
				printf("\n");
				break;
			}
			case 5: {
				start = clock();
				Sort_vstavkami(a, n);
				finish = clock();
				double duration = (double)(finish - start) / CLOCKS_PER_SEC;
				printf("Vremya: %f sec\n ", duration);
				vivodmassive(a, n);
				printf("\n");
				break;

			}
			case 6: {
				start = clock();
				bubblsort(a, n);
				finish = clock();
				double duration = (double)(finish - start) / CLOCKS_PER_SEC;
				printf("Vremya: %f sec\n ", duration);
				vivodmassive(a, n);
				printf("\n");
				break;
			}
			case 7: {
				start = clock();
				bubblesort2(a, n);
				finish = clock();
				double duration = (double)(finish - start) / CLOCKS_PER_SEC;
				printf("Vremya: %f sec\n ", duration);
				vivodmassive(a, n);
				printf("\n");
				break;
			}


			}
		}

	}

	printf("Programma zavershena");
}


