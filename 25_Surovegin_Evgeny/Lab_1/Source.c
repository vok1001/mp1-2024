#include<malloc.h>
//#include <stdlib.h>  // для malloc() 
#include<stdio.h>
#include<locale.h>
#include<time.h>
void check(int n,int* a)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (i != n - 1)
		{
			if (a[i] <= a[i + 1])
			{
				k++;
			}
		}
	}
	if (k == n - 1)
	{
		printf("Массив отсортирован\n");
	}
	else
	{
		printf("Массив не отсортирован\n");
	}
}
int Generation_n()
{
	int n;
	scanf_s("%d", &n);
	while (n > 10000 || n <= 0)
	{
		printf("Выберете n повторно\n");
		scanf_s("%d", &n);
	}
	return n;
}
void Massiv(int ans, int n, int* user)
{
	if (ans == 1)
	{
		printf("Вручную\n");
		for (int i = 0; i < n; i++)
		{
			scanf_s("%d", &user[i]);
		}
	}
	else
	{
		printf("Случайная генерация\n");
		for (int i = 0; i < n; i++)
		{
			user[i] = rand();
		}
	}
}
int Menu()
{
	int ans1;
	printf("Выберете способ сортировки массива\n");
	printf("1.Сортировка пузырьком\n");
	printf("2.Сортировка вставками\n");
	printf("3.Сортировка выбором\n");
	printf("4.Сортировка подсчетом\n");
	printf("5.Сортировка двойным пузырьком\n");
	printf("6.Сортировка Хоара\n");
	printf("7.Сортировка Слиянием\n");
	scanf_s("%d", &ans1);
	while (ans1 > 7 || ans1 < 1)
	{
		printf("Выберете способ сортировки массива повторно\n");
		scanf_s("%d", &ans1);
	}
	return(ans1);
}

struct sort_stat
{
	int srav;
	int per;
};

