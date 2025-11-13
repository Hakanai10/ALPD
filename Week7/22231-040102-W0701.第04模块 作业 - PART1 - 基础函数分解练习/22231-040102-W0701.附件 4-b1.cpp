/* 学号 姓名 班级 */
#include <iostream>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch(num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
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
		default:
			cout << "error";
			break;
		}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	/* 按需完成 */
	
	
	double n, n_;
	while (1)
	{
		cout << "请输入[0-100亿)之间的数字:" << endl;
		cin >> n;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(4294967295, '\n');
		}
		else if (n >= 0 && n < 10000000000.0)
			break;
	}
	n = n + 0.001;//误差修正
	int shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, yuan, jiao, fen;
	int yiji, wanji, geji;//亿级、万级、个级
	double xiaoshu;//小数
	int xiaoshu_;//用于存储十分位和百分位
	int printzero = 0;





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
		daxie(shiyi, printzero);
		if (shiyi)	
			cout << "拾";

		daxie(yi, printzero);
		cout << "亿";
	}


	if (wanji)
	{
		if (yiji && (baiwan || shiwan || wan))
			printzero = 1;
		daxie(qianwan, printzero);
		if (qianwan)
			cout << "仟";
		printzero = 0;

		if (qianwan && (shiwan || wan))
			printzero = 1;
		daxie(baiwan, printzero);
		if (baiwan)
			cout << "佰";
		printzero = 0;
		
		if (baiwan && wan)
			printzero = 1;
		daxie(shiwan, printzero);
		if (shiwan)
			cout << "拾";
		printzero = 0;

		daxie(wan, printzero);
		cout << "万";
	}


	if (!geji)
	{
		if (!yiji && !wanji && !xiaoshu_)
		{
			printzero = 1;
			daxie(yuan, printzero);
			cout << "圆";
			printzero = 0;
		}
		else if (yiji || wanji)
			cout << "圆";
	}
	else
	{
		if ((yiji || wanji) && (bai || shi || yuan))
			printzero = 1;
		daxie(qian, printzero);
		if (qian)
			cout << "仟";
		printzero = 0;

		if (qian && (shi || yuan))
			printzero = 1;
		daxie(bai, printzero);
		if (bai)
			cout << "佰";
		printzero = 0;

		if (bai && yuan)
			printzero = 1;
		daxie(shi, printzero);
		if (shi)
			cout << "拾";
		printzero = 0;

		daxie(yuan, printzero);
		cout << "圆";
	}


	if (!xiaoshu_)
		cout << "整" << endl;
	else
	{
		if (int(n))
			printzero = 1;
		daxie(jiao, printzero);
		if (jiao)
			cout << "角";
		printzero = 0;

		if (!fen)
			cout << "整" << endl;
		else
		{
			daxie(fen, printzero);
			cout << "分" << endl;
		}
	}
	return 0;
}
