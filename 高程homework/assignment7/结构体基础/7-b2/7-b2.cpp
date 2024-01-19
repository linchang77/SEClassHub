/* 2250420 陈君 软工 */
#define _CRT_SECURE_NO_WARNINGS		//使用了VS认为unsafe的函数
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
	static const HANDLE __hout = GetStdHandle(STD_OUTPUT_HANDLE);		//取标准输出设备对应的句柄
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(__hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(__hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(__hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(__hout, coord);
	return;
}
/***************************************************************************
  函数名称：
  功    能：输出菜单
  输入参数：
  返 回 值：
  说    明：
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
	cout << endl << "【优惠信息】：" << endl;
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
	cout<< "【输入规则说明】：" << endl;
	cout << "ANV=香辣鸡腿堡+薯条(小)+百事可乐(小) / akaak=香辣鸡腿堡*3+香辣鸡翅*2" << endl;
	cout << "字母不分大小写，不限顺序，单独输入0则退出程序" << endl;
	cout << endl<<"请点单：";
}
/***************************************************************************
  函数名称：
  功    能：算价钱
  输入参数：
  返 回 值：
  说    明：
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
  函数名称：
  功    能：算价钱
  输入参数：
  返 回 值：
  说    明：
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
  函数名称：
  功    能：将订单排序
  输入参数：
  返 回 值：
  说    明：
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
  函数名称：
  功    能：获取订单
  输入参数：
  返 回 值：
  说    明：
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
	sort(order);//将订单排序
}
int main()
{
	const struct KFC list[] = {
	{'A', "香辣鸡腿堡",			19.5},
	{'B', "劲脆鸡腿堡",			19.5},
	{'C', "新奥尔良烤鸡腿堡",		20.0},
	{'D', "老北京鸡肉卷",			18.5},
	{'E', "黄金SPA鸡排堡(藤椒风味)",	18.0},
	{'F', "经典美式风味嫩牛堡(单层)",	18.0},
	{'G', "吮指原味鸡(1块)",		12.5},
	{'H', "黄金脆皮鸡",			13.5},
	{'I', "新奥尔良烤翅(2块)",		13.5},
	{'J', "劲爆鸡米花",			12.0},
	{'K', "香辣鸡翅(2块)",			12.5},
	{'L', "热辣香骨鸡(3块)",		12.5},
	{'M', "汁汁厚做培根三层和牛堡",	55.0},
	{'N', "薯条(小)",				9.0},
	{'O', "薯条(中)",				12.5},
	{'P', "薯条(大)",				14.5},
	{'Q', "芙蓉蔬荟汤",			9.0},
	{'R', "原味花筒冰激凌",			6.0},
	{'S', "醇香土豆泥",			7.5},
	{'T', "黄金鸡块",				12.5},
	{'U', "葡式蛋挞",				8.0},
	{'V', "百事可乐(小)",			8.5},
	{'W', "百事可乐(中)",			10.0},
	{'X', "百事可乐(大)",			12.0},
	{'Y', "九珍果汁",				13.0},
	{'Z', "雪顶咖啡",				14.5},
	{'\0', NULL,				0}
	};
	const struct SPECIAL special[] = {
	{"AOW", "OK三件套(香辣鸡腿堡)",		31}, //如果有需要，放开此项，注释掉下一行的“COW”优惠，观察优惠菜单是否发生了变化
	//	{"COW", "OK三件套(新奥尔良烤鸡腿堡)",	33.5}, //如果有需要，放开此项，注释掉上一行的“AOW”优惠，观察优惠菜单是否发生了变化
		{"HHHHHKKKSUWWW", "超爆全家桶(脆皮鸡)",	101},
		{"APUY", "人气明星配四件套(8折)",		44},
		{"GG","吮指原味鸡(2块)",			21},
		{"", NULL, 0}
	};
	while (1)
	{
		putoutmenu(list, special);
		char order[100];
		getorder(order);
		cout << "你的点餐=";
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
		cout << "共计：" << getprize(order,list,special) << "元" << endl;
		cout << "点单完成，按任意键继续." << endl;
		_getch();
		cct_cls();
	}
	
}