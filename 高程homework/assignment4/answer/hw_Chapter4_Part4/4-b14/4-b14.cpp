/*2250420 �� �¾�*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
double is_zero(double n)
{
	if (n <= 1e-6 && n >= -1e-6)
		return 0;
	return n;
}
void func1(int a, int b, int c)
{
	cout << "����һԪ���η���" << endl;
}
void func2(int a, int b, int c)
{
	cout << "���������ʵ����" << endl;
	cout << "x1=x2=" << is_zero(-b / a / 2) << endl;
}
void func3(int a, int b, int c)
{
	cout << "����������ʵ����" << endl;
	cout << "x1=" << is_zero((-b + sqrt(b * b - 4 * a * c)) / (2 * a)) << endl;
	cout << "x2=" << is_zero((-b - sqrt(b * b - 4 * a * c)) / (2 * a)) << endl;
}
void func4(int a, int b, int c)
{
	cout << "�����������" << endl;
	if (is_zero(-b / 2 / a) != 0)
	{
		cout << "x1=" << is_zero(-b / 2 / a) << "+" << is_zero(sqrt(-(b * b - 4 * a * c)) / 2 / fabs(a)) << "i" << endl;
		cout << "x2=" << is_zero(-b / 2 / a) << "-" << is_zero(sqrt(-(b * b - 4 * a * c)) / 2 / fabs(a)) << "i" << endl;
	}
	else
	{
		if (is_zero(sqrt(-(b * b - 4 * a * c)) / 2 / fabs(a)) == 1)
		{
			cout << "x1=" << "i" << endl;
			cout << "x2=" << "-" << "i" << endl;
		}
		else
		{
			cout << "x1=" << is_zero(sqrt(-(b * b - 4 * a * c)) / 2 / fabs(a)) << "i" << endl;
			cout << "x2=" << "-" << is_zero(sqrt(-(b * b - 4 * a * c)) / 2 / fabs(a)) << "i" << endl;
		}

	}
}
int main()
{
	double a, b, c;
	cout << "������һԪ���η��̵�����ϵ��a,b,c:" << endl;
	cin >> a >> b >> c;
	if (a == 0)
		func1(a, b, c);
		return 0;
	if (b * b - 4 * a * c <= 1e-6 && b * b - 4 * a * c >= 0)
		func2(a, b, c);
	else if (b * b - 4 * a * c > 0)
		func3(a, b, c);
	else
		func4(a, b, c);
	return 0;
}
