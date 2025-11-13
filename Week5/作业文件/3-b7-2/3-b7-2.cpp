//国01 康嘉玮 2253372
#include <iostream>
using namespace std;

int main()
{
	cout << "请输入找零值：" << endl;

	int fifty, twenty, ten, five, one, fivejiao, jiao, fivefen, twofen, fen;
	double cash;

	cin >> cash;

	fifty = (int)cash / 50;
	cash = cash - fifty * 50;
	twenty = (int)cash / 20;
	cash = cash - twenty * 20;
	ten = (int)cash / 10;
	cash = cash - ten * 10;
	five = (int)cash / 5;
	cash = cash - five * 5;
	one = (int)cash;

	cash = (cash - (int)cash) * 100;//将角和分放到整数部分

	fivejiao = (int)cash / 50;
	cash = cash - fivejiao * 50;
	jiao = (int)cash / 10;
	cash = cash - jiao * 10;
	fivefen = (int)cash / 5;
	cash = cash - fivefen * 5;
	twofen = (int)cash / 2;
	cash = cash - twofen * 2;
	fen = (int)cash;

	cout << "共" << fifty + twenty + ten + five + one + fivejiao + jiao + fivefen + twofen + fen << "张找零，具体如下：" << endl;
	if (fifty != 0)
		cout << "50元 : " << fifty << "张" << endl;
	if (twenty != 0)
		cout << "20元 : " << twenty << "张" << endl;
	if (ten != 0)
		cout << "10元 : " << ten << "张" << endl;
	if (five != 0)
		cout << "5元  : " << five << "张" << endl;
	if (one != 0)
		cout << "1元  : " << one << "张" << endl;
	if (fivejiao != 0)
		cout << "5角  : " << fivejiao << "张" << endl;
	if (jiao != 0)
		cout << "1角  : " << jiao << "张" << endl;
	if (fivefen != 0)
		cout << "5分  : " << fivefen << "张" << endl;
	if (twofen != 0)
		cout << "2分  : " << twofen << "张" << endl;
	if (fen != 0)
		cout << "1分  : " << fen << "张" << endl;

	return 0;
}
