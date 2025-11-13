/* 国01 康嘉玮 2253372 */
#include <iostream>
using namespace std;

int main()
{
	int light[100] = { 0 };
	int i, j;

	for (i = 1; i <= 100; i++)
		for (j = 0; j < 100; j++)
			if ((j + 1) % i == 0)												/*加1是因为数组下标从0开始*/
				light[j] = !light[j];											/*调节灯开关*/

	for (j = 0; j < 100; j++)
		if (light[j])
			cout << j + 1 << " ";												/*输出亮着的灯*/
	cout << endl;

	return 0;
}