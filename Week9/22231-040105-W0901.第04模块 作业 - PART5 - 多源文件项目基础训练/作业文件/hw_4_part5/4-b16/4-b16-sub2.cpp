/* 国01 2253372 康嘉玮 */
#include <iostream>
#include <cmath>
using namespace std;

void posidelta(double a, double b, double delta)
{
	if (a < 0)
	{
		a = -a;
		b = -b;
	}

	cout << "有两个不等实根：" << endl;
	cout << "x1=" << (-b + sqrt(delta)) / (2 * a) << endl;
	cout << "x2=" << (-b - sqrt(delta)) / (2 * a) << endl;
}