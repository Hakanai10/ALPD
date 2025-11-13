//国01 康嘉玮 2253372
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	cout << "请输入三角形的两边及其夹角(角度)" << endl;
	int a, b, angle;
	cin >> a >> b >> angle;
	float S;
	S = (float)(1.0 / 2.0 * a * b * sin(angle / 180.0 * 3.14159));
	cout << setiosflags(ios::fixed) << setprecision(3);
	cout << "三角形面积为 : " << S;
	return 0;
}