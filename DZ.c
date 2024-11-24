//1 Задача на массивы средняя сложность номер 19
#include <stdio.h>

void count_marks(int a[][3], int n)
{
	int i, j, ocenka;
	int neyvka = 0, neyd = 0, ydovl = 0, hor = 0, otl = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 3; j++)
		{
			ocenka = a[i][j];
			switch (ocenka)
			{
			case 1:
				neyvka++;
				break;
			case 2:
				neyd++;
				break;
			case 3:
				ydovl++;
				break;
			case 4:
				hor++;
				break;
			case 5:
				otl++;
				break;
			default:
				printf("Incorrect ocenka\n");
				printf("Will be replaces as 1\n");
				ocenka = 1;
				break;
			}
		}
	}
	printf("neyvka = %d\n", neyvka);
	printf("neyd = %d\n", neyd);
	printf("ydovl = %d\n", ydovl);
	printf("hor = %d\n", hor);
	printf("otl = %d\n", otl);
}

void check_matrix(int a[][3], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		printf("student %d: ", i + 1);
		for (j = 0; j < 3; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int marks[1000][3];
	int n;
	int ocenka;
	int i, j;
	printf("Max students count is 1000\n");
	printf("Enter students count: \n");
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("Enter students ocenka: \n");
			scanf_s("%d", &ocenka);
			marks[i][j] = ocenka;
		}
		printf("------------------\n");
	}
	check_matrix(marks, n);
	printf("------------------\n");
	count_marks(marks, n);
	return 0;
}