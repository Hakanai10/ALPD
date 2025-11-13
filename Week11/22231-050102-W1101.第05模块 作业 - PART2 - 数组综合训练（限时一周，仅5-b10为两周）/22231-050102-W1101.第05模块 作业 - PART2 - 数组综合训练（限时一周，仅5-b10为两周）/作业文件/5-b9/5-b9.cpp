/* 国01 康嘉玮 2253372 */
#include <iostream>
using namespace std;

int different_9(int number[9])
{
	int i, j, isdifferent = 0;
	for (i = 0; i < 9; i++)
		for (j = i + 1; j < 9; j++)
			if (number[i] == number[j])
				return 0;
	return 1;
}

int main()
{
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;

	int number[9][9], trans[9][9], box[9][9];
	int x, y, i, j;
	int issolution = 1;
	for (y = 0; y < 9; y++)
		for (x = 0; x < 9; x++)
		{
			while (1)
			{
				cin >> number[y][x];
				if (cin.fail())
				{
					cout << "请重新输入第" << y + 1 << "行" << x + 1 << "列(行列均从1开始计数)的值" << endl;
					cin.clear();
					cin.ignore(4095, '\n');
				}
				else if (number[y][x] < 1 || number[y][x] > 9)
					cout << "请重新输入第" << y + 1 << "行" << x + 1 << "列(行列均从1开始计数)的值" << endl;
				else
					break;
			}
		}

	for (y = 0; y < 9; y++)
		for (x = 0; x < 9; x++)
			trans[x][y] = number[y][x];											//行列交换

	for (y = 0; y < 9; y++)
		for (x = 0; x < 9; x++)
		{
			i = y / 3 * 3 + x / 3;
			j = y % 3 * 3 + x % 3;
			box[i][j] = number[x][y];
		}																		//将原来的矩阵按照九宫格划分开来

	for (y = 0; y < 9; y++)
		if (!different_9(number[y]))
			issolution = 0;
	for (x = 0; x < 9; x++)
		if (!different_9(trans[x]))
			issolution = 0;
	for (i = 0; i < 9; i++)
		if (!different_9(box[i]))
			issolution = 0;
	//每行、每列、每个九宫格都没有重复元素则是解，否则不是。此三处选用的循环变量名可以是x，y，i，j中的任何一个，作用相同。


	if (!issolution)
		cout << "不";
	cout << "是数独的解" << endl;

	return 0;
}