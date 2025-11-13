#include <iostream>
#include <conio.h>
using namespace std;

#include "cmd_console_tools.h"

/* 函数声明最好是放在头文件中，因为只有这一行，就直接放在cpp中 */
int pop_menu(const char** menu, const char* title, const int start_x, const int start_y, const int width, const int high, const int bk_color, const int fg_color);

/***************************************************************************
  函数名称：
  功    能：显示提示信息
  输入参数：
  返 回 值：
  说    明：如果读不懂，暂时放着，等指针和引用学习完成后再阅读
***************************************************************************/
static void to_be_continued(const char* prompt = NULL, const int X = 0, const int Y = 22)
{
	cct_setcolor(); //恢复缺省颜色
	cct_gotoxy(X, Y);

	if (prompt)
		cout << prompt << "，按回车键继续...";
	else
		cout << "按回车键继续...";

	/* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
	while (_getch() != '\r')
		;

	return;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	const char* menu[] = {
		"基本解",
		"基本解(步数记录)",
		"内部数组显示(横向)",
		"内部数组显示(纵向+横向)",
		"图形解-预备-画三个圆柱",
		"图形解-预备-在起始柱上画n个盘子",
		"图形解-预备-第一次移动",
		"图形解-自动移动版本",
		"图形解-游戏版",
		"退出",
		NULL
	};

	if (1) {	//高度小于项数，宽度小于串长
		cct_cls();
		int ret = pop_menu(menu, "汉诺塔菜单1", 10, 10, 20, 8, COLOR_BLACK, COLOR_HWHITE);

		cct_gotoxy(0, 20);
		cct_setcolor(); //恢复缺省颜色
		if (ret > 0)
			cout << "本次选择为菜单的第" << ret << "项." << endl;
		else
			cout << "本次未选择菜单." << endl;
		to_be_continued();
	}

	if (1) {	//高度大于项数，宽度大于串长
		cct_cls();
		int ret = pop_menu(menu, "汉诺塔菜单2", 0, 0, 40, 20, COLOR_WHITE, COLOR_HBLUE);

		cct_gotoxy(0, 20);
		cct_setcolor(); //恢复缺省颜色
		if (ret > 0)
			cout << "本次选择为菜单的第" << ret << "项." << endl;
		else
			cout << "本次未选择菜单." << endl;
		to_be_continued();
	}

	if (1) {	//高度大于项数，宽度大于串长，宽度越界
		cct_cls();
		cct_setconsoleborder(80, 25);
		int ret = pop_menu(menu, "汉诺塔菜单3", 60, 0, 40, 9, COLOR_BLACK, COLOR_HWHITE);

		cct_gotoxy(0, 20);
		cct_setcolor(); //恢复缺省颜色
		if (ret > 0)
			cout << "本次选择为菜单的第" << ret << "项." << endl;
		else
			cout << "本次未选择菜单." << endl;
		to_be_continued();
	}

	if (1) {	//高度大于项数，宽度大于串长，宽度越界但可滚动
		cct_cls();
		cct_setconsoleborder(80, 25, 200, 50);
		int ret = pop_menu(menu, "汉诺塔菜单4", 60, 0, 40, 12, COLOR_BLUE, COLOR_HYELLOW);

		cct_gotoxy(0, 20);
		cct_setcolor(); //恢复缺省颜色
		if (ret > 0)
			cout << "本次选择为菜单的第" << ret << "项." << endl;
		else
			cout << "本次未选择菜单." << endl;
		to_be_continued();
	}

	return 0;
}
