/*2250420 �� �¾�*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
void func1(int a, int b, int c);
void func2(int a, int b, int c);
void func3(int a, int b, int c);
void func4(int a, int b, int c);
double is_zero(double n)
{
	if (n <= 1e-6 && n >= -1e-6)
		return 0;
	return n;
}
int main()
{
	double a, b, c;
	cout << "������һԪ���η��̵�����ϵ��a,b,c:" << endl;
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
