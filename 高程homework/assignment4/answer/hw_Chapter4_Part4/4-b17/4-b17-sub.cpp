/*2250420 �� �¾�*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
extern double a, b, c;
double is_zero(double n);
void func1()
{
	cout << "����һԪ���η���" << endl;
}
void func2()
{
	cout << "���������ʵ����" << endl;
	cout << "x1=x2=" << is_zero(-b / a / 2) << endl;
}
void func3()
{
	cout << "����������ʵ����" << endl;
	cout << "x1=" << is_zero((-b + sqrt(b * b - 4 * a * c)) / (2 * a)) << endl;
	cout << "x2=" << is_zero((-b - sqrt(b * b - 4 * a * c)) / (2 * a)) << endl;
}
void func4()
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