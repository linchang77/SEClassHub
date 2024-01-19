/*2250420 �� �¾�*/
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

/***************************************************************************
  �������ƣ�memu
  ��    ��:��ʾ�˵�
  �����������
  �� �� ֵ��int
  ˵    ������
***************************************************************************/
int menu(const HANDLE hout)
{
	char a;
	cls(hout);//��ʾ�˵���ʱ��Ҫ������
	printf("1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)\n");
	printf("2.��I��J��K��L��������������(��Сд���ɣ��߽����)\n");
	printf("3.�ü�ͷ�������������ң��߽�ֹͣ\n");
	printf("4.�ü�ͷ�������������ң��߽����\n");
	printf("5.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ,������������ƶ�)\n");
	printf("6.��I��J��K��L��������������(��Сд���ɣ��߽���ƣ�������������ƶ�)\n");
	printf("0.�˳�\n");
	printf("[��ѡ��0-6]\n"); 
	while (1)
	{
		a = _getch();
		if (a >= '0' && a <= '6')
			break;
	}
	return a;
}
/************************************************
    �������ܺ���
************************************************/ 	 
void func1(HANDLE hout);
void func2(HANDLE hout);
void func3(HANDLE hout);
void func4(HANDLE hout);
void func5(HANDLE hout);
void func6(HANDLE hout);
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
    srand((unsigned int)(time(0)));/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
    while (1)
    {
        switch (menu(hout) - 48)//���ڷ���ֵΪchar����ת��ɵ�intҪ��ȥ48
	    {
	    case 1:
           	func1(hout);
	        break;
        case 2:
	        func2(hout);
	        break;
        case 3:
		    func3(hout);
		    break;
        case 4:
		    func4(hout);
		    break;
        case 5:
	        func5(hout);
        	break;
        case 6:
	        func6(hout);
	        break;
        case 0:exit(1);
	    }
    }
