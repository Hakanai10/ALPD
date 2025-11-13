//国01 康嘉玮 2253372
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << "请输入x的值[-10 ~ +65]" << endl;
	int x;
	cin >> x;
	double sum = 0, deltax = 1;
	int i;
	if (x < -10 || x > 65)
		cout << "输入非法，请重新输入" << endl;
	else
	{
		for (i = 1; deltax >= 1e-6 || deltax <= -1e-6; i++)
		{
			sum = sum + deltax;
			deltax = deltax * x / i;
		}
		cout << setprecision(10) << "e^" << x << "=" << sum;
	}
	
	return 0;
}