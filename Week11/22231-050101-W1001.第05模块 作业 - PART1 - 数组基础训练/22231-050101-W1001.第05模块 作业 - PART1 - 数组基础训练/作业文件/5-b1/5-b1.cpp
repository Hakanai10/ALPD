/* 国01 康嘉玮 2253372 */
#include <iostream>
using namespace std;

int main()
{
	cout << "请输入任意个正整数（升序，最多20个），以-1结束" << endl;

	int a[20];
	int i;	
	int length = 0;
	for (i = 0; i < 20; i++)
	{
		cin >> a[i];
		if (a[i] < 0)
			break;
		length++;
	}
	cin.ignore(4095, '\n');

	if (!length)
		cout << "无有效输入";
	else
	{
		cout << "原数组为：" << endl;
		for (i = 0; a[i] >= 0 && i < 20; i++)
			cout << a[i] << " ";
		cout << endl;
		cout << "请输入要插入的正整数" << endl;

		int insert;
		int inserted_a[21];
		int ismin = 1;															/*最小值标记*/
		cin >> insert;
		for (i = 0; i < length; i++)
			inserted_a[i] = a[i];												/*将a[i]数组的值放在inserted_a[1]中*/
		for (i = length - 1; i >= 0; i--)										/*从后往前检测*/
		{
			if (insert >= inserted_a[i])										/*检测到插入的数大于某个原来的数a[i]*/
			{
				ismin = 0;														/*说明不是最小值*/
				int j;
				for (j = length - 1; j > i; j--)
					inserted_a[j + 1] = inserted_a[j];
				inserted_a[i + 1] = insert;
				break;
			}																	/*将该数插入inserted_a[i]后面，并后移其后的元素*/
		}
		if (ismin)																/*如果是最小值，则在接下来的步骤插入*/
		{
			for (i = length - 1; i > 0; i--)
				inserted_a[i + 1] = inserted_a[i];
			inserted_a[0] = insert;
		}																		/*将所有元素后移一位，被插入元素置为首元素inserted_a[0]*/


		cout << "插入后的数组为：" << endl;
		for (i = 0; i < length + 1; i++)
			cout << inserted_a[i] << " ";
	}

	cout << endl;

	return 0;
}