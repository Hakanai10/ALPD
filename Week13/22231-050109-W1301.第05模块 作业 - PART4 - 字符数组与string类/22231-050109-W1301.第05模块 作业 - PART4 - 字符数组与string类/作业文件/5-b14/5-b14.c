/* 2253372 ¿µ¼Îçâ ¹ú01 */
/* 2251883 ÁõÉùìä 2252498 ÌÆÎÄÔ´ 2252543 ÖÜèªè¤ 2251739 ÍõÔÆÅô 2250882 ´÷ºë±ó */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define X 26
#define Y 10
#define MINE_NUM 50

int num_of_mines(int array[Y][X], int x, int y)
{
	int num = 0;
	int i, j;

	for (i = (y == 0 ? y : y - 1); i <= (y == Y - 1 ? y : y + 1); i++)
		for (j = (x == 0 ? x : x - 1); j <= (x == X - 1 ? x : x + 1); j++)
		{
			if (i == y && j == x)
				continue;
			if (array[i][j] == -1)
				num++;
		}

	return num;
}

int main()
{
	int array[Y][X] = { 0 };
	int i, j;
	int numerror = 0;

	for (i = 0; i < Y; i++)
		for (j = 0; j < X; j++)
			if (!scanf("%d", &array[i][j]))
			{
				array[i][j] = -1;
				getchar();
			}

	int sum_of_mines = 0;
	for (i = 0; i < Y; i++)
	{
		for (j = 0; j < X; j++)
			if (array[i][j] == -1)
				sum_of_mines++;
			else if(array[i][j]!= num_of_mines(array, j, i))
				numerror = 1;
	}



	if (sum_of_mines != MINE_NUM)
		printf("´íÎó1\n");
	else if (numerror)
		printf("´íÎó2\n");
	else
		printf("ÕıÈ·\n");

	return 0;
}