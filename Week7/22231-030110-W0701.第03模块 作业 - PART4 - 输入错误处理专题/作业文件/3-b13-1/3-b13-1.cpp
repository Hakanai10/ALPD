/* 国01 2253372 康嘉玮 */
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int year, month, firstday;
	int day;
	int daymax;
	int i;

	while (1) 
	{
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> year >>month;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(4294967295, '\n');			
		}
		else if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12)
			break;
		cout << "输入非法，请重新输入" << endl;
	}

	while (1)
	{
		cout << "请输入"<<year<<"年"<<month<<"月1日的星期(0-6表示星期日-星期六) : ";
		cin >> firstday;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(4294967295, '\n');
			cout << "输入非法，请重新输入" << endl;
		}
		else if (firstday >= 0 && firstday <= 6)
			break;
		cout << "输入非法，请重新输入" << endl;
	}


	switch (month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			daymax = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			daymax = 30;
			break;
		case 2:
			if (year % 4 == 0)//鉴于年份范围，此处无需写全判断条件
				daymax = 29;
			else
				daymax = 28;
			break;
	}


	cout << endl << year << "年" << month << "月的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	for (i = 1; i <= firstday; i++)
		cout << "        ";
	for (day = 1; day <= daymax; day++,firstday++)
	{
		cout << setw(4) << day << "    ";
		if (firstday % 7 == 6)
			cout << endl;
	}
	cout << endl;

	return 0;
}