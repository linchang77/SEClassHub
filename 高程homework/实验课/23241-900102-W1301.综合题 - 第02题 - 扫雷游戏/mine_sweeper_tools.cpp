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
  �������ƣ�setparameter
  ��    �ܣ�����row��column��bombnum�Ĳ���
  ����������Ѷ�ϵ�����ڲ�����
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void setparameter(int* B_row, int* B_column, int* bombnum, int difficulty)
{
	if (difficulty == 1)
	{
		*bombnum = 10;
		*B_row = 9;
		*B_column = 9;
	}
	else if (difficulty == 2)
	{
		*bombnum = 40;
		*B_row = 16;
		*B_column = 16;
	}
	else if (difficulty == 3)
	{
		*bombnum = 99;
		*B_row = 16;
		*B_column = 30;
	}
}
/***************************************************************************
  �������ƣ�to_be_continued
  ��    �ܣ���ʾ����
  ���������const char* prompt, const int X, const int Y
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void to_be_continued(const char* prompt, const int X, const int Y)
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
  �������ƣ�
  ��    �ܣ�����չ��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void openarea(plaid bomb[][30], int row, int column, int B_row, int B_column)
{
	find(bomb, row, column, B_row, B_column);//�ҳ�0��·��
	//putoutbomb(bomb, B_row, B_column, 1);
	//putoutbomb(bomb, B_row, B_column, 3);
	openflag(bomb, B_row, B_column);
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�Ѱ��0��·��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void find(plaid bomb[][30], int row, int column, int B_row, int B_column)
{
	if (row<0 || row>=B_row || column<0 || column>=B_column
		||bomb[row][column].element != '0' || bomb[row][column].flag == 1)//�������Խ��ͽ���
		return;
	else
	{
		    bomb[row][column].flag = 1;
	}
	find(bomb, row + 1, column, B_row, B_column);
	find(bomb, row, column + 1, B_row, B_column);
	find(bomb, row, column - 1, B_row, B_column);
	find(bomb, row - 1, column, B_row, B_column);
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ��򿪴򿪵�0����Χ��flag
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void openflag(plaid bomb[][30], int B_row, int B_column)
{
	bool tag = 1;
	while (tag)
	{
		tag = 0;//�жϵĲ���
		for (int i = 0; i < B_row; i++)//����һ�����̣�����0��Χ������û�д�
		{
			for (int j = 0; j < B_column; j++)
				if (bomb[i][j].flag!=1&&bomb_checkzero(bomb, i, j, B_row, B_column) )//�������㻹û�д򿪾ͼ���費��Ҫ��
				{
					bomb[i][j].flag = 1;
					tag = 1;
				}
		}
		//�����������tagû�з����ı�˵��������û����Ҫ�򿪵Ķ����˾ͽ���
	}
	
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�Ϊ������ɫ,�����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void setcolor(plaid bomb[][30], int B_row, int B_column)
{
	cout << endl << "�㿪������飺" << endl;
	cout << "  |";
	for (int i = 1; i <= B_column; i++)
	{
		if (i < 10)
			cout << i << " ";
		else
			cout << char('a' + i - 10) << " ";
	}
	cout << endl;
	cout << "--+";
	for (int i = 0; i < B_column; i++)
		cout << "--";
	cout << "--" << endl;
	for (int i = 0; i < B_row; i++)
	{
		cout << char('A' + i) << " " << "|";
		for (int j = 0; j < B_column; j++)
		{
			int x, y;
			cct_getxy(x, y);//��ȡ��ǰ����λ��
			if (bomb[i][j].flag == 1)//��������flagΪ1��˵��Ҫ��ɫ
			{
				if(bomb[i][j].element=='*')
					cout << "* ";
				else
				{
					cct_showch(x, y, bomb[i][j].element, 14, bomb[i][j].element - '0');
					cct_setcolor(); //�ָ�ȱʡ��ɫ
					cout << " ";
				}	
			}
			else if (bomb[i][j].flag == -1)
			{
				cct_showch(x, y, 'X', 4, 7);
				cct_setcolor(); //�ָ�ȱʡ��ɫ
				cout << " ";
			}
			else
			    cout << "X ";

		}
		cout << endl;
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ��ж�������Χ��û��0
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
bool bomb_checkzero(plaid bomb[][30], int i, int j, int B_row, int B_column)
{
	for (int n = i - 1; (n <= (i + 1)) && (n < B_row); n++)//ȷ���в����߽�
	{
		if (n < 0)//���n����������һ��
			continue;
		for (int m = j - 1; m <= j + 1 && m < B_column; m++)//ȷ���в�Խ��
		{
			if (m < 0 || (n == i && m == j))//���n�������̻��ߵ���ԭ�������Ӿ���һ��
				continue;
			if (bomb[n][m].element == '0' && bomb[n][m].flag == 1)//�����Χ�д򿪵�0�ͽ�����Ӵ�
				return true;
		}
	}
	return false;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ����ַ����͵�row��column����int
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void changetoint(int& row, int& column, int B_column)
{
	row -= 'A';
	if (column >= '1' && column <= '9')
		column -= '1';
	else if (column >= 'a' && column <= 'a' + B_column - 10)
		column = column - 'a' + 9;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ��ж��Ƿ���Ϸ����
  ���������
  �� �� ֵ��
  ˵    �����������������flag�����˾ͽ�����
***************************************************************************/
bool is_over(plaid bomb[][30], int B_row, int B_column)
{
	for (int i = 0; i < B_row; i++)
	{
		for (int j = 0; j < B_column; j++)
			if (bomb[i][j].element != '*' && bomb[i][j].flag == 0)
				return false;
	}
	return true;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ������û������row��column
  ���������
  �� �� ֵ��
  ˵    ����Ĭ�Ϸ�����%˵����������֮ǰ�ķ��ţ����������%��#������q�ͷ����������
***************************************************************************/
char getinrc(int& row, int& column, int B_row, int B_column)
{
	char tag = '%';
	while (1)
	{
		row = _getch();
		if (row >= 'A' && row <= 'A' + B_row - 1)
		{
			cout << char(row);
			break;
		}
		else if (row == 'q' || row == 'Q')
			return 'q';
		else if (row == '#' || row == '!')
		{
			tag = row;
			cout << char(row);
		}
			
		else if (row == '&')
		{
			cout << char(row);
			return '&';
		}
			
	}
	while (1)
	{
		column = _getch();
		if ((column >= '1' && column <= '9') || (column >= 'a' && column <= 'a' + B_column - 10))
		{
			cout << char(column);
			break;
		}
	}
	changetoint(row, column, B_column);
	return tag;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ������Ѷ����ô��ڵĴ�С
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void setconsoleborder(int difficulty)
{
	switch (difficulty)
	{
	case 1:
		cct_setfontsize("��������",16,8);
		cct_setconsoleborder(59,35,59,35);
		break;
	case 2:
		cct_setfontsize("��������", 16, 8);
		cct_setconsoleborder(101,56,101,56);
		break;
	case 3:
		cct_setfontsize("��������", 16, 8);
		cct_setconsoleborder(185,56,185,56);
		break;
	case 4:
		cct_setfontsize("������", 24, 0);
		cct_setconsoleborder(100,30,100,30);
		break;
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ������ṩ������λ�ã�������Ļ��ʵ�ʵ�λ��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void getposition(int& x, int& y, int B_row,int i,int j)
{
	x = 6 * j + 5;
	y = 3 * i + 4;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�����Ļ�ϵ�����ת�����ڲ�����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void changetoinside(int& x, int& y, int B_row, int B_column, int i, int j)
{
	if ((i - 4) % 6 >= 0 && (i - 4) % 6 <= 3 && (j - 3) >= 0 && (j - 3) % 3 <= 1 && i >= 4 && j >= 3)
	{
		y = (i-4) / 6;
		x = (j-3) / 3;
	}
	else
	{
		x = -1;
		y = -1;
	}
}