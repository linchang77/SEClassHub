/* 软工 2250420 陈君 */
#pragma once
//数组中的元素，flag为1表示可见要被上色出来，flag为0说明不可见不能上色，flag为-1，说明被手动排除
struct plaid {
	char element;//扫雷图中的元素
	int flag;//这个元素是否显示
	int alreadyflag;
};
/* 空文件，给出的目的是防止大家把文件名弄错 */
int showmenu();
int getdifficulty(); 
/*功能函数*/
void Func1(plaid bomb[][30], int bombnum, int B_row, int B_column);
int Func2(plaid bomb[][30], int bombnum, int B_row, int B_column);
void Func3(plaid bomb[][30], int bombnum, int B_row, int B_column);
void Func4(plaid bomb[][30], int bombnum, int B_row, int B_column);
void Func5(plaid bomb[][30], int bombnum, int B_row, int B_column);
void Func6(plaid bomb[][30], int bombnum, int B_row, int B_column);
void Func7(plaid bomb[][30], int bombnum, int B_row, int B_column);
void Func8(plaid bomb[][30], int bombnum, int B_row, int B_column, int command = 0);
void Func9(plaid bomb[][30], int bombnum, int B_row, int B_column);
/*控制内部数组的函数*/
void create_bomb1(plaid bomb[][30], int bombnum, int B_row, int B_column);
void create_bomb2(plaid bomb[][30], int bombnum, int B_row, int B_column, int row, int column);
void openarea(plaid bomb[][30], int row, int column, int B_row, int B_column);//领域展开doge
void openflag(plaid bomb[][30], int B_row, int B_column);
void find(plaid bomb[][30], int row, int column, int B_row, int B_column);
void creatflag(int i, int j, plaid bomb[][30], int row, int column);//对数组的这个位置进行计数
bool bomb_checkzero(plaid bomb[][30], int i, int j, int B_row, int B_column);
/*涂色函数*/
void setcolor(plaid bomb[][30], int B_row, int B_column);
void putoutframe(int B_row, int B_column);
void putoutframelines(int i, int B_column);
void setblocks(plaid bomb[][30], int B_row, int B_column);
void setbombflag(plaid bomb[][30], int B_row, int B_column, int tag);
void blockgetcolor(int i, int j, int color);
/*输出函数*/
void putoutbomb(plaid bomb[][30], int B_row, int B_column,int command);
void putbombnum(int bombnum);
/*输入函数*/
void setparameter(int* B_row, int* B_column, int* bombnum, int difficulty);
void to_be_continued(const char* prompt, const int X = 0, const int Y = 22);//提示继续函数
void changetoint(int& row, int& column, int B_column);
char getinrc(int& row, int& column, int B_row, int B_column);
/*其他函数*/
bool is_over(plaid bomb[][30], int B_row, int B_column);
void getposition(int& x, int& y, int B_row, int i, int j);
void changetoinside(int& x, int& y, int B_row, int B_column, int i, int j);
/*控制台函数*/
void setconsoleborder(int difficulty);
int getpisition(plaid bomb[][30], int bombnum, int B_row, int B_column, int& nrow, int& ncolumn, int func);



