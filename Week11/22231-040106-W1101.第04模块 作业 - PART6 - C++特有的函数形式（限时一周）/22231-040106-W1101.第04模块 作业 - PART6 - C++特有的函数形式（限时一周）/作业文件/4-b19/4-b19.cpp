/* 国01 康嘉玮 2253372 */
#include <iostream>
using namespace std;

int min(int x, int y, int z=2147483647, int w=2147483647)
{
	int minimum;
	minimum = x < y ? x : y;
	minimum = minimum < z ? minimum : z;
	minimum = minimum < w ? minimum : w;
	return minimum;
}

int main()
{
	int num, x, y, z, w;
	while (1)
	{
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> num;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(4095, '\n');
		}
		else if (num > 4 || num < 2)
		{
			cout << "个数输入错误" << endl;
			return 0;
		}
		else
		{
			switch (num)
			{
				case 2:
					cin >> x >> y;
					break;
				case 3:
					cin >> x >> y >> z;
					break;
				case 4:
					cin >> x >> y >> z >> w;
					break;
			}
			if (cin.fail())
				cin.clear();
			else if (num == 2 && x > 0 && y > 0)
				break;
			else if (num == 3 && x > 0 && y > 0 && z > 0)
				break;
			else if (num == 4 && x > 0 && y > 0 && z > 0 && w > 0)
				break;															//不能用switch-case，因为switch-case语句中的break不会跳出循环
			cin.ignore(4095, '\n');
		}
	}


	cout << "min=";
	switch (num)
	{
		case 2:
			cout << min(x, y);
			break;
		case 3:
			cout << min(x, y, z);
			break;
		case 4:
			cout << min(x, y, z, w);
			break;
	}
	cout << endl;

	return 0;
}