#include "stdio.h"
#include "locale.h"
void print_menu()
{
	setlocale(LC_ALL, "Russian");
	printf("0. Input_array\n");
	printf("1. RandomArray\n");
	printf("2. Bubble sort\n");
	printf("3. Insert sort\n");
	printf("4. Counting sort\n");
	printf("5. Сортировка_Хоара\n");
	printf("6. Linear_search\n");
	printf("7. Binary_search\n");
	printf("8. Copy_array\n");
	printf("9. Exit\n");
}

void Bubble_sort(int A[], int n)
{
	printf("Сортировка пузырьком\n");
	int i, j, temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (A[j] > A[j + 1])
			{// Меняем A[j] и A[j+1]
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
	}
}

void Insert_sort(int A[], int n)
{
	printf("Сортировка вставками\n");
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = A[i];
		j = i - 1;

		// Перемещаем элементы A[0..i-1], которые больше key,
		// на одно положение вперед от их текущей позиции
		while (j >= 0 && A[j] > key)
		{
			A[j + 1] = A[j];
			j = j - 1;
		}
		A[j + 1] = key;
	}
}

void counting_Sort(int arr[], int n, int maxVal)
{
}




void Linear_search(int A[], int n, int val)
{
	int i, k;
	i = 0;
	k = 0;
	while ((i < n) && (A[i] != val))
		i++;
	if (i < n)
		k = i;
	printf("\nлинейный поиск\n");
	printf("% d", k);
}
void Binary_search(int A[], int n, int val)
{
	int m, l, r, f;
	m = 0;
	l = 0;
	r = n - 1;
	f = 0;
	while ((l <= r) && !f)
	{
		m = (l + r) / 2;
		if (val > A[m])
			l = m + 1;
		else if (val < A[m])
			r = m - 1;
		else f = 1;

	}
}
void Copy_array(int A[], int B[], int n)
{
	int i;
	for (i = 0;i < n;i++)
		B[i] = A[i];
}

void Input_array(n)
{
	int A[n];
	for (int i = 0; i < n; i++)
	{
		printf("Элемент %d: ", i + 1);
		scanf("%d", &A[i]);
	}

}

void RandomArray(int A[], int n, int min, int max)
{
	for (int i = 0; i < n; i++)
	{
		A[i] = min + rand() % (max - min + 1);  // Генерация случайного числа в диапазоне [min, max]
	}
}

int main()
{
	int status = 0; // этап решения. 0 - ничего, 1 - введен массив, 2 - отсортирован массив
	while (c != 9)
	{
		print_menu();
		scanf_s("%d", &c);
		switch (c)
		{
		case 0: {
			int n;
			scanf_s("Введите %d элементов массива:\n", &n);
			Input_array(n); status = 1; break;
		}

		}
	}
}