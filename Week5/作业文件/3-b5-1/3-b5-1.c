//国01 康嘉玮 2253372
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("请输入年，月，日\n");

	int year, month, day;
	int leap = 0;																		//闰年标记
	int dayerror = 0, monerror = 0;														//错误标记
	int daysum;

	scanf("%d%d%d", &year, &month, &day);

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		leap = 1;//如为闰年，闰年标记置1
	switch (month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (day <= 0 || day > 31)
				dayerror = 1;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (day <= 0 || day > 30)
				dayerror = 1;
			break;
		case 2:
			if (leap && (day <= 0 || day > 29) || !leap && (day <= 0 || day > 28))
				dayerror = 1;
			break;
		default:
			printf("输入错误-月份不正确\n");
			monerror = 1;
			break;
	}//如有错，相应错误标记置1
	if(!monerror)
	{ 
		if (dayerror)
			printf("输入错误-日与月的关系非法\n");
		else
		{
			switch (month)
			{
				case 1:
					daysum = day;
					break;
				case 2:
					daysum = day + 31;
					break;
				case 3:
					daysum = day + 59 + leap;
					break;
				case 4:
					daysum = day + 90 + leap;
					break;
				case 5:
					daysum = day + 120 + leap;
					break;
				case 6:
					daysum = day + 151 + leap;
					break;
				case 7:
					daysum = day + 181 + leap;
					break;
				case 8:
					daysum = day + 212 + leap;
					break;
				case 9:
					daysum = day + 243 + leap;
					break;
				case 10:
					daysum = day + 273 + leap;
					break;
				case 11:
					daysum = day + 304 + leap;
					break;
				case 12:
					daysum = day + 334 + leap;
					break;
			}
			printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, daysum);
		}	
	}
	return 0;
}