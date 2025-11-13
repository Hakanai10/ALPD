/* 2253372 康嘉玮 国01 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int _move = 1;
int _A[10] = { 0 }, _B[10] = { 0 }, _C[10] = { 0 };
int _Atop = 0, _Btop = 0, _Ctop = 0;

void printchar(char ch, int num)
{
    if (num > 0)
    {
        printf("%c", ch);
        printchar(ch, num - 1);
    }
}

void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1)
    {
        printf("第%4d 步(%2d): %c-->%c ", _move, n, src, dst);
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

        int i;
        printf("A:");
        for (i = 0; i < _Atop; i++)
            printf("%2d", _A[i]);
        printchar(' ', 21 - _Atop * 2);
        printf("B:");
        for (i = 0; i < _Btop; i++)
            printf("%2d", _B[i]);
        printchar(' ', 21 - _Btop * 2);
        printf("C:");
        for (i = 0; i < _Ctop; i++)
            printf("%2d", _C[i]);
        printchar(' ', 21 - _Ctop * 2);
        printf("\n");

        _move++;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        printf("第%4d 步(%2d): %c-->%c ", _move, n, src, dst);
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

        int i;
        printf("A:");
        for (i = 0; i < _Atop; i++)
            printf("%2d", _A[i]);
        printchar(' ', 21 - _Atop * 2);
        printf("B:");
        for (i = 0; i < _Btop; i++)
            printf("%2d", _B[i]);
        printchar(' ', 21 - _Btop * 2);
        printf("C:");
        for (i = 0; i < _Ctop; i++)
            printf("%2d", _C[i]);
        printchar(' ', 21 - _Ctop * 2);
        printf("\n");

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
        printf("请输入汉诺塔的层数(1-10)\n");
        scanf("%d", &n);
        while (getchar() != '\n')
            ;
        if (n >= 1 && n <= 10)
            break;
    }
    while (1)
    {
        printf("请输入起始柱(A-C)\n");
        scanf("%c", &src);
        while (getchar() != '\n')
            ;
        if (src >= 'a' && src <= 'c')
        {
            src -= 32;
        }
        if (src >= 'A' && src <= 'C')
            break;
    }
    while (1)
    {
        printf("请输入目标柱(A-C)\n");
        scanf("%c", &dst);
        while (getchar() != '\n')
            ;
        if (dst >= 'a' && dst <= 'c')
        {
            dst -= 32;
        }
        if (dst >= 'A' && dst <= 'C')
            if (dst != src)
                break;
            else
                printf("目标柱(%c)不能与起始柱(%c)相同\n", dst, src);
    }

    tmp = 'A' + 'B' + 'C' - dst - src;
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
    printf("初始:");
    printchar(' ', 16);
    printf("A:");
    for (i = 0; i < _Atop; i++)
        printf("%2d", _A[i]);
    printchar(' ', 21 - _Atop * 2);
    printf("B:");
    for (i = 0; i < _Btop; i++)
        printf("%2d", _B[i]);
    printchar(' ', 21 - _Btop * 2);
    printf("C:");
    for (i = 0; i < _Ctop; i++)
        printf("%2d", _C[i]);
    printchar(' ', 21 - _Ctop * 2);
    printf("\n");


    hanoi(n, src, tmp, dst);

    return 0;
}