/* 国01 2253372 康嘉玮 */
#include <iostream>
#include <string>
using namespace std;

void input10(string str1[], string str2[], int n[])
{
	int i;
	for (i = 0; i < 10; i++)
	{
		cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
		cin >> str1[i] >> str2[i] >> n[i];
	}
}

void sort(string majorstr[], string minorsyr[], int n[])
{
	int i, j;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 9 - i; j++)
		{
			if (majorstr[j] > majorstr[j + 1])
			{
				string k;
				int l;
				k = majorstr[j];
				majorstr[j] = majorstr[j + 1];
				majorstr[j + 1] = k;

				k = minorsyr[j];
				minorsyr[j] = minorsyr[j + 1];
				minorsyr[j + 1] = k;

				l = n[j];
				n[j] = n[j + 1];
				n[j + 1] = l;
			}
		}
}

void output(string str1[], string str2[], int n[])
{
	int i;

	cout << endl << "全部学生(学号升序) :" << endl;
	for (i = 0; i < 10; i++)
		cout << str1[i] << " " << str2[i] << " " << n[i] << endl;
}

int main()
{
	string number[10], name[10];
	int score[10];

	input10(number, name, score);
	sort(number, name, score);
	output(number, name, score);

	return 0;
}