return 0;
}
void func1(HANDLE hout)
{
	cls(hout);//������
	init_border(hout);/* ��ʾ��ʼ�ı߿����е�����ַ� */
	int x = 35;//��ʼ�����
	int y = 9;
	gotoxy(hout, x, y);//�ù�����м�
	while (1)
	{

		char ch = _getch();//��ȡ��������  
		if (ch == 'i' || ch == 'I') //��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" 
		{
			//�ж�Խ��
			if (y <= 1)
				continue;
			y = y - 1;
			gotoxy(hout, x, y);//�ƶ����
		}
		if (ch == 'j' || ch == 'J') //��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" 
		{
			if (x <= 1)//�ж�Խ��
				continue;
			x--;
			gotoxy(hout, x, y);//�ƶ����
		}
		if (ch == 'k' || ch == 'K') //��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" 
		{
			if (y >= MAX_Y)//�ж�Խ��
				continue;
			y = y + 1;
			gotoxy(hout, x, y);//�ƶ����
		}
		if (ch == 'l' || ch == 'L') //��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" 
		{
			if (x >= MAX_X)
				continue;//�ж�Խ��
			x++;
			gotoxy(hout, x, y);//�ƶ����
		}
		if (ch == ' ')
		{
			putchar(' ');
			gotoxy(hout, x, y);
		}
		if (ch == 'q' || ch == 'Q')
		{
			gotoxy(hout, 0, 23);
			printf("��Ϸ�������س������ز˵�");
			while (1)
			{
				char a = _getch();
				if (a == '\r')
					break;
			}
			break;
		}
	}
}
void func2(HANDLE hout)
{
	cls(hout);//������
	init_border(hout);/* ��ʾ��ʼ�ı߿����е�����ַ� */
	int x = 35;//��ʼ�����
	int y = 9;
	gotoxy(hout, x, y);//�ù�����м�
	while (1)
	{

		char ch = _getch();//��ȡ��������  
		if (ch == 'i' || ch == 'I') //��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" 
		{
			//�ж�Խ��
			if (y <= 1)
				y = MAX_Y;
			else
				y--;
			gotoxy(hout, x, y);//�ƶ����
		}
		if (ch == 'j' || ch == 'J') //��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" 
		{
			if (x <= 1)//�ж�Խ��
				x = MAX_X;
			else
				x--;
			gotoxy(hout, x, y);//�ƶ����
		}
		if (ch == 'k' || ch == 'K') //��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" 
		{
			if (y >= MAX_Y)//�ж�Խ��
				y = 1;
			else
				y++;
			gotoxy(hout, x, y);//�ƶ����
		}
		if (ch == 'l' || ch == 'L') //��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" 
		{
			if (x >= MAX_X)
				x = 1;
			else
				x++;
			gotoxy(hout, x, y);//�ƶ����
		}
		if (ch == ' ')
		{
			putchar(' ');
			gotoxy(hout, x, y);
		}
		if (ch == 'q' || ch == 'Q')
		{
			gotoxy(hout, 0, 23);
			printf("��Ϸ�������س������ز˵�");
			while (1)
			{
				char a = _getch();
				if (a == '\r')
					break;
			}
			break;
		}

	}
}
void func3(HANDLE hout)
{
	cls(hout);//������
	init_border(hout);/* ��ʾ��ʼ�ı߿����е�����ַ� */
	int x = 35;//��ʼ�����
	int y = 9;
	gotoxy(hout, x, y);//�ù�����м�
	while (1)
	{

		int ch = _getch();//��ȡ��������  
		if (ch == ' ')
		{
			putchar(' ');
			gotoxy(hout, x, y);
			continue;
		}
		if (ch == 'q' || ch == 'Q')
		{
			gotoxy(hout, 0, 23);
	    	printf("��Ϸ�������س������ز˵�");
			while (1)
			{
				char a = _getch();
				if (a == '\r')
					break;
			}
			break;
		}
		if (ch != 224)
			continue;
		int ch1 = _getch();
		if (ch == 224 && ch1 == 72)
		{
			//�ж�Խ��
			if (y <= 1)
				continue;
			y = y - 1;
			gotoxy(hout, x, y);//�ƶ����
		}
		if (ch == 224 && ch1 == 75) //��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" 
		{
			if (x <= 1)//�ж�Խ��
				continue;
			x--;
			gotoxy(hout, x, y);//�ƶ����
		}
		if (ch == 224 && ch1 == 80) //��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" 
		{
			if (y >= MAX_Y)//�ж�Խ��
				continue;
			y = y + 1;
			gotoxy(hout, x, y);//�ƶ����
		}
		if (ch == 224 && ch1 == 77) //��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" 
		{
			if (x >= MAX_X)
				continue;//�ж�Խ��
			x++;
			gotoxy(hout, x, y);//�ƶ����
		}
	}
}
void func4(HANDLE hout)
{
	cls(hout);//������
	init_border(hout);/* ��ʾ��ʼ�ı߿����е�����ַ� */
	int x = 35;//��ʼ�����
	int y = 9;
	gotoxy(hout, x, y);//�ù�����м�
	while (1)
	{
		int ch = _getch();//��ȡ��������   
		if (ch == ' ')
		{
			putchar(' ');
			gotoxy(hout, x, y);
			continue;
		}
		if (ch == 'q' || ch == 'Q')
		{
			gotoxy(hout, 0, 23);
			printf("��Ϸ�������س������ز˵�");
			while (1)
			{
				char a = _getch();
				if (a == '\r')
					break;
			}
			break;
		}
		if (ch != 224)
			continue;
		int ch1 = _getch();
		if (ch == 224 && ch1 == 72) //��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" 
		{
			//�ж�Խ��
			if (y <= 1)
				y = MAX_Y;
			else
				y--;
			gotoxy(hout, x, y);//�ƶ����
		}
		if (ch == 224 && ch1 == 75) //��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" 
		{
			if (x <= 1)//�ж�Խ��
				x = MAX_X;
			else
				x--;
			gotoxy(hout, x, y);//�ƶ����
		}
		if (ch == 224 && ch1 == 80) //��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" 
		{
			if (y >= MAX_Y)//�ж�Խ��
				y = 1;
			else
				y++;
			gotoxy(hout, x, y);//�ƶ����
		}
		if (ch == 224 && ch1 == 77) //��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" 
		{
			if (x >= MAX_X)
				x = 1;
			else
				x++;
			gotoxy(hout, x, y);//�ƶ����
		}
	}
}
void func5(HANDLE hout)
{
	cls(hout);//������
	init_border(hout);/* ��ʾ��ʼ�ı߿����е�����ַ� */
	int x = 35;//��ʼ�����
	int y = 9;
	gotoxy(hout, x, y);//�ù�����м�
	while (1)
	{
		int ch = _getch();//��ȡ��������  
		if (ch == 224)
		{
			int ch1 = _getch();
			continue;
		}
		if (ch == 'i' || ch == 'I') //��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" 
		{
			//�ж�Խ��
			if (y <= 1)
				continue;
			y = y - 1;
			gotoxy(hout, x, y);//�ƶ����
		}
		if (ch == 'j' || ch == 'J') //��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" 
		{
			if (x <= 1)//�ж�Խ��
				continue;
			x--;
			gotoxy(hout, x, y);//�ƶ����
		}
		if (ch == 'k' || ch == 'K') //��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" 
		{
			if (y >= MAX_Y)//�ж�Խ��
				continue;
			y = y + 1;
			gotoxy(hout, x, y);//�ƶ����
		}
		if (ch == 'l' || ch == 'L') //��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" 
		{
			if (x >= MAX_X)
				continue;//�ж�Խ��
			x++;
			gotoxy(hout, x, y);//�ƶ����
		}
		if (ch == ' ')
		{
			putchar(' ');
			gotoxy(hout, x, y);
		}
		if (ch == 'q' || ch == 'Q')
		{
			gotoxy(hout, 0, 23);
			printf("��Ϸ�������س������ز˵�");
			while (1)
			{
				char a = _getch();
				if (a == '\r')
					break;
			}
			break;
		}
	}
}
void func6(HANDLE hout)
{
	cls(hout);//������
	init_border(hout);/* ��ʾ��ʼ�ı߿����е�����ַ� */
	int x = 35;//��ʼ�����
	int y = 9;
	gotoxy(hout, x, y);//�ù�����м�
	while (1)
	{

		int ch = _getch();//��ȡ��������  
		if (ch == 224)
		{
			int ch1 = _getch();
			continue;
		}
		if (ch == 'i' || ch == 'I') //��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" 
		{
			//�ж�Խ��
			if (y <= 1)
				y = MAX_Y;
			else
				y--;
			gotoxy(hout, x, y);//�ƶ����
		}
		if (ch == 'j' || ch == 'J') //��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" 
		{
			if (x <= 1)//�ж�Խ��
				x = MAX_X;
			else
				x--;
			gotoxy(hout, x, y);//�ƶ����
		}
		if (ch == 'k' || ch == 'K') //��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" 
		{
			if (y >= MAX_Y)//�ж�Խ��
				y = 1;
			else
				y++;
			gotoxy(hout, x, y);//�ƶ����
		}
		if (ch == 'l' || ch == 'L') //��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" 
		{
			if (x >= MAX_X )
				x = 1;
			else
				x++;
			gotoxy(hout, x, y);//�ƶ����
		}
		if (ch == ' ')
		{
			putchar(' ');
			gotoxy(hout, x, y);
		}
		if (ch == 'q' || ch == 'Q')
		{
			gotoxy(hout, 0, 23);
			printf("��Ϸ�������س������ز˵�");
			while (1)
			{
				char a = _getch();
				if (a == '\r')
					break;
			}
			break;
		}

	}
}












