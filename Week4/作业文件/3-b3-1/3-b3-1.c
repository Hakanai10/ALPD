//国01 康嘉玮 2253372
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("请输入[0-100亿)之间的数字:\n");
	double n;
	scanf("%lf", &n);
	n = n + 0.005;																				//四舍五入到百分位

	int shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, yuan, jiao, fen;
	shiyi = (int)(n / 1000000000.0);															//将n的十亿位求出来

	n = n - shiyi * 1000000000.0;																//去除十亿位，使n整数部分在int范围内
	yi = (int)n / 100000000;
	qianwan = (int)n % 100000000 / 10000000;
	baiwan = (int)n % 10000000 / 1000000;
	shiwan = (int)n % 1000000 / 100000;
	wan = (int)n % 100000 / 10000;
	qian = (int)n % 10000 / 1000;
	bai = (int)n % 1000 / 100;
	shi = (int)n % 100 / 10;
	yuan = (int)n % 10;

	n = (n - (int)n) * 100;																		//n的小数点后前两位
	jiao = (int)n % 100 / 10;
	fen = (int)n % 10;

	printf("十亿位 : %d\n", shiyi);
	printf("亿位   : %d\n", yi);
	printf("千万位 : %d\n", qianwan);
	printf("百万位 : %d\n", baiwan);
	printf("十万位 : %d\n", shiwan);
	printf("万位   : %d\n", wan);
	printf("千位   : %d\n", qian);
	printf("百位   : %d\n", bai);
	printf("十位   : %d\n", shi);
	printf("圆     : %d\n", yuan);
	printf("角     : %d\n", jiao);
	printf("分     : %d\n", fen);
	return 0;
}
