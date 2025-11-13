/* 国01 康嘉玮 2253372 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int leap(int year)
{
	if (year % 100 == 0)
		year /= 100;
	return !(year % 4);
}

int number_of_day(int year, int month, int day)
{
	int base_of_day[12] = { 0,31,59 + leap(year),90 + leap(year),
							120 + leap(year),151 + leap(year),181 + leap(year),212 + leap(year) ,
							243 + leap(year),273 + leap(year),304 + leap(year),334 + leap(year) };
	return base_of_day[month - 1] + day;
}

int main()
{
	printf("请输入年，月，日\n");

	int year, month, day;
	scanf("%d%d%d", &year, &month, &day);
	int daymax[12] = { 31,28 + leap(year),31,30,31,30,31,31,30,31,30,31 };

	if (month <= 0 || month > 12)
		printf("输入错误-月份不正确");
	else if (day <= 0 || day > daymax[month - 1])
		printf("输入错误-日与月的关系非法");
	else
		printf("%d-%d-%d是%d年的第%d天", year, month, day, year, number_of_day(year, month, day));

	return 0;
}