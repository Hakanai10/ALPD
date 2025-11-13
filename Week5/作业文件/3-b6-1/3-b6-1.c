//国01 康嘉玮 2253372
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("请输入[0-100亿)之间的数字:\n");
	double n, n_;
	scanf("%lf", &n);
	n = n + 0.001;//误差修正
	int shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, yuan, jiao, fen;
	int yiji, wanji, geji;//亿级、万级、个级
	double xiaoshu;//小数
	int xiaoshu_;//用于存储十分位和百分位

	yiji = (int)(n / 100000000);
	n_ = n - yiji * 100000000.0;//将n的值缩小到int的范围内，以便强制类型转换
	wanji = (int)n_ / 10000;
	geji = (int)n_ % 10000;
	xiaoshu = n_ - (int)n_;

	shiyi = yiji / 10;
	yi = yiji % 10;

	qianwan = wanji / 1000;
	baiwan = wanji % 1000 / 100;
	shiwan = wanji % 100 / 10;
	wan = wanji % 10;

	qian = geji / 1000;
	bai = geji % 1000 / 100;
	shi = geji % 100 / 10;
	yuan = geji % 10;

	xiaoshu_ = (int)(xiaoshu * 100);
	jiao = xiaoshu_ / 10;
	fen = xiaoshu_ % 10;

	//以下是输出处理
	printf("大写结果是:\n");

	if (yiji)
	{
		switch (shiyi)
		{
			case 1:
				printf("壹拾");
				break;
			case 2:
				printf("贰拾");
				break;
			case 3:
				printf("叁拾");
				break;
			case 4:
				printf("肆拾");
				break;
			case 5:
				printf("伍拾");
				break;
			case 6:
				printf("陆拾");
				break;
			case 7:
				printf("柒拾");
				break;
			case 8:
				printf("捌拾");
				break;
			case 9:
				printf("玖拾");
				break;
		}
		switch (yi)
		{
			case 1:
				printf("壹");
				break;
			case 2:
				printf("贰");
				break;
			case 3:
				printf("叁");
				break;
			case 4:
				printf("肆");
				break;
			case 5:
				printf("伍");
				break;
			case 6:
				printf("陆");
				break;
			case 7:
				printf("柒");
				break;
			case 8:
				printf("捌");
				break;
			case 9:
				printf("玖");
				break;
		}
		printf("亿");
	}



	if (wanji)
	{
		switch (qianwan)
		{
			case 0:
				if (yiji && (baiwan || shiwan || wan))
					printf("零");//如果亿级为0并且万级后三位不全为0，则要读
				break;
			case 1:
				printf("壹仟");
				break;
			case 2:
				printf("贰仟");
				break;
			case 3:
				printf("叁仟");
				break;
			case 4:
				printf("肆仟");
				break;
			case 5:
				printf("伍仟");
				break;
			case 6:
				printf("陆仟");
				break;
			case 7:
				printf("柒仟");
				break;
			case 8:
				printf("捌仟");
				break;
			case 9:
				printf("玖仟");
				break;
		}
		switch (baiwan)
		{
			case 0:
				if (qianwan && (shiwan || wan))
					printf("零");//如果千万位非零且万级后两位不全是0，则要读
				break;
			case 1:
				printf("壹佰");
				break;
			case 2:
				printf("贰佰");
				break;
			case 3:
				printf("叁佰");
				break;
			case 4:
				printf("肆佰");
				break;
			case 5:
				printf("伍佰");
				break;
			case 6:
				printf("陆佰");
				break;
			case 7:
				printf("柒佰");
				break;
			case 8:
				printf("捌佰");
				break;
			case 9:
				printf("玖佰");
				break;
		}
		switch (shiwan)
		{
			case 0:
				if (baiwan && wan)
					printf("零");//如果百万位和万位均非零则要读
				break;
			case 1:
				printf("壹拾");
				break;
			case 2:
				printf("贰拾");
				break;
			case 3:
				printf("叁拾");
				break;
			case 4:
				printf("肆拾");
				break;
			case 5:
				printf("伍拾");
				break;
			case 6:
				printf("陆拾");
				break;
			case 7:
				printf("柒拾");
				break;
			case 8:
				printf("捌拾");
				break;
			case 9:
				printf("玖拾");
				break;
		}
		switch (wan)
		{
			case 1:
				printf("壹");
				break;
			case 2:
				printf("贰");
				break;
			case 3:
				printf("叁");
				break;
			case 4:
				printf("肆");
				break;
			case 5:
				printf("伍");
				break;
			case 6:
				printf("陆");
				break;
			case 7:
				printf("柒");
				break;
			case 8:
				printf("捌");
				break;
			case 9:
				printf("玖");
				break;
		}
		printf("万");
	}



	if (!geji)
	{
		if (!yiji && !wanji && !xiaoshu_)
			printf("零");//原数为0时要读，否则不读
	}
	else
	{
		switch (qian)
		{
			case 0:
				if ((yiji || wanji) && (bai || shi || yuan))
					printf("零");//前面不全是0和后三位不全是0时要读0
				break;
			case 1:
				printf("壹仟");
				break;
			case 2:
				printf("贰仟");
				break;
			case 3:
				printf("叁仟");
				break;
			case 4:
				printf("肆仟");
				break;
			case 5:
				printf("伍仟");
				break;
			case 6:
				printf("陆仟");
				break;
			case 7:
				printf("柒仟");
				break;
			case 8:
				printf("捌仟");
				break;
			case 9:
				printf("玖仟");
				break;
		}
		switch (bai)
		{
			case 0:
				if (qian && (shi || yuan))
					printf("零");//千位非0且十位和个位不全是0时要读0
				break;
			case 1:
				printf("壹佰");
				break;
			case 2:
				printf("贰佰");
				break;
			case 3:
				printf("叁佰");
				break;
			case 4:
				printf("肆佰");
				break;
			case 5:
				printf("伍佰");
				break;
			case 6:
				printf("陆佰");
				break;
			case 7:
				printf("柒佰");
				break;
			case 8:
				printf("捌佰");
				break;
			case 9:
				printf("玖佰");
				break;
		}
		switch (shi)
		{
			case 0:
				if (bai && yuan)//百位和个位均非0时要读
					printf("零");
				break;
			case 1:
				printf("壹拾");
				break;
			case 2:
				printf("贰拾");
				break;
			case 3:
				printf("叁拾");
				break;
			case 4:
				printf("肆拾");
				break;
			case 5:
				printf("伍拾");
				break;
			case 6:
				printf("陆拾");
				break;
			case 7:
				printf("柒拾");
				break;
			case 8:
				printf("捌拾");
				break;
			case 9:
				printf("玖拾");
				break;
		}
		switch (yuan)
		{
			case 1:
				printf("壹");
				break;
			case 2:
				printf("贰");
				break;
			case 3:
				printf("叁");
				break;
			case 4:
				printf("肆");
				break;
			case 5:
				printf("伍");
				break;
			case 6:
				printf("陆");
				break;
			case 7:
				printf("柒");
				break;
			case 8:
				printf("捌");
				break;
			case 9:
				printf("玖");
				break;
		}
	}
	if ((int)n||!xiaoshu_)
		printf("圆");//如果整数部分不是0或者整数部分和小数部分均为0，则输出圆；如果整数部分是0且小数部分不是0，则只输出角和分

	if (!xiaoshu_)
		printf("整\n");
	else
	{
		if (!jiao)
			if((int)n)
				printf("零");//整数部分非0且十分位为0时要读0
			else
				;
		else
		{
			switch (jiao)
			{
				case 1:
					printf("壹");
					break;
				case 2:
					printf("贰");
					break;
				case 3:
					printf("叁");
					break;
				case 4:
					printf("肆");
					break;
				case 5:
					printf("伍");
					break;
				case 6:
					printf("陆");
					break;
				case 7:
					printf("柒");
					break;
				case 8:
					printf("捌");
					break;
				case 9:
					printf("玖");
					break;
			}
			printf("角");
		}
		if (!fen)
			printf("整\n");
		else
		{
			switch(fen)
			{
				case 1:
					printf("壹");
					break;
				case 2:
					printf("贰");
					break;
				case 3:
					printf("叁");
					break;
				case 4:
					printf("肆");
					break;
				case 5:
					printf("伍");
					break;
				case 6:
					printf("陆");
					break;
				case 7:
					printf("柒");
					break;
				case 8:
					printf("捌");
					break;
				case 9:
					printf("玖");
					break;
			}
			printf("分\n");
		}
	}

	return 0;
}