//国01 康嘉玮 2253372
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("请输入找零值：\n");
	int fifty, twenty, ten, five, one, fivejiao, jiao, fivefen, twofen, fen;
	double cash;

	scanf("%lf", &cash);

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

	printf("共%d张找零，具体如下：\n", fifty + twenty + ten + five + one + fivejiao + jiao + fivefen + twofen + fen);
	if (fifty != 0)
		printf("50元 : %d张\n", fifty);
	if (twenty != 0)
		printf("20元 : %d张\n", twenty);
	if (ten != 0)
		printf("10元 : %d张\n", ten);
	if (five != 0)
		printf("5元  : %d张\n", five);
	if (one != 0)
		printf("1元  : %d张\n", one);
	if (fivejiao != 0)
		printf("5角  : %d张\n", fivejiao);
	if (jiao != 0)
		printf("1角  : %d张\n", jiao);
	if (fivefen != 0)
		printf("5分  : %d张\n", fivefen);
	if (twofen != 0)
		printf("2分  : %d张\n", twofen);
	if (fen != 0)
		printf("1分  : %d张\n", fen);

	return 0;
}
