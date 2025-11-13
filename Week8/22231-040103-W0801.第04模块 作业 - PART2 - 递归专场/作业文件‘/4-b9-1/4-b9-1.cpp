#include <iostream>
#include <iomanip>
using namespace std;

unsigned times_of_fibonacci(int n)
{
	switch (n)
	{
		case 1:
		case 2:
			return 1;
			break;
		default:
			return times_of_fibonacci(n - 1) + times_of_fibonacci(n - 2) + 1;
			break;
	}
}

void print(int n)
{
	if (n == 1)
		cout << "项数为" << setw(2) << n << "时的执行次数 : " << setw(10) << times_of_fibonacci(n) << endl;
	else
	{
		print(n - 1);
		cout << "项数为" << setw(2) << n << "时的执行次数 : " << setw(10) << times_of_fibonacci(n) << endl;
	}
}

int main()
{
	print(46);
	return 0;
}