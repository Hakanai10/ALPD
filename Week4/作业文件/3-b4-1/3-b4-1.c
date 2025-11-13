//国01 康嘉玮 2253372
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	printf("请输入三角形的两边及其夹角(角度)\n");
	int a, b, angle;
	scanf("%d%d%d", &a, &b, &angle);
	float S;
	S =(float)( 1.0 / 2.0 * a * b * sin(angle / 180.0 * 3.14159));
	printf("三角形面积为 : %.3f", S);
	return 0;
}
