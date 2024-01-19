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
/* 空文件，给出的目的是为了防止把文件名弄错 */
int main()
{
	
	while (true)
	{
		/* demo中首先执行此句，设置窗口大小和缓冲区*/
		setconsoleborder(4);
		int command, difficulty;
		plaid bomb[16][30] ;
		//数组初始化
		for (int i = 0; i < 16; i++)
			for (int j = 0; j < 30; j++)
			{
				bomb[i][j].element = 0;
				bomb[i][j].flag = 0;
				bomb[i][j].alreadyflag = 0;
			}
		int bombnum, B_row,B_column;
		command = showmenu();//调用menu中的展示UI
		if (command == 0)
			exit(1);
		difficulty = getdifficulty();//获取难度值
		setparameter(&B_row, &B_column, &bombnum, difficulty);
		switch (command)
		{
			 case 1:
				 Func1(bomb,bombnum,B_row,B_column);
				 break;
			 case 2:
				 Func2(bomb, bombnum, B_row, B_column);
				 break;
			 case 3:
				 Func3(bomb, bombnum, B_row, B_column);
				 break;
			 case 4:
				 Func4(bomb, bombnum, B_row, B_column);
				 break;
			 case 5:
				 setconsoleborder(difficulty);
				 Func5(bomb, bombnum, B_row, B_column);
				 break;
			 case 6:
				 setconsoleborder(difficulty);
				 Func6(bomb, bombnum, B_row, B_column);
				 break;
			 case 7:
				 setconsoleborder(difficulty);
				 Func7(bomb, bombnum, B_row, B_column);
				 break;
			 case 8:
				 setconsoleborder(difficulty);
				 Func8(bomb, bombnum, B_row, B_column);
				 break;
			 case 9:
				 setconsoleborder(difficulty);
				 Func9(bomb, bombnum, B_row, B_column);
				 break;
		}
		cout << endl << endl << "按回车键继续...";
		while (_getch() != '\r')
			;
		cct_setcolor();
		cct_cls();
	}
	return 0;
}