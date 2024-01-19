#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	int a[4];
	int i = -1, j = -1;
	char s;
	while (1)
	{
		cout << "***************************************" << endl;
		cout << "**                                   **" << endl;
		cout << "**        欢迎进入逻辑运算程序       **" << endl;
		cout << "**                                   **" << endl;
		cout << "***************************************" << endl << endl;
		cout << endl;
		cout << "  请输入P的值（0或1）,以回车结束:";
		cin >> i;
		if (i != 0 && i != 1)
		{
			cout << endl << "  P的值输入有误,请重新输入!";
			Sleep(2000);
			system("cls");  //清屏
			continue;
		}
		cout << endl << "  请输入Q的值（0或1）,以回车结束:";
		cin >> j;
		if (j != 0 && j != 1)
		{
			printf("\n  Q的值输入有误,请重新输入!");
			Sleep(2000);
			system("cls");  //清屏
			continue;
		}
		a[0] = i && j;  //与运算
		a[1] = i || j;  //或运算
		a[2] = (!i) || j;  //蕴含运算，将其转化为与或非形式
		a[3] = ((!i) || j) && ((!j) || i);  //等值运算，将其转化为与或非形式
		cout << endl << endl << "  合取:" << endl << "       P/\\Q = " << a[0] << endl;
		cout << "  析取:" << endl << "       P\\/Q = " << a[1] << endl;
		cout << "  条件:" << endl << "       P->Q = " << a[2] << endl;
		cout << "  双条件:" << endl << "       P<->Q = " << a[3] << endl;
		cout << endl;
		int tag = 0;
		while (1)
		{
			cout << "是否继续运算?（y/n）";//询问是否继续操作
			cin >> s;
			if (s == 'y' || s == 'n')
			{
				if (s == 'y')
				{
					system("cls");  //清屏
					tag = -1;
					break;
				}
				else
				{
					printf("欢迎下次再次使用!\n");  //退出
					tag == 1;
					exit(0);
				}
			}
			else
				cout << "输入错误,请重新输入!" << endl;//错误校验
		}
		if (tag == -1)
			continue;
		else if (tag == 1)
			break;
	}
	return 0;
}
