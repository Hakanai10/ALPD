//国01 康嘉玮 2253372
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("请输入一个[1..30000]间的整数:\n");
	int n, wan, qian, bai, shi, ge;
	scanf("%d", &n);
	wan = n / 10000;
	qian = n % 10000 / 1000;
	bai = n % 1000/ 100;
	shi = n % 100 / 10;
	ge = n % 10;
	printf("万位 : %d\n", wan);
	printf("千位 : %d\n", qian);
	printf("百位 : %d\n", bai);
	printf("十位 : %d\n", shi);
	printf("个位 : %d\n", ge);
	return 0;
}
