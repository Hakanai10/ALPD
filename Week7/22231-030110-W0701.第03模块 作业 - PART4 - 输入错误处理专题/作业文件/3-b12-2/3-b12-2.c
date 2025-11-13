/* 国01 2253372 康嘉玮 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ret, x;

	while (1) {
		printf("请输入x的值[0-100] : ");
		ret = scanf("%d", &x); //读入x的方式必须是scanf且格式符为%d，不准用非scanf
		if (ret == 1 && (x >= 0 && x <= 100))
			break;
		else if (!ret)
			while (getchar() != '\n')
				;//如果输入有非法字符，则什么都不做，直到读取到换行符，然后执行下面的错误信息输出，再重新执行循环。
		printf("输入有错[ret=%d x=%d],请重新输入\n", ret, x); //确认一下，ret的值（即scanf的返回值）是什么含义？ 
															  //scanf的返回值是正常读取的格式控制符的个数。ret==0表示没有正常输入。
	}

	printf("ret=%d x=%d\n", ret, x);

	return 0;
}
