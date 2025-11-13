//国01 康嘉玮 2253372
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << "请输入一个[1..30000]间的整数:" << endl;
	int n, wan, qian, bai, shi, ge;
	cin >> n;
	wan = n / 10000;
	qian = n % 10000 / 1000;
	bai = n % 1000 / 100;
	shi = n % 100 / 10;
	ge = n % 10;
	cout << "万位 : " << wan << endl;
	cout << "千位 : " << qian << endl;
	cout << "百位 : " << bai << endl;
	cout << "十位 : " << shi << endl;
	cout << "个位 : " << ge << endl;
	return 0;
}