/*2250420 软工 陈君*/
#include <iostream>
#include <iomanip>
#include<cmath>
#include"4-b16.h"
using namespace std;
double is_zero(double n)
{
	if (n <= 1e-6 && n >= -1e-6)
		return 0;
	return n;
}
int main()
{
	double a, b, c;
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	cin >> a >> b >> c;
	if (a == 0)
	{
		func1(a, b, c);
		return 0;
	}
	if (b * b - 4 * a * c <= 1e-6 && b * b - 4 * a * c >= 0)
		func2(a, b, c);
	else if (b * b - 4 * a * c > 0)
		func3(a, b, c);
	else
		func4(a, b, c);
	return 0;
}
