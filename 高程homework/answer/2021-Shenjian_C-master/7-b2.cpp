/* 1953609 ��� ���͢ */
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;
struct KFC
{
	char type;
	char food[20];
	double price;
};

struct SPECIAL
{
	char type[20];
	char food[21];
	double price;
};
int main()
{
	const struct KFC list[] =
	{
	{'A', "�������ȱ�",         18},
	{'B', "���༦�ȱ�",         18},
	{'C', "�°¶��������ȱ�",   18.5},
	{'D', "�������������",   14.0},
	{'E', "�ϱ��������",       16.5},
	{'F', "������ţ��",     19},
	{'G', "˱ָԭζ��(1��)",   11.5},
	{'H', "������Ƭ��Ƥ��",   12.5},
	{'I', "�°¶�������(2��)", 12},
	{'J', "�������׻�",         10.5},
	{'K', "��������(2��)",     11.0},
	{'L', "������Ǽ�(3��)",     11.0},
	{'M', "����ɫ��",           12.5},
	{'N', "����(С)",           8},
	{'O', "����(��)",           11},
	{'P', "����(��)",           13},
	{'Q', "ܽ��������",         8},
	{'R', "ԭζ��Ͳ������",     6},
	{'S', "����������",         6.5},
	{'T', "�������װ�",         8.0},
	{'U', "��ʽ��̢",           7.5},
	{'V', "���¿���(С)",       7.0},
	{'W', "���¿���(��)",       9.5},
	{'X', "���¿���(��)",       11.5},
	{'Y', "�����֭����",       12.0},
	{'Z', "����������",         11.0},
	{'\0', NULL,                0}
	};
	const struct SPECIAL special[] = 
	{
		//	{"ANV", "�������ȱ����������",    22}, //�������Ҫ���ſ����ע�͵���һ�еġ�BMV���Żݣ��۲��Żݲ˵��Ƿ����˱仯
			{"BMV", "���༦�ȱ���ֵ�ײ�",    24},
			{"ABCGGIIKKOUWWW", "��ֵȫ��Ͱ", 100},
			{"KIIRRJUWW", "�ͷ�С��Ͱ",  65},
			{"JJ","�������׻�(2��С)",      9.5},
			{NULL, NULL, 0}
	};
	int discount[5][26] = { 0 };
	for (int i = 0; special[i].price != 0; i++)
	{
		for (unsigned int j = 0; j < strlen(special[i].type); j++)
		{
			if (special[i].type[j] - 'A' >= 0)
				discount[i][special[i].type[j] - 'A']++;
		}
	}
	while (1)
	{
		int tag = 0;
		double cost = 0;
		char order[100] = { '0' };
		int charge[27] = { 0 };
		int location = 0;
		system("mode con cols=120 lines=35");
		cout << "=============================================================" << endl;
		cout << "                      KFC 2021�����˵�                       " << endl;
		cout << "=============================================================" << endl;
		for (int i = 0; list[i].price != 0; i++)
		{
			cout << setw(2) << list[i].type << " " << setiosflags(ios::left) << setw(20) << list[i].food << setw(8) << list[i].price;
			if ((i + 1) % 2 == 0)
				cout << endl;
			else
				cout << setw(2) << "|";
			cout << resetiosflags(ios::left);
		}
		cout << endl;
		cout << "���Ż���Ϣ����" << endl;
		for (int i = 0; special[i].price != 0; i++)
		{
			cout << special[i].food << "=";
			for (unsigned int j = 0; j < strlen(special[i].type); j++)
			{
				for (int k = 0; k < 26; k++)
				{
					if (special[i].type[j] == list[k].type)
					{
						cout << list[k].food;
						if (discount[i][special[i].type[j] - 'A'] > 1)
						{
							cout << "*" << discount[i][special[i].type[j] - 'A'];
							j += discount[i][special[i].type[j] - 'A'] - 1;
						}
						if (j < strlen(special[i].type) - 1)
							cout << "+";
						else
						{
							cout << "=";
							break;
						}
					}
				}
			}
			cout << special[i].price << endl;
		}
		cout << endl;
		cout << "���������˵������" << endl
			<< "ANV = �������ȱ� + ����(С) + ���¿���(С) / akaak = �������ȱ� * 3 + �������� * 2" << endl
			<< "��ĸ���ִ�Сд������˳�򣬵�������0���˳�����" << endl << endl;
		cout << "��㵥��";
		for (unsigned int i = 0;; i++)
		{
			order[i] = getchar();
			if (order[i] == '\n')
				break;
			if (order[0] == '0'&& getchar()== '\n')
			{
				tag = 2;
				break;
			}
			if (order[i] >= 'a' && order[i] <= 'z')
				order[i] -= 32;
			else if (order[i] < 'A' || order[i] > 'Z' || !cin.good())
			{
				cout << "������󣬰����������." << endl;
				tag = 1;
				break;
			}
		}
		if (tag == 1)
		{
			while (getchar() !='\n' );
			_getch();
			system("cls");
			continue;
		}
		else if (tag == 2)
			break;
		for (unsigned int i = 0; i < strlen(order); i++)
		{
			if (order[i] - 'A' >= 0)
				charge[order[i] - 'A']++;
		}
		for (int i = 26; i >= 0; i--)
		{
			if (charge[i] != 0)
			{
				location = i;
				break;
			}
		}
		cout << "���ĵ��=";
		for (unsigned int i = 0; list[i].price != 0; i++)
		{
			if (charge[i] != 0)
			{
				cout << list[i].food;
				if (charge[i] > 1)
					cout << "*" << charge[i];
				if (i != location)
					cout << "+";
				else
					cout << endl;
			}
		}
		for (int i = 0; special[i].price != 0; i++)
		{
			int sum = 99999;
			tag = 0;
			for (unsigned int j = 0; j < 26; j++)
			{
				if (discount[i][j] != 0)
					if (charge[j] >= discount[i][j] && charge[j] != 0)
					{
						if (charge[j] / discount[i][j] < sum)
							sum = charge[j] / discount[i][j];
					}
					else
					{
						tag = 3;
						break;
					}
			}
			if (sum != 99999 && tag != 3)
			{
				cost += special[i].price * sum;
				for (unsigned int j = 0; j < 26; j++)
				{
					if (discount[i][j] != 0)
						charge[j] -= discount[i][j] * sum;
				}
			}
		}
		for (int i = 0; i <= location; i++)
		{
			if (charge[i] > 0)
				cost += charge[i] * list[i].price;
		}
		cout << "���ƣ�" << cost << "Ԫ" << endl;
		cout << "�㵥��ɣ������������." << endl;
		_getch();
		system("cls");
    }
	return 0;
}