struct sort_stat def_bubble(int n, int* a)
{
	struct sort_stat res;
	res.srav = 0;
	res.per = 0;
	printf("Сортировка пузырьком\n");

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)//сортировка пузырьком
		{
			res.srav++;
			if (a[j] > a[j + 1])
			{
				res.per++;
				int b = a[j];
				a[j] = a[j + 1];
				a[j + 1] = b;
			}
		}
	}
	return res;
}
struct sort_stat  vstavka(int n, int* a)
{
	struct sort_stat res;
	res.srav = 0;
	res.per = 0;
	int newel, pos, k = 0;
	for (int i = 1; i < n; i++)//сортировка вставками
	{
		newel = a[i];
		pos = i - 1;
		while (pos >= 0 && a[pos] > newel)
		{
			res.per++;
			a[pos + 1] = a[pos];
			pos -= 1;
			k++;
		}
		res.srav += k;
		a[pos + 1] = newel;
		k = 0;
	}
	return res;
}
struct sort_stat vibor(int n, int* a)
{
	struct sort_stat res;
	res.srav = 0;
	res.per = 0;
	int minpos;
	for (int i = 0; i < n; i++)
	{
		minpos = i;
		for (int j = i + 1; j < n; j++)//сортировка выбором
		{
			res.srav++;
			if (a[minpos] > a[j])
			{
				minpos = j;
			}
		}
		int b = a[minpos];
		a[minpos] = a[i];
		a[i] = b;
		res.per++;
	}
	return res;
}
struct sort_stat podschet(int n, int* a)
{
	struct sort_stat res;
	res.srav = 0;
	res.per = 0;
	int pos = 0, max = a[0], min=a[0];//сортировка подсчетом
	int* count;
	for (int i = 0; i < n; i++)
	{
		res.srav++;
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	min = abs(min);
	count = malloc(sizeof(int) * (max+min));
	for (int i = 0; i <= max+min; i++)
	{
		count[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
			count[a[i]+min]++;
	}
	for (int i = 0; i <= max+min; i++)
	{
		res.srav++;
		if (count[i] > 0)
		{
			for (int j = 0; j < count[i]; j++)
			{
				a[pos] = i-min;
				pos++;
			}
		}
	}
	return res;
}
	


struct sort_stat double_bubble(int n, int* a)
{
	struct sort_stat res;
	res.srav = 0;
	res.per = 0;
	int f = 1, left = 0, right = n - 1;//сложный пузырек
	for (int i = 0; (i < n) && (f); i++)
	{
		f = 0;
		if (i % 2 == 1)
		{
			for (int j = left; j < right; j++)
			{
				res.srav++;
				if (a[j] > a[j + 1])
				{
					int b = a[j];
					a[j] = a[j + 1];
					a[j + 1] = b;
					f = 1;
					res.per++;
				}
			}
			right--;
		}
		else
		{
			for (int j = right; j > left; j--)
			{
				res.srav++;
				if (a[j] < a[j - 1])
				{
					int b = a[j];
					a[j] = a[j - 1];
					a[j - 1] = b;
					f = 1;
					res.per++;
				}
			}
			left++;
		}
	}
	return res;
}
struct sort_stat Hoar(int left, int right, struct sort_stat res,int n, int* a)//Хоар
{
	int i = left, j = right;
	int mid = (right + left) / 2;
	int val = a[mid];
	while (i <= j)
	{
		while (a[i] < val)
		{
			i++;
			res.srav++;
		}
		while (a[j] > val)
		{
			j--;
			res.srav++;
		}
		if (i <= j)
		{
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
			res.per++;
		}
	}
	if (j > left)
	{
		res = Hoar(left, j, res, n, a);
	}
	if (i < right)
	{
		res = Hoar(i, right, res, n, a);
	}
	return res;
}
struct sort_stat sliyanie(int l, int mid, int r, struct sort_stat res, int n, int* a)
{
	int i, j, k;
	int n1 = mid - l + 1;
	int n2 = r - mid;
	int* leftArr = malloc(sizeof(int) * n1);
	int* rightArr = malloc(sizeof(int) * n2);
	for (i = 0; i < n1; i++)
	{
		leftArr[i] = a[l + i];
	}
	for (j = 0; j < n2; j++)
	{
		rightArr[j] = a[mid + 1 + j];
	}
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		res.srav++;
		res.per++;
		if (leftArr[i] <= rightArr[j])
		{
			a[k] = leftArr[i];
			i++;
		}
		else
		{
			a[k] = rightArr[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		res.per++;
		a[k] = leftArr[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		res.per++;
		a[k] = rightArr[j];
		j++;
		k++;
	}
	free(leftArr);
	free(rightArr);

	return res;
}
struct sort_stat razbivka(int l, int r, struct sort_stat res, int n, int* a)
{
	if (l < r)
	{
		int  mid = (l + r) / 2;
		res = razbivka(l, mid, res, n, a);
		res = razbivka(mid + 1, r, res, n, a);
		res = sliyanie(l, mid, r, res, n, a);
	}

	return res;
}
int poisk(int n, int* a)
{
	int chislo, ans2;
	printf("Выберете число для поиска\n");
	scanf_s("%d", &chislo);
	printf("Выберете способ поиска\n");
	printf("1.Линейный поиск\n");
	printf("2.Бинарный поиск\n");
	scanf_s("%d", &ans2);
	while (ans2 > 2 || ans2 < 1)
	{
		printf("Выберете способ поиска повторно\n");
		scanf_s("%d", &ans2);
	}
	if (ans2 == 1)
	{
		for (int i = 0; i < n; i++)//лин поиск
		{
			if (a[i] == chislo)
			{
				return(i);
			}
		}
	}
	else if (ans2 == 2)//бин поиск
	{
		int l = 0, r = n - 1, f = 0, c;
		while (l <= r)
		{
			c = (l + r) / 2;
			if (a[c] == chislo)
			{
				return(c);
			}
			if (a[c] > chislo)
			{
				r = c - 1;
			}
			else
			{
				l = c + 1;
			}
		}
	}
	return(-1);
}
int povtor()
{
	int ok;
	printf("Хотите повторить?\n");
	printf("1 - Да\n");
	printf("2 - Нет\n");
	scanf_s("%d", &ok);
	while (ok > 2 || ok < 1)
	{
		printf("Введите повторно\n");
		scanf_s("%d", &ok);
	}
	if (ok == 1)
	{
		printf("С тем же массивом?\n");
		printf("1 - Да\n");
		printf("2 - Нет\n");
		scanf_s("%d", &ok);
	}
	else
	{
		ok = 0;
	}
	return(ok);
}

unsigned long long vremya() // наносекунды
{
	struct timespec q;
	timespec_get(&q, TIME_UTC);
	return(q.tv_sec * 1000000000 + q.tv_nsec);
}

int main()
{
	int* a = NULL;
	int* user = NULL;
	int n; 
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int ans, ans1, per = 0, srav = 0, chislo, index, ok;
	do
	{
		printf("Введите длину массива\n");
		n = Generation_n();
		printf("Выберите способ ввода массива\n");
		printf("1.Вручную\n");
		printf("2.Случайная генерация\n");
		scanf_s("%d", &ans);
		while (ans < 1 || ans > 2)
		{
			printf("Выберете повторно\n");
			scanf_s("%d", &ans);
		}
		user = malloc(sizeof(int) * n);
		a = malloc(sizeof(int) * n);
		Massiv(ans,n, user);
		do
		{
			ok = 0;
			struct sort_stat res;
			res.srav = 0;
			res.per = 0;
			ans1 = Menu();
			for (int i = 0; i < n; i++)
			{
				a[i] = user[i];
			}
			// засечь время
			unsigned long long time_start = vremya();
			switch(ans1)
			{
				case 1:
				{
					res = def_bubble(n, a);
					break;
				}
				case 2:
				{
					res = vstavka(n, a);
					break;
				}
				case 3:
				{
					res = vibor(n, a);
					break;
				}
				case 4:
				{
					res = podschet(n, a);
					break;
				}
				case 5:
				{
					res = double_bubble(n, a);
					break;
				}
				case 6:
				{
					res = Hoar(0, n - 1, res, n, a);

				}
				case 7:
				{
					res = razbivka(0, n - 1, res, n, a);
					break;
				}
			}
			// засечь время второй раз
			unsigned long long time_end = vremya();
			check(n, a);
			printf("Оригинальный массив:\n");
			for (int i = 0; i < n; i++)
			{
				printf("%d ", user[i]);
			}
			printf("\n");
			printf("Отсортированный массив:\n");
			for (int i = 0; i < n; i++)
			{
				printf("%d ", a[i]);
			}
			printf("\n");
			index = poisk(n,a);
			unsigned time_diff = time_end - time_start;
			if (index == -1)
			{
				printf("Такого числа нет\n");
			}
			else
			{
				printf("Найдено, индекс = %d\n", index);
			}
			printf("Количество сравнений = %d\n", res.srav);
			printf("Количество перестановок = %d\n", res.per);
			printf("Затрачено времени: %d наносекунд\n", time_diff);

			ok = povtor();
		} while (ok == 1);

		free(user);
		free(a);
	} while (ok == 2);
}