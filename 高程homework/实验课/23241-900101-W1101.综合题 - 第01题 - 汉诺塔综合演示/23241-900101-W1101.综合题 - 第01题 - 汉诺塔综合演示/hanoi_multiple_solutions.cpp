/* �� 2250420 �¾� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <tchar.h>
#include <string.h>
#include <Windows.h>
#include<conio.h>
#include "cmd_console_tools.h"
#include"hanoi.h"
using namespace std;
/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1����ű� hanoi_main.cpp �и��ݲ˵�����ֵ���õĸ��˵����Ӧ��ִ�к���

     ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */
int plate[3][10];
int num[3];//��¼�����ϵ�������
int step = 0;
int sleep;
/***************************************************************************
  �������ƣ�setparameter
  ��    �ܣ���ʼ��������Ŀ��������ʼ��
  ���������char* src, char* dst,char* temp, int* n
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void setparameter(char* src, char* dst,char* temp, int* n)
{
	while (1)
	{
		cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
		cin >> *n;
		if (*n <= 10 && *n >= 1)
		{
			while (getchar() != '\n')
				;
			break;
		}
		cin.clear();
		while (getchar() != '\n')
			;
	}
	while (1)
	{
		cout << "��������ʼ��(A-C)" << endl;
		cin >> src;
		if (*src >= 'a' && *src <= 'c')
		{
			*src = *src - 32;
			while (getchar() != '\n')
				;
			break;
		}
		if (*src >= 'A' && *src <= 'C')
		{
			while (getchar() != '\n')
				;
			break;
		}

		cin.clear();
		while (getchar() != '\n')
			;
	}

	while (1)
	{
		cout << "������Ŀ����(A-C)" << endl;
		cin >> dst;
		if (dst == src)
		{
			while (getchar() != '\n')
				;
			cout << "Ŀ����(A)��������ʼ��(A)��ͬ" << endl;
			continue;
		}
		if (*dst >= 'a' && *dst <= 'c' && *dst != *src)
		{
			*dst = *dst - 32;
			while (getchar() != '\n')
				;
			break;
		}
		if (*dst >= 'A' && *dst <= 'C' && *dst != *src)
		{
			while (getchar() != '\n')
				;
			break;
		}

		cin.clear();
		while (getchar() != '\n')
			;
	}
	*temp = 'A' + 'B' + 'C' - *src - *dst;
	initplate(*src, *n);
}
/***************************************************************************
  �������ƣ�hanoi
  ��    �ܣ��ݹ���ú���
  ���������int n, char src, char tmp, char dst,const int command
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst,const int command)
{
	if (n == 1) //A   B   C
	{
		step++;
		putout_by_command(command, n, step, src, dst);//��̨�����ƶ���֮��ͼ��ʼ�ƶ�
		if(command==8)
		    func7(n, src, dst,command);
		return;
	}
	hanoi(n - 1, src, dst, tmp,command);
	step++;
	putout_by_command(command, n, step, src, dst);
	if(command==8)
		func7(n, src, dst,command);
	hanoi(n - 1, tmp, src, dst,command);
}
/***************************************************************************
  �������ƣ�clear_screen
  ��    �ܣ���������
  ���������void
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void clear_screen()
{
	cct_setcolor(); //�ָ�ȱʡ��ɫ
	while (1)
	{
		if (_getch() == '\r')
		{
			cct_cls();
			break;
		}
	}
}
/***************************************************************************
  �������ƣ�putout_by_command
  ��    �ܣ��������
  ���������const int command, int n, int step, char src, char dst
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void putout_by_command(const int command, int n, int step, char src, char dst)
{
	switch (command)
	{
	case 1:
		if(n==1)
		cout << " 1# " << src << "-->" << dst << endl;
		else
		cout << setiosflags(ios::right) << setw(2) << n << "# " << src << "-->" << dst << endl;
		break;
	case 2:
		if (n == 1)
			cout << "��" << setiosflags(ios::right) << setw(4) << step << " ��" << "(" <<
			setiosflags(ios::right) << setw(2) << "1" << "#: " << src << "-->" << dst<<")" << endl;
		else
			cout << "��" << setiosflags(ios::right) << setw(4) << step << " ��" << "(" <<
			setiosflags(ios::right) << setw(2) << n << "#: " << src << "-->" << dst << ")" <<endl;
		break;
	case 3:
		if (n == 1)
			cout << "��" << setiosflags(ios::right) << setw(4) << step << " ��" << "(" <<
				setiosflags(ios::right) << setw(2) << "1" << "): " << src << "-->" << dst;
		else
			cout << "��" << setiosflags(ios::right) << setw(4) << step << " ��" << "(" <<
				setiosflags(ios::right) << setw(2) << n << "): " << src << "-->" << dst;
		move(src, dst);
		putout(command);
		break;
	case 4:
		sleeptime(sleep);
		cct_gotoxy(0, 17);
		if (n == 1) //A   B   C
			cout << "��" << setiosflags(ios::right) << setw(4) << step << "��" << "(" <<
				"1" << "#: " << src << "-->" << dst<<") ";
		else
			cout << "��" << setiosflags(ios::right) << setw(4) << step << "��" << "(" <<
				n << "#: " << src << "-->" << dst << ") ";
		move(src, dst);
		putout(command);
		//sleeptime(sleep);
		putoutplate(command);
		break;
	case 8:
		sleeptime(sleep);
		cct_gotoxy(0, 32);
		cct_setcolor();
		if (n == 1) //A   B   C
			cout << "��" << setiosflags(ios::right) << setw(4) << step << "��" << "(" <<
			"1" << "#: " << src << "-->" << dst << ") ";
		else
			cout << "��" << setiosflags(ios::right) << setw(4) << step << "��" << "(" <<
			n << "#: " << src << "-->" << dst << ") ";
		move(src, dst);
		putout(command);
		//sleeptime(sleep);
		putoutplate(command);
		break;
	}
}
/***************************************************************************
  �������ƣ�move
  ��    �ܣ��ƶ�����
  ���������const int command, int n, int step, char src, char dst
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void move(char src, char dst)
{
	plate[dst - 'A'][num[dst - 'A']] = plate[src - 'A'][num[src - 'A'] - 1];
	plate[src - 'A'][num[src - 'A'] - 1] = 0;
	num[dst - 'A']++;
	num[src - 'A']--;
}
/***************************************************************************
  �������ƣ�putout
  ��    �ܣ�����������
  ���������const int command, int n, int step, char src, char dst
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void putout(int command)
{
	cct_setcolor();
	cout << " A:";
	for (int i = 0; i < 10; i++)
		if (plate[0][i] > 0)
			cout << setw(2) << plate[0][i]; 
		else
			cout << "  ";
	cout << " B:";
	for (int i = 0; i < 10; i++)
		if (plate[1][i] > 0)
			cout << setw(2) << plate[1][i];
		else
			cout << "  ";
	cout << " C:";
	for (int i = 0; i < 10; i++)
		if (plate[2][i] > 0)
			cout << setw(2) << plate[2][i];
		else
			cout << "  ";
	cout << endl;
}
/***************************************************************************
  �������ƣ�initplate
  ��    �ܣ���ʼ������
  ���������char src, int n
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void initplate(char src, int n)
{
	for (int i = 0; i < n; i++)
		plate[src - 'A'][i] = n - i;
	num[src - 'A'] = n;
}
/***************************************************************************
  �������ƣ�setslee
  ��    �ܣ���ʼ����ʱ����
  �����������
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void setsleep()
{
	while (1)
	{
		cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
		cin >> sleep;
		if (sleep >= 0 && sleep <= 5)
			break;
		cin.clear();
	}
}
/***************************************************************************
  �������ƣ�initputout4
  ��    �ܣ�����4�ĳ�ʼ��ҳ��
  ���������char src,char dst,int n,int command
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void initputout(char src,char dst,int n,int command)
{
	cct_cls();
	cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << sleep << endl;
	putoutpillar(command);
	putoutplate(command);
	if(command==4)
		cct_gotoxy(0, 17);
	if(command==8||command==9)
		cct_gotoxy(0, 32);
	cout << "��ʼ: ";
	putout(command);
	if(command==8||command==9)
	    func6(n,src);
}
/***************************************************************************
  �������ƣ�putoutpillar
  ��    �ܣ��������
  �����������
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void putoutpillar(int command)
{
	int extra = 0;
	if (command == 8 || command == 9)
		extra = 15;
	cct_gotoxy(9, 12+extra);
	cout << "=========================";
	cct_gotoxy(11, 13 + extra);
	cout << 'A';
	cct_gotoxy(21, 13 + extra);
	cout << 'B';
	cct_gotoxy(31, 13 + extra);
	cout << 'C';
}
void putoutplate(int command)
{
	cct_setcolor();
	int extra = 0;
	if (command == 8 || command == 9)
		extra = 15;
	for (int i = 0; i < 10; i++)
	{
		cct_gotoxy(10, 11 - i + extra);
		if (plate[0][i] > 0)
			cout << setw(2) << plate[0][i];
		else
			cout << "  ";
	}
	for (int i = 0; i < 10; i++)
	{
		cct_gotoxy(20, 11 - i + extra);
		if (plate[1][i] > 0)
			cout << setw(2) << plate[1][i];
		else
			cout << "  ";
	}
	for (int i = 0; i < 10; i++)
	{
		cct_gotoxy(30, 11 - i + extra);
		if (plate[2][i] > 0)
			cout << setw(2) << plate[2][i];
		else
			cout << "  ";
	}
}
/***************************************************************************
  �������ƣ�sleeptime
  ��    �ܣ���ʱ�������ڿ��������ƶ��ٶ�
  ���������int sleep
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void sleeptime(int sleep)
{
	switch (sleep)
	{
	case 0:
		while (_getch() != 13)
			;
		break;
	default:
		Sleep(100 * (6 - sleep));
	}
}
/***************************************************************************
  �������ƣ�to_be_continued
  ��    �ܣ���ʾ����
  ���������const char* prompt, const int X, const int Y 
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void to_be_continued(const char* prompt, const int X, const int Y )
{
	cct_setcolor(); //�ָ�ȱʡ��ɫ
	cct_gotoxy(X, Y);

	if (prompt)
		cout << prompt << "�����س�������...";
	else
		cout << "���س�������...";

	/* ���Գ��س�������������루ע�⣺_getch�Ļس���\r����getchar��\n��*/
	while (_getch() != '\r')
		;

	cct_cls();

	return;
}
/***************************************************************************
  �������ƣ�func5
  ��    �ܣ�����5
  ���������void
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void func5()//����5
{
	int color_x = 14;
	int color_y = 14;
	int row = 15;
	int column = 1;
	for (int i = 0; i < 3; i++)
        cct_showch(column+i*32, row, ' ', color_y, color_x, 23);
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cct_showch(column+11+j*32, row-i-1, ' ', color_y, color_x, 1);
			Sleep(100);
		}
	}
}
/***************************************************************************
  �������ƣ�func6
  ��    �ܣ�����6,��ʾ����
  ���������int n,char src
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void func6(int n,char src)
{
	int row = 15;
	int column = 1;
	func5();//����ʾ����
	for (int i = 0; i < n; i++)
	{
		cct_showch(12+32*(src-'A')-n+i, row - 1 - i, ' ', n - i, n - i, (n - i) * 2 + 1);
		Sleep(100);
	}		
}
/***************************************************************************
  �������ƣ�func7
  ��    �ܣ�����7,�ƶ�����
  ���������int n,char src��char dst
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void func7(int plate_num, char src, char dst,int command)   //����7
{
	if(command==7)
	move(src, dst);
	int src_hight = num[src - 'A']+1;
	int dst_hight = num[dst - 'A']-1;
	int row = 15;
	int column = 1;
	int sleeptime = 100;
	//��ʼ������λ��
	int x = 12+32*(src-'A')-plate_num;//�ƶ����ӵ�x����
	int y = row-src_hight;//�ƶ����ӵ�y����
	int dst_x = 12 + 32 * (dst - 'A') - plate_num;
	int dst_y = row - dst_hight-1;
	if (command == 7)
	{
		while (_getch() != '\r')
			;
		
	}
	//�����˶�������
	while (y >1)
	{
		cct_showch(x, y, ' ', plate_num, plate_num, plate_num * 2 + 1);
		Sleep(sleeptime);
		cct_showch(x, y, ' ', 0, 0, plate_num * 2 + 1);
		if(y>=3)
		cct_showch(x+plate_num, y, ' ', 14, 14, 1);
		Sleep(sleeptime);
		y--;	
	}
	//�����ƶ�
	while (x != dst_x)
	{
		cct_showch(x, y, ' ', plate_num, plate_num, plate_num * 2 + 1);
		Sleep(sleeptime);
		cct_showch(x, y, ' ', 0, 0, plate_num * 2 + 1);
		Sleep(sleeptime);
		x = x + ((src > dst) ? -1 : 1);
	}
	while (y < dst_y)
	{
		cct_showch(x, y, ' ', plate_num, plate_num, plate_num * 2 + 1);
		Sleep(sleeptime);
		cct_showch(x, y, ' ', 0, 0, plate_num * 2 + 1);
		if (y >= 3)
			cct_showch(x + plate_num, y, ' ', 14, 14, 1);
		Sleep(sleeptime);
		y++;
	}
	cct_showch(x, y, ' ', plate_num, plate_num, plate_num * 2 + 1);
	cct_setcolor(); //�ָ�ȱʡ��ɫ
}
/***************************************************************************
  �������ƣ�menu_5_6_7
  ��    �ܣ�5��6��7�Ĳ˵����ú���
  ���������int command, int num, char src, char dst
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void menu_5_6_7(int command, int num, char src, char dst)
{
	cct_cls();
	switch (command)
	{
	case 5:
		func5();
		break;
	case 6:
		func6(num,src);
		break;
	case 7:
		cout << "�� A �ƶ��� C���� 4 ��";
		func6(num, src);
		func7(1,src, 'A' + 'B' + 'C' - src - dst,command);
		break;
	}
}
void startgame(char src,char dst,int n)//��ʼ��Ϸ
{
	cct_setcolor();//������ɫ
	while (1)
	{
		cct_gotoxy(0, 34);
		cout << "�������ƶ�������(������ʽ��AC=A���˵������ƶ���C��Q=�˳�) ��";
		char now_src, now_dst;
		while (1)
		{
			cct_gotoxy(0, 34);
			cout << "�������ƶ�������(������ʽ��AC=A���˵������ƶ���C��Q=�˳�) ��";
			now_src = _getch();
			now_dst = _getch();
			if (now_src >= 'a')
				now_src = now_src - 32;
			if (now_dst >= 'a')
				now_dst = now_dst - 32;
			if (now_src >= 'A' && now_src <= 'C' && now_dst >= 'A' && now_dst <= 'C' && now_src != now_dst,is_valid(now_src,now_dst))
				break;
		}
		step++;
		putout_by_command(8, plate[now_src - 'A'][num[now_src - 'A'] - 1], step, now_src, now_dst);//��̨�����ƶ���֮��ͼ��ʼ�ƶ�
		func7(plate[now_dst-'A'][num[ now_dst - 'A']-1], now_src, now_dst, 8);
		if (plate[now_dst - 'A'][num[now_dst - 'A'] - 1] == 1 && num[now_dst - 'A'] == n)
		{
			cct_gotoxy(0, 35);
			cout << "��Ϸ����!";
			break;
		}
	}
}
bool is_valid(char now_src, char now_dst)//�жϺϷ�
{
	if (plate[now_src - 'A'][num[now_src - 'A'] - 1] == 0)
	{
		cct_gotoxy(0, 35);
		cout << "Դ��Ϊ��!";
		Sleep(600);
		cct_gotoxy(0, 35);
		cout << "                     ";
		return false;
	}
	if (plate[now_src - 'A'][num[now_src - 'A'] - 1] > plate[now_dst - 'A'][num[now_dst - 'A'] - 1]&&
		plate[now_dst - 'A'][num[now_dst - 'A'] - 1]!=0)
	{
		cct_gotoxy(0, 36);
		cout << "����ѹС�̣��ƶ��Ƿ�!";
		Sleep(600);
		cct_gotoxy(0, 36);
		cout << "                     ";
		return false;
	}
	return true;
}