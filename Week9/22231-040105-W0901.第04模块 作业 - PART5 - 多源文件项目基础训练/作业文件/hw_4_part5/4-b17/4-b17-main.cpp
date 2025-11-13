/* 国01 2253372 康嘉玮 */
#include <iostream>
#include <cmath>
using namespace std;

void error();
void posidelta();
void zerodelta();
void negadelta();

double a, b, c;

int main()
{
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;

	cin >> a >> b >> c;
	if (fabs(a) < 0.000001)
		a = 0.0;
	if (fabs(b) < 0.000001)
		b = 0.0;
	if (fabs(c) < 0.000001)
		c = 0.0;

	double delta = b * b - 4 * a * c;
	if (fabs(delta) < 0.000001)
		delta = 0.0;

	if (a == 0)
		error();
	else
	{
		if (delta == 0)
			zerodelta();
		else if (delta > 0)
			posidelta();
		else if (delta < 0)
			negadelta();
	}

	return 0;
}
