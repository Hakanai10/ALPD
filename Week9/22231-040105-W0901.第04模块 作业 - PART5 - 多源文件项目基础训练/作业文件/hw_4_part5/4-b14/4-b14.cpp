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

int main()
{
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;

	double a, b, c;
	cin >> a >> b >> c;
	if (fabs(a) < 1e-6)
		a = 0.0;
	if (fabs(b) < 1e-6)
		b = 0.0; 
	if (fabs(c) < 1e-6)
		c = 0.0;

	double delta = b * b - 4 * a * c;
	if (fabs(delta) < 1e-6)
		delta = 0.0;

	if(a==0)
		error();
	else
	{
		if (delta == 0)
			zerodelta(a, b);
		else if (delta > 0)
			posidelta(a, b, delta);
		else if (delta < 0)
			negadelta(a, b, delta);
	}

	return 0;
}