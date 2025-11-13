//国01 康嘉玮 2253372
#include <iostream>
#include <iomanip>
using namespace std;

int zeller(int y, int m, int d)
{
	if (m <= 2)
	{
		m = m + 12;
		y--;
	}
	int century = y / 100, year = y % 100;
	int w = (year + year / 4 + century / 4 - 2 * century + 13 * (m + 1) / 5 + d - 1) % 7;			
	if (w < 0)
		w += 7;																	//用w表示给定的日期是周几，但按Zeller公式有可能得到负值，此时需+7使之变为正值
	return w;
}

void printchar(char ch, int num)
{
	for (; num >= 1; num--)
		cout << ch;
}

void print_calendar(int y)
{
	int max_of_day[13] = { 0,31,28 + (y % 4 == 0 && y % 100 != 0 || y % 400 == 0),31,30,31,30,31,31,30,31,30,31 };
	int line;
	int month = 1;
	int printingday[4] = { 0,1,1,1 };
	int weekday[4] = { 0,1,1,1 };
	for (line = 1; line <= 4; line++)
	{
		int i;
		for (i = 1; i <= 3; i++)
		{
			printchar(' ', 11);
			cout << setw(2) << month << "月";
			month++;
			if (i == 3)
				break;
			printchar(' ', 17);
		}
		cout << endl;

		for (i = 1; i <= 3; i++)
		{
			cout << "Sun Mon Tue Wed Thu Fri Sat";
			if (i == 3)
				break;
			printchar(' ', 5);
		}
		cout << endl;

		cout << setiosflags(ios::left);
		month -= 3;
		while (printingday[1] <= max_of_day[month] || printingday[2] <= max_of_day[month + 1] || printingday[3] <= max_of_day[month + 2])
		{
			for (i = 1; i <= 3; i++)
			{
				weekday[i] = zeller(y, month, printingday[i]);
				printchar(' ', weekday[i] * 4);
				for (; weekday[i] != 7; printingday[i]++, weekday[i]++)
				{
					cout << setw(4);
					if (printingday[i] <= max_of_day[month])
						cout << printingday[i];
					else
						cout << ' ';
				}
				weekday[i] = 0;
				if (i == 3)
				{
					cout << endl;
					month -= 2;
				}
				else
				{
					printchar(' ', 4);
					month++;
				}
			}
		}
		cout << resetiosflags(ios::left) << endl;
		for (i = 1; i <= 3; i++)
			printingday[i] = 1;
		month += 3;
	}
	cout << endl;
}

int main()
{
	int year;

	while (1)
	{
		cout << "请输入年份[1900-2100]" << endl;

		cin >> year;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(4095, '\n');
		}
		else if (year >= 1900 && year <= 2100)
			break;
	}

	cout << year << "年的日历:" << endl << endl;
	print_calendar(year);

	return 0;
}