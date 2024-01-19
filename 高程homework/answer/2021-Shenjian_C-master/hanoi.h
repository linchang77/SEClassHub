/*1953609 ��� ���͢*/
#pragma once

/* ------------------------------------------------------------------------------------------------------

     ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ------------------------------------------------------------------------------------------------------ */
char menu(void);
void hanoi(int n, char src, char tmp, char dst, char sign);
void initial(char num);
void move(char src, char dst);
void print();
void print_move(int n, char src, char dst, char sign);
void print_move_one(int n, char src, char dst, char sign);
void print_tower(char sign);
void transverse(int n, char src, char tmp, char dst,char sign);
void wait();
void print_disk();
void print_disk_ini(char src, int sum);
void disk_move(int n, char src, char dst, char sign);
