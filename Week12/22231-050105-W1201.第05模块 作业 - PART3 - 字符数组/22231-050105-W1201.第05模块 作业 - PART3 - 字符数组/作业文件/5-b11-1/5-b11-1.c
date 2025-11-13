/* 国01 2253372 康嘉玮 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖";
char result[256];

void print_daxie(double data)
{
	int ji[3] = { 0 };
	int demical[3] = { 0 };
	int i;
	int pointer = 0;
	char name_of_ji[] = "个万亿", name_of_digit[] = "个拾佰仟", name_of_demical[] = "圆角分", zheng[] = "整";
	data += 0.005;																//修正存储误差

	{
		double datatemp = data;
		for (i = 0; i < 3; i++)
		{
			ji[i] = (int)(datatemp - (int)(datatemp / 10000) * 10000.0);
			datatemp = datatemp / 10000;
		}
	}

	data = data - (ji[2] * 1e8 + ji[1] * 1e4 + ji[0]);

	{
		double datatemp = data;
		for (i = 1; i < 3; i++)
		{
			demical[i] = (int)(datatemp * 10);
			datatemp = datatemp * 10 - demical[i];
		}
	}

	for (i = 2; i >= 0; i--)
	{
		int j;
		int digit[4] = { 0 };
		{
			int jitemp = ji[i];
			for (j = 0; j < 4; j++)
			{
				digit[j] = jitemp % 10;
				jitemp /= 10;
			}
		}

		for (j = 3; j >= 0; j--)
		{
			if (digit[j])
			{
				result[pointer] = chnstr[2 * digit[j]];
				result[pointer + 1] = chnstr[2 * digit[j] + 1];
				pointer += 2;
				if (j)
				{
					result[pointer] = name_of_digit[2 * j];
					result[pointer + 1] = name_of_digit[2 * j + 1];
					pointer += 2;
				}
			}
			else
			{
				int itemp = i, jtemp = j;
				int printzero = 0;
				switch (j)
				{
					case 3:
						for (itemp = 2; itemp > i; itemp--)
							if (ji[itemp] != 0)
							{
								for (jtemp = 2; jtemp >= 0; jtemp--)
									if (digit[jtemp] != 0)
									{
										printzero = 1;
										break;
									}
								break;
							}
						break;
					case 2:
						if (digit[3] != 0 && (digit[1] != 0 || digit[0] != 0))
							printzero = 1;
						break;
					case 1:
						if (digit[2] != 0 && digit[0] != 0)
							printzero = 1;
						break;
					case 0:
						if (!(ji[2] || ji[1] || ji[0] || demical[1] || demical[2]) && i == 0)
							printzero = 1;
						break;

				}
				if (printzero)
				{
					result[pointer] = chnstr[0];
					result[pointer + 1] = chnstr[1];
					pointer += 2;
				}
			}
		}

		if (ji[i] && i)
		{
			result[pointer] = name_of_ji[2 * i];
			result[pointer + 1] = name_of_ji[2 * i + 1];
			pointer += 2;
		}
	}

	/*判断是否输出"圆"*/
	if (ji[2] || ji[1] || ji[0])
	{
		result[pointer] = name_of_demical[0];
		result[pointer + 1] = name_of_demical[1];
		pointer += 2;
	}
	else if(!(demical[1] || demical[2]))
	{
		result[pointer] = name_of_demical[0];
		result[pointer + 1] = name_of_demical[1];
		pointer += 2;
	}

	if (demical[1] || demical[2])
	{
		for (i = 1; i < 3; i++)
		{
			if (demical[i])
			{
				result[pointer] = chnstr[2 * demical[i]];
				result[pointer + 1] = chnstr[2 * demical[i] + 1];
				pointer += 2;
				result[pointer] = name_of_demical[2 * i];
				result[pointer + 1] = name_of_demical[2 * i + 1];
				pointer += 2;
			}
			else if (i == 1 && (ji[2] || ji[1] || ji[0]))
			{
				result[pointer] = chnstr[0];
				result[pointer + 1] = chnstr[1];
				pointer += 2;
			}
		}
	}

	if (!demical[2])
	{
		result[pointer] = zheng[0];
		result[pointer + 1] = zheng[1];
		pointer += 2;
	}

	printf("%s\n", result);
}

int main()
{
	double data;
	while (1)
	{
		printf("请输入[0-100亿)之间的数字:\n");
		if (!scanf("%lf", &data))
			while (getchar() != '\n')
				;
		else if (data >= 0 && data < 1e10)
			break;
	}

	printf("大写结果是:\n");
	print_daxie(data);

	return 0;
}