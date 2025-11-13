/* 国01 康嘉玮 2253372 */
#include <iostream>
using namespace std;

int main()
{
	cout << "请输入成绩（最多1000个），以-1结束" << endl;

	int point[1000];															/*分数*/
	int i, j;																	/*计数变量*/
	int mid;																	/*在交换变量值时作为中间值*/
	int size = 0;																/*实际需要用到的数组元素数量*/
	int number_of_same_data = 1;												/*第几个处于该分数的人*/
	for (i = 0; i < 1000; i++)
	{
		cin >> point[i];
		if (point[i] < 0)
			break;
		size++;
	}
	while (getchar() != '\n')
		;																		/*读取数组并清空缓冲区*/

	if (!size)
		cout << "无有效输入" << endl;
	else
	{
		cout << "输入的数组为:";
		for (i = 0; i < size; i++)
		{
			if (i % 10 == 0)
				cout << endl;
			cout << point[i] << " ";
		}
		cout << endl;															/*上面的语句用于输出数组*/

		for (i = 0; i < size; i++)
			for (j = i; j < size; j++)
				if (point[i] < point[j])
				{
					mid = point[i];
					point[i] = point[j];
					point[j] = mid;
				}																/*这段代码用于降序排序*/

		cout << "分数与名次的对应关系为:" << endl;

		for (i = 0; i < size - 1; i++)
		{			
			cout << point[i] << " " << i + 2 - number_of_same_data << endl;		/*i+2-number_of_same_data是为了使相同值的不同元素在输出时名次正确且相等*/
			if (point[i + 1] == point[i])
				number_of_same_data++;
			else
				number_of_same_data = 1;										/*以上四行用于判断下一个元素是否与目前元素相等，若是，则其次序加一；否则重置*/
		}
		cout << point[i] << " " << i + 2 - number_of_same_data << endl;
		/*上面的语句用于输出所有数据及名次，由于前面的语句不能处理最后一个（即最小的一个）数据，故单独处理*/
	}

	return 0;
}