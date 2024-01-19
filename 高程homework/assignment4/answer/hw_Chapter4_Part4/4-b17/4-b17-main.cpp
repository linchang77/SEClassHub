/*2250420 软工 陈君*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
double a, b, c;
void func1();
void func2();
void func3();
void func4();

double is_zero(double n)
{
	if (n <= 1e-6 && n >= -1e-6)
		return 0;
	return n;
}
int main()
{

	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	cin >> a >> b >> c;
	if (a == 0)
	{
		func1();
		return 0;
	}
	if (b * b - 4 * a * c <= 1e-6 && b * b - 4 * a * c >= 0)
		func2();
	else if (b * b - 4 * a * c > 0)
		func3();
	else
		func4();
	return 0;
}
