#include <iostream>  
#include <iomanip>     
#include <graphics.h>  
#include <math.h>  
#include <conio.h>  
#include <time.h>  
#include "header.h"

using namespace std;

#define PI 3.1415927
#define MY_ORANGE 0x88BBFF
#define MY_BLUE 0xFF8888
#define MY_GREEN 0x88FF88
#define MY_RED 0x8888FF

#define RADIUS 480
#define RADIUS_OF_HR 200
#define RADIUS_OF_MIN 325
#define RADIUS_OF_SEC 450
#define LENGTH_OF_POINTER 20
#define LENGTH_OF_SPECIAL 50
#define THICKNESS 20


void init()
{
	initgraph(2 * RADIUS + 1, 2 * RADIUS + 1);

	AntiAliasingForCircle(RADIUS, RADIUS, RADIUS, 1, (0xFF - RADIUS / 4) * (256 * 256 + 256 + 1), 0);					//外层圆抗锯齿

	int radius;
	for (radius = RADIUS; radius >= 0; radius -= 4)																		//画渐变圆
	{
		int rgb = 0xFF - radius / 4;
		setfillcolor(rgb * 256 * 256 + rgb * 256 + rgb);
		setlinecolor(rgb * 256 * 256 + rgb * 256 + rgb);
		solidcircle(RADIUS, RADIUS, radius);
	}

	setlinecolor(WHITE);

	int i;
	for (i = 0; i < 60; i++)																							//和下一个for循环都是画空白光标
	{
		setlinestyle(0, THICKNESS);
		line(RADIUS + (int)(RADIUS_OF_SEC * sin(i * PI / 30)), RADIUS - (int)(RADIUS_OF_SEC * cos(i * PI / 30)), RADIUS + (int)((RADIUS_OF_SEC - (i % 5 ? LENGTH_OF_POINTER : LENGTH_OF_SPECIAL)) * sin(i * PI / 30)), RADIUS - (int)((RADIUS_OF_SEC - (i % 5 ? LENGTH_OF_POINTER : LENGTH_OF_SPECIAL)) * cos(i * PI / 30)));

		setlinestyle(0, THICKNESS);
		line(RADIUS + (int)(RADIUS_OF_MIN * sin(i * PI / 30)), RADIUS - (int)(RADIUS_OF_MIN * cos(i * PI / 30)), RADIUS + (int)((RADIUS_OF_MIN - (i % 5 ? LENGTH_OF_POINTER : LENGTH_OF_SPECIAL)) * sin(i * PI / 30)), RADIUS - (int)((RADIUS_OF_MIN - (i % 5 ? LENGTH_OF_POINTER : LENGTH_OF_SPECIAL)) * cos(i * PI / 30)));
	}
	for (i = 0; i < 12; i++)
	{
		setlinestyle(0, THICKNESS);
		line(RADIUS + (int)(RADIUS_OF_HR * sin(i * PI / 6)), RADIUS - (int)(RADIUS_OF_HR * cos(i * PI / 6)), RADIUS + (int)((RADIUS_OF_HR - (i % 3 ? LENGTH_OF_POINTER : LENGTH_OF_SPECIAL)) * sin(i * PI / 6)), RADIUS - (int)((RADIUS_OF_HR - (i % 3 ? LENGTH_OF_POINTER : LENGTH_OF_SPECIAL)) * cos(i * PI / 6)));
	}
}

