/*2250420 �� �¾�*/
#include<iostream>
#include <iomanip>
#include"cct.h"
#include<conio.h>
#include<Windows.h>
using namespace std;
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int plate[3][10];
int num[3];//��¼�����ϵ�������
int step = 0;
int sleep, put;//��ʱʱ�䣬���Ƿ���ʾ����
void putout()//�����ǰ�������
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
void putoutplate()//����������
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
void putoutpillar()//�������
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
  �������ƣ�move
  ��    �ܣ��ƶ�����
  �����������ʼ����Ŀ����
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void move(char src, char dst)
{
	plate[dst - 'A'][num[dst - 'A']] = plate[src - 'A'][num[src - 'A'] - 1];
	plate[src - 'A'][num[src - 'A'] - 1] = 0;
	num[dst - 'A']++;
	num[src - 'A']--;
}
//��ʱ����
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
		cout << "��" << setiosflags(ios::right) << setw(4) << step << "��" << "(" <<
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
	cout << "��" << setiosflags(ios::right) << setw(4) << step << "��" << "(" <<
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
	//����
	while (1)
	{
		cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
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
		cout << "��������ʼ��(A-C)" << endl;
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
		cout << "������Ŀ����(A-C)" << endl;
		cin >> dst;
		if (dst == src)
		{
			while (getchar() != '\n')
				;
			cout << "Ŀ����(A)��������ʼ��(A)��ͬ" << endl;
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
	//����sleep
	while (1)
	{
		cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
		cin >> sleep;
		if (sleep >= 0 && sleep <= 5)
			break;
		cin.clear();
	}
	while (1)
	{
		cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
		cin >> put;
		if (put >= 0 && put <= 1)
			break;
		cin.clear();
	}
	cct_cls();
	if (put == 1)
	{
		cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << sleep << "����ʾ�ڲ�����ֵ" << endl;
		cct_gotoxy(21, 25);
		cout << "��ʼ:";
		putoutpillar();
		putoutplate();
		putout();
	}
	else
	{
		cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << sleep << "������ʾ�ڲ�����ֵ" << endl;
		putoutpillar();
		putoutplate();
	}	
	hanoi(n, src, tmp, dst);
	cct_gotoxy(21, 35);
	system("pause"); //���������ʾ��ͣ��ע�⣺ֻ�ʺ����ض��������ر������ĳ���Ӵ˾���÷�Ϊ0��

	return 0;
}
