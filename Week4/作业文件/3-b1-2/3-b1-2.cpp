//国01 康嘉玮 2253372
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << "请输入半径和高度" << endl;
	double r, h;
	const double pi = 3.14159;
	cin >> r >> h;
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout <<"圆周长       : " << 2.0 * pi * r << endl;
	cout <<"圆面积       : " << pi * r * r << endl;
	cout <<"圆球表面积   : " << 4.0 * pi * r * r << endl;
	cout <<"圆球体积     : " << 4.0 / 3.0 * pi * r * r * r << endl;
	cout <<"圆柱体积     : " << pi * r * r * h << endl;
}