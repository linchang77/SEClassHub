/* �� 2250420 �¾� */
#pragma once

/* ------------------------------------------------------------------------------------------------------

     ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ------------------------------------------------------------------------------------------------------ */
int showmenu();//չʾ�˵��������û�ѡ���ѡ��
void setparameter(char* src, char* dst, char* temp, int* n);//��ʼ��������Ŀ��������ʼ��
void hanoi(int n, char src, char tmp, char dst, const int command);//�ݹ���ú���
void clear_screen();//��������
void putout_by_command(const int command, int n, int step, char src, char dst);//�������
void move(char src, char dst);//�ƶ�����
void putout(int command);//�����ǰ�������
void initplate(char src, int n);//��ʼ������
void setsleep();//������ʱ����
void initputout(char src, char dst, int n, int command);//���������
void sleeptime(int sleep);//��ʱ����
void putoutpillar(int command);//�������
void putoutplate(int command);//�������
void func5();//����5
void to_be_continued(const char* prompt, const int X = 0, const int Y = 22);//��ʾ��������
void func6(int n, char src);//����6
void func7(int plate_num, char src, char dst, int command);//����7
void menu_5_6_7(int command, int num, char src, char dst);//����5��6��7
void startgame(char src,char dst,int num);//��ʼ��Ϸ
bool is_valid(char now_src, char now_dst);//�жϺϷ