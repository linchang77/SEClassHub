/* 软工 2250420 陈君 */
#pragma once

/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */
int showmenu();//展示菜单，返回用户选择的选项
void setparameter(char* src, char* dst, char* temp, int* n);//初始化层数，目标柱和起始柱
void hanoi(int n, char src, char tmp, char dst, const int command);//递归调用函数
void clear_screen();//清屏函数
void putout_by_command(const int command, int n, int step, char src, char dst);//输出函数
void move(char src, char dst);//移动盘子
void putout(int command);//输出当前数组情况
void initplate(char src, int n);//初始化盘子
void setsleep();//设置延时参数
void initputout(char src, char dst, int n, int command);//输出化界面
void sleeptime(int sleep);//延时函数
void putoutpillar(int command);//输出柱子
void putoutplate(int command);//输出盘子
void func5();//功能5
void to_be_continued(const char* prompt, const int X = 0, const int Y = 22);//提示继续函数
void func6(int n, char src);//功能6
void func7(int plate_num, char src, char dst, int command);//功能7
void menu_5_6_7(int command, int num, char src, char dst);//功能5，6，7
void startgame(char src,char dst,int num);//开始游戏
bool is_valid(char now_src, char now_dst);//判断合法