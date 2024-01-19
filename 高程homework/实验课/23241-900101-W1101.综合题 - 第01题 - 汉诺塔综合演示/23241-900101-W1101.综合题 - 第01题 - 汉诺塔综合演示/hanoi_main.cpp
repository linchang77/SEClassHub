/* 软工 250420 陈君 */
#include<iostream>
#include"cmd_console_tools.h"
#include"hanoi.h"
/* ----------------------------------------------------------------------------------

     本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

     本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	int command,num;//声明选项和汉诺塔层数
	char src, dst,temp;//声明柱子


	/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	cct_setconsoleborder(120, 40, 120, 9000);
	while (true)
	{
		command = showmenu();//调用menu中的展示UI
		if (command <= 4)
		{
			if (command == 0)
				exit(1);
			setparameter(&src, &dst, &temp, &num);//初始化参数
			if (command == 4)
			{
				setsleep();
				initputout(src, dst, num, command);//功能4的初始化
			}
			hanoi(num, src, temp, dst, command);
			if (command < 4)
				std::cout << "按回车键继续";
			clear_screen();
		}
		else if (command >= 5&&command <=7)
		{
			setparameter(&src, &dst, &temp, &num);//初始化参数
			menu_5_6_7(command,num,src,dst);
			to_be_continued(NULL);
		}
		else if (command == 8)
		{
			setparameter(&src, &dst, &temp, &num);//初始化参数
			setsleep();
			initputout(src, dst, num, command);//初始化
			hanoi(num, src, temp, dst, command);
			to_be_continued(NULL,0,35);
		}
		else if (command == 9)
		{
			setparameter(&src, &dst, &temp, &num);//初始化参数
			initputout(src, dst, num, command);//初始化
			startgame(src, dst, num);//开始游戏
			to_be_continued(NULL, 0, 38);
		}
	}
	

	return 0;
}
