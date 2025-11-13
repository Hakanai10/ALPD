//国01 康嘉玮 2253372
#include <iostream>
using namespace std;

int main()
{
	cout << "请输入[0-100亿)之间的数字:" << endl;
	double n, n_;
	cin >> n;
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
	cout << "大写结果是:" << endl;

	if (yiji)
	{
		switch (shiyi)
		{
			case 1:
				cout << "壹拾";
				break;
			case 2:
				cout << "贰拾";
				break;
			case 3:
				cout << "叁拾";
				break;
			case 4:
				cout << "肆拾";
				break;
			case 5:
				cout << "伍拾";
				break;
			case 6:
				cout << "陆拾";
				break;
			case 7:
				cout << "柒拾";
				break;
			case 8:
				cout << "捌拾";
				break;
			case 9:
				cout << "玖拾";
				break;
		}
		switch (yi)
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
		}
		cout << "亿";
	}



	if (wanji)
	{
		switch (qianwan)
		{
			case 0:
				if (yiji && (bai || shi || yuan))
					cout << "零";//如果亿级为0并且万级后三位不全为0，则要读
				break;
			case 1:
				cout << "壹仟";
				break;
			case 2:
				cout << "贰仟";
				break;
			case 3:
				cout << "叁仟";
				break;
			case 4:
				cout << "肆仟";
				break;
			case 5:
				cout << "伍仟";
				break;
			case 6:
				cout << "陆仟";
				break;
			case 7:
				cout << "柒仟";
				break;
			case 8:
				cout << "捌仟";
				break;
			case 9:
				cout << "玖仟";
				break;
		}
		switch (baiwan)
		{
			case 0:
				if (qianwan && (shiwan || wan))
					cout << "零";//如果千万位非零且万级后两位不全是0，则要读
				break;
			case 1:
				cout << "壹佰";
				break;
			case 2:
				cout << "贰佰";
				break;
			case 3:
				cout << "叁佰";
				break;
			case 4:
				cout << "肆佰";
				break;
			case 5:
				cout << "伍佰";
				break;
			case 6:
				cout << "陆佰";
				break;
			case 7:
				cout << "柒佰";
				break;
			case 8:
				cout << "捌佰";
				break;
			case 9:
				cout << "玖佰";
				break;
		}
		switch (shiwan)
		{
			case 0:
				if (baiwan && wan)
					cout << "零";//如果百万位和万位均非零则要读
				break;
			case 1:
				cout << "壹拾";
				break;
			case 2:
				cout << "贰拾";
				break;
			case 3:
				cout << "叁拾";
				break;
			case 4:
				cout << "肆拾";
				break;
			case 5:
				cout << "伍拾";
				break;
			case 6:
				cout << "陆拾";
				break;
			case 7:
				cout << "柒拾";
				break;
			case 8:
				cout << "捌拾";
				break;
			case 9:
				cout << "玖拾";
				break;
		}
		switch (wan)
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
		}
		cout << "万";
	}



	if (!geji)
	{
		if (!yiji && !wanji && !xiaoshu_)
			cout << "零";//原数为0时要读，否则不读
	}
	else
	{
		switch (qian)
		{
			case 0:
				if ((yiji || wanji) && (bai || shi || yuan))
					cout << "零";//前面不全是0和后三位不全是0时要读0
				break;
			case 1:
				cout << "壹仟";
				break;
			case 2:
				cout << "贰仟";
				break;
			case 3:
				cout << "叁仟";
				break;
			case 4:
				cout << "肆仟";
				break;
			case 5:
				cout << "伍仟";
				break;
			case 6:
				cout << "陆仟";
				break;
			case 7:
				cout << "柒仟";
				break;
			case 8:
				cout << "捌仟";
				break;
			case 9:
				cout << "玖仟";
				break;
		}
		switch (bai)
		{
			case 0:
				if (qian && (shi || yuan))
					cout << "零";//千位非0且十位和个位不全是0时要读0
				break;
			case 1:
				cout << "壹佰";
				break;
			case 2:
				cout << "贰佰";
				break;
			case 3:
				cout << "叁佰";
				break;
			case 4:
				cout << "肆佰";
				break;
			case 5:
				cout << "伍佰";
				break;
			case 6:
				cout << "陆佰";
				break;
			case 7:
				cout << "柒佰";
				break;
			case 8:
				cout << "捌佰";
				break;
			case 9:
				cout << "玖佰";
				break;
		}
		switch (shi)
		{
			case 0:
				if (bai && yuan)//百位和个位均非0时要读
					cout << "零";
				break;
			case 1:
				cout << "壹拾";
				break;
			case 2:
				cout << "贰拾";
				break;
			case 3:
				cout << "叁拾";
				break;
			case 4:
				cout << "肆拾";
				break;
			case 5:
				cout << "伍拾";
				break;
			case 6:
				cout << "陆拾";
				break;
			case 7:
				cout << "柒拾";
				break;
			case 8:
				cout << "捌拾";
				break;
			case 9:
				cout << "玖拾";
				break;
		}
		switch (yuan)
		{
			case 1:
				cout << "壹";
				break;
			case 2:
				cout << "贰";
				break;
			case 3:
				cout << "叁";
				break;
			case 4:
				cout << "肆";
				break;
			case 5:
				cout << "伍";
				break;
			case 6:
				cout << "陆";
				break;
			case 7:
				cout << "柒";
				break;
			case 8:
				cout << "捌";
				break;
			case 9:
				cout << "玖";
				break;
		}
	}
	if ((int)n || !xiaoshu_)
		cout << "圆";//如果整数部分不是0或者整数部分和小数部分均为0，则输出圆；如果整数部分是0且小数部分不是0，则只输出角和分

	if (!xiaoshu_)
		cout << "整\n";
	else
	{
		if (!jiao)
			if ((int)n)
				cout << "零";//整数部分非0且十分位为0时要读0
			else
				;
		else
		{
			switch (jiao)
			{
				case 1:
					cout << "壹";
					break;
				case 2:
					cout << "贰";
					break;
				case 3:
					cout << "叁";
					break;
				case 4:
					cout << "肆";
					break;
				case 5:
					cout << "伍";
					break;
				case 6:
					cout << "陆";
					break;
				case 7:
					cout << "柒";
					break;
				case 8:
					cout << "捌";
					break;
				case 9:
					cout << "玖";
					break;
			}
			cout << "角";
		}
		if (!fen)
			cout << "整\n";
		else
		{
			switch (fen)
			{
				case 1:
					cout << "壹";
					break;
				case 2:
					cout << "贰";
					break;
				case 3:
					cout << "叁";
					break;
				case 4:
					cout << "肆";
					break;
				case 5:
					cout << "伍";
					break;
				case 6:
					cout << "陆";
					break;
				case 7:
					cout << "柒";
					break;
				case 8:
					cout << "捌";
					break;
				case 9:
					cout << "玖";
					break;
			}
			cout << "分\n";
		}
	}

	return 0;
}