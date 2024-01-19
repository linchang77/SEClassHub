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
void initial_graph(char sign)
{
	cct_setcursor(CURSOR_INVISIBLE);
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
	int moto[8][10] = { 0 };
	int findmoto[8][10] = { 0 };
	int target = 0;
	if (sign == '8' || sign == '9')
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
	set_arr(moto, row, column);
	if (sign == '5') {
		int a, b, c, d;
		cct_getconsoleborder(a, b, c, d);
		cct_setcolor();
		cct_cls();
		getGraphSizeInfo(row, column, false, c, d);
		d += 5;
		c += 4;
		cct_setconsoleborder(c, d + 5);
		cct_gotoxy(0, 0);
		cout << "��Ļ��ǰ����Ϊ��" << c << "��" << d << "��";
		drawborder(row, column, false);
		for (int i = 0; i < row; i++) 
		{
			for (int j = 0; j < column; j++) 
			{
				drawCard(i, j, moto[i][j], false);
				Sleep(30);
			}
		}
		cct_setcolor();
		setbottonCur();
		end(column);
		cct_setconsoleborder(a, b);
	}
	if (sign == '6') 
	{
		int a, b, c, d;
		cct_getconsoleborder(a, b, c, d);
		cct_setcolor();
		cct_cls();
		getGraphSizeInfo(row, column, true, c, d);
		d += 5;
		cct_setconsoleborder(c, d + 5);
		cct_gotoxy(0, 0);
		cout << "��Ļ��ǰ����Ϊ��" << c << "��" << d << "��";
		drawborder(row, column, true);
		for (int i = 0; i < row; i++) 
		{
			for (int j = 0; j < column; j++) 
			{
				drawCard(i, j, moto[i][j], true);
				Sleep(30);
			}
		}
		cct_setcolor();
		setbottonCur();
		end(column);
		cct_setconsoleborder(a, b);
	}
	if (sign == '7') 
	{
		int a, b, c, d, e;
		cct_getconsoleborder(a, b, c, d);
		cct_setcolor();
		cct_cls();
		getGraphSizeInfo(row, column, true, c, d);
		d += 5;
		cct_setconsoleborder(c, d + 5);
		cct_gotoxy(0, 0);
		cout << "��Ļ��ǰ����Ϊ��" << c << "��" << d << "��";
		drawborder(row, column, true);
		for (int i = 0; i < row; i++) 
		{
			for (int j = 0; j < column; j++) 
			{
				drawCard(i, j, moto[i][j], true);
				Sleep(30);
			}
		}
		int x, y, lastX, lastY;
		x = y = lastX = lastY = 0;
		while (true) 
		{
			if (cct_read_keyboard_and_mouse(c, c, c, d, e) == CCT_KEYBOARD_EVENT) 
			{
				if (d == 13)break;
				switch (e)
				{
					case KB_ARROW_UP:
						drawCard(lastY, lastX, moto[lastY][lastX], true);
						if (--y < 0) 
						{
							y = row - 1;
						}
						lastY = y;
						drawCard(y, x, moto[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
						break;
					case KB_ARROW_DOWN:
						drawCard(lastY, lastX, moto[lastY][lastX], true);
						if (++y >= row) 
						{
							y = 0;
						}
						lastY = y;
						drawCard(y, x, moto[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
						break;
					case KB_ARROW_LEFT:
						drawCard(lastY, lastX, moto[lastY][lastX], true);
						if (--x < 0) 
						{
							x = column - 1;
						}
						lastX = x;
						drawCard(y, x, moto[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
						break;
					case KB_ARROW_RIGHT:
						drawCard(lastY, lastX, moto[lastY][lastX], true);
						if (++x >= column) 
						{
							x = 0;
						}
						lastX = x;
						drawCard(y, x, moto[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
						break;
					default:
						break;
				}
			}
		}
		cct_setcolor();
		setbottonCur();
		end(column);
		cct_setconsoleborder(a, b);
	}
	if (sign == '8')
	{
		int a, b, c, d, e;
		cct_getconsoleborder(a, b, c, d);
		cct_setcolor();
		cct_cls();
		getGraphSizeInfo(row, column, true, c, d);
		d += 5;
		cct_setconsoleborder(c, d + 5);
		cct_gotoxy(0, 0);
		cout << "��Ļ��ǰ����Ϊ��" << c << "��" << d << "��";
		drawborder(row, column, true);
		for (int i = 0; i < row; i++) 
		{
			for (int j = 0; j < column; j++) 
			{
				drawCard(i, j, moto[i][j], true);
				Sleep(30);
			}
		}
		int x, y, lastX, lastY;
		x = y = lastX = lastY = 0;
		bool sure = false;
		drawCard(y, x, moto[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
		while (1) 
		{
			if (cct_read_keyboard_and_mouse(c, c, c, d, e) == CCT_KEYBOARD_EVENT) 
			{
				setbottonCur();
				cct_setcolor();
				cout << "��ͷ���ƶ����س���ѡ��                  ";
				if (d == 13)
				{
					if (!judge_adjoin(moto, row, column, y, x)) 
					{
						setbottonCur();
						cct_setcolor(0, COLOR_HYELLOW);
						cout << "��Χ����ֵͬ";
						cct_setcolor();
						cout << "��ͷ���ƶ����س���ѡ��";
					}
					else {
						if (!sure) {
							for (int i = 0; i < row; i++)
							{
								for (int j = 0; j < column; j++)
								{
									findmoto[i][j] = 0;
								}
							}
							find_res_rec(moto, row, column, findmoto, y, x, moto[y][x]);
						}
						else  //���ٴΰ��»س���ʱ,ȷ��Ҫ�ϲ�ʱ
						{
							int res = moto[y][x];
							int merge_sum = merge_res(moto, row, column, findmoto, y, x);
							int score_cur = score(res, merge_sum);
							cct_setcolor(); cct_gotoxy(0, 0);
							cout << "���ε÷֣�" << score_cur << " �ܵ÷֣�" << score_cur << " �ϳ�Ŀ�꣺" << target;
							for (int i = 0; i < row; i++) {
								for (int j = 0; j < column; j++) {
									if (findmoto[i][j]) {
										drawCard(i, j, moto[i][j], true, COLOR_HWHITE, COLOR_HWHITE);//Ϳ��
									}
								}
							}
							//��˸
							for (int i = 0; i < 5; i++) {
								drawCard(y, x, moto[y][x], true, COLOR_HYELLOW, COLOR_HRED);
								Sleep(100);
								drawCard(y, x, moto[y][x], true);
								Sleep(100);
							}
							cct_setcolor(); setbottonCur();
							cout << "�ϳ���ɣ��س�������0                ";
							int cmd;
							while (1)
							{
								cmd = _getch();
								if (cmd == 13)
								{
									break;
								}
							}
							findmoto[y][x] = 0;
							downAnime(moto, findmoto, row, column);
							down_arr(moto, row, column);
							/*	for (int i = 0; i < row; i++)
								{
									for (int j = 0; j < column; j++)
									{
										findmoto[i][j] = 0;
									}
								}
								*/
							cct_setcolor(); setbottonCur();
							cout << "����0��ɣ��س��������ֵ                ";
							while (1)
							{
								cmd = _getch();
								if (cmd == 13)
								{
									break;
								}
							}
							int max = find_max(moto, row, column);
							for (int i = 0; i < row; i++)
							{
								for (int j = 0; j < column; j++)
								{
									if (moto[i][j] == 0) {
										Sleep(200);
										moto[i][j] = random(max);
										drawCard(i, j, moto[i][j], true);    //�����ֵ
									}
								}
							}
							cct_setcolor();
							setbottonCur();
							end(column);
							cct_setconsoleborder(a, b);
							return;
						}

						for (int i = 0; i < row; i++) {
							for (int j = 0; j < column; j++) {
								if (findmoto[i][j]) {
									drawCard(i, j, moto[i][j], true, COLOR_HYELLOW, COLOR_CYAN);
								}
							}
						}
						drawCard(y, x, moto[y][x], true, COLOR_HYELLOW, COLOR_HRED);
						sure = true;
					}
				}
				if (sure && d != 13) {
					for (int i = 0; i < row; i++) {
						for (int j = 0; j < column; j++) {
							if (findmoto[i][j]) {
								drawCard(i, j, moto[i][j], true);
							}
						}
					}
					drawCard(lastY, lastX, moto[lastY][lastX], true);
					sure = false;
				}
				switch (e)
				{
					case KB_ARROW_UP:
						drawCard(lastY, lastX, moto[lastY][lastX], true);
						if (--y < 0) {
							y = row - 1;
						}
						lastY = y;
						drawCard(y, x, moto[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
						break;
					case KB_ARROW_DOWN:
						drawCard(lastY, lastX, moto[lastY][lastX], true);
						if (++y >= row) {
							y = 0;
						}
						lastY = y;
						drawCard(y, x, moto[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
						break;
					case KB_ARROW_LEFT:
						drawCard(lastY, lastX, moto[lastY][lastX], true);
						if (--x < 0) {
							x = column - 1;
						}
						lastX = x;
						drawCard(y, x, moto[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
						break;
					case KB_ARROW_RIGHT:
						drawCard(lastY, lastX, moto[lastY][lastX], true);
						if (++x >= column) {
							x = 0;
						}
						lastX = x;
						drawCard(y, x, moto[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
						break;
					default:
						break;
				}
			}
		}
		cct_setcolor();
		setbottonCur();
		end(column);
		cct_setconsoleborder(a, b);
	}
	if (sign == '9') {
		int a, b, c, d, e;
		int score_total = 0;
		cct_getconsoleborder(a, b, c, d);
		cct_setcolor();
		cct_cls();
		getGraphSizeInfo(row, column, true, c, d);
		d += 5;
		cct_setconsoleborder(c, d + 5);
		cct_gotoxy(0, 0);
		cout << "��Ļ��ǰ����Ϊ��" << c << "��" << d << "��";
		drawborder(row, column, true);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				drawCard(i, j, moto[i][j], true);
				Sleep(30);
			}
		}
		int x, y, lastX, lastY;
		x = y = lastX = lastY = 0;
		int sure = false;
		bool enter = false;
		drawCard(y, x, moto[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
		while (true) {
			if (cct_read_keyboard_and_mouse(c, c, c, d, e) == CCT_KEYBOARD_EVENT) {
				setbottonCur();
				cct_setcolor();
				cout << "��ͷ���ƶ����س���ѡ��                                                  ";
				if (d == 13)
				{
					if (!judge_adjoin(moto, row, column, y, x)) {

						setbottonCur();
						cct_setcolor(0, COLOR_HYELLOW);
						cout << "��Χ����ֵͬ";
						cct_setcolor();
						cout << "��ͷ���ƶ����س���ѡ��";
					}
					else {
						if (!sure) {
							for (int i = 0; i < row; i++)
							{
								for (int j = 0; j < column; j++)
								{
									findmoto[i][j] = 0;
								}
							}
							find_res_rec(moto, row, column, findmoto, y, x, moto[y][x]);
						}
						else  //���ٴΰ��»س���ʱ,ȷ��Ҫ�ϲ�ʱ
						{
							if (!enter) {
								sure = 3;
								int res = moto[y][x];
								int merge_sum = merge_res(moto, row, column, findmoto, y, x);
								int score_cur = score(res, merge_sum);
								score_total += score_cur;
								cct_setcolor(); cct_gotoxy(0, 0);
								cout << "���ε÷֣�" << score_cur << " �ܵ÷֣�" << score_total << " �ϳ�Ŀ�꣺" << target << "     ";
							}
							for (int i = 0; i < row; i++) {
								for (int j = 0; j < column; j++) {
									if (findmoto[i][j]) {
										drawCard(i, j, moto[i][j], true, COLOR_HWHITE, COLOR_HWHITE);//Ϳ��
									}
								}
							}
							enter = true;

							//��˸
							for (int i = 0; i < 5; i++) {
								drawCard(y, x, moto[y][x], true, COLOR_HYELLOW, COLOR_HRED);
								Sleep(100);
								drawCard(y, x, moto[y][x], true);
								Sleep(100);
							}

							findmoto[y][x] = 0;
							downAnime(moto, findmoto, row, column);
							down_arr(moto, row, column);

							int max = find_max(moto, row, column);
							for (int i = 0; i < row; i++)
							{
								for (int j = 0; j < column; j++)
								{
									if (moto[i][j] == 0) {
										Sleep(200);
										moto[i][j] = random(max);
										drawCard(i, j, moto[i][j], true);    //�����ֵ
									}
								}
							}
							for (int i = 0; i < row; i++)
							{
								for (int j = 0; j < column; j++)
								{
									findmoto[i][j] = 0;
								}
							}
							if (find_max(moto, row, column) >= target)
							{
								setbottonCur();
								cct_setcolor(0, COLOR_HYELLOW);

								cout << "�Ѿ��ϳɵ�" << target;
								cct_setcolor();
								cout << "���س������������Ŀ�����...     ";

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
							setbottonCur();
							cct_setcolor();
							cout << "��ͷ���ƶ����س���ѡ��                    ";
							sure = 2;

						}

						for (int i = 0; i < row; i++) {
							for (int j = 0; j < column; j++) {
								if (findmoto[i][j]) {
									drawCard(i, j, moto[i][j], true, COLOR_HYELLOW, COLOR_CYAN);

								}
							}
						}
						if (sure != 2)drawCard(y, x, moto[y][x], true, COLOR_HYELLOW, COLOR_HRED);
						else drawCard(y, x, moto[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
						sure = true;
					}

				}
				if (sure && d != 13) {
					for (int i = 0; i < row; i++) {
						for (int j = 0; j < column; j++) {
							if (findmoto[i][j]) {
								drawCard(i, j, moto[i][j], true);
							}
						}
					}
					drawCard(lastY, lastX, moto[lastY][lastX], true);
					sure = false;
				}


				switch (e)
				{
					case KB_ARROW_UP:
						enter = false;
						drawCard(lastY, lastX, moto[lastY][lastX], true);
						if (--y < 0) {
							y = row - 1;
						}
						lastY = y;
						drawCard(y, x, moto[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
						break;
					case KB_ARROW_DOWN:
						enter = false;
						drawCard(lastY, lastX, moto[lastY][lastX], true);
						if (++y >= row) {
							y = 0;
						}
						lastY = y;
						drawCard(y, x, moto[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
						break;
					case KB_ARROW_LEFT:
						enter = false;
						drawCard(lastY, lastX, moto[lastY][lastX], true);
						if (--x < 0) {
							x = column - 1;
						}
						lastX = x;
						drawCard(y, x, moto[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
						break;
					case KB_ARROW_RIGHT:
						enter = false;
						drawCard(lastY, lastX, moto[lastY][lastX], true);
						if (++x >= column) {
							x = 0;
						}
						lastX = x;
						drawCard(y, x, moto[y][x], true, COLOR_HYELLOW, COLOR_CYAN);
						break;
					default:
						break;
				}
			}
		}
		cct_setcolor();
		setbottonCur();
		end(column);
		cct_setconsoleborder(a, b);
	}
}

void drawborder(int row, int column, bool haveBorder)
{
	int temp = row;
	row = column;
	column = temp;
	cct_gotoxy(0, 1);
	//width hight��ָ�������еĿ��
	int width = (haveBorder) ? row * 2 * 3 + (row - 1) * 2 :
		row * 2 * 3;
	int hight = (haveBorder) ? column * 3 + (column - 1) : column * 3;
	setbottonCur(true, haveBorder ? hight + 3 : hight + 2); //����
	int unicode_rowLength = (width + 4) / 2;
	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
	cout << "�X";
	for (int i = 0; i < unicode_rowLength - 2; i++) {
		cout << "�T";
		Sleep(30);
	}
	cout << "�[";
	for (int i = 0; i < hight + 1; i++) {
		cct_gotoxy(0, i + 2); cout << "�U";
		cct_gotoxy(width + 2, i + 2); cout << "�U";
		Sleep(30);
	}
	cct_gotoxy(0, hight + 2);
	cout << "�^";
	for (int i = 0; i < unicode_rowLength - 2; i++) {
		cout << "�T";
		Sleep(30);
	}
	cout << "�a";
	if (haveBorder) {
		for (int i = 0; i < column - 1; i++) {

			cct_gotoxy(2, i * 4 + 5);
			cout << "\b\b�c";
			for (int j = 0; j < width / 2; j++) {
				cout << "��";
				Sleep(5);
			}
			cout << "�f";
		}
		int j = 0;
		for (int i = 0; i < row - 1; i++) {
			cct_gotoxy(2 * 4 + i * 8, 1);
			cout << "�h";
			for (j = 0; j < hight; j++) {
				cct_gotoxy(2 * 4 + i * 8, 2 + j);
				cout << "��";
				if (!((j + 1) % 4)) {
					cout << "\b\b��";
					Sleep(30);
				}
			}
			cct_gotoxy(2 * 4 + i * 8, 2 + j);
			cout << "�k";
		}
	}
}

void drawCard(int card_y, int card_x, int value, bool haveBorder, int bgcolor, int fgcolor)
{
	int x = (haveBorder) ? 2 + card_x * 6 + card_x * 2 : 2 + card_x * 6;
	int y = (haveBorder) ? 2 + card_y * 3 + card_y : 2 + card_y * 3;
	if (bgcolor != -1)cct_setcolor(bgcolor, fgcolor);
	else cct_setcolor(value);
	cct_gotoxy(x, y);
	cout << "�X�T�[";
	cct_gotoxy(x, y + 1);
	if (value < 10) {
		cout << "�U " << value << "�U";
	}
	else {
		cout << "�U" << value << "�U";
	}
	cct_gotoxy(x, y + 2);
	cout << "�^�T�a";
}

void setbottonCur(bool set, int value)
{
	static int pox_Y = 0;
	if (set)
	{
		pox_Y = value;
	}
	else
		cct_gotoxy(0, pox_Y);
}
void getGraphSizeInfo(int row, int column, bool haveBorder, int& width, int& heigh)
{
	int temp = row;
	row = column;
	column = temp;
	width = (haveBorder) ? row * 2 * 3 + (row + 1) * 2 :
		row * 2 * 3;
	heigh = (haveBorder) ? column * 3 + (column) : column * 3;
}
void dropCardSmooth(int card_x, int card_y, int value)
{
	int x = 2 + card_x * 6 + card_x * 2;
	int y = 2 + card_y * 3 + card_y;
	int i;
	for (i = 1; i < 5; i++) 
	{
		y++;
		cct_gotoxy(x, y - 1);
		cct_setcolor(15, 0);
		cout << "      ";
		cct_gotoxy(x, y);
		cct_setcolor(value);
		cout << "�X�T�[";
		cct_gotoxy(x, y + 1);
		if (value < 10) 
		{
			cout << "�U " << value << "�U";
		}
		else 
		{
			cout << "�U" << value << "�U";
		}
		cct_gotoxy(x, y + 2);
		cout << "�^�T�a";
		Sleep(40);
	}
	cct_setcolor(15, 0);
	cct_gotoxy(x, y - 1);
	cct_setcolor(15, 0);
	cout << "������";
	//cct_showstr(x, y + 2 + i, "������", 15,0); //�������»���
}
void downAnime(int moto[][10], int findmoto[][10], int row, int column)
{
	//����ɨ��
	int width = row;
	int hight = column;
	for (int j = 0; j < column; j++) 
	{ //��һ��ɨ��
		for (int i = row - 1; i >= 0; i--) 
		{//�����һ�п�ʼɨ��
			if (findmoto[i][j]) 
			{
				int num = 0; //��϶������
				int k;
				for (k = i; k >= 0; --k) 
				{
					if (!findmoto[k][j])break;  //���������ռ��
					if (k == 0) 
					{
						num = 0; break;
					}
					num++;
				}
				if (num) 
				{
					findmoto[k][j] = 1;
					findmoto[i][j] = 0;
				}
				for (int a = 0; a < num; a++) 
				{
					dropCardSmooth(j, k + a, moto[k][j]);
				}
			}
		}
	}
}