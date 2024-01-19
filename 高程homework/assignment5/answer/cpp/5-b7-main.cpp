/*2250420 软工 陈君*/
#include<iostream>
#include <iomanip>
#include"cct.h"
#include<conio.h>
#include<Windows.h>
using namespace std;
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int plate[3][10];
int num[3];//记录柱子上的盘子数
int step = 0;
int sleep, put;//延时时间，和是否显示变量
void putout()//输出当前数组情况
{
	cct_gotoxy(40, 25);
	if (put == 1)
	{ 
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
}
void putoutplate()//输出盘子情况
{
	for (int i = 0; i < 10; i++)
	{  
		cct_gotoxy(11, 19 - i);
		if (plate[0][i] > 0)
			cout << setw(2) << plate[0][i];
		else
			cout << "  ";
	}
	for (int i = 0; i < 10; i++)
	{
		cct_gotoxy(21, 19 - i);
		if (plate[1][i] > 0)
			cout << setw(2) << plate[1][i];
		else
			cout << "  ";
	}
	for (int i = 0; i < 10; i++)
	{
		cct_gotoxy(31, 19 - i);
		if (plate[2][i] > 0)
			cout << setw(2) << plate[2][i];
		else
			cout << "  ";
	}
}
void putoutpillar()//输出柱子
{
	cct_gotoxy(10, 20);
	cout << "=========================";
	cct_gotoxy(12, 21);
	cout << 'A';
	cct_gotoxy(22, 21);
	cout << 'B';
	cct_gotoxy(32, 21);
	cout << 'C';
}
/***************************************************************************
  函数名称：move
  功    能：移动塔盘
  输入参数：起始柱和目标柱
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
//延时函数
void sleeptime(int sleep)
{
	switch (sleep)
	{
	case 0:
		while (_getch() != 13)
			;
		break;
	default:
		Sleep(100 * (6-sleep));
	}
}
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1) //A   B   C
	{
		step++;
		sleeptime(sleep);
		cct_gotoxy(21, 25);
		cout << "第" << setiosflags(ios::right) << setw(4) << step << "步" << "(" <<
			 "1" << "#: " << src << "-->" << dst;
		move(src, dst);
		putout();
		sleeptime(sleep);
		putoutplate();
		return;
	}
	hanoi(n - 1, src, dst, tmp);
	step++;
	sleeptime(sleep);
	cct_gotoxy(21, 25);
	cout << "第" << setiosflags(ios::right) << setw(4) << step << "步" << "(" <<
		n << "#: " << src << "-->" << dst;
	move(src, dst);
	putout();
	sleeptime(sleep);
	putoutplate();
	hanoi(n - 1, tmp, src, dst);
}
int main()
{
	int n;
	char src, tmp, dst;
	//输入
	while (1)
	{
		cout << "请输入汉诺塔的层数(1-10)" << endl;
		cin >> n;
		if (n <= 10 && n >= 1)
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
		if (src >= 'a' && src <= 'c')
		{
			src = src - 32;
			while (getchar() != '\n')
				;
			break;
		}
		if (src >= 'A' && src <= 'C')
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
		if (dst >= 'a' && dst <= 'c' && dst != src)
		{
			dst = dst - 32;
			while (getchar() != '\n')
				;
			break;
		}
		if (dst >= 'A' && dst <= 'C' && dst != src)
		{
			while (getchar() != '\n')
				;
			break;
		}

		cin.clear();
		while (getchar() != '\n')
			;
	}

	for (int i = 0; i < n; i++)
		plate[src - 'A'][i] = n - i;
	num[src - 'A'] = n;
	tmp = 'A' + 'B' + 'C' - src - dst;
	//输入sleep
	while (1)
	{
		cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
		cin >> sleep;
		if (sleep >= 0 && sleep <= 5)
			break;
		cin.clear();
	}
	while (1)
	{
		cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
		cin >> put;
		if (put >= 0 && put <= 1)
			break;
		cin.clear();
	}
	cct_cls();
	if (put == 1)
	{
		cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << sleep << "，显示内部数组值" << endl;
		cct_gotoxy(21, 25);
		cout << "初始:";
		putoutpillar();
		putoutplate();
		putout();
	}
	else
	{
		cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << sleep << "，不显示内部数组值" << endl;
		putoutpillar();
		putoutplate();
	}	
	hanoi(n, src, tmp, dst);
	cct_gotoxy(21, 35);
	system("pause"); //最后用这句表示暂停（注意：只适合于特定程序，无特别声明的程序加此句则得分为0）

	return 0;
}
