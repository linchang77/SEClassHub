/* �� 2250420 �¾� */
/* ���ļ���������Ŀ����Ϊ�˷�ֹ���ļ���Ū�� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <tchar.h>
#include <string.h>
#include <Windows.h>
#include<conio.h>
#include<time.h>
#include <cstdio>
#include "cmd_console_tools.h"
#include"mine_sweeper.h"
using namespace std;

/***************************************************************************
  �������ƣ�showmenu
  ��    �ܣ�չʾ�˵��������û�ѡ���ѡ��
  �����������
  �� �� ֵ������
  ˵    ����
***************************************************************************/
int showmenu()//
{
	cout << "------------------------------------------" << endl;
	cout << "1.ѡ���ѶȲ���ʾ�ڲ�����" << endl;
	cout << "2.�����ʼλ�ò���ʾ���򿪵ĳ�ʼ����" << endl;
	cout << "3.�ڲ����������" << endl;
	cout << "4.�ڲ����������棨��ǡ�����ʱ�䣩" << endl;
	cout << "5.����αͼ�λ���ܲ���ʾ�ڲ�����" << endl;
	cout << "6.������λ�úͺϷ��ԣ���������˳���" << endl;
	cout << "7.���ѡ���ʼλ�ò���ʾ���򿪵ĳ�ʼ����" << endl;
	cout << "8.αͼ�ν��������" << endl;
	cout << "9.αͼ�ν���������" << endl;
	cout << "0.�˳���Ϸ" << endl;
	cout << "------------------------------------------" << endl;
	cout << "[��ѡ��] : ";
	int a;
	while (1)
	{
		a = _getch();
		if (a >= '0' && a <= '9')
			break;
	}
	return a-'0';
}
/***************************************************************************
  �������ƣ�getdifficulty
  ��    �ܣ���ʾ�û������Ѷȣ�������������
  �����������
  �� �� ֵ������
  ˵    ����
***************************************************************************/
int getdifficulty()
{
	cct_cls();
	cout << "��ѡ���Ѷȣ�" << endl;
	cout << "  1.����( 9*9  - 10����)" << endl;
	cout << "  2.�м�(16*16 - 40����)" << endl;
	cout << "  3.�߼�(16*30 - 99����)" << endl;
	cout << "������[1..3]��" << endl;
	int a;
	while (1)
	{
		a = _getch();
		if (a >= '1' && a <= '3')
			break;
	}
	cct_cls();
	return a-'0';
}
/***************************************************************************
  �������ƣ�Func1
  ��    �ܣ�����1
  �������������ͼ�����������У���
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void Func1(plaid bomb[][30], int bombnum, int B_row, int B_column)
{
	create_bomb1(bomb, bombnum, B_row, B_column);//����ɨ��ͼ
	putoutbomb(bomb, B_row, B_column, 1);
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int Func2(plaid bomb[][30], int bombnum, int B_row, int B_column)
{
	

	int row, column;
	putoutbomb(bomb, B_row, B_column, 2);
	cout << endl << endl;
	cout << "�������λ�õ��������꣨���к��У��ϸ����ִ�Сд������G1/Af����Q/q�˳�����";
	if (getinrc(row, column, B_row, B_column)=='q')//��ȡrow��column
	{
		return 1;
	}
	create_bomb2(bomb, bombnum, B_row, B_column, row, column);
	openarea(bomb, row, column, B_row, B_column);//����չ��doge
	
	//putoutbomb(bomb, B_row, B_column, 1);
	//putoutbomb(bomb, B_row, B_column, 3);
	setcolor(bomb, B_row, B_column);//Ϊ����Ϳɫ
	return 0;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�����3����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void Func3(plaid bomb[][30], int bombnum, int B_row, int B_column)
{
	Func2(bomb, bombnum, B_row, B_column);//��ʼ������
	while (1)
	{
		int row, column;
		cout << endl << endl;
		cout << "�������λ�õ��������꣨���к��У��ϸ����ִ�Сд������G1/Af����Q/q�˳�����";
		if (getinrc(row, column, B_row, B_column)=='q')//��ȡrow��column
		{
			return;
		}
		if (bomb[row][column].element == '*')
		{
			cout << endl << endl;
			cout << "��������Ϸ����" << endl;
			return;
		}
		else if (bomb[row][column].element == '0')//���Ϊ0����ô������չ��
			openarea(bomb, row, column, B_row, B_column);//����չ��doge
		else if (bomb[row][column].element <= '8' && bomb[row][column].element >= '1')//���ֻ��һ���͸���Ϳɫ5
			bomb[row][column].flag = 1;
		setcolor(bomb, B_row, B_column);//Ϊ����Ϳɫ
		if (is_over(bomb, B_row, B_column))
		{
			cout << endl << endl;
			cout << "��ϲʤ������Ϸ����" << endl;
			return;
		}
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�����4����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void Func4(plaid bomb[][30], int bombnum, int B_row, int B_column)
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������

	/* �˴�����ĳ���ʼ */
	putoutbomb(bomb, B_row, B_column, 2);
	int time = 0;//�ж��ǲ��ǵ�һ������row��column
	while (1)
	{
		int row, column;
		cout << endl << endl;
		cout << "��������˵����& - ��Ϸ������ʱ��(���ַ����ɣ�����Ҫ������)" << endl;
		cout << "              ! - ��Ǹ�����Ϊ��(����!E3)" << endl;
		cout << "              # - ȡ�����      (����#E#)" << endl;
		cout << "������ ������������к��У��ϸ����ִ�Сд������G1/Af����Q/q�˳�����";
		char tag = getinrc(row, column, B_row, B_column) ;
		if (tag == 'q')
		{
			return;
		}
		else if (tag == '#')
		{
			if (bomb[row][column].flag == -1)
				bomb[row][column].flag = 0;
			setcolor(bomb, B_row, B_column);
		}
		else if (tag == '&')
		{
			QueryPerformanceCounter(&end);		//�����ֹӲ������������
			cout << endl<<"������ʱ�䣺" << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;
		}
		else if (tag == '!' )
		{
			if(bomb[row][column].flag == 0)
			    bomb[row][column].flag = -1;
			setcolor(bomb, B_row, B_column);
		}
		else if (tag == '%')
		{
			if (time == 0)//����ǵ�һ�ε�����ʹ�������
				create_bomb2(bomb, bombnum, B_row, B_column, row, column);//��������
			time++;
			if (bomb[row][column].element == '*'&& bomb[row][column].flag!=-1)//����㵽��û�о���ĵ��׾ͽ�������ʾ���Ҷ�����
			{
				bomb[row][column].flag = 1;
				setcolor(bomb, B_row, B_column);//Ϊ����Ϳɫ
				cout << endl << endl;
				cout << "��������Ϸ����" << endl;
				QueryPerformanceCounter(&end);		//�����ֹӲ������������
				cout << "��ʱ��" << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;
				return;
			}
			else if (bomb[row][column].element == '0')//���Ϊ0����ô������չ��
				openarea(bomb, row, column, B_row, B_column);//����չ��doge
			else if (bomb[row][column].element <= '8' && bomb[row][column].element >= '1'&& bomb[row][column].flag!=-1)//���ֻ��һ���͸���Ϳɫ5
				bomb[row][column].flag = 1;
			setcolor(bomb, B_row, B_column);//Ϊ����Ϳɫ
			if (is_over(bomb, B_row, B_column))
			{
				cout << endl << endl;
				cout << "��ϲʤ������Ϸ����" << endl;
				QueryPerformanceCounter(&end);		//�����ֹӲ������������
				cout << "��ʱ��" << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;
				return;
			}
		}
	}	
}
void Func5(plaid bomb[][30], int bombnum, int B_row, int B_column)
{
	create_bomb1(bomb, bombnum, B_row, B_column);
	putoutframe(B_row,B_column);
	setbombflag(bomb,B_row,B_column,1);
}
void Func6(plaid bomb[][30], int bombnum, int B_row, int B_column)
{
	int nrow, ncolumn;
	Func5(bomb, bombnum, B_row, B_column);
	getpisition(bomb, bombnum, B_row, B_column,nrow,ncolumn,6);
}
void Func7(plaid bomb[][30], int bombnum, int B_row, int B_column)
{
	int nrow, ncolumn;
	putoutframe(B_row, B_column);//������
	setblocks(bomb, B_row, B_column);//Ϊ����Ϳɫ
	getpisition(bomb, bombnum, B_row, B_column, nrow, ncolumn,7);//��ȡѡ�е�λ��
	create_bomb2(bomb, bombnum, B_row, B_column, nrow, ncolumn);//�����ڲ�����
	openarea(bomb, nrow, ncolumn, B_row, B_column);//����չ��doge
	setblocks(bomb, B_row, B_column);//Ϊ����Ϳɫ
	setbombflag(bomb, B_row, B_column,0);
	int row = 3 * (B_row)+4, column = 0;
	cct_gotoxy(column, row);
}
void Func8(plaid bomb[][30], int bombnum, int B_row, int B_column,int command)
{
	/* �˴�����ĳ���ʼ */
	cout << "��esc�˳� ";
	putoutframe(B_row, B_column);//������
	setblocks(bomb, B_row, B_column);//Ϊ����Ϳɫ
	int time = 0;
	while (1)
	{
		int row, column;
		int ret = getpisition(bomb, bombnum, B_row, B_column, row, column, 8) ;
		if (ret == MOUSE_LEFT_BUTTON_CLICK)//����ǵ���
		{
			if (time == 0)//����ǵ�һ�ε�����ʹ�������
				create_bomb2(bomb, bombnum, B_row, B_column, row, column);//��������
			time++;
			//setbombflag(bomb, B_row, B_column, 1);
			if (bomb[row][column].element == '*'&& bomb[row][column].flag!=-1)
			{
				bomb[row][column].flag = 1;
				int nrow = 3 * (B_row)+4, ncolumn = 0;
				cct_gotoxy(ncolumn, nrow);
				cout << "��������Ϸ����      " << endl;
				setblocks(bomb, B_row, B_column);//Ϊ����Ϳɫ
				setbombflag(bomb, B_row, B_column, 0);
				cct_gotoxy(ncolumn, nrow);
				return;
			}
			else if (bomb[row][column].element == '0')//���Ϊ0����ô������չ��
				openarea(bomb, row, column, B_row, B_column);//����չ��doge
			else if (bomb[row][column].element <= '8' && bomb[row][column].element >= '1')//���ֻ��һ���͸���Ϳɫ5
				bomb[row][column].flag = 1;
		}
		else if (ret == MOUSE_RIGHT_BUTTON_CLICK)//������Ҽ�
		{
			if (bomb[row][column].flag == -1)
			{
				bomb[row][column].flag = 0;
				bombnum++;
			}
			else if (bomb[row][column].flag == 0)
			{
				bomb[row][column].flag = -1;
				bombnum--;
			}
		}
		else if (ret == 27)//�����esc,�˳�
		{
			return;
		}
		if (is_over(bomb, B_row, B_column))
		{
			int row = 3 * (B_row)+4, column = 0;
			cct_gotoxy(column, row);
			cout << "��ϲʤ������Ϸ����" << endl;
			return;
		}	
		setblocks(bomb, B_row, B_column);//Ϊ����Ϳɫ
		setbombflag(bomb, B_row, B_column, 0);
	}
}
void Func9(plaid bomb[][30], int bombnum, int B_row, int B_column)
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������
	/* �˴�����ĳ���ʼ */
	int time = 0;
	cout << "Esc�˳�,�ո���ʾʱ��";
	putoutframe(B_row, B_column);//������
	setblocks(bomb, B_row, B_column);//Ϊ����Ϳɫ
	while (1)
	{
		int row, column;
		int ret = getpisition(bomb, bombnum, B_row, B_column, row, column, 8);
		if (ret == MOUSE_LEFT_BUTTON_CLICK)//����ǵ���
		{
			if (time == 0)//����ǵ�һ�ε�����ʹ�������
				create_bomb2(bomb, bombnum, B_row, B_column, row, column);//��������
			time++;
			if (bomb[row][column].element == '*' && bomb[row][column].flag != -1)
			{
				bomb[row][column].flag = 1;
				int nrow = 3 * (B_row)+4, ncolumn = 0;
				cct_gotoxy(ncolumn, nrow);
				cout << "��������Ϸ����      " << endl;
				setblocks(bomb, B_row, B_column);//Ϊ����Ϳɫ
				setbombflag(bomb, B_row, B_column, 0);
				cct_gotoxy(ncolumn, nrow);
				return;
			}
			else if (bomb[row][column].element == '0')//���Ϊ0����ô������չ��
				openarea(bomb, row, column, B_row, B_column);//����չ��doge
			else if (bomb[row][column].element <= '8' && bomb[row][column].element >= '1')//���ֻ��һ���͸���Ϳɫ5
				bomb[row][column].flag = 1;
		}
		else if (ret == MOUSE_RIGHT_BUTTON_CLICK)//������Ҽ�
		{
			if (bomb[row][column].flag == -1)
			{
				bomb[row][column].flag = 0;
				bombnum++;
			}
			else if (bomb[row][column].flag == 0)
			{
				bomb[row][column].flag = -1;
				bombnum--;
			}
			putbombnum(bombnum);
		}
		else if (ret == 27)//�����esc,�˳�
		{
			return;
		}
		else if (ret == 32)//����ǿո�
		{
			QueryPerformanceCounter(&end);		//�����ֹӲ������������
			cct_gotoxy(0, 0);
			cct_setcolor(0, 6);
			cout << "��ǰʱ�䣺" << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��";
			cct_setcolor();
			cout<<", Esc�˳�, �ո���ʾʱ��    " << endl;
		}
		if (is_over(bomb, B_row, B_column))
		{
			QueryPerformanceCounter(&end);		//�����ֹӲ������������
			cct_setcolor(0, 6);
			cout << "����ʱ��" << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��";
			cct_setcolor();
			cout << "��ϲʤ������Ϸ����    ";
			return;
		}
		setblocks(bomb, B_row, B_column);//Ϊ����Ϳɫ
		setbombflag(bomb, B_row, B_column, 0);
	}
}
