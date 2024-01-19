/*1953609 ��� ���͢*/
#include"cmd_console_tools.h"
#include"90-b2.h"
#include <iostream>
#include <iomanip>
#include <tchar.h>
#include <string.h>
#include <Windows.h>
#include<conio.h>
using namespace std;
void print_moto(int moto[][10], int row, int column)//��ӡ����
{
	cout << "��ǰ���飺" << endl;
	cout << "  |";
	for (int i = 0; i < column; i++)
		cout << setw(3) << i;
	cout << endl << "--+";
	for (int i = 0; i < 3 * column; i++)
		cout << "-";
	cout << "-" << endl;
	for (int i = 0; i < row; i++)
	{
		cout << char(i + 'A') << " |";
		for (int j = 0; j < column; j++)
		{
			cout << setw(3) << moto[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int cmd_opr(int moto[][10], int row, int column, int findmoto[][10], int x, int y, int res, int target, int score_sum)
{
	cout << "��ȷ���Ƿ�����ڵ���ֵͬ�ϲ���C2��(Y/N/Q)��";
	char cmd;
	while (1)
	{
		cmd = _getch();
		if (cmd == 'y' || cmd == 'Y')
		{
			cout << "y" << endl << endl;
			cout << "��ֵͬ�鲢�������(��ͬɫ��ʶ)��" << endl;
			int merge_sum = merge_res(moto, row, column, findmoto, x, y);
			print_res(moto, row, column, findmoto, 0);
			int score_cur = score(res, merge_sum);
			score_sum += score_cur;
			cout << endl << "���ε÷֣�" << score_cur << " �ܵ÷֣�" << score_sum << " �ϳ�Ŀ�꣺" << target << endl;
			print_removeZero(moto, row, column, findmoto);
			break;
		}
		else if (cmd == 'n' || cmd == 'N')
		{
			cout << "n" << endl << endl;
			return score_sum;
		}
		else if (cmd == 'q' || cmd == 'Q')
		{
			cout << "q" << endl << endl;
			return -1;
		}
	}
	return score_sum;
}
void print_removeZero(int moto[][10], int row, int column, int findmoto[][10])
{
	cout << endl << "���س����������������0����..." << endl;
	int cmd;
	while (1)
	{
		cmd = _getch();
		if (cmd == 13)
		{
			break;
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			findmoto[i][j] = 0;
		}
	}
	down_arr(moto, row, column);
	cout << "��0�������(��ͬɫ��ʶ)��" << endl;
	cout << "  |";
	for (int i = 0; i < column; i++)
		cout << setw(3) << i;
	cout << endl << "--+";
	for (int i = 0; i < 3 * column; i++)
		cout << "-";
	cout << "-" << endl;
	for (int i = 0; i < row; i++)
	{
		cout << char(i + 'A') << " |";
		for (int j = 0; j < column; j++)
		{
			if (moto[i][j] != 0)
				cout << setw(3) << moto[i][j];
			else
			{
				int x, y;
				cct_getxy(x, y);
				cct_showint(x, y, 0, COLOR_BLACK, COLOR_BLACK, 2);
				cct_showint(x + 2, y, moto[i][j], COLOR_BLACK, COLOR_HYELLOW);
				findmoto[i][j] = 1;
				cct_setcolor(0, 7);
			}
		}
		cout << endl;
	}
	cout << endl << "���س���������ֵ���..." << endl;
	int cmd2;
	while (1)
	{
		cmd2 = _getch();
		if (cmd2 == 13)
		{
			break;
		}
	}
	set_zero(moto, row, column);
	cout << "��ֵ���������(��ͬɫ��ʶ)��" << endl;
	cout << "  |";
	for (int i = 0; i < column; i++)
		cout << setw(3) << i;
	cout << endl << "--+";
	for (int i = 0; i < 3 * column; i++)
		cout << "-";
	cout << "-" << endl;
	for (int i = 0; i < row; i++)
	{
		cout << char(i + 'A') << " |";
		for (int j = 0; j < column; j++)
		{
			if (findmoto[i][j] == 0)
				cout << setw(3) << moto[i][j];
			else
			{
				int x, y;
				cct_getxy(x, y);
				cct_showint(x, y, 0, COLOR_BLACK, COLOR_BLACK, 2);
				cct_showint(x + 2, y, moto[i][j], COLOR_BLACK, COLOR_HYELLOW);
				findmoto[i][j] = 0;
				cct_setcolor(0, 7);
			}
		}
		cout << endl;
	}
	cout << endl << "���κϳɽ��������س���������һ�εĺϳ�..." << endl;
	int cmd3;
	while (1)
	{
		cmd3 = _getch();
		if (cmd3 == 13)
		{
			break;
		}
	}
}
void print_res(int moto[][10], int row, int column, int findmoto[][10], int tag)
{
	if (tag == 1)
	{
		cout << "���ҽ�����飺" << endl;
		cout << "  |";
		for (int i = 0; i < column; i++)
			cout << setw(3) << i;
		cout << endl << "--+";
		for (int i = 0; i < 3 * column; i++)
			cout << "-";
		cout << "-" << endl;
		for (int i = 0; i < row; i++)
		{
			cout << char(i + 'A') << " |";
			for (int j = 0; j < column; j++)
			{
				if (findmoto[i][j] == 0)
					cout << setw(3) << findmoto[i][j];
				else
					cout << setw(3) << "*";
			}
			cout << endl;
		}
		cout << endl << endl << "��ǰ����(��ͬɫ��ʶ)��" << endl;
	}
	cout << "  |";
	for (int i = 0; i < column; i++)
		cout << setw(3) << i;
	cout << endl << "--+";
	for (int i = 0; i < 3 * column; i++)
		cout << "-";
	cout << "-" << endl;
	for (int i = 0; i < row; i++)
	{
		cout << char(i + 'A') << " |";
		for (int j = 0; j < column; j++)
		{
			if (findmoto[i][j] == 0)
				cout << setw(3) << moto[i][j];
			else
			{

				int x, y;
				cct_getxy(x, y);
				cct_showint(x, y, 0, COLOR_BLACK, COLOR_BLACK, 2);
				cct_showint(x + 2, y, moto[i][j], COLOR_BLACK, COLOR_HYELLOW);
				cct_setcolor(0, 7);
			}
		}
		cout << endl;
	}
}

void initial(char sign)
{
	int row, column;
	cct_cls();
	cout << "����������(5-8)��";
	while (1)
	{
		cin >> row;
		if (!cin.good() || row > 8 || row < 5)
		{
			cout << "���벻�Ϸ�������������";
			cct_showch(17, 0, 0, 0, 0, 10);
			cct_setcolor(0, 7);
			cct_gotoxy(17, 0);
			cin.clear();
			cin.ignore(2147483647, '\n');
			continue;
		}
		else
		{
			cin.clear();
			cin.ignore(2147483647, '\n');
			break;
		}
	}
	cout << "����������(5-10)��";
	while (1)
	{
		cin >> column;
		if (!cin.good() || column > 10 || column < 5)
		{
			cout << "���벻�Ϸ�������������";
			cct_showch(18, 1, 0, 0, 0, 10);
			cct_setcolor(0, 7);
			cct_gotoxy(18, 1);
			cin.clear();
			cin.ignore(2147483647, '\n');
			continue;
		}
		else
		{
			cin.clear();
			cin.ignore(2147483647, '\n');
			break;
		}
	}
	int target;
	if (sign == '3' || sign == '4')
	{
		cout << "������ϳ�Ŀ��(5-20)��";
		while (1)
		{
			cin >> target;
			if (!cin.good() || target > 20 || target < 5)
			{
				cout << "���벻�Ϸ�������������";
				cct_showch(21, 2, 0, 0, 0, 10);
				cct_setcolor(0, 7);
				cct_gotoxy(21, 2);
				cin.clear();
				cin.ignore(2147483647, '\n');
				continue;
			}
			else
			{
				cin.clear();
				cin.ignore(2147483647, '\n');
				break;
			}
		}
	}
	cct_gotoxy(0, 4);
	int moto[8][10] = { 0 };
	set_arr(moto, row, column);
	print_moto(moto, row, column);
	char matx;
	int maty;
	while (1)
	{
		cout << endl << "������ĸ+������ʽ[����c2]����������꣺";
		cin >> matx >> maty;
		if (matx >= 'a' && matx <= 'z')
			matx -= 32;
		if (!cin.good() || maty > column || maty < 0 || matx<'A' || matx>char(row + 'A'))
		{
			cout << "���벻�Ϸ�������������";
			cct_showch(38, 5 + column, 0, 0, 0, 10);
			cct_setcolor(0, 7);
			cct_gotoxy(38, 5 + column);
			cin.clear();
			cin.ignore(2147483647, '\n');
			continue;
		}
		else
		{
			cin.clear();
			cin.ignore(2147483647, '\n');
		}
		cout << "����Ϊ" << matx << "��" << maty << "��" << endl << endl;
		int jud_adjoin;
		jud_adjoin = judge_adjoin(moto, row, column, matx - 'A', maty);
		if (jud_adjoin == 1)
			break;
		else
			cout << "����ľ�������λ�ô���������ֵͬ������������" << endl;
	}
	int findmoto[8][10] = { 0 };
	int res = moto[matx - 'A'][maty];
	findmoto[matx - 'A'][maty] = 1;
	if (sign == '1')
	{
		find_res(moto, row, column, findmoto, matx - 'A', maty, res);
		print_res(moto, row, column, findmoto, 1);
	}
	else if (sign == '2')
	{
		find_res_rec(moto, row, column, findmoto, matx - 'A', maty, res);
		print_res(moto, row, column, findmoto, 1);
	}
	else if (sign == '3')
	{
		find_res_rec(moto, row, column, findmoto, matx - 'A', maty, res);
		print_res(moto, row, column, findmoto, 1);
		int score_sum = 0;
		score_sum += cmd_opr(moto, row, column, findmoto, matx - 'A', maty, res, target, score_sum);
	}
	else if (sign == '4')
	{
		int score_sum = 0;
		int tag_four = 0;
		while (1)
		{
			if (tag_four == 1)
				print_moto(moto, row, column);
			while (tag_four == 1)
			{
				cout << endl << "������ĸ+������ʽ[����c2]����������꣺";
				cin >> matx >> maty;
				if (matx >= 'a' && matx <= 'z')
					matx -= 32;
				if (!cin.good() || maty > column || maty < 0 || matx<'A' || matx>char(row + 'A'))
				{
					cout << "���벻�Ϸ�������������";
					cct_showch(38, 5 + column, 0, 0, 0, 10);
					cct_setcolor(0, 7);
					cct_gotoxy(38, 5 + column);
					cin.clear();
					cin.ignore(2147483647, '\n');
					continue;
				}
				else
				{
					cin.clear();
					cin.ignore(2147483647, '\n');
				}
				cout << "����Ϊ" << matx << "��" << maty << "��" << endl << endl;
				int jud_adjoin;
				jud_adjoin = judge_adjoin(moto, row, column, matx - 'A', maty);
				if (jud_adjoin == 1)
				{
					tag_four++;
					break;
				}
				else
					cout << "����ľ�������λ�ô���������ֵͬ������������" << endl;
			}
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					findmoto[i][j] = 0;
				}
			}
			res = moto[matx - 'A'][maty];
			findmoto[matx - 'A'][maty] = 1;
			find_res_rec(moto, row, column, findmoto, matx - 'A', maty, res);
			print_res(moto, row, column, findmoto, 1);
			int score_cur = cmd_opr(moto, row, column, findmoto, matx - 'A', maty, res, target, score_sum);
			tag_four = 1;
			if (score_cur == -1)
				break;
			else
				score_sum += score_cur;
			if (find_max(moto, row, column) >= target)
			{
				int x, y;
				cct_getxy(x, y);
				cct_showstr(x, y, "�Ѿ��ϳɵ�", COLOR_HYELLOW, COLOR_HRED);
				cct_showint(x + 10, y, target, COLOR_HYELLOW, COLOR_HRED);
				cct_setcolor(0, 7);
				cout << endl << "���س������������Ŀ�����..." << endl;
				int cmd;
				while (1)
				{
					cmd = _getch();
					if (cmd == 13)
					{
						break;
					}
				}
				target++;
			}
		}
	}
	end(column);
	return;
}