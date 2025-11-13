/* 2253372 康嘉玮 国01 */
#include <iostream>
#include <iomanip>
using namespace std;


int zeller(int y, int m, int d)
{
	int century = y / 100, year = y % 100;
	int w;
	if (m <= 2)
	{
		m = m + 12;
		year--;
		if (year < 0)
		{
			century--;
			year = 99;
		}
	}
	w = (year + year / 4 + century / 4 - 2 * century + 13 * (m + 1) / 5 + d - 1) % 7;
	return w > 0 ? w : w + 7;
}



void calendar(int year,int month,int firstday)
{
	int daymax;
	int i, day;

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
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)//鉴于年份范围，此处无需写全判断条件
				daymax = 29;
			else
				daymax = 28;
			break;
	}

	cout << endl << year << "年" << month << "月" << endl;
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;
	for (i = 1; i <= firstday; i++)
		cout << "        ";
	for (day = 1; day <= daymax; day++, firstday++)
	{
		cout << setw(4) << day << "    ";
		if (firstday % 7 == 6)
			cout << endl;
	}
	cout << endl;
}





int main()
{
	int year, month, firstday;

	while (1)
	{
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> year >> month;
		if (!cin.good())
		{
			cout << "输入错误，请重新输入" << endl;
			cin.clear();
			cin.ignore(4294967295, '\n');
		}
		else if (year < 1900 || year > 2100)
			cout << "年份不正确，请重新输入" << endl;
		else if (month < 1 || month > 12)
			cout << "月份不正确，请重新输入" << endl;
		else
			break;
	}


	firstday = zeller(year, month, 1);

	calendar(year, month, firstday);
	return 0;
}