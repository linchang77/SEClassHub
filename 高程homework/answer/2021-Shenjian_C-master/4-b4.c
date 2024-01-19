/*1953609 ��� ���͢*/
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
			char ch    ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/
int menu()
{
	printf("1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)\n");
	printf("2.��I��J��K��L��������������(��Сд���ɣ��߽����)\n");
	printf("3.�ü�ͷ�������������ң��߽�ֹͣ\n");
	printf("4.�ü�ͷ�������������ң��߽����\n");
	printf("5.��I��J��K��L��������������(�����ͷ���������ƶ�����Сд���ɣ��߽�ֹͣ\n");
	printf("6.��I��J��K��L��������������(�����ͷ���������ƶ�����Сд���ɣ��߽�ֹͣ\n");
	printf("0.�˳�\n[��ѡ��0-6] ");
	//��ѭ���У���ֻ���ijkl��ASCII�룬������224�������⴦��
    //�������224+75���ں���224�Ժ󱻵���K����
	int input;
	while (1)
	{
		input = _getch();
		if (input <= '6' && input >= '0')
			break;
	}
	return input;
}
void move_by_ijkl(int u, int d, int l, int r, int tag_huirao, int five_six)
{
	int input;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	srand((unsigned int)(time(0)));
	init_border(hout);
	int x = 35, y = 9;
	gotoxy(hout, x, y);
	while (1)
	{
		input = _getch();
		if (five_six == 1)
			if (input == 224)
				_getch();
		if (tag_huirao == 0)
		{
			if (input == u || input == u - 32)
			{
				if (y == 1)
					y = 2;
				gotoxy(hout, x, --y);
			}
			if (input == d || input == d - 32)
			{
				if (y == 17)
					y = 16;
				gotoxy(hout, x, ++y);
			}
			if (input == l || input == l - 32)
			{
				if (x == 1)
					x = 2;
				gotoxy(hout, --x, y);
			}
			if (input == r || input == r - 32)
			{
				if (x == 69)
					x = 68;
				gotoxy(hout, ++x, y);
			}
		}
		else
		{
			if (input == u || input == u - 32)
			{
				if (y == 1)
					y = 18;
				gotoxy(hout, x, --y);
			}
			if (input == d || input == d - 32)
			{
				if (y == 17)
					y = 0;
				gotoxy(hout, x, ++y);
			}
			if (input == l || input == l - 32)
			{
				if (x == 1)
					x = 70;
				gotoxy(hout, --x, y);
			}
			if (input == r || input == r - 32)
			{
				if (x == 69)
					x = 0;
				gotoxy(hout, ++x, y);
			}
		}
		if (input == ' ')
			printf(" \b");
		if (input == 'q' || input == 'q' - 32)
		{
			gotoxy(hout, 0, 23);
			printf("��Ϸ���������س������ز˵�.\n");
			while (1)
			{
				input = _getch();
				if (input == 13)
				{
					cls(hout);
					gotoxy(hout, 0, 0);
					return;
				}
			}
		}
	}
}
void move_by_arrow(int u, int d, int l, int r, int tag_huirao)
{
	//��ѭ���У���ֻ���ijkl��ASCII�룬������224�������⴦��
    //�������224+75���ں���224�Ժ󱻵���K����
	int input;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	srand((unsigned int)(time(0)));
	init_border(hout);
	int x = 35, y = 9;
	gotoxy(hout, x, y);
	while (1)
	{
		input = _getch();
		if (input == 224)
		{
			input = _getch();
			if (tag_huirao == 0)
			{
				if (input == u || input == u - 32)
				{
					if (y == 1)
						y = 2;
					gotoxy(hout, x, --y);
				}
				if (input == d || input == d - 32)
				{
					if (y == 17)
						y = 16;
					gotoxy(hout, x, ++y);
				}
				if (input == l || input == l - 32)
				{
					if (x == 1)
						x = 2;
					gotoxy(hout, --x, y);
				}
				if (input == r || input == r - 32)
				{
					if (x == 69)
						x = 68;
					gotoxy(hout, ++x, y);
				}
			}
			else
			{
				if (input == u || input == u - 32)
				{
					if (y == 1)
						y = 18;
					gotoxy(hout, x, --y);
				}
				if (input == d || input == d - 32)
				{
					if (y == 17)
						y = 0;
					gotoxy(hout, x, ++y);
				}
				if (input == l || input == l - 32)
				{
					if (x == 1)
						x = 70;
					gotoxy(hout, --x, y);
				}
				if (input == r || input == r - 32)
				{
					if (x == 69)
						x = 0;
					gotoxy(hout, ++x, y);
				}
			}
		}
		if (input == ' ')
			printf(" \b");
		if (input == 'q' || input == 'q' - 32)
		{
			gotoxy(hout, 0, 23);
			printf("��Ϸ���������س������ز˵�.\n");
			while (1)
			{
				input = _getch();
				if (input == 13)
				{
					cls(hout);
					gotoxy(hout, 0, 0);
					return;
				}
			}
		}
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	int input;
	while (1)
	{
		input = menu();
		switch (input)
		{
			case '0':
				return 0;
				break;
			case '1':
				move_by_ijkl('i', 'k', 'j', 'l', 0, 0);
				break;
			case '2':
				move_by_ijkl('i', 'k', 'j', 'l', 1, 0);
				break;
			case  '3':
				move_by_arrow(72, 80, 75, 77, 0);
				break;
			case '4':
				move_by_arrow(72, 80, 75, 77, 1);
				break;
			case '5':
				move_by_ijkl('i', 'k', 'j', 'l', 0, 1);
				break;
			case '6':
				move_by_ijkl('i', 'k', 'j', 'l', 1, 1);
				break;
			default:
				break;
		}
	}
	return 0;
}
//const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
//srand((unsigned int)(time(0)));

/* �˾�������ǵ���ϵͳ��cls�������� */
//cls(hout);

/* ��ʾ��ʼ�ı߿����е�����ַ� */
//init_border(hout);

//��ͣ
//getchar();

//gotoxy(hout, 0, 23);
//printf("��Ϸ���������س����˳�.\n");

//��ͣ(�˴���ҵҪ����ֻ�ܰ��س��˳���Ŀǰ��getcharʾ���������������+�س��˳�������������������Ļ��)
//getchar();
