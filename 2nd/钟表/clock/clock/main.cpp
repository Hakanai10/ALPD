#include <iostream>  
#include <iomanip>     
#include <graphics.h>  
#include <math.h>  
#include <conio.h>  
#include <time.h>
#include "header.h"
using namespace std;
#define PI 3.1415927

int main()
{
    struct tm t;
    time_t now;
    time(&now);
    localtime_s(&t, &now);                                                      // 获取当地时间

    init();                                                                     // 自定义图形初始化函数，用于绘制时钟界面
    ticktock(t.tm_hour, t.tm_min, t.tm_sec);

    while (!_kbhit())                                                           // 无键盘操作时进入循环
    {
        struct tm t1;
        time_t now1;

        time(&now1);
        localtime_s(&t1, &now1);                                                // 获取当地时间
        if (t.tm_sec != t1.tm_sec)
           ticktock(t1.tm_hour, t1.tm_min, t1.tm_sec, t.tm_hour, t.tm_min, t.tm_sec);
        t = t1;
        now = now1;
    }
    char ch = _getch();                                                         // 按任意键准备退出时钟程序
    closegraph();                                                               // 退出图形界面
    return 0;
}