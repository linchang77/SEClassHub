/*1953609 ��� ���͢*/
#include"cmd_console_tools.h"
#include"hanoi.h"
#include<iostream>
#include<conio.h>
using namespace std;
/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1����main����
	2����ʼ����Ļ
	3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

     ���ļ�Ҫ��
	1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ�֣�const��#define�������Ʒ�Χ�ڣ�
	2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
	cct_setconsoleborder(120, 40, 120, 9000);
	while (1)
	{
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
				initial(select);
				cct_cls();
				print_disk();
				break;
			case '6':
				initial(select);
				break;
			case '7':
				initial(select);
				break;
			case '8':
				initial(select);
				break;
			case '9':
				initial(select);
				break;
			default:
				break;
		}
		cout << endl << "���س�������" << endl;
		int cmd;
		while (1)
		{
			cmd = _getch();
			if (cmd == 13)
			{
				cct_cls();
				break;
			}
				
		}
	}
	return 0;
}
