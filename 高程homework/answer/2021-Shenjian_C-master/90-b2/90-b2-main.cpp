/*1953609 ��� ���͢*/
#include"cmd_console_tools.h"
#include"90-b2.h"
#include<iostream>
#include<conio.h>
using namespace std;

char menu()
{
	cct_setconsoleborder(120, 40, 120, 9000);
	cct_cls();
	cout << "-----------------------------------" << endl
		<< "1.�������ҳ��ɺϳ����ʶ���ǵݹ飩" << endl
		<< "2.�������ҳ��ɺϳ����ʶ���ݹ飩" << endl
		<< "3.���������һ�κϳɣ��ֲ�����ʾ��" << endl
		<< "4.�����������棨�ֲ�����ʾ��" << endl
		<< "5.αͼ�ν�����ʾ��ʼ���飨�޷ָ��ߣ�" << endl
		<< "6.αͼ�ν�����ʾ��ʼ���飨�зָ��ߣ�" << endl
		<< "7.αͼ�ν������ü�ͷ��ѡ��ǰɫ��" << endl
		<< "8.αͼ�ν������һ�κϳɣ��ֲ��裩" << endl
		<< "9.αͼ�ν���������" << endl
		<< "0.�˳�" << endl
		<< "-----------------------------------" << endl
		<< "[��ѡ��0-9] ";
	while (1)
	{
		const char num = _getch();
		if (num < '0' || num>'9')
		{
			cin.clear();
			continue;
		}
		return num;
	}
}
int main()
{

	while (1)
	{
		time_t t;
		srand((unsigned)time(&t));
		cct_setconsoleborder(120, 40, 120, 9000);
		cct_cls();
		const int select = menu();
		switch (select)  //������� ��������ֱ���
		{
			case '0':
				cout << endl;
				return 0;
			case '1':
				initial(select);
				break;
			case '2':
				initial(select);
				break;
			case '3':
				initial(select);
				break;
			case '4':
				initial(select);
				break;
			case '5':
				initial_graph(select);
				break;
			case '6':
				initial_graph(select);
				break;
			case '7':
				initial_graph(select);
				break;
			case '8':
				initial_graph(select);
			case '9':
				initial_graph(select);
				break;
			default:
				break;
		}
	}
	return 0;
}