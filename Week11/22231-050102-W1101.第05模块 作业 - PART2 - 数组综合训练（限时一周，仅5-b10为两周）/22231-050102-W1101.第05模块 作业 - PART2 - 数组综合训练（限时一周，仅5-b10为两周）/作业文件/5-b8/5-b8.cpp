/* 国01 康嘉玮 2253372 */
#include <iostream>
using namespace std;

int isconvex(int num, double location[][2])
{
	int isconvex = 1;
	int i;
	double product[7];
	for (i = 0; i < num; i++)
	{
		double x1, x2, y1, y2;
		x1 = location[(i + 1) % num][0] - location[i][0];
		x2 = location[(i + 2) % num][0] - location[(i + 1) % num][0];
		y1 = location[(i + 1) % num][1] - location[i][1];
		y2 = location[(i + 2) % num][1] - location[(i + 1) % num][1];
		product[i] = x1 * y2 - x2 * y1;
	}
	for (i = 0; i < num; i++)
	{
		if (product[i] * product[(i + 1) % num] < 0)
			isconvex = 0;
	}
	return isconvex;
}

double area(int num, double location[][2])
{
	int i;
	double area = 0;
	for (i = 1; i < num - 1; i++)
	{
		double x1, x2, y1, y2;
		x1 = location[i][0] - location[0][0];
		x2 = location[i + 1][0] - location[0][0];
		y1 = location[i][1] - location[0][1];
		y2 = location[i + 1][1] - location[0][1];
		area += (x1 * y2 - x2 * y1) / 2.0;
	}
	return area > 0 ? area : -area;
}



int main()
{
	int num;
	double location[7][2];
	int i;
	while (1)
	{
		cout << "请输入多边形的顶点数量(4-7)" << endl;
		cin >> num;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(4096, '\n');
		}
		else if (num >= 4 && num <= 7)
			break;
	}
	cout << "请按顺时针/逆时针方向输入" << num << "个顶点的x,y坐标：" << endl;
	for (i = 0; i < num; i++)
	{
		while (1)
		{
			cout << "请输入第" << i + 1 << "个顶点的坐标：" << endl;
			cin >> location[i][0] >> location[i][1];
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(4096, '\n');
			}
			else
				break;
		}
	}

	if (!isconvex(num, location))
		cout << "不是凸" << num << "边形" << endl;
	else
		cout << "凸" << num << "边形的面积=" << area(num, location) << endl;

	return 0;
}
