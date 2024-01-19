/* �� 250420 �¾� */
#include<iostream>
#include"cmd_console_tools.h"
#include"hanoi.h"
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
	int command,num;//����ѡ��ͺ�ŵ������
	char src, dst,temp;//��������


	/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
	cct_setconsoleborder(120, 40, 120, 9000);
	while (true)
	{
		command = showmenu();//����menu�е�չʾUI
		if (command <= 4)
		{
			if (command == 0)
				exit(1);
			setparameter(&src, &dst, &temp, &num);//��ʼ������
			if (command == 4)
			{
				setsleep();
				initputout(src, dst, num, command);//����4�ĳ�ʼ��
			}
			hanoi(num, src, temp, dst, command);
			if (command < 4)
				std::cout << "���س�������";
			clear_screen();
		}
		else if (command >= 5&&command <=7)
		{
			setparameter(&src, &dst, &temp, &num);//��ʼ������
			menu_5_6_7(command,num,src,dst);
			to_be_continued(NULL);
		}
		else if (command == 8)
		{
			setparameter(&src, &dst, &temp, &num);//��ʼ������
			setsleep();
			initputout(src, dst, num, command);//��ʼ��
			hanoi(num, src, temp, dst, command);
			to_be_continued(NULL,0,35);
		}
		else if (command == 9)
		{
			setparameter(&src, &dst, &temp, &num);//��ʼ������
			initputout(src, dst, num, command);//��ʼ��
			startgame(src, dst, num);//��ʼ��Ϸ
			to_be_continued(NULL, 0, 38);
		}
	}
	

	return 0;
}
