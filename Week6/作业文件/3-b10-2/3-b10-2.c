/* 国01 2253372 康嘉玮*/
#include <stdio.h>
#include <windows.h> //取系统时间

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */

	int x1 = 100, x2 = 999, x3 = 1953 - 100 - 999;
	int d1, d2, d3, d4, d5, d6, d7, d8, d9;
	int No = 1;
	while (x1 <= 1953/3)
	{
		d1 = x1 / 100;
		d2 = x1 % 100 / 10;
		d3 = x1 % 10;
		d4 = x2 / 100;
		d5 = x2 % 100 / 10;
		d6 = x2 % 10;
		d7 = x3 / 100;
		d8 = x3 % 100 / 10;
		d9 = x3 % 10;
		if (d1 != d2 && d1 != d3 && d1 != d4 && d1 != d5 && d1 != d6 && d1 != d7 && d1 != d8 && d1 != d9)//因为此算法保证了三个数百位非零，故不再写入判断条件。
			if (d2 != d3 && d2 != d4 && d2 != d5 && d2 != d6 && d2 != d7 && d2 != d8 && d2 != d9 && d2 != 0)
				if (d3 != d4 && d3 != d5 && d3 != d6 && d3 != d7 && d3 != d8 && d3 != d9 && d3 != 0)
					if (d4 != d5 && d4 != d6 && d4 != d7 && d4 != d8 && d4 != d9)
						if (d5 != d6 && d5 != d7 && d5 != d8 && d5 != d9 && d5 != 0)
							if (d6 != d7 && d6 != d8 && d6 != d9 && d6 != 0)
								if (d7 != d8 && d7 != d9)
									if(d8!=d9&&d8!=0)
										if (d9 != 0)//判断各位数互不相同
										{
											printf("No.%3d : %d+%d+%d=%d\n", No, x1, x3, x2, x1 + x2 + x3);
											No++;
										}
		x3++;
		x2--;//为了使三个数的和不变
		if (x2 < x3)
		{
			x2 = 999;
			x1++;
			x3 = 1953 - x1 - x2;//保证x2>=x3
		}
		if (x3 < x1)
		{
				x3 = x1;
				x2 = 1953 - x1 - x3;
		}//保证x3>=x1，即确保x1<=x3<=x2
	}
	printf("total=%d\n", No-1);
	

	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	printf("计数器频率 : %lldHz\n", tick.QuadPart);
	printf("计数器计数 : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f秒\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}