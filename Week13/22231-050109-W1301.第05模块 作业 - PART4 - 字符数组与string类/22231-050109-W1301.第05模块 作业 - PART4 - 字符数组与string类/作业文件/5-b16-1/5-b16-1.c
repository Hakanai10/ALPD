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

void sort(char majorstr[][8], char minorstr[][9], int n[])
{
	int i, j;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 9 - i; j++)
		{
			if (strcmp(majorstr[j], majorstr[j + 1]) < 0)
			{
				char k[9];
				int l;
				strcpy(k, majorstr[j]);
				strcpy(majorstr[j], majorstr[j + 1]);
				strcpy(majorstr[j + 1], k);

				strcpy(k, minorstr[j]);
				strcpy(minorstr[j], minorstr[j + 1]);
				strcpy(minorstr[j + 1], k);

				l = n[j];
				n[j] = n[j + 1];
				n[j + 1] = l;
			}
		}
}

void output(char str1[][8], char str2[][9], int n[])
{
	int i;

	printf("\n及格学生(学号降序):\n");
	for (i = 0; i < 10; i++)
		if (n[i] >= 60)
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