void ticktock(int new_hour, int new_minute, int new_second, int old_hour, int old_minute, int old_second)
{
	int i;

	setlinestyle(0, THICKNESS);
	if (!new_second)																									//新的分钟，此时秒数显示清零
	{
		setlinecolor(WHITE);
		for (i = 0; i < 60; i++)
			line(RADIUS + (int)(RADIUS_OF_SEC * sin(i * PI / 30)), RADIUS - (int)(RADIUS_OF_SEC * cos(i * PI / 30)), RADIUS + (int)((RADIUS_OF_SEC - (i % 5 ? LENGTH_OF_POINTER : LENGTH_OF_SPECIAL)) * sin(i * PI / 30)), RADIUS - (int)((RADIUS_OF_SEC - (i % 5 ? LENGTH_OF_POINTER : LENGTH_OF_SPECIAL)) * cos(i * PI / 30)));
	}
	setlinecolor(MY_BLUE);
	if (old_second == -1)																								//if语句初始化秒针，下面一行是画新的一秒
		for (i = 0; i < new_second; i++)
			line(RADIUS + (int)(RADIUS_OF_SEC * sin(i * PI / 30)), RADIUS - (int)(RADIUS_OF_SEC * cos(i * PI / 30)), RADIUS + (int)((RADIUS_OF_SEC - (i % 5 ? LENGTH_OF_POINTER : LENGTH_OF_SPECIAL)) * sin(i * PI / 30)), RADIUS - (int)((RADIUS_OF_SEC - (i % 5 ? LENGTH_OF_POINTER : LENGTH_OF_SPECIAL)) * cos(i * PI / 30)));
	line(RADIUS + (int)(RADIUS_OF_SEC * sin(new_second * PI / 30)), RADIUS - (int)(RADIUS_OF_SEC * cos(new_second * PI / 30)), RADIUS + (int)((RADIUS_OF_SEC - (new_second % 5 ? LENGTH_OF_POINTER : LENGTH_OF_SPECIAL)) * sin(new_second * PI / 30)), RADIUS - (int)((RADIUS_OF_SEC - (new_second % 5 ? LENGTH_OF_POINTER : LENGTH_OF_SPECIAL)) * cos(new_second * PI / 30)));


	setlinestyle(0, THICKNESS);																							//新的小时，分数清零
	if (!new_minute)
	{
		setlinecolor(WHITE);
		for (i = 0; i < 60; i++)
			line(RADIUS + (int)(RADIUS_OF_MIN * sin(i * PI / 30)), RADIUS - (int)(RADIUS_OF_MIN * cos(i * PI / 30)), RADIUS + (int)((RADIUS_OF_MIN - (i % 5 ? LENGTH_OF_POINTER : LENGTH_OF_SPECIAL)) * sin(i * PI / 30)), RADIUS - (int)((RADIUS_OF_MIN - (i % 5 ? LENGTH_OF_POINTER : LENGTH_OF_SPECIAL)) * cos(i * PI / 30)));
	}
	setlinecolor(MY_GREEN);
	if (old_minute == -1)																								//if语句初始化分针，下面一行是画新的一分钟
		for (i = 0; i < new_minute; i++)
			line(RADIUS + (int)(RADIUS_OF_MIN * sin(i * PI / 30)), RADIUS - (int)(RADIUS_OF_MIN * cos(i * PI / 30)), RADIUS + (int)((RADIUS_OF_MIN - (i % 5 ? LENGTH_OF_POINTER : LENGTH_OF_SPECIAL)) * sin(i * PI / 30)), RADIUS - (int)((RADIUS_OF_MIN - (i % 5 ? LENGTH_OF_POINTER : LENGTH_OF_SPECIAL)) * cos(i * PI / 30)));
	line(RADIUS + (int)(RADIUS_OF_MIN * sin(new_minute * PI / 30)), RADIUS - (int)(RADIUS_OF_MIN * cos(new_minute * PI / 30)), RADIUS + (int)((RADIUS_OF_MIN - (new_minute % 5 ? LENGTH_OF_POINTER : LENGTH_OF_SPECIAL)) * sin(new_minute * PI / 30)), RADIUS - (int)((RADIUS_OF_MIN - (new_minute % 5 ? LENGTH_OF_POINTER : LENGTH_OF_SPECIAL)) * cos(new_minute * PI / 30)));

	setlinestyle(0, THICKNESS);
	if (!(new_hour % 12))																								//AM/PM切换，时数清零
	{
		setlinecolor(WHITE);
		for (i = 0; i < 12; i++)
			line(RADIUS + (int)(RADIUS_OF_HR * sin(i * PI / 6)), RADIUS - (int)(RADIUS_OF_HR * cos(i * PI / 6)), RADIUS + (int)((RADIUS_OF_HR - (i % 3 ? LENGTH_OF_POINTER : LENGTH_OF_SPECIAL)) * sin(i * PI / 6)), RADIUS - (int)((RADIUS_OF_HR - (i % 3 ? LENGTH_OF_POINTER : LENGTH_OF_SPECIAL)) * cos(i * PI / 6)));
	}
	setlinecolor(new_hour >= 12 ? MY_ORANGE : MY_RED);
	if (old_hour == -1)																									//if语句初始化时针，下面一行是画新的一小时
		for (i = 0; i < new_hour % 12; i++)
			line(RADIUS + (int)(RADIUS_OF_HR * sin(i * PI / 6)), RADIUS - (int)(RADIUS_OF_HR * cos(i * PI / 6)), RADIUS + (int)((RADIUS_OF_HR - (i % 3 ? LENGTH_OF_POINTER : LENGTH_OF_SPECIAL)) * sin(i * PI / 6)), RADIUS - (int)((RADIUS_OF_HR - (i % 3 ? LENGTH_OF_POINTER : LENGTH_OF_SPECIAL)) * cos(i * PI / 6)));
	line(RADIUS + (int)(RADIUS_OF_HR * sin(new_hour * PI / 6)), RADIUS - (int)(RADIUS_OF_HR * cos(new_hour * PI / 6)), RADIUS + (int)((RADIUS_OF_HR - (new_hour % 3 ? LENGTH_OF_POINTER : LENGTH_OF_SPECIAL)) * sin(new_hour * PI / 6)), RADIUS - (int)((RADIUS_OF_HR - (new_hour % 3 ? LENGTH_OF_POINTER : LENGTH_OF_SPECIAL)) * cos(new_hour * PI / 6)));
}

void AntiAliasingForCircle(int x0, int y0, int radius, int thickness, int fg_color, int bk_color)
{
	int x, y;
	for (y = 0; y <= RADIUS * 2 + 1; y++)
		for (x = 0; x <= RADIUS * 2 + 1; x++)
		{
			double distance = fabs(sqrt((x0 - x) * (x0 - x) + (y0 - y) * (y0 - y)) - radius) - thickness / 2.0;

			double alpha = 0.5 - distance;
			if (alpha > 1)
				alpha = 1;
			else if (alpha < 0)
				alpha = 0;

			if (alpha)
				putpixel(x, y, RGB(alpha * GetRValue(fg_color) + (1 - alpha) * GetRValue(bk_color), alpha * GetGValue(fg_color) + (1 - alpha) * GetGValue(bk_color), alpha * GetBValue(fg_color) + (1 - alpha) * GetBValue(bk_color)));
		}
}