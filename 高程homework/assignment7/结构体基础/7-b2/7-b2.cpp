/* 2250420 �¾� �� */
#define _CRT_SECURE_NO_WARNINGS		//ʹ����VS��Ϊunsafe�ĺ���
#include <iostream>
#include <iomanip>
#include<Windows.h>
#include<conio.h>
#include<string.h>
using namespace std;
struct KFC
{
	char tag;
	char name[100];
	float prize;
};
struct SPECIAL
{
	char tags[100];
	char name[100];
	float prize;
};
void cct_cls(void)
{
	static const HANDLE __hout = GetStdHandle(STD_OUTPUT_HANDLE);		//ȡ��׼����豸��Ӧ�ľ��
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(__hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(__hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(__hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(__hout, coord);
	return;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�����˵�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void putoutmenu(const struct KFC list[], const struct SPECIAL special[])
{
	cout << "=========================================================================" << endl;
	for (int i = 0; list[i].tag != '\0'; i++)
	{
		cout << " "<< list[i].tag << " " << setw(26) << setiosflags(ios::left)<<list[i].name << setw(7) << list[i].prize;
		if (i % 2 == 0)
			cout << "|  ";
		else
			cout << endl;
	}
	cout << endl << "���Ż���Ϣ����" << endl;
	for (int j = 0; special[j].tags[0] != '\0'; j++)
	{
		cout << special[j].name << "=";
		for (int i = 0; special[j].tags[i] != '\0'; i++)
		{
			if (i > 0)
				cout << "+";
			int num = 1;
			while (list[special[j].tags[i] - 'A'].tag == list[special[j].tags[i+1] - 'A'].tag)
			{
				i++;
				num++;
			}
			if (num == 1)
				cout << list[special[j].tags[i] - 'A'].name;
			else
				cout << list[special[j].tags[i] - 'A'].name << "*" << num;
		}
		cout << endl;
	}
	cout << endl;
	cout<< "���������˵������" << endl;
	cout << "ANV=�������ȱ�+����(С)+���¿���(С) / akaak=�������ȱ�*3+��������*2" << endl;
	cout << "��ĸ���ִ�Сд������˳�򣬵�������0���˳�����" << endl;
	cout << endl<<"��㵥��";
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ����Ǯ
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int check(char order[], const struct KFC list[], const struct SPECIAL special[])
{
	for (int i = 0; special[i].tags[0] != '\0'; i++)
	{
		int tag = 1;
		for (int j = 0; j <= strlen(order)&& j <= strlen(special[i].tags); j++)
			if (order[j]!=special[i].tags[j])
				tag=0;
		if(tag==1)
		    return i;
	}
	return -1;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ����Ǯ
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
float getprize(char order[], const struct KFC list[], const struct SPECIAL special[])
{
	int num = check(order, list, special);
	float sum = 0;
	if(num!=-1)
	{
		sum=special[num].prize;
	}
	else
	{
		for (int i = 0; order[i] != '\0'; i++)
		{
			sum+=list[order[i] - 'A'].prize;
		}
	}
	return sum;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�����������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void sort(char order[])
{
	for(int i=0;order[i]!='\0';i++)
		for (int j = strlen(order) - 1; j > i; j--)
		{
			if (order[j] < order[j - 1])
			{
				char temp = order[j];
				order[j] = order[j - 1];
				order[j - 1] = temp;
			}
		}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ���ȡ����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void getorder(char order[])
{
	int i = 0;
	while (1)
	{
		char ch = getchar();
		if (ch == '\n')
		{
			order[i] = '\0';
			break;
		}
		else
		{
			if (ch > 'a')
				ch -= 32;
			order[i] = ch;
			i++;
		}
	}
	sort(order);//����������
}
int main()
{
	const struct KFC list[] = {
	{'A', "�������ȱ�",			19.5},
	{'B', "���༦�ȱ�",			19.5},
	{'C', "�°¶��������ȱ�",		20.0},
	{'D', "�ϱ��������",			18.5},
	{'E', "�ƽ�SPA���ű�(�ٽ���ζ)",	18.0},
	{'F', "������ʽ��ζ��ţ��(����)",	18.0},
	{'G', "˱ָԭζ��(1��)",		12.5},
	{'H', "�ƽ��Ƥ��",			13.5},
	{'I', "�°¶�������(2��)",		13.5},
	{'J', "�������׻�",			12.0},
	{'K', "��������(2��)",			12.5},
	{'L', "������Ǽ�(3��)",		12.5},
	{'M', "֭֭������������ţ��",	55.0},
	{'N', "����(С)",				9.0},
	{'O', "����(��)",				12.5},
	{'P', "����(��)",				14.5},
	{'Q', "ܽ��������",			9.0},
	{'R', "ԭζ��Ͳ������",			6.0},
	{'S', "����������",			7.5},
	{'T', "�ƽ𼦿�",				12.5},
	{'U', "��ʽ��̢",				8.0},
	{'V', "���¿���(С)",			8.5},
	{'W', "���¿���(��)",			10.0},
	{'X', "���¿���(��)",			12.0},
	{'Y', "�����֭",				13.0},
	{'Z', "ѩ������",				14.5},
	{'\0', NULL,				0}
	};
	const struct SPECIAL special[] = {
	{"AOW", "OK������(�������ȱ�)",		31}, //�������Ҫ���ſ����ע�͵���һ�еġ�COW���Żݣ��۲��Żݲ˵��Ƿ����˱仯
	//	{"COW", "OK������(�°¶��������ȱ�)",	33.5}, //�������Ҫ���ſ����ע�͵���һ�еġ�AOW���Żݣ��۲��Żݲ˵��Ƿ����˱仯
		{"HHHHHKKKSUWWW", "����ȫ��Ͱ(��Ƥ��)",	101},
		{"APUY", "�����������ļ���(8��)",		44},
		{"GG","˱ָԭζ��(2��)",			21},
		{"", NULL, 0}
	};
	while (1)
	{
		putoutmenu(list, special);
		char order[100];
		getorder(order);
		cout << "��ĵ��=";
		for (int i = 0; order[i] != '\0'; i++)
		{
			if (i > 0)
				cout << "+";
			int num = 1;
			while (list[order[i] - 'A'].tag == list[order[i + 1] - 'A'].tag)
			{
				i++;
				num++;
			}
			if (num == 1)
				cout << list[order[i] - 'A'].name;
			else
				cout << list[order[i] - 'A'].name << "*" << num;
		}
		cout << endl;
		cout << "���ƣ�" << getprize(order,list,special) << "Ԫ" << endl;
		cout << "�㵥��ɣ������������." << endl;
		_getch();
		cct_cls();
	}
	
}