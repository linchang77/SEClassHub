/*1953609 ��� ���͢*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
int zeller(int y, int m, int d)
{
	int week,century;
	int w;
	if (m < 3)
	{
		m += 12;
		y -= 1;
	}
	century = y / 100;
	y = y % 100;
	week = y + y / 4 + century / 4 - 2 * century +(13 * (m + 1) / 5) + d - 1;
	while (week < 0)
		week += 7;
	w = week % 7;
	return w;
}
int main()
{  
    int week, year, month,day;
	while (1) 
	{
		cout << "��������[1900-2100]���¡��գ�"<<endl;
		cin >> year >> month >> day;
		if (!cin.good())
		{
			while (getchar() != '\n')
				;
			cin.clear();
			cout << "�����������������" << endl;
			continue;
		}
		if (year<1900||year> 2100)
		{
			while (getchar() != '\n')
				;
			cin.clear();
			cout << "��ݲ���ȷ������������" << endl;
			continue;
		}
		if (month < 1 || month>12)
		{
			while (getchar() != '\n')
				;
			cin.clear();
			cout << "�·ݲ���ȷ������������" << endl;
			continue;
		}
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day < 1 || day>31)
			{
				while (getchar() != '\n')
					;
				cin.clear();
				cout << "�ղ���ȷ������������" << endl;
				continue;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day < 1 || day>30)
			{
				while (getchar() != '\n')
					;
				cin.clear();
				cout << "�ղ���ȷ������������" << endl;
				continue;
			}
		}
		else if (month == 2)
		{
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			{
				if (day < 1 || day>29)
				{
					while (getchar() != '\n')
						;
					cin.clear();
					cout << "�ղ���ȷ������������" << endl;
					continue;
				}
			}
			else if (day < 1 || day>28)
			{
				while (getchar() != '\n')
					;
				cin.clear();
				cout << "�ղ���ȷ������������" << endl;
				continue;
			}
		}
		week=zeller(year, month, day);
		switch (week)
		{
			case 0:
				cout << "������" << endl;
				break;
			case 1:
				cout << "����һ" << endl;
				break;
			case 2:
				cout << "���ڶ�" << endl;
				break;
			case 3:
				cout << "������" << endl;
				break;
			case 4:
				cout << "������" << endl;
				break;
			case 5:
				cout << "������" << endl;
				break;
			case 6:
				cout << "������" << endl;
				break;
			default:
				break;
		}
		break;
	}
	return 0;
}
