/* -----------------------------------------

     ���ļ�����Ҫ�ύ��������Ķ�

   ----------------------------------------- */
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
using namespace std;

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ��ʾ��Ϣ
  ���������
  �� �� ֵ��
  ˵    �����������������ʱ���ţ���ָ�������ѧϰ��ɺ����Ķ�
***************************************************************************/
static void to_be_continued(const char *prompt, const int X = 0, const int Y = 22)
{
	cct_setcolor(); //�ָ�ȱʡ��ɫ
	cct_gotoxy(X, Y);

	if (prompt)
		cout << prompt << "�����س�������...";
	else
		cout << "���س�������...";

	/* ���Գ��س�������������루ע�⣺_getch�Ļس���\r����getchar��\n��*/
	while (_getch() != '\r')
		;

	cct_cls();

	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����������������ʱ���ţ���ָ�������ѧϰ��ɺ����Ķ�
***************************************************************************/
static void display_border(const char *prompt, int &cols, int &lines, int &buffer_cols, int &buffer_lines)
{
	int i;

	/* ȡ���д��ڵĴ�С
	���ڵ�����  ����ʾ���ڵĴ�С
	�����������У��������Ĵ�С����������������ʱ������ֺ��������Ĺ����ˣ�*/
	cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);

	cout << prompt << endl;
	cout << "  ���ڵ���  ��" << lines << endl;
	cout << "  ���ڵ���  ��" << cols << endl;
	cout << "  ���������У�" << buffer_lines << endl;
	cout << "  ���������У�" << buffer_cols << endl;
	cout << endl;

	/* ��ӡ 01234567890123456789... */
	for (i = 0; i < buffer_cols; i++)
		cout << i % 10;

	/* ��ӡ 0         1         ... */
	for (i = 0; i < buffer_cols; i += 10) {
		if (i < 100)
			cout << i / 10 << "         "; //9���ո�
		else
			cout << i / 10 << "        "; //8���ո�
	}

	/* ǰ������ʾ9�У��ӵ�10�У����9����ʼ
	���������30�У�0-29�������һ������������״̬������ӡ(0-28) ���� */
	for (i = 9; i < buffer_lines; i++) {
		cout << endl << "# " << i;		//�ȴ�ӡ�س��ٴ�ӡ�кţ�Ŀ�ģ�1������������ݿ�һ�� 2�����һ�к��ܼӻس������������������ͻ����
		if (i == buffer_lines - 1) //���һ��
			cout << " (����ǻ���������-1)";
	}

	cct_gotoxy(0, 0);//���ص����������Ϸ����˾䲻��ʡ�ԣ�������ʾλ�ò���ȷ��
	/* ����й�������������ʾ */
	if (cols < buffer_cols || lines < buffer_lines) {
		cct_gotoxy(10, 13);
		cout << "�����϶����������鿴�кż��к�";
	}

	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ָ��λ�ã���ָ����ɫ����ʾһ���ַ����ɴ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	to_be_continued("cmd_console_tools��������ʾ��ʼ", 0, 0);




	

	if (1) {
		int X = 0, Y = 0;
		int ret, maction;
		int keycode1, keycode2;
		int loop = 1;

		cct_enable_mouse();

		/* ��ӡ��ʼ���λ��[0,0] */
		cct_setcursor(CURSOR_INVISIBLE);	//�رչ��
		cout << "����\"����\"�˵� - \"ѡ��\"��Ƭ�н������²�����" << endl;
		cout << "    ѡ��\"ʹ�þɰ����̨\"" << endl;
		cout << "    ȡ��\"���ٱ༭ģʽ\"" << endl;
		cout << "    ȡ��\"����ģʽ\"" << endl;
		cout << endl << endl;
		cout << "�ɲ��������/˫��,�Ҽ���/˫��,���Ҽ�ͬʱ�������֣������Ҽ�˫��/ESC����������" << endl;
		//		cout << "[��ǰ���λ��] X:0  Y:0"; //��ӡ��ʼ���λ��

		while (loop) {
			/* �����/���̣�����ֵΪ���������е�ĳһ��, ��ǰ���λ����<X,Y>�� */
			ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);

			if (ret == CCT_MOUSE_EVENT) {
				/* ת����7�н��д�ӡ */
				cct_gotoxy(0, 7);
				cout << "[��ǰ���λ��] X:" << setw(2) << X << " Y:" << setw(2) << Y << " ����:";

				switch (maction) {
					case MOUSE_ONLY_MOVED:
						cout << "�ƶ�          " << endl;
						//showch(X, Y, '*');����ӡ�κ�����
						break;
					case MOUSE_LEFT_BUTTON_CLICK:			//�������
						cout << "�������      " << endl;
						cct_showch(X, Y, '1');			//�����ָ��λ����ʾ1
						break;
					case MOUSE_LEFT_BUTTON_DOUBLE_CLICK:	//˫�����
						cout << "˫�����      " << endl;
						cct_showch(X, Y, '2');			//�����ָ��λ����ʾ2
						break;
					case MOUSE_RIGHT_BUTTON_CLICK:			//�����Ҽ�
						cout << "�����Ҽ�      " << endl;
						cct_showch(X, Y, '3');			//�����ָ��λ����ʾ3
						break;
					case MOUSE_RIGHT_BUTTON_DOUBLE_CLICK:	//˫���Ҽ�
						cout << "˫���Ҽ�      " << endl;
						cct_showch(X, Y, '4');			//�����ָ��λ����ʾ4
						loop = 0;
						break;
					case MOUSE_LEFTRIGHT_BUTTON_CLICK:		//ͬʱ�������Ҽ�
						cout << "ͬʱ�������Ҽ�" << endl;
						cct_showch(X, Y, '5');			//�����ָ��λ����ʾ5
						break;
					case MOUSE_WHEEL_CLICK:
						cout << "���¹���      " << endl;
						break;
					case MOUSE_WHEEL_MOVED_UP:
						cout << "���������ƶ�  " << endl;
						break;
					case MOUSE_WHEEL_MOVED_DOWN:
						cout << "���������ƶ�  " << endl;
						break;
					case MOUSE_NO_ACTION:
					default:
						cout << "��������" << endl;
						cct_showch(X, Y, '0');			//�����ָ��λ����ʾ0
						break;
				} //end of switch(maction)
			} //end of if (CCT_MOUSE_EVENT)
			else if (ret == CCT_KEYBOARD_EVENT) {
				/* ת����9�н��д�ӡ */
				cct_gotoxy(0, 9);
				cout << "[��ǰ����] : ";

				switch (keycode1) {
					case 27:	//ESC��
						loop = 0;
						cout << "ESC       ";
						break;
					case 32:	//SPACE��
						loop = 0;
						cout << "SPACE     ";
						break;
					case 224:
						switch (keycode2) {
							case KB_ARROW_UP:
								cout << "�ϼ�ͷ    ";
								break;
							case KB_ARROW_DOWN:
								cout << "�¼�ͷ    ";
								break;
							case KB_ARROW_LEFT:
								cout << "���ͷ    ";
								break;
							case KB_ARROW_RIGHT:
								cout << "�Ҽ�ͷ    ";
								break;
						}
						break;
					default:	//������ֱ�Ӵ�ӡASCIIֵ
						if (keycode2)
							cout << "Keycode=" << keycode1 << '/' << keycode2 << endl;
						else
							cout << "Keycode=" << keycode1 << endl;
						break;
				}//end of swicth(keycode1)
			}//end of else if(ret == CCT_KEYBOARD_EVENT��
		} //end of while(1)

		cct_disable_mouse();	//�������
		cct_setcursor(CURSOR_VISIBLE_NORMAL);	//�򿪹��
		to_be_continued("�����̲�����ʾ���");
	}

	if (1) {
		/* ��ʾ��ǰϵͳ�������Ϣ */
		cct_getfontinfo();
		to_be_continued("��ʾ��ǰ����������Ϣ���");

		/* ���������壬28���� */
		cct_setconsoleborder(60, 25);
		cct_setfontsize("������", 28); //Truetype����ֻ��Ҫ����һ�������߶ȼ���
		cout << "��������Ϊ������28" << endl << endl;
		cct_getfontinfo();
		/* ������һЩ���� */
		cout << "**************************" << endl;
		cout << "abcdefghijklmnopqrstuvwxyz" << endl;
		cout << "�����������" << endl;
		cout << "**************************" << endl;
		to_be_continued("����Ϊ������28���");//ȱʡ��22�д�ӡ��������ֻ��15�У������ڵ�10�д�ӡ

		/* ���������壬12���� */
		cct_setfontsize("������", 12);
		cout << "��������Ϊ������12" << endl << endl;
		cct_getfontinfo();
		/* ������һЩ���� */
		cout << "**************************" << endl;
		cout << "abcdefghijklmnopqrstuvwxyz" << endl;
		cout << "�����������" << endl;
		cout << "**************************" << endl;
		to_be_continued("����Ϊ������12���");//ȱʡ��22�д�ӡ��������ֻ��15�У������ڵ�10�д�ӡ

		/* �������壬1*1 */
		cct_cls();
		to_be_continued("Ԥ�棺��������1*1�ῴ����", 0, 0); //Ԥ����Ϣ
		/* ��������Ϊ 1*1 ��С*/
		cct_setfontsize("������", 1);

		/* ���ô��ڴ�С */
		int w = 600, h = 300;
		int i;

		cct_setconsoleborder(w, h);		//˵������Ļ��ʾ��߱ȴ�Լ2:1�����600*300��������

		/* ��һ�������Σ��������������Σ�ʵ�ʻ�����(10,10)-(590,290)�ĳ����Σ� */
		cct_setcolor(COLOR_HYELLOW, COLOR_HRED);
		for (i = 10; i < w - 10; i++) { //����������(10,10-590,10  /  10,290-590,290)
			cct_gotoxy(i, 10);
			cout << '*';
			cct_gotoxy(i, 290);
			cout << '*';
			Sleep(1);
		}
		for (i = 10; i < h - 10; i++) { //����������(10,10-290,10  /  590,10-590,290)
			cct_gotoxy(10, i);
			cout << '*';
			cct_gotoxy(590, i);
			cout << '*';
			Sleep(1);
		}

		/* �ٻ�һ��Բ */
		const int point_x = 300, point_y = 150, r = 100;
		int angle, x, y;
		const double pi = 3.14159;

		/* ��X�� */
		for (i = 30; i < w - 30; i++) {//X�����
			cct_gotoxy(i, point_y);
			cout << '*';
			Sleep(1);
		}
		for (i = 20; i > 0; i -= 2) { //X��ļ�ͷ
			cct_gotoxy(w - 30 - i, point_y - i / 2);
			cout << '*';
			cct_gotoxy(w - 30 - i, point_y + i / 2);
			cout << '*';
			Sleep(1);
		}

		/* ��Y�� */
		for (i = 30; i < h - 30; i++) {//Y�����
			cct_gotoxy(point_x, i);
			cout << '*';
			Sleep(1);
		}
		for (i = 10; i > 0; i --) { //Y��ļ�ͷ
			cct_gotoxy(point_x - i, 30 + i);
			cout << '*';
			cct_gotoxy(point_x + i, 30 + i);
			cout << '*';
			Sleep(1);
		}

		/* ��Բ */
		for (angle = 0; angle < 360; angle++) {//�Ƕȴ�0-360ѭ��
			x = int(r * cos(angle * pi / 180));
			y = -int(r * sin(angle * pi / 180)); //ȡ��������Ϊcmd���ڵ�������y���£�Ϊ���ֺ���ѧһֱ����һ��
			cct_gotoxy(point_x + x * 2, point_y + y); //x*2����Ϊ�����
			cout << '*';
			Sleep(1);
		}

		cct_setcolor(); //�ָ���ʼ��ɫ
		to_be_continued("����Ϊ����1*1���", 0, 295);

		/* ���õ���10*20 */
		cct_setfontsize("Terminal", 20, 10);
		cct_setconsoleborder(80, 25);
		cout << "��������Ϊ����10*20" << endl << endl;
		cct_getfontinfo();
		/* ������һЩ���� */
		cout << "**************************" << endl;
		cout << "abcdefghijklmnopqrstuvwxyz" << endl;
		cout << "�����������" << endl;
		cout << "**************************" << endl;
		to_be_continued("����Ϊ��������10*20���");

		/* ���õ���3*5 */
		cct_cls();
		to_be_continued("Ԥ�棺���õ���3*5�ῴ����", 0, 0); //Ԥ����Ϣ
		/* ��������Ϊ 3*5 ��С*/
		cct_setfontsize("Terminal", 5, 3);
		/* ���ô��ڴ�С */
		cct_setconsoleborder(200, 100);
		cout << "��������Ϊ����3*5" << endl << endl;
		cct_getfontinfo();
		/* ������һЩ���ݣ������ܿ��壩 */
		cout << "**************************" << endl;
		cout << "abcdefghijklmnopqrstuvwxyz" << endl;
		cout << "�����������" << endl;
		cout << "**************************" << endl;
		to_be_continued("����Ϊ��������3*5���");

		/* ��������Ϊ 8*16 ��С*/
		cct_setfontsize("Terminal", 16, 8);
		cct_setconsoleborder(120, 30, 120, 9001);
		cout << "��������Ϊ����8*16" << endl << endl;
		cct_getfontinfo();
		/* ������һЩ���� */
		cout << "**************************" << endl;
		cout << "abcdefghijklmnopqrstuvwxyz" << endl;
		cout << "�����������" << endl;
		cout << "**************************" << endl;
		to_be_continued("����仯��ʾ���");
	}

	return 0;
}
