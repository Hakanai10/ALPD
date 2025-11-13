/* 国01 2253372 康嘉玮 */
#include <iostream>
#include <cstring>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?";

int main()
{
	while (getchar() != '\n')
		;																		//忽略第一行

	int len, capital, small, number, others;
	int error = 0;

	cin >> len >> capital >> small >> number >> others;
	if (cin.fail())
		error = 1;
	else if (len < 12 || len > 16)
		error = 1;
	else if (capital < 2 || capital > len)
		error = 1;
	else if (small < 2 || small > len)
		error = 1;
	else if (number < 2 || number > len)
		error = 1;
	else if (others < 2 || others > len)
		error = 1;
	else if (capital + small + number + others > len)
		error = 1;
	else
	{
		int j;
		for (j = 0; j < 10; j++)
		{
			char password[17] = { 0 };
			int i;
			int num[4] = { 0,0,0,0 };											//0代表大写，1代表小写，2代表数字，3代表其它

			getchar();															//读取并忽略上一行的换行符
			for (i = 0; i < len; i++)
			{
				password[i] = getchar();
				if (password[i] >= 'A' && password[i] <= 'Z')
					num[0]++;
				else if (password[i] >= 'a' && password[i] <= 'z')
					num[1]++;
				else if (password[i] >= '0' && password[i] <= '9')
					num[2]++;
				else if (strchr(other, password[i]))
					num[3]++;
			}

			if (!(num[0] >= capital && num[1] >= small && num[2] >= number && num[3] >= others))
			{
				error = 1;
				break;
			}

		}
	}

	if (error)
		cout << "错误" << endl;
	else
		cout << "正确" << endl;

	return 0;
}