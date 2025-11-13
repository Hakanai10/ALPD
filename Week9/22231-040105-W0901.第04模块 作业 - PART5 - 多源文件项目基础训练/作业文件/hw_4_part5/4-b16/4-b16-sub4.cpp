/* 国01 2253372 康嘉玮 */
#include <iostream>
#include <cmath>
using namespace std;

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