/* 软工 2250420 陈君 */
/* 空文件，给出的目的是为了防止把文件名弄错 */
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
  函数名称：create_bomb
  功    能：产生内部数组
  输入参数：难度系数，内部数组
  返 回 值：空
  说    明：
***************************************************************************/
void create_bomb1(plaid bomb[][30], int bombnum, int B_row, int B_column)
{
	srand((unsigned)time(NULL));//初始化种子
	for (int i = 0; i < bombnum; i++)
	{
		int row = rand() % B_row;
		int column = rand() % B_column;
		if (bomb[row][column].element == '*')
			i--;
		else
			bomb[row][column].element = '*';
	}
	//产生这个点周围地雷的个数
	for (int i = 0; i < B_row; i++)
		for (int j = 0; j < B_column; j++)
			if (bomb[i][j].element != '*')
				creatflag(i, j, bomb, B_row, B_column);
}
/***************************************************************************
  函数名称：putoutbomb
  功    能：输出内部数组
  输入参数：难度系数，内部数组
  返 回 值：空
  说    明：
***************************************************************************/
void putoutbomb(plaid bomb[][30], int B_row, int B_column, int command)
{
	cout << "内部数组：" << endl;
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
  函数名称：creatflag
  功    能：产生旗帜
  输入参数：这个点的位置，地雷图，行列
  返 回 值：空
  说    明：
*********putoutbomb******************************************************************/
void creatflag(int i, int j, plaid bomb[][30], int row, int column)
{
	int sum = 0;
	int tag = 0;
	for (int n = i - 1; (n <= (i + 1)) && (n < row); n++)//确保行不超边界
	{
		if (n < 0)//如果n超出棋盘下一个
			continue;
		for (int m = j - 1; m <= j + 1 && m < column; m++)//确保列不越界
		{
			if (m < 0 || (n == i && m == j))//如果n超出棋盘或者等于原来的棋子就下一个
				continue;
			if (bomb[n][m].element == '*')
				sum++;
		}
	}
	bomb[i][j].element = sum + '0';
}
/***************************************************************************
  函数名称：
  功    能：产生功能二规定的内部数组
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void create_bomb2(plaid bomb[][30], int bombnum, int B_row, int B_column, int row, int column)
{
	srand((unsigned)time(NULL));//初始化种子
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
	//产生这个点周围地雷的个数
	for (int i = 0; i < B_row; i++)
		for (int j = 0; j < B_column; j++)
			if (bomb[i][j].element != '*')
				creatflag(i, j, bomb, B_row, B_column);
}
