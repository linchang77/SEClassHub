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
  �������ƣ�
  ��    �ܣ���ʾ���λ��,�����ڵ���󷵻��¼������Ҹ��������ָ����������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int getpisition(plaid bomb[][30], int bombnum, int B_row, int B_column, int& nrow, int& ncolumn,int func)
{
	int row = 3 * (B_row)+4, column = 0;
	int loop = 1;
	cct_enable_mouse();
	cct_setcursor(CURSOR_INVISIBLE);
	while (loop)
	{
		int x = 0;
		int y = 0;//�������
		int maction, kaction1, kaction2, ret;//�����¼�
		 ret = cct_read_keyboard_and_mouse(x, y, maction, kaction1, kaction2);
		if (ret == CCT_MOUSE_EVENT) {
			cct_gotoxy(column, row);

			changetoinside(nrow, ncolumn, B_row, B_column, x, y);
			if (nrow >= 0 && ncolumn >= 0)
				cout << "[��ǰ���] " << char(nrow + 'A') << "��" << ncolumn << "��       ";
			else
				cout << "[��ǰ���] λ�÷Ƿ�     ";
			if (maction == MOUSE_LEFT_BUTTON_CLICK)//�������,�˳�ѭ��
				return MOUSE_LEFT_BUTTON_CLICK;
			if (maction == MOUSE_RIGHT_BUTTON_CLICK && func == 8)
				return MOUSE_RIGHT_BUTTON_CLICK;
		}
		else if (ret == CCT_KEYBOARD_EVENT&&func==8)
		{
			return  kaction1;
		}
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ����ͼ�ο��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void putoutframe(int B_row, int B_column)
{
	cout << endl << "     ";
	for (int i = 0; i < B_column; i++)
		cout << setiosflags(ios::left) << setw(6) << i;
	cout << "  ";
	putoutframelines(1, B_column);
	for (int i = 0; i < B_row; i++)
	{
		//��ӡ��1��
		cout << "  ";
		putoutframelines(2, B_column);
		//��ӡ�ڶ���
		cct_setcolor();
		cout << char('A' + i) << " ";
		putoutframelines(2, B_column);
		//��ӡ������
		cout << "  ";
		if (i == B_row - 1)
			putoutframelines(4, B_column);
		else
			putoutframelines(3, B_column);
	}

}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�����ָ��i���������ܵ�ָ����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void putoutframelines(int i, int B_column)
{
	switch (i)
	{
	case 1:
		//��ӡ��ͷ
		cct_setcolor(15, 0);
		cout << "�X";
		for (int j = 0; j < B_column - 1; j++)
			cout << "�T�T�j";
		cout << "�T�T�[";
		cct_setcolor();
		cout << " ";
		break;
	case 2:
		//��ӡ�м��
		for (int j = 0; j < B_column; j++)
		{
			cct_setcolor(15, 0);
			cout << "�U";
			cct_setcolor(7, 0);
			cout << "    ";
		}
		cct_setcolor(15, 0);
		cout << "�U";
		cct_setcolor();
		cout << " ";
		break;
	case 3:
		//��ӡ�ڶ���
		cct_setcolor(15, 0);
		cout << "�d";
		for (int j = 0; j < B_column - 1; j++)
			cout << "�T�T�p";
		cout << "�T�T�g";
		cct_setcolor();
		cout << " ";
		break;
	case 4:
		//��ӡ��β
		cct_setcolor(15, 0);
		cout << "�^";
		for (int j = 0; j < B_column - 1; j++)
			cout << "�T�T�m";
		cout << "�T�T�a";
		cct_setcolor();
		cout << " ";
		break;
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ������׺�������ʾ,���tagΪ1��ȫ��ʾ�����tagΪ0����ʾfalgΪ1��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void setbombflag(plaid bomb[][30], int B_row, int B_column,int tag)
{
	for (int i = 0; i < B_row; i++)
	{
		for (int j = 0; j < B_column; j++)
			if ((tag==1||bomb[i][j].flag==1)&& bomb[i][j].element!='0')
			{//�ж�����:��������ǰ���£����tag==1ȫ�����������ֻ���falgΪ1��
				int x, y;
				getposition(x, y, B_row, i, j);
				if (bomb[i][j].element != '*')
					cct_showch(x, y, bomb[i][j].element, 7, bomb[i][j].element - '0');
				else
					cct_showch(x, y, '*', 7, 0);
				cct_setcolor();
			}
			else if (bomb[i][j].flag == -1)
			{
				int x, y;
				getposition(x, y, B_row, i, j);
				cct_showch(x, y, '#', 12, 7);
			}
	}
	cct_setcolor();
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ������ڲ��������Ϣ��������ɫ
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void setblocks(plaid bomb[][30], int B_row, int B_column)
{
	for (int i = 0; i < B_row; i++)
	{
		for (int j = 0; j < B_column; j++)
		{
			if (bomb[i][j].flag == 1&& bomb[i][j].alreadyflag==0)//��������flagΪ1���ϰ�ɫ
			{
				blockgetcolor(i, j, 7);
				bomb[i][j].alreadyflag = 1;
			}
			else if (bomb[i][j].flag == -1&&bomb[i][j].alreadyflag == 0)//�Ϻ�ɫ
			{
				blockgetcolor(i, j, 12);
				bomb[i][j].alreadyflag = 1;
			}
			else if(bomb[i][j].flag == 0 )//�ϻ�ɫ
			{
				blockgetcolor(i, j, 6);
				bomb[i][j].alreadyflag = 0;
			}
		}
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ������������ڲ������λ����ɫ
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void blockgetcolor(int i, int j, int color)
{
	int row, column;
	getposition(column,row,0,i, j);//��ȡ�����½�ƫ��һ���λ��
	cct_showch(column-1, row , ' ', color, 0, 4);
	cct_showch(column - 1, row - 1, ' ', color, 0, 4);
	cct_setcolor();
}
void putbombnum(int bombnum)
{
	if (bombnum < 0)
		bombnum = 0;
	cct_gotoxy(0, 0);
	cct_setcolor(0, 6);
	cout << "ʣ�������� " << bombnum << ",";
	cct_setcolor();
	cout << "Esc�˳����ո���ʾʱ��";
}