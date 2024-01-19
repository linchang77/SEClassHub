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
  函数名称：setparameter
  功    能：设置row，column，bombnum的参数
  输入参数：难度系数，内部数组
  返 回 值：空
  说    明：
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
  函数名称：to_be_continued
  功    能：提示继续
  输入参数：const char* prompt, const int X, const int Y
  返 回 值：空
  说    明：
***************************************************************************/
void to_be_continued(const char* prompt, const int X, const int Y)
{
	cct_setcolor(); //恢复缺省颜色
	cct_gotoxy(X, Y);

	if (prompt)
		cout << prompt << "，按回车键继续...";
	else
		cout << "按回车键继续...";

	/* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
	while (_getch() != '\r')
		;

	cct_cls();

	return;
}
/***************************************************************************
  函数名称：
  功    能：领域展开
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void openarea(plaid bomb[][30], int row, int column, int B_row, int B_column)
{
	find(bomb, row, column, B_row, B_column);//找出0的路径
	//putoutbomb(bomb, B_row, B_column, 1);
	//putoutbomb(bomb, B_row, B_column, 3);
	openflag(bomb, B_row, B_column);
}
/***************************************************************************
  函数名称：
  功    能：寻找0的路径
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void find(plaid bomb[][30], int row, int column, int B_row, int B_column)
{
	if (row<0 || row>=B_row || column<0 || column>=B_column
		||bomb[row][column].element != '0' || bomb[row][column].flag == 1)//如果数组越界就结束
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
  函数名称：
  功    能：打开打开的0的周围的flag
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void openflag(plaid bomb[][30], int B_row, int B_column)
{
	bool tag = 1;
	while (tag)
	{
		tag = 0;//判断的参数
		for (int i = 0; i < B_row; i++)//遍历一遍棋盘，看看0周围的子有没有打开
		{
			for (int j = 0; j < B_column; j++)
				if (bomb[i][j].flag!=1&&bomb_checkzero(bomb, i, j, B_row, B_column) )//如果这个点还没有打开就检测需不需要打开
				{
					bomb[i][j].flag = 1;
					tag = 1;
				}
		}
		//如果遍历下来tag没有发生改变说明场面上没有需要打开的东西了就结束
	}
	
}
/***************************************************************************
  函数名称：
  功    能：为领域上色,并输出
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void setcolor(plaid bomb[][30], int B_row, int B_column)
{
	cout << endl << "点开后的数组：" << endl;
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
			cct_getxy(x, y);//获取当前光标的位置
			if (bomb[i][j].flag == 1)//如果这个子flag为1，说明要上色
			{
				if(bomb[i][j].element=='*')
					cout << "* ";
				else
				{
					cct_showch(x, y, bomb[i][j].element, 14, bomb[i][j].element - '0');
					cct_setcolor(); //恢复缺省颜色
					cout << " ";
				}	
			}
			else if (bomb[i][j].flag == -1)
			{
				cct_showch(x, y, 'X', 4, 7);
				cct_setcolor(); //恢复缺省颜色
				cout << " ";
			}
			else
			    cout << "X ";

		}
		cout << endl;
	}
}
/***************************************************************************
  函数名称：
  功    能：判断数组周围有没有0
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
bool bomb_checkzero(plaid bomb[][30], int i, int j, int B_row, int B_column)
{
	for (int n = i - 1; (n <= (i + 1)) && (n < B_row); n++)//确保行不超边界
	{
		if (n < 0)//如果n超出棋盘下一个
			continue;
		for (int m = j - 1; m <= j + 1 && m < B_column; m++)//确保列不越界
		{
			if (m < 0 || (n == i && m == j))//如果n超出棋盘或者等于原来的棋子就下一个
				continue;
			if (bomb[n][m].element == '0' && bomb[n][m].flag == 1)//如果周围有打开的0就将这个子打开
				return true;
		}
	}
	return false;
}
/***************************************************************************
  函数名称：
  功    能：将字符类型的row和column换成int
  输入参数：
  返 回 值：
  说    明：
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
  函数名称：
  功    能：判断是否游戏结束
  输入参数：
  返 回 值：
  说    明：如果数组中所有flag都打开了就结束了
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
  函数名称：
  功    能：读入用户输入的row和column
  输入参数：
  返 回 值：
  说    明：默认符号是%说明不用在意之前的符号，如果读入有%，#，！，q就返回这个符号
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
  函数名称：
  功    能：根据难度设置窗口的大小
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void setconsoleborder(int difficulty)
{
	switch (difficulty)
	{
	case 1:
		cct_setfontsize("点阵字体",16,8);
		cct_setconsoleborder(59,35,59,35);
		break;
	case 2:
		cct_setfontsize("点阵字体", 16, 8);
		cct_setconsoleborder(101,56,101,56);
		break;
	case 3:
		cct_setfontsize("点阵字体", 16, 8);
		cct_setconsoleborder(185,56,185,56);
		break;
	case 4:
		cct_setfontsize("新宋体", 24, 0);
		cct_setconsoleborder(100,30,100,30);
		break;
	}
}
/***************************************************************************
  函数名称：
  功    能：根据提供的数组位置，返回屏幕上实际的位置
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void getposition(int& x, int& y, int B_row,int i,int j)
{
	x = 6 * j + 5;
	y = 3 * i + 4;
}
/***************************************************************************
  函数名称：
  功    能：将屏幕上的坐标转换到内部数组
  输入参数：
  返 回 值：
  说    明：
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