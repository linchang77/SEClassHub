#include"4-b16.h"
void func3(int a, int b, int c)
{
	cout << "����������ʵ����" << endl;
	cout << "x1=" << is_zero((-b + sqrt(b * b - 4 * a * c)) / (2 * a)) << endl;
	cout << "x2=" << is_zero((-b - sqrt(b * b - 4 * a * c)) / (2 * a)) << endl;
}