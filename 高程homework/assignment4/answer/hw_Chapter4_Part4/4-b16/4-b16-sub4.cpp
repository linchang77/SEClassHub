#include"4-b16.h"
void func4(int a, int b, int c)
{
	cout << "有两个虚根：" << endl;
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