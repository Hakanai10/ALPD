/* 2253372 国01 康嘉玮 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数，但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量和静态局部变量
   ----------------------------------------------------------------------------------- */


   /***************************************************************************
	   函数名称：
	   功    能：打印递减半行
	   输入参数：
	   返 回 值：
	   说    明：形参按需设置
	 ***************************************************************************/
void print_line_decrease(char start_ch, char end_ch)
{
	if (end_ch == start_ch)
		cout << start_ch;
	else
	{
		cout << end_ch;
		print_line_decrease(start_ch, end_ch - 1);
	}
}


/***************************************************************************
	函数名称：
	功    能：打印递增半行
	输入参数：
	返 回 值：
	说    明：形参按需设置
  ***************************************************************************/
void print_line_increase(char start_ch, char end_ch)
{
	if (start_ch == end_ch)
		cout << end_ch;
	else
	{
		cout << start_ch;
		print_line_increase(start_ch + 1, end_ch);
	}
}


   /***************************************************************************
	 函数名称：
	 功    能：打印字母塔
	 输入参数：
	 返 回 值：
	 说    明：形参按需设置
   ***************************************************************************/
void print_tower(char start_ch, char end_ch, int width, int upsidedown)
{
	/* 按需实现，函数中不允许任何形式的循环*/
	int width_of_space = (width - (end_ch - start_ch) * 2 - 1) / 2;
	if (!upsidedown)
	{
		if (end_ch == start_ch)
			cout << setw(width_of_space + 1) << end_ch << endl;
		else
		{
			print_tower(start_ch, end_ch - 1, width, upsidedown);
			if (width_of_space)
				cout << setw(width_of_space) << " ";
			print_line_decrease(start_ch, end_ch);
			print_line_increase(start_ch + 1, end_ch);
			cout << endl;
		}
	}
	else
	{
		if (end_ch == start_ch)
			cout << setw(width_of_space + 1) << end_ch << endl;
		else
		{
			if (width_of_space)
				cout << setw(width_of_space) << " ";
			print_line_increase(start_ch, end_ch);
			print_line_decrease(start_ch, end_ch - 1);
			cout << endl;
			print_tower(start_ch + 1, end_ch, width, upsidedown);
		}
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}

	/* 正三角字母塔(中间为A) */
	cout << setw((end_ch - 'A') * 2 + 1) << setfill('=') << "=" << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "正三角字母塔" << endl;
	cout << setw((end_ch - 'A') * 2 + 1) << "=" << setfill(' ') << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower('A', end_ch, (end_ch - 'A') * 2 + 1, 0);
	cout << endl;

	/* 倒三角字母塔(两边为A) */
	cout << setw((end_ch - 'A') * 2 + 1) << setfill('=') << "=" << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "倒三角字母塔" << endl;
	cout << setw((end_ch - 'A') * 2 + 1) << "=" << setfill(' ') << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower('A', end_ch, (end_ch - 'A') * 2 + 1, 1);
	cout << endl;

	return 0;
}