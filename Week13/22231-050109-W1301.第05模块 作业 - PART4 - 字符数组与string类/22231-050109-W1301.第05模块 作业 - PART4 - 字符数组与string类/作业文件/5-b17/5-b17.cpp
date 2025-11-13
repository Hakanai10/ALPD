/* 国01 2253372 康嘉玮 */
#include <iostream>
#include <time.h>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?";

int main()
{
	int len, capital, small, number, others;

	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;

	cin >> len >> capital >> small >> number >> others;
	if (cin.fail())
		cout << "输入非法" << endl;
	else if (len < 12 || len > 16)
		cout << "密码长度[" << len << "]不正确" << endl;
	else if (capital < 2 || capital > len)
		cout << "大写字母个数[" << capital << "]不正确" << endl;
	else if (small < 2 || small > len)
		cout << "小写字母个数[" << small << "]不正确" << endl;
	else if (number < 2 || number > len)
		cout << "数字个数[" << number << "]不正确" << endl;
	else if (others < 2 || others > len)
		cout << "其它符号个数[" << others << "]不正确" << endl;
	else if (capital + small + number + others > len)
		cout << "所有字符类型之和[" << capital << "+" << small << "+" << number << "+" << others << "]大于总密码长度[" << len << "]" << endl;
	else
	{	
		cout << len << " " << capital << " " << small << " " << number << " " << others << endl;
		srand((unsigned int)(time(0)));

		int j;
		for (j = 0; j < 10; j++)
		{
			char password[17] = { 0 };
			int i;
			int type[17];
			int num[4] = { 0,0,0,0 };											//0代表大写，1代表小写，2代表数字，3代表其它

			for (i = 0; i < 17; i++)
				type[i] = -1;

			do
			{
				for (i = 0; i < 4; i++)
					num[i] = 0;
				for (i = 0; i < len; i++)
				{
					type[i] = rand() % 4;
					num[type[i]]++;
				}
			} while (!(num[0] >= capital && num[1] >= small && num[2] >= number && num[3] >= others));

			for (i = 0; i < len; i++)
			{
				switch (type[i])
				{
					case 0:
						password[i] = rand() % 26 + 'A';
						break;
					case 1:
						password[i] = rand() % 26 + 'a';
						break;
					case 2:
						password[i] = rand() % 10 + '0';
						break;
					case 3:
						password[i] = other[rand() % 15];
				}
			}

			printf("%s\n", password);
		}
	}

	return 0;
}