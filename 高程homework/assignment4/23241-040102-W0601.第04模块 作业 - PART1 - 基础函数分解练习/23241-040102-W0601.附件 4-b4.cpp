/* ѧ�� ���� �༶ */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)//��q֮������Ȼ���ٵ�menu 
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
  ���������HANDLE hout ������豸���
            int X       ��ָ��λ�õ�x����
            int Y       ��ָ��λ�õ�y����
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
  ���������HANDLE hout ������豸���
            int X       ��ָ��λ�õ�x����
            int Y       ��ָ��λ�õ�y����
            char ch     ��Ҫ��ӡ���ַ�
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
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/

/***************************************************************************
  �������ƣ�memu
  ��    ��:��ʾ�˵� 
  ����������� 
  �� �� ֵ��int 
  ˵    ������ 
***************************************************************************/
int menu()
{
	cout<<"1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)"<<endl;
	cout<<"2.��I��J��K��L��������������(��Сд���ɣ��߽����)"<<endl;
	cout<<"3.�ü�ͷ�������������ң��߽�ֹͣ"<<endl;
	cout<<"4.�ü�ͷ�������������ң��߽����"<<endl;
	cout<<"5.�ü�ͷ��������������(�߽�ֹͣ����ʾ��дHPKM���ƶ��Ĵ��󣬴����Ҫʵ��)"<<endl;
	cout<<"6.�ü�ͷ��������������(�߽���ƣ���ʾ��дHPKM���ƶ��Ĵ��󣬴����Ҫʵ��)"<<endl;
	cout<<"0.�˳�"<<endl;
	cout<<"[��ѡ��0-6]";
	int a;
	cin >>a;
	return a;
 } 
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand((unsigned int)(time(0)));

	/* �˾�������ǵ���ϵͳ��cls�������� */
	cls(hout);

	/* ��ʾ��ʼ�ı߿����е�����ַ� */
	init_border(hout);

	//��ͣ
	getchar();

	gotoxy(hout, 0, 23);
	cout << "��Ϸ���������س����˳�." << endl;

	//��ͣ(�˴���ҵҪ����ֻ�ܰ��س��˳���Ŀǰ��getcharʾ���������������+�س��˳�������������������Ļ��)
	getchar();

	return 0;
}
