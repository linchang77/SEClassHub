/* �� 2250420 �¾� */
#pragma once
//�����е�Ԫ�أ�flagΪ1��ʾ�ɼ�Ҫ����ɫ������flagΪ0˵�����ɼ�������ɫ��flagΪ-1��˵�����ֶ��ų�
struct plaid {
	char element;//ɨ��ͼ�е�Ԫ��
	int flag;//���Ԫ���Ƿ���ʾ
	int alreadyflag;
};
/* ���ļ���������Ŀ���Ƿ�ֹ��Ұ��ļ���Ū�� */
int showmenu();
int getdifficulty(); 
/*���ܺ���*/
void Func1(plaid bomb[][30], int bombnum, int B_row, int B_column);
int Func2(plaid bomb[][30], int bombnum, int B_row, int B_column);
void Func3(plaid bomb[][30], int bombnum, int B_row, int B_column);
void Func4(plaid bomb[][30], int bombnum, int B_row, int B_column);
void Func5(plaid bomb[][30], int bombnum, int B_row, int B_column);
void Func6(plaid bomb[][30], int bombnum, int B_row, int B_column);
void Func7(plaid bomb[][30], int bombnum, int B_row, int B_column);
void Func8(plaid bomb[][30], int bombnum, int B_row, int B_column, int command = 0);
void Func9(plaid bomb[][30], int bombnum, int B_row, int B_column);
/*�����ڲ�����ĺ���*/
void create_bomb1(plaid bomb[][30], int bombnum, int B_row, int B_column);
void create_bomb2(plaid bomb[][30], int bombnum, int B_row, int B_column, int row, int column);
void openarea(plaid bomb[][30], int row, int column, int B_row, int B_column);//����չ��doge
void openflag(plaid bomb[][30], int B_row, int B_column);
void find(plaid bomb[][30], int row, int column, int B_row, int B_column);
void creatflag(int i, int j, plaid bomb[][30], int row, int column);//����������λ�ý��м���
bool bomb_checkzero(plaid bomb[][30], int i, int j, int B_row, int B_column);
/*Ϳɫ����*/
void setcolor(plaid bomb[][30], int B_row, int B_column);
void putoutframe(int B_row, int B_column);
void putoutframelines(int i, int B_column);
void setblocks(plaid bomb[][30], int B_row, int B_column);
void setbombflag(plaid bomb[][30], int B_row, int B_column, int tag);
void blockgetcolor(int i, int j, int color);
/*�������*/
void putoutbomb(plaid bomb[][30], int B_row, int B_column,int command);
void putbombnum(int bombnum);
/*���뺯��*/
void setparameter(int* B_row, int* B_column, int* bombnum, int difficulty);
void to_be_continued(const char* prompt, const int X = 0, const int Y = 22);//��ʾ��������
void changetoint(int& row, int& column, int B_column);
char getinrc(int& row, int& column, int B_row, int B_column);
/*��������*/
bool is_over(plaid bomb[][30], int B_row, int B_column);
void getposition(int& x, int& y, int B_row, int i, int j);
void changetoinside(int& x, int& y, int B_row, int B_column, int i, int j);
/*����̨����*/
void setconsoleborder(int difficulty);
int getpisition(plaid bomb[][30], int bombnum, int B_row, int B_column, int& nrow, int& ncolumn, int func);



