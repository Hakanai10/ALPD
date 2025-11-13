/* 国01 2253372 康嘉玮 */
#include <iostream>
using namespace std;

int main()
{
	char str[3][128];
	int i;
	for (i = 0; i < 3; i++)
	{
		cout << "请输入第" << i + 1 << "行" << endl;
		fgets(str[i], 128, stdin);
	}

	int capital = 0, small = 0, number = 0, space = 0, other = 0;
	for (i = 0; i < 3; i++)
	{
		int pointer;
		for (pointer = 0; str[i][pointer] != '\0' && str[i][pointer] != '\n'; pointer++)
		{
			if (str[i][pointer] >= 'A' && str[i][pointer] <= 'Z')
				capital++;
			else if (str[i][pointer] >= 'a' && str[i][pointer] <= 'z')
				small++;
			else if (str[i][pointer] >= '0' && str[i][pointer] <= '9')
				number++;
			else if (str[i][pointer] == ' ')
				space++;
			else
				other++;
		}
	}

	cout << "大写 : " << capital << endl;
	cout << "小写 : " << small << endl;
	cout << "数字 : " << number << endl;
	cout << "空格 : " << space << endl;
	cout << "其它 : " << other << endl;

	return 0;
}