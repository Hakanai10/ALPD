/* ¹ú01 2253372 ¿µ¼Îçâ */
#include <iostream>
#include <time.h>
using namespace std;

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
	srand((unsigned int)(time(0)));
	int array[Y][X] = { 0 };
	int i, j;
	int mine_x[MINE_NUM], mine_y[MINE_NUM];
	for (i = 0; i < MINE_NUM; i++)
	{
		do
		{
			mine_x[i] = rand() % X;
			mine_y[i] = rand() % Y;
		} while (array[mine_y[i]][mine_x[i]] == -1);
		array[mine_y[i]][mine_x[i]] = -1;
	}
	for (i = 0; i < Y; i++)
		for (j = 0; j < X; j++)
			if (array[i][j] != -1)
				array[i][j] = num_of_mines(array, j, i);

	for (i = 0; i < Y; i++)
	{
		for (j = 0; j < X; j++)
			if (array[i][j] != -1)
				cout << array[i][j] << " ";
			else
				cout << "* ";
		cout << endl;
	}

	return 0;
}