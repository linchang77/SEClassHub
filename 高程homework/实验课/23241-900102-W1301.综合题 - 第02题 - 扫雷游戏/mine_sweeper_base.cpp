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
  �������ƣ�create_bomb
  ��    �ܣ������ڲ�����
  ����������Ѷ�ϵ�����ڲ�����
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void create_bomb1(plaid bomb[][30], int bombnum, int B_row, int B_column)
{
	srand((unsigned)time(NULL));//��ʼ������
	for (int i = 0; i < bombnum; i++)
	{
		int row = rand() % B_row;
		int column = rand() % B_column;
		if (bomb[row][column].element == '*')
			i--;
		else
			bomb[row][column].element = '*';
	}
	//�����������Χ���׵ĸ���
	for (int i = 0; i < B_row; i++)
		for (int j = 0; j < B_column; j++)
			if (bomb[i][j].element != '*')
				creatflag(i, j, bomb, B_row, B_column);
}
/***************************************************************************
  �������ƣ�putoutbomb
  ��    �ܣ�����ڲ�����
  ����������Ѷ�ϵ�����ڲ�����
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void putoutbomb(plaid bomb[][30], int B_row, int B_column, int command)
{
	cout << "�ڲ����飺" << endl;
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
	if (command == 1)
	{
		for (int i = 0; i < B_row; i++)
		{
			cout << char('A' + i) << " " << "|";
			for (int j = 0; j < B_column; j++)
				cout << char(bomb[i][j].element) << " ";
			cout << endl;
		}
	}
	else if (command == 2)
	{
		for (int i = 0; i < B_row; i++)
		{
			cout << char('A' + i) << " " << "|";
			for (int j = 0; j < B_column; j++)
				cout << "X" << " ";
			cout << endl;
		}
	}
	else if (command == 3)
	{
		for (int i = 0; i < B_row; i++)
		{
			cout << char('A' + i) << " " << "|";
			for (int j = 0; j < B_column; j++)
				cout << bomb[i][j].flag << " ";
			cout << endl;
		}
	}
}
/***************************************************************************
  �������ƣ�creatflag
  ��    �ܣ���������
  ���������������λ�ã�����ͼ������
  �� �� ֵ����
  ˵    ����
*********putoutbomb******************************************************************/
void creatflag(int i, int j, plaid bomb[][30], int row, int column)
{
	int sum = 0;
	int tag = 0;
	for (int n = i - 1; (n <= (i + 1)) && (n < row); n++)//ȷ���в����߽�
	{
		if (n < 0)//���n����������һ��
			continue;
		for (int m = j - 1; m <= j + 1 && m < column; m++)//ȷ���в�Խ��
		{
			if (m < 0 || (n == i && m == j))//���n�������̻��ߵ���ԭ�������Ӿ���һ��
				continue;
			if (bomb[n][m].element == '*')
				sum++;
		}
	}
	bomb[i][j].element = sum + '0';
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ��������ܶ��涨���ڲ�����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void create_bomb2(plaid bomb[][30], int bombnum, int B_row, int B_column, int row, int column)
{
	srand((unsigned)time(NULL));//��ʼ������
	for (int i = 0; i < bombnum; i++)
	{
		int random_row = rand() % B_row;
		int random_column = rand() % B_column;
		if (bomb[random_row][random_column].element == '*' || (abs(random_row - row) <= 1 && abs(random_column - column) <= 1))
		{
			i--;
		}
		else
			bomb[random_row][random_column].element = '*';
	}
	//�����������Χ���׵ĸ���
	for (int i = 0; i < B_row; i++)
		for (int j = 0; j < B_column; j++)
			if (bomb[i][j].element != '*')
				creatflag(i, j, bomb, B_row, B_column);
}
