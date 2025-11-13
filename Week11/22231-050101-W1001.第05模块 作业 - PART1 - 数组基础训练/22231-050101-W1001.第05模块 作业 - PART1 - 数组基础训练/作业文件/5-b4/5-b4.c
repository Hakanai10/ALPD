/* 国01 康嘉玮 2253372 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("请输入成绩（最多1000个），以-1结束\n");

	int point[1000];															/*分数*/
	int i, j;																	/*计数变量*/
	int mid;																	/*在交换变量值时作为中间值*/
	int size = 0;																/*实际需要用到的数组元素数量*/
	int number_of_same_data = 1;												/*同一分数的人数*/
	for (i = 0; i < 1000; i++)
	{
		scanf("%d", &point[i]);
		if (point[i] < 0)
			break;
		size++;
	}
	while (getchar() != '\n')
		;																		/*读取数组并清空缓冲区*/

	if (!size)
		printf("无有效输入\n");
	else
	{
		printf("输入的数组为:");
		for (i = 0; i < size; i++)
		{
			if (i % 10 == 0)
				printf("\n");
			printf("%d ", point[i]);
		}
		printf("\n");															/*上面的语句用于输出数组*/

		for (i = 0; i < size; i++)
			for (j = i; j < size; j++)
				if (point[i] < point[j])
				{
					mid = point[i];
					point[i] = point[j];
					point[j] = mid;
				}																/*这段代码用于降序排序*/

		printf("分数与人数的对应关系为:\n");

		for (i = 0; i < size-1; i++)
		{
			if (point[i + 1] == point[i])
				number_of_same_data++;
			else
			{
				printf("%d %d\n", point[i], number_of_same_data);
				number_of_same_data = 1;
			}
		}
		printf("%d %d\n", point[i], number_of_same_data);						
		/*上面的语句用于输出所有数据及出现次数，由于前面的语句不能处理最后一个（即最小的一个）数据，故单独处理*/
	}
	
	return 0;
}