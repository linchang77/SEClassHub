/*1953609 ��� ���͢*/
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ����������һ�����������������������ӵĺ����в������κ���ʽ��ѭ��
				 ������ų���
				 ����const�ͱ���
		������ ������ȫ�ֱ���
   ----------------------------------------------------------------------------------- */
void printA(char start,char end)
{
	cout << start;
	if (start == end)
	{
		return;
	}
	else
	{
		printA(start - 1,end);
	}
}
void converse(char start, char end)
{
	cout << start;
	if (end == start)
	{
		return;
	}
	else
		converse(start +1, end);
}
   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ���������ӡ������
	 ���������order - 0 ������������
			   order - 1 ������������
	 �� �� ֵ��
	 ˵    ����
   ***************************************************************************/
void print_tower(char start_ch, char end_ch, int order)
{
	/* ����ʵ�֣������в������κ���ʽ��ѭ�����������徲̬�ֲ����� */
	if (order == 0)
	{
		cout << setfill(' ');
		cout << setw((end_ch - start_ch) + 1) << start_ch;
		if (start_ch != 'A')
		{
			printA(start_ch - 1,'A');
			converse('B', start_ch);
			cout << endl;
			if (start_ch == end_ch)
				return;
			else
				print_tower(start_ch + 1, end_ch, order);
		}
		else
		{
			cout << endl;
			if (end_ch != 'A')
				print_tower(start_ch + 1, end_ch, order);
			else
				return;
		}
	}
	else
	{
		if (start_ch == end_ch)
		{
			if (end_ch != 'A')
				return;
			else
			{
				cout << 'A' << endl;
				return;
			}
		}
		else
		{
			cout << setfill(' ');
			if (start_ch == 'A')
				converse(start_ch, end_ch);
			else
				converse(start_ch + 1, end_ch);
			printA(end_ch - 1, start_ch);
			cout << endl;
			cout << setw(start_ch - 63) << char((start_ch + 1));
			print_tower(start_ch + 1, end_ch, order);
		}
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч) */
	while (1) {
		cout << "����������ַ�(A~Z)" << endl;
		end_ch = getchar();			//����������һ���ַ�
		while (getchar() != '\n')	//��ջ�����ʣ���ַ�
			;
		if (end_ch >= 'A' && end_ch <= 'Z')
			break;
	}

	/* ��������ĸ��(�м�ΪA) */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl;/* ����ĸ����󳤶����= */
	cout << "��������ĸ��" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl;/* ����ĸ����󳤶����= */
	print_tower('A', end_ch, 0);
	cout << endl;

	/* ��������ĸ��(����ΪA) */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl; /* ����ĸ����󳤶����= */
	cout << "��������ĸ��" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl; /* ����ĸ����󳤶����= */
	print_tower('A', end_ch, 1);
	cout << endl;

	return 0;
}
