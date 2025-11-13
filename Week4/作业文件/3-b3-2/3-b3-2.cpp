//国01 康嘉玮 2253372
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << "请输入[0-100亿)之间的数字:" << endl;
	double n;
	cin >> n;
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
	cout << "十亿位 : " << shiyi << endl;
	cout << "亿位   : " << yi << endl;
	cout << "千万位 : " << qianwan << endl;
	cout << "百万位 : " << baiwan << endl;
	cout << "十万位 : " << shiwan << endl;
	cout << "万位   : " << wan << endl;
	cout << "千位   : " << qian << endl;
	cout << "百位   : " << bai << endl;
	cout << "十位   : " << shi << endl;
	cout << "圆     : " << yuan << endl;
	cout << "角     : " << jiao << endl;
	cout << "分     : " << fen << endl;
	return 0;
}

