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
/* ���ļ���������Ŀ����Ϊ�˷�ֹ���ļ���Ū�� */
int main()
{
	
	while (true)
	{
		/* demo������ִ�д˾䣬���ô��ڴ�С�ͻ�����*/
		setconsoleborder(4);
		int command, difficulty;
		plaid bomb[16][30] ;
		//�����ʼ��
		for (int i = 0; i < 16; i++)
			for (int j = 0; j < 30; j++)
			{
				bomb[i][j].element = 0;
				bomb[i][j].flag = 0;
				bomb[i][j].alreadyflag = 0;
			}
		int bombnum, B_row,B_column;
		command = showmenu();//����menu�е�չʾUI
		if (command == 0)
			exit(1);
		difficulty = getdifficulty();//��ȡ�Ѷ�ֵ
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
		cout << endl << endl << "���س�������...";
		while (_getch() != '\r')
			;
		cct_setcolor();
		cct_cls();
	}
	return 0;
}