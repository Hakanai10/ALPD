/* 国01 2253372 康嘉玮 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void input10(char str1[][8], char str2[][9], int n[])
{
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		scanf("%s%s%d", str1[i], str2[i], &n[i]);
	}
}

void sort(char str1[][8], char str2[][9], int n[])
{
	int i, j;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 9 - i; j++)
		{
			if (n[j] < n[j + 1])
			{
				char k[9];
				int l;
				strcpy(k, str1[j]);
				strcpy(str1[j], str1[j + 1]);
				strcpy(str1[j + 1], k);

				strcpy(k, str2[j]);
				strcpy(str2[j], str2[j + 1]);
				strcpy(str2[j + 1], k);

				l = n[j];
				n[j] = n[j + 1];
				n[j + 1] = l;
			}
		}
}

void output(char str1[][8], char str2[][9], int n[])
{
	int i;

	printf("\n全部学生(成绩降序):\n");
	for (i = 0; i < 10; i++)
		printf("%s %s %d\n", str1[i], str2[i], n[i]);
}

int main()
{
	char number[10][8], name[10][9];
	int score[10];

	input10(number, name, score);
	sort(number, name, score);
	output(number, name, score);

	return 0;
}