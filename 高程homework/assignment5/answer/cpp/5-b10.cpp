/*2250420 �� �¾�*/
#include <iostream>
#include <iomanip>
using namespace std;
void print_first_line(int a);
int zeller(int y, int m, int d)
{
	int c;
	if (m < 3)
	{
		y--;
		m = m + 12;
		c = y / 100;
		y = y % 100;
	}
	else
	{
		c = y / 100;
		y = y % 100;
	}

	int w = y + (y / 4) + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	while (1)
	{
		if (w > 0)
			break;
		w = w + 7;

	}
	return w % 7;
}
void print_three_line(int a, int b, int c, int i) //��ӡǰ����
{
	cout << "           " << setiosflags(ios::right) << setw(2)<< i * 3 + 1 << "��" << "                 "
	 	 << "           " << setiosflags(ios::right) << setw(2)<< i * 3 + 2 << "��" << "                 "
		 << "           " << setiosflags(ios::right) << setw(2)<< i * 3 + 3 << "��" << "            " << endl;
		 cout<<resetiosflags (ios::right);
	cout << "Sun Mon Tue Wed Thu Fri Sat" << "     "
		<< "Sun Mon Tue Wed Thu Fri Sat" << "     "
		<< "Sun Mon Tue Wed Thu Fri Sat" << endl;
	print_first_line(a);
	print_first_line(b);
	print_first_line(c);
	cout << endl;
}
void print_first_line(int a)
{
	for (int i = 0; i < 4 * a; i++)
		cout << " ";
	for (int i = 1; i <= 7 - a; i++)
		cout << setiosflags(ios::left) << setw(2) << i << "  ";
	cout << "    ";
}
//�ж�a�Ƿ񳬹���Χ 
bool larger(int a, int* month, int i)
{
	return a > month[i - 1];
}
//�����������µڶ��п�ʼ������,�Լ���һ����,�Լ��·����� 
void print_five_line(int a, int b, int c, int quarter, int* month)
{
	for (int j = 0; j < 5; j++)
	{
		if(larger(a, month, quarter * 3 + 1)
	     &&larger(b, month, quarter * 3 + 2)
		 &&larger(c, month, quarter * 3 + 3))
		    break;
		for (int i = 0; i < 7; i++)
		{
			if (larger(a, month, quarter * 3 + 1))//���������Χ�Ϳ�ʼ����ո� 
				cout << "    ";
			else
			{
				cout << setiosflags(ios::left) << setw(2) << a << "  ";
				a++;
			}
		}
		cout << "    ";
		for (int i = 0; i < 7; i++)
		{
			if (larger(b, month, quarter * 3 + 2))//���������Χ�Ϳ�ʼ����ո� 
				cout << "    ";
			else
			{
				cout << setiosflags(ios::left) << setw(2) << b << "  ";
				b++;
			}
		}
		cout << "    ";
		for (int i = 0; i < 7; i++)
		{
			if (larger(c, month, quarter * 3 + 3))//���������Χ�Ϳ�ʼ����ո� 
				cout << "    ";
			else
			{
				cout << setiosflags(ios::left) << setw(2) << c << "  ";
				c++;
			}
		}
		cout << endl;
	}

}
void print_canlendar(int year)
{
	bool leap = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (leap)
		month[1] = 29;
	for (int i = 0; i < 4; i++) //�����ȴ�ӡ 
	{
		//���ÿ���µ�һ�������ڼ� 
		int first_month = zeller(year, i * 3 + 1, 1);
		int second_month = zeller(year, i * 3 + 2, 1);
		int third_month = zeller(year, i * 3 + 3, 1);
		print_three_line(first_month, second_month, third_month, i); //��ӡǰ���� 
		print_five_line(8 - first_month, 8 - second_month, 8 - third_month, i , month);//��ӡʣ�µ�����
		cout << endl;
	}
}
int main()
{
	cout << "���������[1900-2100]" << endl;
	int year;
	cin >> year;
	cout << year << "�������:" << endl;
	cout << endl;
	print_canlendar(year);
    cout<<endl;
	return 0;
}
