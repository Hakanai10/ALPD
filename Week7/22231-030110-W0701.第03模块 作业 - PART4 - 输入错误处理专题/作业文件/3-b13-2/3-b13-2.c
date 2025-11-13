/* 国01 2253372 康嘉玮 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int year, month, firstday;
	int day;
	int daymax;
	int i;
	int ret1,ret2,ret;//输出函数返回值


	while (1)
	{
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		ret1 = scanf("%d", &year);
		ret2 = scanf("%d", &month);
		if (ret1 && ret2 && year >= 2000 && year <= 2030 && month >= 1 && month <= 12)
			break;
		else if (!ret1)
			while (getchar() != '\n')
				;
		else if (!ret2)
			while (getchar() != '\n')
				;
		printf("输入非法，请重新输入\n");
	}


	while (1)
	{
		printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ", year, month);
		ret = scanf("%d", &firstday);
		if (firstday >= 0 && firstday <= 6)
			break;
		else if (!ret)
			while (getchar() != '\n')
				;
		printf("输入非法，请重新输入\n");
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

	printf("\n%d年%d月的月历为:\n", year, month);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
	for (i = 1; i <= firstday; i++)
		printf("        ");
	for (day = 1; day <= daymax; day++, firstday++)
	{
		printf("%4d    ",day);
		if (firstday % 7 == 6)
			printf("\n");
	}
	printf("\n");

	return 0;
}