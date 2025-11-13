/* 国01 2253372 康嘉玮 */
#include <iostream>
#include <cmath>
using namespace std;

void error();
void posidelta(double a, double b, double delta);
void zerodelta(double a, double b);
void negadelta(double a, double b, double delta);


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

	if (a == 0)
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