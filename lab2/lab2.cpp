#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	clock_t start, end; // объявляем переменные для определения времени выполнения

	int i = 0, j = 0, r;
	int elem_c;
	int n = 10000;
	int** a;
	a = (int**)malloc(n * sizeof(int*));
	int** b;
	b = (int**)malloc(n * sizeof(int*));
	int** c;
	c = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		a[i] = (int*)malloc(n * sizeof(int));
		b[i] = (int*)malloc(n * sizeof(int));
		c[i] = (int*)malloc(n * sizeof(int));
	}

	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i < n)
	{
		while (j < n)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i < n)
	{
		while (j < n)
		{
			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}

	start = clock();
	printf("%f", float(start) / float(CLOCKS_PER_SEC));

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			elem_c = 0;
			for (r = 0; r < n; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}

	end = clock();
	printf("\n%f", float(end) / float(CLOCKS_PER_SEC));
	printf("\n%f", float(end - start) / float(CLOCKS_PER_SEC));

	free(a);
	free(b);
	free(c);
	return(0);
}
