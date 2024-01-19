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
  函数名称：
  功    能：显示光标位置,并且在点击后返回事件，并且更新鼠标所指的数组坐标
  输入参数：
  返 回 值：
  说    明：
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
		int y = 0;//鼠标坐标
		int maction, kaction1, kaction2, ret;//键鼠事件
		 ret = cct_read_keyboard_and_mouse(x, y, maction, kaction1, kaction2);
		if (ret == CCT_MOUSE_EVENT) {
			cct_gotoxy(column, row);

			changetoinside(nrow, ncolumn, B_row, B_column, x, y);
			if (nrow >= 0 && ncolumn >= 0)
				cout << "[当前光标] " << char(nrow + 'A') << "行" << ncolumn << "列       ";
			else
				cout << "[当前光标] 位置非法     ";
			if (maction == MOUSE_LEFT_BUTTON_CLICK)//按下左键,退出循环
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
  函数名称：
  功    能：输出图形框架
  输入参数：
  返 回 值：
  说    明：
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
		//打印第1层
		cout << "  ";
		putoutframelines(2, B_column);
		//打印第二层
		cct_setcolor();
		cout << char('A' + i) << " ";
		putoutframelines(2, B_column);
		//打印第三层
		cout << "  ";
		if (i == B_row - 1)
			putoutframelines(4, B_column);
		else
			putoutframelines(3, B_column);
	}

}
/***************************************************************************
  函数名称：
  功    能：根据指令i逐行输出框架的指定行
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void putoutframelines(int i, int B_column)
{
	switch (i)
	{
	case 1:
		//打印表头
		cct_setcolor(15, 0);
		cout << "╔";
		for (int j = 0; j < B_column - 1; j++)
			cout << "══╦";
		cout << "══╗";
		cct_setcolor();
		cout << " ";
		break;
	case 2:
		//打印中间层
		for (int j = 0; j < B_column; j++)
		{
			cct_setcolor(15, 0);
			cout << "║";
			cct_setcolor(7, 0);
			cout << "    ";
		}
		cct_setcolor(15, 0);
		cout << "║";
		cct_setcolor();
		cout << " ";
		break;
	case 3:
		//打印第二层
		cct_setcolor(15, 0);
		cout << "╠";
		for (int j = 0; j < B_column - 1; j++)
			cout << "══╬";
		cout << "══╣";
		cct_setcolor();
		cout << " ";
		break;
	case 4:
		//打印表尾
		cct_setcolor(15, 0);
		cout << "╚";
		for (int j = 0; j < B_column - 1; j++)
			cout << "══╩";
		cout << "══╝";
		cct_setcolor();
		cout << " ";
		break;
	}
}
/***************************************************************************
  函数名称：
  功    能：将地雷和旗帜显示,如果tag为1就全显示，如果tag为0就显示falg为1的
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void setbombflag(plaid bomb[][30], int B_row, int B_column,int tag)
{
	for (int i = 0; i < B_row; i++)
	{
		for (int j = 0; j < B_column; j++)
			if ((tag==1||bomb[i][j].flag==1)&& bomb[i][j].element!='0')
			{//判断条件:不输出零的前提下，如果tag==1全部输出，否则只输出falg为1的
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
  函数名称：
  功    能：根据内部数组的信息给方块上色
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void setblocks(plaid bomb[][30], int B_row, int B_column)
{
	for (int i = 0; i < B_row; i++)
	{
		for (int j = 0; j < B_column; j++)
		{
			if (bomb[i][j].flag == 1&& bomb[i][j].alreadyflag==0)//如果这个子flag为1，上白色
			{
				blockgetcolor(i, j, 7);
				bomb[i][j].alreadyflag = 1;
			}
			else if (bomb[i][j].flag == -1&&bomb[i][j].alreadyflag == 0)//上红色
			{
				blockgetcolor(i, j, 12);
				bomb[i][j].alreadyflag = 1;
			}
			else if(bomb[i][j].flag == 0 )//上黄色
			{
				blockgetcolor(i, j, 6);
				bomb[i][j].alreadyflag = 0;
			}
		}
	}
}
/***************************************************************************
  函数名称：
  功    能：根据所给的内部数组的位置上色
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void blockgetcolor(int i, int j, int color)
{
	int row, column;
	getposition(column,row,0,i, j);//获取块左下角偏右一格的位置
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
	cout << "剩余雷数： " << bombnum << ",";
	cct_setcolor();
	cout << "Esc退出，空格显示时间";
}