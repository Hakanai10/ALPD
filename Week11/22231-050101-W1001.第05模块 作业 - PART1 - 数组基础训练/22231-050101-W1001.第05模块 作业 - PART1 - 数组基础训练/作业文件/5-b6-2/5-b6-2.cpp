/* 2253372 康嘉玮 国01 */
#include <iostream>
#include <iomanip>
using namespace std;

int _move = 1;
int _col[3][10] = { 0 };
int _top[3] = { 0,0,0 };

void printchar(char ch, int num)
{
    if (num > 0)
    {
        cout << ch;
        printchar(ch, num - 1);
    }
}

void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1)
    {
        cout << "第" << setw(4) << _move << " 步(" << setw(2) << n << "): " << src << "-->" << dst << " ";

        _col[dst - 'A'][_top[dst - 'A']++] = _col[src - 'A'][--_top[src - 'A']];
        _col[src - 'A'][_top[src - 'A']] = 0;
       
        int i;
        cout << "A:";
        for (i = 0; i < _top[0]; i++)
            cout << setw(2) << _col[0][i];
        printchar(' ', 21 - _top[0] * 2);
        cout << "B:";
        for (i = 0; i < _top[1]; i++)
            cout << setw(2) << _col[1][i];
        printchar(' ', 21 - _top[1] * 2);
        cout << "C:";
        for (i = 0; i < _top[2]; i++)
            cout << setw(2) << _col[2][i];
        printchar(' ', 21 - _top[2] * 2);
        cout << endl;

        _move++;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        cout << "第" << setw(4) << _move << " 步(" << setw(2) << n << "): " << src << "-->" << dst << " ";
        _col[dst - 'A'][_top[dst - 'A']++] = _col[src - 'A'][--_top[src - 'A']];
        _col[src - 'A'][_top[src - 'A']] = 0;

        int i;
        cout << "A:";
        for (i = 0; i < _top[0]; i++)
            cout << setw(2) << _col[0][i];
        printchar(' ', 21 - _top[0] * 2);
        cout << "B:";
        for (i = 0; i < _top[1]; i++)
            cout << setw(2) << _col[1][i];
        printchar(' ', 21 - _top[1] * 2);
        cout << "C:";
        for (i = 0; i < _top[2]; i++)
            cout << setw(2) << _col[2][i];
        printchar(' ', 21 - _top[2] * 2);
        cout << endl;

        _move++;
        hanoi(n - 1, tmp, src, dst);
    }
}

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
        {
            src -= 32;
        }
        if (src >= 'A' && src <= 'C')
            break;
    }
    while (1)
    {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        cin.ignore(4096, '\n');
        if (dst >= 'a' && dst <= 'c')
        {
            dst -= 32;
        }
        if (dst >= 'A' && dst <= 'C')
            if (dst != src)
                break;
            else
                cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
    }

    tmp = 'A' + 'B' + 'C' - dst - src;
    int i;
    for (i = 0; i < n; i++)
    {
        _col[src - 'A'][i] = n - i;
        _top[src - 'A']++;
    }
    cout << "初始:";
    printchar(' ', 16);
    cout << "A:";
    for (i = 0; i < _top[0]; i++)
        cout << setw(2) << _col[0][i];
    printchar(' ', 21 - _top[0] * 2);
    cout << "B:";
    for (i = 0; i < _top[1]; i++)
        cout << setw(2) << _col[1][i];
    printchar(' ', 21 - _top[1] * 2);
    cout << "C:";
    for (i = 0; i < _top[2]; i++)
        cout << setw(2) << _col[2][i];
    printchar(' ', 21 - _top[2] * 2);
    cout << endl;


    hanoi(n, src, tmp, dst);

    return 0;
}