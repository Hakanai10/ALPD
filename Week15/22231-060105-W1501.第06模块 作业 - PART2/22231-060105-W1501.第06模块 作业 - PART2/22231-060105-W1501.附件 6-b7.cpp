#include <iostream>
#include "cmd_console_tools.h"
using namespace std;

#if 0	//此处置0，则使用老师提供的lib库中的popmenu，提交作业的时候，一定要置为1 

/* 此处允许按需增加自己的pop_menu实现时需要的函数，但都要声明为static */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int pop_menu(const char** menu, const char* title, const int start_x, const int start_y, const int width, const int high, const int bk_color, const int fg_color)
{
	cout << title << endl; //此句需要删掉
	return 0;//根据实际情况返回
}

#endif
