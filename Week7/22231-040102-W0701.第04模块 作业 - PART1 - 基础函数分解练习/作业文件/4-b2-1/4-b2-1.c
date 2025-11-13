/* 2253372 康嘉玮 国01 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


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
	return w > 0 ? w: w + 7;
}










int main()
{
	int year, month, day, week;
	int retyear,retmonth,retday;
	int daymax;;
	while (1)
	{
		printf("请输入年[1900-2100]、月、日：\n");
		retyear = scanf("%d", &year);
		retmonth = scanf("%d", &month);
		retday = scanf("%d", &day);

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

		if (!retyear)
		{
			printf("输入错误，请重新输入\n");
			while (getchar() != '\n')
				;
		}

		else if (!retmonth)
		{
			printf("输入错误，请重新输入\n");
			while (getchar() != '\n')
				;
		}
		else if (!retday)
		{
			printf("输入错误，请重新输入\n");
			while (getchar() != '\n')
				;
		}
		else if (year < 1900 || year > 2100)
			printf("年份不正确，请重新输入\n");
		else if (month < 1 || month > 12)
			printf("月份不正确，请重新输入\n");
		else if (day < 1 || day > daymax)
			printf("日不正确，请重新输入\n");
		else
			break;
	}

	week = zeller(year, month, day);
	printf("星期");
	switch (week)
	{
		case 0:
			printf("日\n");
			break;
		case 1:
			printf("一\n");
			break;
		case 2:
			printf("二\n");
			break; 
		case 3:
			printf("三\n");
			break; 
		case 4:
			printf("四\n");
			break;
		case 5:
			printf("五\n");
			break;
		case 6:
			printf("六\n");
			break;
	}

	return 0;
}