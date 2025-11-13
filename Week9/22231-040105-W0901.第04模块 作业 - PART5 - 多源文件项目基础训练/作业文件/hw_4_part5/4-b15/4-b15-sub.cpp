/* 国01 2253372 康嘉玮 */
#include <iostream>
#include <cmath>
using namespace std;

void error()
{
	cout << "不是一元二次方程" << endl;
}

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

void zerodelta(double a, double b)
{
	cout << "有两个相等实根：" << endl;
	cout << "x1=x2=" << -b / (2 * a) << endl;
}

void negadelta(double a, double b, double delta)
{
	double im = sqrt(-delta) / (2 * a);
	if (im < 0)
		im = -im;

	cout << "有两个虚根：" << endl;
	cout << "x1=";
	if (b)
	{
		cout << -b / (2 * a);
		cout << "+";
	}
	if (im != 1)
		cout << im;
	cout << "i" << endl;
	cout << "x2=";
	if (b)
		cout << -b / (2 * a);
	cout << "-";
	if (im != 1)
		cout << im;
	cout << "i" << endl;
}