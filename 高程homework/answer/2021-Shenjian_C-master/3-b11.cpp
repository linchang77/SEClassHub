/*1953609 ��� ���͢*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //ȡϵͳʱ��
using namespace std;
int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������

	/* �˴�����ĳ���ʼ */
	int num = 0;
	for (int i = 123; i <= 598; i++)
	{
		const int a = (i / 10) % 10;
		const int b = i / 100;
		const int c = i % 10;
		if (a == b || a == c || b == c || a == 0 || b == 0 || c == 0)
			continue;
		for (int j = i + 1; j <= 987; j++)
		{
			const int d = (j / 10) % 10;
			const int e = j / 100;
			const int f = j % 10;
			if (d == a || d == b || d == c || e == a || e == b || e == c || f == a || f == b || f == c || d == e || d == f || f == e || d == 0 || e == 0 || f == 0)
				continue;
			else
			{
				const int k = 1953 - i - j;
				if (k < j || k > 987)
					continue;
				const int m = (k / 10) % 10;
				const int n = k / 100;
				const int p = k % 10;
				if (m == a || m == b || m == c || m == e || m == d || m == f || m == 0)
					continue;
				else if (n == a || n == b || n == c || n == e || n == d || n == f || n == 0)
					continue;
				else if (p == a || p == b || p == c || p == e || p == d || p == f || p == 0)
					continue;
				else if (m == n || m == p || n == p)
					continue;
				else
				{
					num++;
					cout << "No." << setw(3) << num << " : " << i << "+" << j << "+" << 1953 - i - j << "=1953" << endl;
				}
			}
		}
	}
	cout << "total=" << num << endl;
	/* �˴�����ĳ������ */

	QueryPerformanceCounter(&end);		//�����ֹӲ������������

	cout << "������Ƶ�� : " << tick.QuadPart << "Hz" << endl;
	cout << "���������� : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;

	return 0;
}