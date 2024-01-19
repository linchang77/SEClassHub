/* 软工 2250420 陈君 */
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

     本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
int plate[3][10];
int num[3];//记录柱子上的盘子数
int step = 0;
int sleep;
/***************************************************************************
  函数名称：setparameter
  功    能：初始化层数，目标柱和起始柱
  输入参数：char* src, char* dst,char* temp, int* n
  返 回 值：空
  说    明：
***************************************************************************/
void setparameter(char* src, char* dst,char* temp, int* n)
{
	while (1)
	{
		cout << "请输入汉诺塔的层数(1-10)" << endl;
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
		cout << "请输入起始柱(A-C)" << endl;
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
		cout << "请输入目标柱(A-C)" << endl;
		cin >> dst;
		if (dst == src)
		{
			while (getchar() != '\n')
				;
			cout << "目标柱(A)不能与起始柱(A)相同" << endl;
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
  函数名称：hanoi
  功    能：递归调用函数
  输入参数：int n, char src, char tmp, char dst,const int command
  返 回 值：空
  说    明：
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst,const int command)
{
	if (n == 1) //A   B   C
	{
		step++;
		putout_by_command(command, n, step, src, dst);//后台数组移动完之后图像开始移动
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
  函数名称：clear_screen
  功    能：清屏函数
  输入参数：void
  返 回 值：空
  说    明：
***************************************************************************/
void clear_screen()
{
	cct_setcolor(); //恢复缺省颜色
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
  函数名称：putout_by_command
  功    能：输出函数
  输入参数：const int command, int n, int step, char src, char dst
  返 回 值：空
  说    明：
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
			cout << "第" << setiosflags(ios::right) << setw(4) << step << " 步" << "(" <<
			setiosflags(ios::right) << setw(2) << "1" << "#: " << src << "-->" << dst<<")" << endl;
		else
			cout << "第" << setiosflags(ios::right) << setw(4) << step << " 步" << "(" <<
			setiosflags(ios::right) << setw(2) << n << "#: " << src << "-->" << dst << ")" <<endl;
		break;
	case 3:
		if (n == 1)
			cout << "第" << setiosflags(ios::right) << setw(4) << step << " 步" << "(" <<
				setiosflags(ios::right) << setw(2) << "1" << "): " << src << "-->" << dst;
		else
			cout << "第" << setiosflags(ios::right) << setw(4) << step << " 步" << "(" <<
				setiosflags(ios::right) << setw(2) << n << "): " << src << "-->" << dst;
		move(src, dst);
		putout(command);
		break;
	case 4:
		sleeptime(sleep);
		cct_gotoxy(0, 17);
		if (n == 1) //A   B   C
			cout << "第" << setiosflags(ios::right) << setw(4) << step << "步" << "(" <<
				"1" << "#: " << src << "-->" << dst<<") ";
		else
			cout << "第" << setiosflags(ios::right) << setw(4) << step << "步" << "(" <<
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
			cout << "第" << setiosflags(ios::right) << setw(4) << step << "步" << "(" <<
			"1" << "#: " << src << "-->" << dst << ") ";
		else
			cout << "第" << setiosflags(ios::right) << setw(4) << step << "步" << "(" <<
			n << "#: " << src << "-->" << dst << ") ";
		move(src, dst);
		putout(command);
		//sleeptime(sleep);
		putoutplate(command);
		break;
	}
}
/***************************************************************************
  函数名称：move
  功    能：移动盘子
  输入参数：const int command, int n, int step, char src, char dst
  返 回 值：空
  说    明：
***************************************************************************/
void move(char src, char dst)
{
	plate[dst - 'A'][num[dst - 'A']] = plate[src - 'A'][num[src - 'A'] - 1];
	plate[src - 'A'][num[src - 'A'] - 1] = 0;
	num[dst - 'A']++;
	num[src - 'A']--;
}
/***************************************************************************
  函数名称：putout
  功    能：输出盘子情况
  输入参数：const int command, int n, int step, char src, char dst
  返 回 值：空
  说    明：
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
  函数名称：initplate
  功    能：初始化盘子
  输入参数：char src, int n
  返 回 值：空
  说    明：
***************************************************************************/
void initplate(char src, int n)
{
	for (int i = 0; i < n; i++)
		plate[src - 'A'][i] = n - i;
	num[src - 'A'] = n;
}
/***************************************************************************
  函数名称：setslee
  功    能：初始化延时参数
  输入参数：空
  返 回 值：空
  说    明：
***************************************************************************/
void setsleep()
{
	while (1)
	{
		cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
		cin >> sleep;
		if (sleep >= 0 && sleep <= 5)
			break;
		cin.clear();
	}
}
/***************************************************************************
  函数名称：initputout4
  功    能：功能4的初始化页面
  输入参数：char src,char dst,int n,int command
  返 回 值：空
  说    明：
***************************************************************************/
void initputout(char src,char dst,int n,int command)
{
	cct_cls();
	cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << sleep << endl;
	putoutpillar(command);
	putoutplate(command);
	if(command==4)
		cct_gotoxy(0, 17);
	if(command==8||command==9)
		cct_gotoxy(0, 32);
	cout << "初始: ";
	putout(command);
	if(command==8||command==9)
	    func6(n,src);
}
/***************************************************************************
  函数名称：putoutpillar
  功    能：输出柱子
  输入参数：空
  返 回 值：空
  说    明：
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
  函数名称：sleeptime
  功    能：延时函数用于控制盘子移动速度
  输入参数：int sleep
  返 回 值：空
  说    明：
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
  函数名称：to_be_continued
  功    能：提示继续
  输入参数：const char* prompt, const int X, const int Y 
  返 回 值：空
  说    明：
***************************************************************************/
void to_be_continued(const char* prompt, const int X, const int Y )
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
  函数名称：func5
  功    能：功能5
  输入参数：void
  返 回 值：空
  说    明：
***************************************************************************/
void func5()//功能5
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
  函数名称：func6
  功    能：功能6,显示盘子
  输入参数：int n,char src
  返 回 值：空
  说    明：
***************************************************************************/
void func6(int n,char src)
{
	int row = 15;
	int column = 1;
	func5();//先显示柱子
	for (int i = 0; i < n; i++)
	{
		cct_showch(12+32*(src-'A')-n+i, row - 1 - i, ' ', n - i, n - i, (n - i) * 2 + 1);
		Sleep(100);
	}		
}
/***************************************************************************
  函数名称：func7
  功    能：功能7,移动盘子
  输入参数：int n,char src，char dst
  返 回 值：空
  说    明：
***************************************************************************/
void func7(int plate_num, char src, char dst,int command)   //功能7
{
	if(command==7)
	move(src, dst);
	int src_hight = num[src - 'A']+1;
	int dst_hight = num[dst - 'A']-1;
	int row = 15;
	int column = 1;
	int sleeptime = 100;
	//初始化盘子位置
	int x = 12+32*(src-'A')-plate_num;//移动盘子的x坐标
	int y = row-src_hight;//移动盘子的y坐标
	int dst_x = 12 + 32 * (dst - 'A') - plate_num;
	int dst_y = row - dst_hight-1;
	if (command == 7)
	{
		while (_getch() != '\r')
			;
		
	}
	//向上运动出柱子
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
	//横向移动
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
	cct_setcolor(); //恢复缺省颜色
}
/***************************************************************************
  函数名称：menu_5_6_7
  功    能：5，6，7的菜单调用函数
  输入参数：int command, int num, char src, char dst
  返 回 值：空
  说    明：
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
		cout << "从 A 移动到 C，共 4 层";
		func6(num, src);
		func7(1,src, 'A' + 'B' + 'C' - src - dst,command);
		break;
	}
}
void startgame(char src,char dst,int n)//开始游戏
{
	cct_setcolor();//设置颜色
	while (1)
	{
		cct_gotoxy(0, 34);
		cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";
		char now_src, now_dst;
		while (1)
		{
			cct_gotoxy(0, 34);
			cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";
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
		putout_by_command(8, plate[now_src - 'A'][num[now_src - 'A'] - 1], step, now_src, now_dst);//后台数组移动完之后图像开始移动
		func7(plate[now_dst-'A'][num[ now_dst - 'A']-1], now_src, now_dst, 8);
		if (plate[now_dst - 'A'][num[now_dst - 'A'] - 1] == 1 && num[now_dst - 'A'] == n)
		{
			cct_gotoxy(0, 35);
			cout << "游戏结束!";
			break;
		}
	}
}
bool is_valid(char now_src, char now_dst)//判断合法
{
	if (plate[now_src - 'A'][num[now_src - 'A'] - 1] == 0)
	{
		cct_gotoxy(0, 35);
		cout << "源柱为空!";
		Sleep(600);
		cct_gotoxy(0, 35);
		cout << "                     ";
		return false;
	}
	if (plate[now_src - 'A'][num[now_src - 'A'] - 1] > plate[now_dst - 'A'][num[now_dst - 'A'] - 1]&&
		plate[now_dst - 'A'][num[now_dst - 'A'] - 1]!=0)
	{
		cct_gotoxy(0, 36);
		cout << "大盘压小盘，移动非法!";
		Sleep(600);
		cct_gotoxy(0, 36);
		cout << "                     ";
		return false;
	}
	return true;
}