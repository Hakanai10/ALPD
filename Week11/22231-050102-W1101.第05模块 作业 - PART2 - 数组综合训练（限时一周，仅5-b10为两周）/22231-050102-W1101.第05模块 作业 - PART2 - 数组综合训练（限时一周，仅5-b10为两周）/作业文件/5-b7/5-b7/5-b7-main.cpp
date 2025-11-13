//国01 康嘉玮 2253372
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include "5-b7.h"
#include <stdio.h>
#define A_X 40
#define B_X 50
#define C_X 60
#define COL_Y 15
#define ARRAY_X 20
#define ARRAY_Y 20

using namespace std;

int _move = 1;
int _A[10] = { 0 }, _B[10] = { 0 }, _C[10] = { 0 };
int _Atop = 0, _Btop = 0, _Ctop = 0;
static int _printarray=0;
int _speed = 0;
/***************************************************************************
  函数名称：
  功    能：用于多次输出同一字符
  输入参数：输出的字符和次数
  返 回 值：
  说    明：
***************************************************************************/

void printchar(char ch, int num)
{
    if (num > 0)
    {
        cout << ch;
        printchar(ch, num - 1);
    }
}

/***************************************************************************
  函数名称：
  功    能：实现汉诺塔移动
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1)
    {
        int temp;

        switch (src)
        {
            case 'A':
                temp = _A[--_Atop];
                _A[_Atop] = 0;
                break;
            case 'B':
                temp = _B[--_Btop];
                _B[_Btop] = 0;
                break;
            case 'C':
                temp = _C[--_Ctop];
                _C[_Ctop] = 0;
                break;
        }
        switch (dst)
        {
            case 'A':
                _A[_Atop++] = temp;
                temp = 0;
                break;
            case 'B':
                _B[_Btop++] = temp;
                temp = 0;
                break;
            case 'C':
                _C[_Ctop++] = temp;
                temp = 0;
                break;
        }

        int i, y;
        cct_gotoxy(ARRAY_X, ARRAY_Y);
        cout << "第" << setw(4) << _move << "步(" << n << "#: " << src << "-->" << dst << ")";
        printchar(' ', 16);
        if (_printarray)
        {
            cout << "A:";
            for (i = 0; i < _Atop; i++)
                cout << setw(2) << _A[i];
            printchar(' ', 21 - _Atop * 2);
            cout << "B:";
            for (i = 0; i < _Btop; i++)
                cout << setw(2) << _B[i];
            printchar(' ', 21 - _Btop * 2);
            cout << "C:";
            for (i = 0; i < _Ctop; i++)
                cout << setw(2) << _C[i];
            printchar(' ', 21 - _Ctop * 2);

            while (!_speed)
                if (_getch() == '\r')
                    break;
        }

        y = COL_Y - 1;
        for (i = 0; i < 10; i++, y--)
        {
            cct_gotoxy(A_X, y);
            if (_A[i])
                cout << _A[i];
            putchar(' ');
        }
        y = COL_Y - 1;
        for (i = 0; i < 10; i++, y--)
        {
            cct_gotoxy(B_X, y);
            if (_B[i])
                cout << _B[i];
            putchar(' ');
        }
        y = COL_Y - 1;
        for (i = 0; i < 10; i++, y--)
        {
            cct_gotoxy(C_X, y);
            if (_C[i])
                cout << _C[i];
            putchar(' ');
        }
        if (_speed)
        {
            switch (_speed)
            {
                case 1:
                    Sleep(800);
                case 2:
                    Sleep(400);
                case 3:
                    Sleep(200);
                case 4:
                    Sleep(100);
                case 5:
                    Sleep(50);
            }
        }
        else
            while (1)
                if (_getch() == '\r')
                    break;

        _move++;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        int temp;

        switch (src)
        {
            case 'A':
                temp = _A[--_Atop];
                _A[_Atop] = 0;
                break;
            case 'B':
                temp = _B[--_Btop];
                _B[_Btop] = 0;
                break;
            case 'C':
                temp = _C[--_Ctop];
                _C[_Ctop] = 0;
                break;
        }
        switch (dst)
        {
            case 'A':
                _A[_Atop++] = temp;
                temp = 0;
                break;
            case 'B':
                _B[_Btop++] = temp;
                temp = 0;
                break;
            case 'C':
                _C[_Ctop++] = temp;
                temp = 0;
                break;
        }   
        int i, y;
        cct_gotoxy(ARRAY_X, ARRAY_Y);
        cout << "第" << setw(4) << _move << "步(" << n << "#: " << src << "-->" << dst << ")";
        printchar(' ', 16);
        if (_printarray)
        {
            cout << "A:";
            for (i = 0; i < _Atop; i++)
                cout << setw(2) << _A[i];
            printchar(' ', 21 - _Atop * 2);
            cout << "B:";
            for (i = 0; i < _Btop; i++)
                cout << setw(2) << _B[i];
            printchar(' ', 21 - _Btop * 2);
            cout << "C:";
            for (i = 0; i < _Ctop; i++)
                cout << setw(2) << _C[i];
            printchar(' ', 21 - _Ctop * 2);

            while (!_speed)
                if (_getch() == '\r')
                    break;
        }


        y = COL_Y - 1;
        for (i = 0; i < 10; i++, y--)
        {
            cct_gotoxy(A_X, y);
            if (_A[i])
                cout << _A[i];
            putchar(' ');
        }
        y = COL_Y - 1;
        for (i = 0; i < 10; i++, y--)
        {
            cct_gotoxy(B_X, y);
            if (_B[i])
                cout << _B[i];              
            putchar(' ');
        }
        y = COL_Y - 1;
        for (i = 0; i < 10; i++, y--)
        {
            cct_gotoxy(C_X, y);
            if (_C[i])
                cout << _C[i];
            putchar(' ');
        }
        if (_speed)
        {
            switch (_speed)
            {
                case 1:
                    Sleep(800);
                case 2:
                    Sleep(400);
                case 3:
                    Sleep(200);
                case 4:
                    Sleep(100);
                case 5:
                    Sleep(50);
            }
        }
        else
            while (1)
                if (_getch() == '\r')
                    break;

        _move++;
        hanoi(n - 1, tmp, src, dst);
    }
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
    int n;
    char src, tmp, dst;
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(4096, '\n');
        }
        else
        {
            cin.ignore(4096, '\n');
            if (n >= 1 && n <= 10)
                break;
        }
    }
    while (1)
    {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        cin.ignore(4096, '\n');
        if (src >= 'a' && src <= 'c')
            src -= 32;
        if (src >= 'A' && src <= 'C')
            break;
    }
    while (1)
    {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        cin.ignore(4096, '\n');
        if (dst >= 'a' && dst <= 'c')
            dst -= 32;
        if (dst >= 'A' && dst <= 'C')
            if (dst != src)
                break;
            else
                cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
    }
    while (1)
    {
        cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
        cin >> _speed;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(4095, '\n');
        }
        if (_speed >= 0 && _speed <= 5)
            break;
    }
    while (1)
    {
        cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
        cin >> _printarray;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(4095, '\n');
        }
        if (_printarray == 0 || _printarray == 1)
            break;
    }

    cct_cls();
    cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << _speed << "，";
    if (!_printarray)
        cout << "不";
    cout << "显示内部数组值";
    cct_gotoxy(ARRAY_X, ARRAY_Y);
    int i;
    for (i = 0; i < n; i++)
    {
        switch (src)
        {
            case 'A':
                _A[i] = n - i;
                _Atop++;
                break;
            case 'B':
                _B[i] = n - i;
                _Btop++;
                break;
            case 'C':
                _C[i] = n - i;
                _Ctop++;
                break;
        }
    }

    if (_printarray)
    {
        cout << "初始:";
        printchar(' ', 16);
        cout << "A:";
        for (i = 0; i < _Atop; i++)
            cout << setw(2) << _A[i];
        printchar(' ', 21 - _Atop * 2);
        cout << "B:";
        for (i = 0; i < _Btop; i++)
            cout << setw(2) << _B[i];
        printchar(' ', 21 - _Btop * 2);
        cout << "C:";
        for (i = 0; i < _Ctop; i++)
            cout << setw(2) << _C[i];
        printchar(' ', 21 - _Ctop * 2);

        while (!_speed)
            if (_getch() == '\r')
                break;
    }

    cct_gotoxy(A_X-1, COL_Y);
    printchar('=', C_X - A_X + 3);
    cct_gotoxy(A_X, COL_Y+1);
    cout << "A";
    printchar(' ', B_X - A_X - 1);
    cout << "B";
    printchar(' ', C_X - B_X - 1);
    cout << "C";

    int y = COL_Y - 1;
    switch (src)
    {
        case 'A':
            for (i = 0; i < _Atop; i++, y--)
            {
                cct_gotoxy(A_X, y);
                cout << _A[i];
            }
            break;
        case 'B':
            for (i = 0; i < _Btop; i++, y--)
            {
                cct_gotoxy(B_X, y);
                cout << _B[i];
            }
            break;
        case 'C':
            for (i = 0; i < _Ctop; i++, y--)
            {
                cct_gotoxy(C_X, y);
                cout << _C[i];
            }
            break;
    }

    if (_speed)
    {
        switch (_speed)
        {
            case 1:
                Sleep(800);
            case 2:
                Sleep(400);
            case 3:
                Sleep(200);
            case 4:
                Sleep(100);
            case 5:
                Sleep(50);
        }
    }
    else
        while(1)
            if (_getch() == '\r')
                break;

    tmp = 'A' + 'B' + 'C' - dst - src;
    hanoi(n, src, tmp, dst);

    cct_gotoxy(0, ARRAY_Y + 1);
	system("pause"); //最后用这句表示暂停（注意：只适合于特定程序，无特别声明的程序加此句则得分为0）
	return 0;
}