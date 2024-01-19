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
  函数名称：showmenu
  功    能：展示菜单，返回用户选择的选项
  输入参数：空
  返 回 值：整型
  说    明：
***************************************************************************/
int showmenu()//
{
	cout << "------------------------------------------" << endl;
	cout << "1.选择难度并显示内部数组" << endl;
	cout << "2.输入初始位置并显示被打开的初始区域" << endl;
	cout << "3.内部数组基础版" << endl;
	cout << "4.内部数组完整版（标记、运行时间）" << endl;
	cout << "5.画出伪图形化框架并显示内部数据" << endl;
	cout << "6.检测鼠标位置和合法性（左键单击退出）" << endl;
	cout << "7.鼠标选择初始位置并显示被打开的初始区域" << endl;
	cout << "8.伪图形界面基础版" << endl;
	cout << "9.伪图形界面完整版" << endl;
	cout << "0.退出游戏" << endl;
	cout << "------------------------------------------" << endl;
	cout << "[请选择] : ";
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
  函数名称：getdifficulty
  功    能：提示用户输入难度，并返回主函数
  输入参数：空
  返 回 值：整型
  说    明：
***************************************************************************/
int getdifficulty()
{
	cct_cls();
	cout << "请选择难度：" << endl;
	cout << "  1.初级( 9*9  - 10颗雷)" << endl;
	cout << "  2.中级(16*16 - 40颗雷)" << endl;
	cout << "  3.高级(16*30 - 99颗雷)" << endl;
	cout << "请输入[1..3]：" << endl;
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
  函数名称：Func1
  功    能：功能1
  输入参数：地雷图，地雷数，行，列
  返 回 值：空
  说    明：
***************************************************************************/
void Func1(plaid bomb[][30], int bombnum, int B_row, int B_column)
{
	create_bomb1(bomb, bombnum, B_row, B_column);//产生扫雷图
	putoutbomb(bomb, B_row, B_column, 1);
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int Func2(plaid bomb[][30], int bombnum, int B_row, int B_column)
{
	

	int row, column;
	putoutbomb(bomb, B_row, B_column, 2);
	cout << endl << endl;
	cout << "输入非雷位置的行列坐标（先行后列，严格区分大小写，例：G1/Af，按Q/q退出）：";
	if (getinrc(row, column, B_row, B_column)=='q')//读取row，column
	{
		return 1;
	}
	create_bomb2(bomb, bombnum, B_row, B_column, row, column);
	openarea(bomb, row, column, B_row, B_column);//领域展开doge
	
	//putoutbomb(bomb, B_row, B_column, 1);
	//putoutbomb(bomb, B_row, B_column, 3);
	setcolor(bomb, B_row, B_column);//为领域涂色
	return 0;
}
/***************************************************************************
  函数名称：
  功    能：功能3函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void Func3(plaid bomb[][30], int bombnum, int B_row, int B_column)
{
	Func2(bomb, bombnum, B_row, B_column);//初始化区域
	while (1)
	{
		int row, column;
		cout << endl << endl;
		cout << "输入非雷位置的行列坐标（先行后列，严格区分大小写，例：G1/Af，按Q/q退出）：";
		if (getinrc(row, column, B_row, B_column)=='q')//读取row，column
		{
			return;
		}
		if (bomb[row][column].element == '*')
		{
			cout << endl << endl;
			cout << "你输了游戏结束" << endl;
			return;
		}
		else if (bomb[row][column].element == '0')//如果为0，那么请领域展开
			openarea(bomb, row, column, B_row, B_column);//领域展开doge
		else if (bomb[row][column].element <= '8' && bomb[row][column].element >= '1')//如果只是一个就给他涂色5
			bomb[row][column].flag = 1;
		setcolor(bomb, B_row, B_column);//为领域涂色
		if (is_over(bomb, B_row, B_column))
		{
			cout << endl << endl;
			cout << "恭喜胜利，游戏结束" << endl;
			return;
		}
	}
}
/***************************************************************************
  函数名称：
  功    能：功能4函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void Func4(plaid bomb[][30], int bombnum, int B_row, int B_column)
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	putoutbomb(bomb, B_row, B_column, 2);
	int time = 0;//判断是不是第一次输入row，column
	while (1)
	{
		int row, column;
		cout << endl << endl;
		cout << "特殊输入说明：& - 游戏已运行时间(单字符即可，不需要加坐标)" << endl;
		cout << "              ! - 标记该坐标为雷(例：!E3)" << endl;
		cout << "              # - 取消标记      (例：#E#)" << endl;
		cout << "请输入 （坐标必须先行后列，严格区分大小写，例：G1/Af，按Q/q退出）：";
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
			QueryPerformanceCounter(&end);		//获得终止硬件计数器计数
			cout << endl<<"已运行时间：" << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;
		}
		else if (tag == '!' )
		{
			if(bomb[row][column].flag == 0)
			    bomb[row][column].flag = -1;
			setcolor(bomb, B_row, B_column);
		}
		else if (tag == '%')
		{
			if (time == 0)//如果是第一次点击，就创建数组
				create_bomb2(bomb, bombnum, B_row, B_column, row, column);//创建数组
			time++;
			if (bomb[row][column].element == '*'&& bomb[row][column].flag!=-1)//如果点到了没有警告的地雷就讲地雷显示并且读出来
			{
				bomb[row][column].flag = 1;
				setcolor(bomb, B_row, B_column);//为领域涂色
				cout << endl << endl;
				cout << "你输了游戏结束" << endl;
				QueryPerformanceCounter(&end);		//获得终止硬件计数器计数
				cout << "耗时：" << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;
				return;
			}
			else if (bomb[row][column].element == '0')//如果为0，那么请领域展开
				openarea(bomb, row, column, B_row, B_column);//领域展开doge
			else if (bomb[row][column].element <= '8' && bomb[row][column].element >= '1'&& bomb[row][column].flag!=-1)//如果只是一个就给他涂色5
				bomb[row][column].flag = 1;
			setcolor(bomb, B_row, B_column);//为领域涂色
			if (is_over(bomb, B_row, B_column))
			{
				cout << endl << endl;
				cout << "恭喜胜利，游戏结束" << endl;
				QueryPerformanceCounter(&end);		//获得终止硬件计数器计数
				cout << "耗时：" << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;
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
	putoutframe(B_row, B_column);//输出框架
	setblocks(bomb, B_row, B_column);//为方块涂色
	getpisition(bomb, bombnum, B_row, B_column, nrow, ncolumn,7);//获取选中的位置
	create_bomb2(bomb, bombnum, B_row, B_column, nrow, ncolumn);//创建内部数组
	openarea(bomb, nrow, ncolumn, B_row, B_column);//领域展开doge
	setblocks(bomb, B_row, B_column);//为方块涂色
	setbombflag(bomb, B_row, B_column,0);
	int row = 3 * (B_row)+4, column = 0;
	cct_gotoxy(column, row);
}
void Func8(plaid bomb[][30], int bombnum, int B_row, int B_column,int command)
{
	/* 此处是你的程序开始 */
	cout << "按esc退出 ";
	putoutframe(B_row, B_column);//输出框架
	setblocks(bomb, B_row, B_column);//为方块涂色
	int time = 0;
	while (1)
	{
		int row, column;
		int ret = getpisition(bomb, bombnum, B_row, B_column, row, column, 8) ;
		if (ret == MOUSE_LEFT_BUTTON_CLICK)//如果是单击
		{
			if (time == 0)//如果是第一次点击，就创建数组
				create_bomb2(bomb, bombnum, B_row, B_column, row, column);//创建数组
			time++;
			//setbombflag(bomb, B_row, B_column, 1);
			if (bomb[row][column].element == '*'&& bomb[row][column].flag!=-1)
			{
				bomb[row][column].flag = 1;
				int nrow = 3 * (B_row)+4, ncolumn = 0;
				cct_gotoxy(ncolumn, nrow);
				cout << "你输了游戏结束      " << endl;
				setblocks(bomb, B_row, B_column);//为方块涂色
				setbombflag(bomb, B_row, B_column, 0);
				cct_gotoxy(ncolumn, nrow);
				return;
			}
			else if (bomb[row][column].element == '0')//如果为0，那么请领域展开
				openarea(bomb, row, column, B_row, B_column);//领域展开doge
			else if (bomb[row][column].element <= '8' && bomb[row][column].element >= '1')//如果只是一个就给他涂色5
				bomb[row][column].flag = 1;
		}
		else if (ret == MOUSE_RIGHT_BUTTON_CLICK)//如果是右键
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
		else if (ret == 27)//如果是esc,退出
		{
			return;
		}
		if (is_over(bomb, B_row, B_column))
		{
			int row = 3 * (B_row)+4, column = 0;
			cct_gotoxy(column, row);
			cout << "恭喜胜利，游戏结束" << endl;
			return;
		}	
		setblocks(bomb, B_row, B_column);//为方块涂色
		setbombflag(bomb, B_row, B_column, 0);
	}
}
void Func9(plaid bomb[][30], int bombnum, int B_row, int B_column)
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数
	/* 此处是你的程序开始 */
	int time = 0;
	cout << "Esc退出,空格显示时间";
	putoutframe(B_row, B_column);//输出框架
	setblocks(bomb, B_row, B_column);//为方块涂色
	while (1)
	{
		int row, column;
		int ret = getpisition(bomb, bombnum, B_row, B_column, row, column, 8);
		if (ret == MOUSE_LEFT_BUTTON_CLICK)//如果是单击
		{
			if (time == 0)//如果是第一次点击，就创建数组
				create_bomb2(bomb, bombnum, B_row, B_column, row, column);//创建数组
			time++;
			if (bomb[row][column].element == '*' && bomb[row][column].flag != -1)
			{
				bomb[row][column].flag = 1;
				int nrow = 3 * (B_row)+4, ncolumn = 0;
				cct_gotoxy(ncolumn, nrow);
				cout << "你输了游戏结束      " << endl;
				setblocks(bomb, B_row, B_column);//为方块涂色
				setbombflag(bomb, B_row, B_column, 0);
				cct_gotoxy(ncolumn, nrow);
				return;
			}
			else if (bomb[row][column].element == '0')//如果为0，那么请领域展开
				openarea(bomb, row, column, B_row, B_column);//领域展开doge
			else if (bomb[row][column].element <= '8' && bomb[row][column].element >= '1')//如果只是一个就给他涂色5
				bomb[row][column].flag = 1;
		}
		else if (ret == MOUSE_RIGHT_BUTTON_CLICK)//如果是右键
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
		else if (ret == 27)//如果是esc,退出
		{
			return;
		}
		else if (ret == 32)//如果是空格
		{
			QueryPerformanceCounter(&end);		//获得终止硬件计数器计数
			cct_gotoxy(0, 0);
			cct_setcolor(0, 6);
			cout << "当前时间：" << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒";
			cct_setcolor();
			cout<<", Esc退出, 空格显示时间    " << endl;
		}
		if (is_over(bomb, B_row, B_column))
		{
			QueryPerformanceCounter(&end);		//获得终止硬件计数器计数
			cct_setcolor(0, 6);
			cout << "共用时：" << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒";
			cct_setcolor();
			cout << "恭喜胜利，游戏结束    ";
			return;
		}
		setblocks(bomb, B_row, B_column);//为方块涂色
		setbombflag(bomb, B_row, B_column, 0);
	}
}
