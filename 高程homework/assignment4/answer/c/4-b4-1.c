/*2250420 软工 陈君*/
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
			char ch    ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
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

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/***************************************************************************
  函数名称：memu
  功    能:显示菜单
  输入参数：空
  返 回 值：int
  说    明：无
***************************************************************************/
int menu(const HANDLE hout)
{
	char a;
	cls(hout);//显示菜单的时候要先清屏
	printf("1.用I、J、K、L键控制上下左右(大小写均可，边界停止)\n");
	printf("2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)\n");
	printf("3.用箭头键控制上下左右，边界停止\n");
	printf("4.用箭头键控制上下左右，边界回绕\n");
	printf("5.用I、J、K、L键控制上下左右(大小写均可，边界停止,且左方向键不会移动)\n");
	printf("6.用I、J、K、L键控制上下左右(大小写均可，边界回绕，且左方向键不会移动)\n");
	printf("0.退出\n");
	printf("[请选择0-6]\n"); 
	while (1)
	{
		a = _getch();
		if (a >= '0' && a <= '6')
			break;
	}
	return a;
}
/************************************************
    六个功能函数
************************************************/ 	 
void func1(HANDLE hout);
void func2(HANDLE hout);
void func3(HANDLE hout);
void func4(HANDLE hout);
void func5(HANDLE hout);
void func6(HANDLE hout);
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
    srand((unsigned int)(time(0)));/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
    while (1)
    {
        switch (menu(hout) - 48)//由于返回值为char类型转变成的int要减去48
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
	cls(hout);//先清屏
	init_border(hout);/* 显示初始的边框及其中的随机字符 */
	int x = 35;//初始化光标
	int y = 9;
	gotoxy(hout, x, y);//让光标在中间
	while (1)
	{

		char ch = _getch();//读取键盘输入  
		if (ch == 'i' || ch == 'I') //用I、J、K、L键控制上下左右(大小写均可，边界停止)" 
		{
			//判断越界
			if (y <= 1)
				continue;
			y = y - 1;
			gotoxy(hout, x, y);//移动光标
		}
		if (ch == 'j' || ch == 'J') //用I、J、K、L键控制上下左右(大小写均可，边界停止)" 
		{
			if (x <= 1)//判断越界
				continue;
			x--;
			gotoxy(hout, x, y);//移动光标
		}
		if (ch == 'k' || ch == 'K') //用I、J、K、L键控制上下左右(大小写均可，边界停止)" 
		{
			if (y >= MAX_Y)//判断越界
				continue;
			y = y + 1;
			gotoxy(hout, x, y);//移动光标
		}
		if (ch == 'l' || ch == 'L') //用I、J、K、L键控制上下左右(大小写均可，边界停止)" 
		{
			if (x >= MAX_X)
				continue;//判断越界
			x++;
			gotoxy(hout, x, y);//移动光标
		}
		if (ch == ' ')
		{
			putchar(' ');
			gotoxy(hout, x, y);
		}
		if (ch == 'q' || ch == 'Q')
		{
			gotoxy(hout, 0, 23);
			printf("游戏结束按回车键返回菜单");
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
	cls(hout);//先清屏
	init_border(hout);/* 显示初始的边框及其中的随机字符 */
	int x = 35;//初始化光标
	int y = 9;
	gotoxy(hout, x, y);//让光标在中间
	while (1)
	{

		char ch = _getch();//读取键盘输入  
		if (ch == 'i' || ch == 'I') //用I、J、K、L键控制上下左右(大小写均可，边界停止)" 
		{
			//判断越界
			if (y <= 1)
				y = MAX_Y;
			else
				y--;
			gotoxy(hout, x, y);//移动光标
		}
		if (ch == 'j' || ch == 'J') //用I、J、K、L键控制上下左右(大小写均可，边界停止)" 
		{
			if (x <= 1)//判断越界
				x = MAX_X;
			else
				x--;
			gotoxy(hout, x, y);//移动光标
		}
		if (ch == 'k' || ch == 'K') //用I、J、K、L键控制上下左右(大小写均可，边界停止)" 
		{
			if (y >= MAX_Y)//判断越界
				y = 1;
			else
				y++;
			gotoxy(hout, x, y);//移动光标
		}
		if (ch == 'l' || ch == 'L') //用I、J、K、L键控制上下左右(大小写均可，边界停止)" 
		{
			if (x >= MAX_X)
				x = 1;
			else
				x++;
			gotoxy(hout, x, y);//移动光标
		}
		if (ch == ' ')
		{
			putchar(' ');
			gotoxy(hout, x, y);
		}
		if (ch == 'q' || ch == 'Q')
		{
			gotoxy(hout, 0, 23);
			printf("游戏结束按回车键返回菜单");
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
	cls(hout);//先清屏
	init_border(hout);/* 显示初始的边框及其中的随机字符 */
	int x = 35;//初始化光标
	int y = 9;
	gotoxy(hout, x, y);//让光标在中间
	while (1)
	{

		int ch = _getch();//读取键盘输入  
		if (ch == ' ')
		{
			putchar(' ');
			gotoxy(hout, x, y);
			continue;
		}
		if (ch == 'q' || ch == 'Q')
		{
			gotoxy(hout, 0, 23);
	    	printf("游戏结束按回车键返回菜单");
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
			//判断越界
			if (y <= 1)
				continue;
			y = y - 1;
			gotoxy(hout, x, y);//移动光标
		}
		if (ch == 224 && ch1 == 75) //用I、J、K、L键控制上下左右(大小写均可，边界停止)" 
		{
			if (x <= 1)//判断越界
				continue;
			x--;
			gotoxy(hout, x, y);//移动光标
		}
		if (ch == 224 && ch1 == 80) //用I、J、K、L键控制上下左右(大小写均可，边界停止)" 
		{
			if (y >= MAX_Y)//判断越界
				continue;
			y = y + 1;
			gotoxy(hout, x, y);//移动光标
		}
		if (ch == 224 && ch1 == 77) //用I、J、K、L键控制上下左右(大小写均可，边界停止)" 
		{
			if (x >= MAX_X)
				continue;//判断越界
			x++;
			gotoxy(hout, x, y);//移动光标
		}
	}
}
void func4(HANDLE hout)
{
	cls(hout);//先清屏
	init_border(hout);/* 显示初始的边框及其中的随机字符 */
	int x = 35;//初始化光标
	int y = 9;
	gotoxy(hout, x, y);//让光标在中间
	while (1)
	{
		int ch = _getch();//读取键盘输入   
		if (ch == ' ')
		{
			putchar(' ');
			gotoxy(hout, x, y);
			continue;
		}
		if (ch == 'q' || ch == 'Q')
		{
			gotoxy(hout, 0, 23);
			printf("游戏结束按回车键返回菜单");
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
		if (ch == 224 && ch1 == 72) //用I、J、K、L键控制上下左右(大小写均可，边界停止)" 
		{
			//判断越界
			if (y <= 1)
				y = MAX_Y;
			else
				y--;
			gotoxy(hout, x, y);//移动光标
		}
		if (ch == 224 && ch1 == 75) //用I、J、K、L键控制上下左右(大小写均可，边界停止)" 
		{
			if (x <= 1)//判断越界
				x = MAX_X;
			else
				x--;
			gotoxy(hout, x, y);//移动光标
		}
		if (ch == 224 && ch1 == 80) //用I、J、K、L键控制上下左右(大小写均可，边界停止)" 
		{
			if (y >= MAX_Y)//判断越界
				y = 1;
			else
				y++;
			gotoxy(hout, x, y);//移动光标
		}
		if (ch == 224 && ch1 == 77) //用I、J、K、L键控制上下左右(大小写均可，边界停止)" 
		{
			if (x >= MAX_X)
				x = 1;
			else
				x++;
			gotoxy(hout, x, y);//移动光标
		}
	}
}
void func5(HANDLE hout)
{
	cls(hout);//先清屏
	init_border(hout);/* 显示初始的边框及其中的随机字符 */
	int x = 35;//初始化光标
	int y = 9;
	gotoxy(hout, x, y);//让光标在中间
	while (1)
	{
		int ch = _getch();//读取键盘输入  
		if (ch == 224)
		{
			int ch1 = _getch();
			continue;
		}
		if (ch == 'i' || ch == 'I') //用I、J、K、L键控制上下左右(大小写均可，边界停止)" 
		{
			//判断越界
			if (y <= 1)
				continue;
			y = y - 1;
			gotoxy(hout, x, y);//移动光标
		}
		if (ch == 'j' || ch == 'J') //用I、J、K、L键控制上下左右(大小写均可，边界停止)" 
		{
			if (x <= 1)//判断越界
				continue;
			x--;
			gotoxy(hout, x, y);//移动光标
		}
		if (ch == 'k' || ch == 'K') //用I、J、K、L键控制上下左右(大小写均可，边界停止)" 
		{
			if (y >= MAX_Y)//判断越界
				continue;
			y = y + 1;
			gotoxy(hout, x, y);//移动光标
		}
		if (ch == 'l' || ch == 'L') //用I、J、K、L键控制上下左右(大小写均可，边界停止)" 
		{
			if (x >= MAX_X)
				continue;//判断越界
			x++;
			gotoxy(hout, x, y);//移动光标
		}
		if (ch == ' ')
		{
			putchar(' ');
			gotoxy(hout, x, y);
		}
		if (ch == 'q' || ch == 'Q')
		{
			gotoxy(hout, 0, 23);
			printf("游戏结束按回车键返回菜单");
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
	cls(hout);//先清屏
	init_border(hout);/* 显示初始的边框及其中的随机字符 */
	int x = 35;//初始化光标
	int y = 9;
	gotoxy(hout, x, y);//让光标在中间
	while (1)
	{

		int ch = _getch();//读取键盘输入  
		if (ch == 224)
		{
			int ch1 = _getch();
			continue;
		}
		if (ch == 'i' || ch == 'I') //用I、J、K、L键控制上下左右(大小写均可，边界停止)" 
		{
			//判断越界
			if (y <= 1)
				y = MAX_Y;
			else
				y--;
			gotoxy(hout, x, y);//移动光标
		}
		if (ch == 'j' || ch == 'J') //用I、J、K、L键控制上下左右(大小写均可，边界停止)" 
		{
			if (x <= 1)//判断越界
				x = MAX_X;
			else
				x--;
			gotoxy(hout, x, y);//移动光标
		}
		if (ch == 'k' || ch == 'K') //用I、J、K、L键控制上下左右(大小写均可，边界停止)" 
		{
			if (y >= MAX_Y)//判断越界
				y = 1;
			else
				y++;
			gotoxy(hout, x, y);//移动光标
		}
		if (ch == 'l' || ch == 'L') //用I、J、K、L键控制上下左右(大小写均可，边界停止)" 
		{
			if (x >= MAX_X )
				x = 1;
			else
				x++;
			gotoxy(hout, x, y);//移动光标
		}
		if (ch == ' ')
		{
			putchar(' ');
			gotoxy(hout, x, y);
		}
		if (ch == 'q' || ch == 'Q')
		{
			gotoxy(hout, 0, 23);
			printf("游戏结束按回车键返回菜单");
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












