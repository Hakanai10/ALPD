/* 2253372 康嘉玮 国01 */
#include <iostream>
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










int main()
{
	int year, month, day, week;
	int daymax;;
	while (1)
	{
		cout << "请输入年[1900-2100]、月、日：" << endl;
		cin >> year >> month >> day;

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
				if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)//鉴于年份范围，此处必须写全判断条件
					daymax = 29;
				else
					daymax = 28;
				break;
		}

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
		else if (day < 1 || day > daymax)
			cout << "日不正确，请重新输入" << endl;
		else
			break;
	}


	week = zeller(year, month, day);
	cout<<"星期"<<endl;
	switch (week)
	{
		case 0:
			cout << "日" << endl;
			break;
		case 1:
			cout << "一" << endl;
			break;
		case 2:
			cout << "二" << endl;
			break;
		case 3:
			cout << "三" << endl;
			break;
		case 4:
			cout << "四" << endl;
			break;
		case 5:
			cout << "五" << endl;
			break;
		case 6:
			cout << "六" << endl;
			break;
	}
}