//2 Задача на массивы номер 13
#include <stdio.h>

int matrix[1000][1000];
int matrix_result[1000][1000];

void check_matrix(int a[][1000], int n, int m)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", a[i][j]);
		}	
		printf("\n");
	}
}

int main()
{
	int m, n;
	int minimum = 1000000, stroks_minimum = -1;
	int i, j;
	int matrix_element = 0;
	int flag = 0;
	printf("Len stroka (m <= 999): ");
	scanf_s("%d", &m);
	printf("Len stolbec (n <= 999): ");
	scanf_s("%d", &n);
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf_s("%d", &matrix_element);
			matrix[i][j] = matrix_element;
			if (matrix_element < minimum)
			{
				minimum = matrix_element;
				stroks_minimum = i;
			}
		}
	}
	printf("------------------\n");
	check_matrix(matrix, n, m);
	for (i = 0; i < m; i++)
	{
		if (i == stroks_minimum)
			flag = 1;
		if (flag == 0)
		{
			for (j = 0; j < n; j++)
			{
				matrix_result[i][j] = matrix[i][j];
			}
		}
		else
		{
			for (j = 0; j < n; j++)
			{
				matrix_result[i][j] = matrix[i + 1][j];
			}
		}
	}
	printf("------------------\n");
	check_matrix(matrix_result, n - 1, m);
	return 0;
}
