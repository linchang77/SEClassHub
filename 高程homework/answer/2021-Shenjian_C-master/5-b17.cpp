/* 1953609 ��� ���͢ */
#include <iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

int main()
{
	srand((unsigned)time(NULL));
    cout << "���������볤��(12-16)����д��ĸ����(��2)��Сд��ĸ����(��2)�����ָ���(��2)���������Ÿ���(��2)" << endl;
    int len, big, small, num, sym;
    cin >> len >> big >> small >> num >> sym;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(2147483647, '\n');
		cout << "���뺬�зǷ��ַ�." << endl;
		return 0;
	}
	if (len < 12 || len>16)
	{
		cout << "���볤��[" << len << "]����ȷ" << endl;
		return 0;
	}
	if (big < 2)
	{
		cout << "��д��ĸ����[" << big << "]����ȷ" << endl;
		return 0;
	}
	if (small < 2)
	{
		cout << "Сд��ĸ����[" << small << "]����ȷ" << endl;
		return 0;
	}
	if (num < 2)
	{
		cout << "���ָ���[" << num << "]����ȷ" << endl;
		return 0;
	}
	if (sym < 2)
	{
		cout << "�������Ÿ���[" << sym << "]����ȷ" << endl;
		return 0;
	}
	if (big + small + num + sym > len)
	{
		cout << "�����ַ�����֮��[" << big << "+" << small << "+" << num << "+" << sym << "]���������볤��[" << len << "]" << endl;
		return 0;
	}
    cout << len << " " << big << " " << small << " " << num << " " << sym << endl;
    char pw[10][17];
	int  big1=big, small1=small, num1=num, sym1=sym;
	const int sur = len - big - small - num - sym;
	int sur1 = sur;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < len; j++)
		{
			int a = rand() % 94 + 33;
			if (a >= 'A' && a <= 'Z')
			{
				big1--;
				if (big1 < 0)
				{
					big1++;
					sur1--;
					if (sur1 < 0)
					{
						j--;
						sur1++;
						continue;
					}					
				}
			}
			else if (a >= 'a' && a <= 'z')
			{
				small1--;
				if (small1 < 0)
				{
					small1++;
					sur1--;
					if (sur1 < 0)
					{
						j--;
						sur1++;
						continue;
					}
				}
			}
			else if (a >= '0' && a <= '9')
			{
				num1--;
				if (num1 < 0)
				{
					num1++;
					sur1--;
					if (sur1 < 0)
					{
						j--;
						sur1++;
						continue;
					}
				}
			}
			else
			{
				sym1--;
				if (sym1 < 0)
				{
					sym1++;
					sur1--;
					if (sur1 < 0)
					{
						j--;
						sur1++;
						continue;
					}
				}
			}
			pw[i][j] = a;
		}
		big1 = big, small1 = small, num1 = num, sym1 = sym,sur1=sur;
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < len; j++)
		{
			cout << pw[i][j];
		}
		cout << endl;
	}
    return 0;
}