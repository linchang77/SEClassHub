#include<iostream>
#include<cstring>
using namespace std;
void place(int row, int num, char queen[8][8], bool bcolumn[8],
	bool bMain_diagonal[15], bool bSub_diagonal[15]);
void putout(char queen[8][8],int num);
int main()
{
	char queen[8][8];
	//四个辅助数组
	bool bcolumn[8];
	bool bMain_diagonal[15];
	bool bSub_diagonal[15];
	//初始化
	for (int i = 0; i < 8; i++)
	{
		bcolumn[i] = false;
	}
	for (int i = 0; i < 15; i++)
	{
		bMain_diagonal[i]=false;
		bSub_diagonal[i]=false;
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			queen[i][j]='0';
	}
	cout << "现有N×N的棋盘，放入N个皇后，要求所有皇后不在同一行，列和同一斜线上!" << endl << endl;
	cout << "请输入皇后的个数:";
	int num;
	cin >> num;
	place(0,num,queen,bcolumn,bMain_diagonal,bSub_diagonal);
	system("pause");
}
void place(int row,int num,char queen[8][8],bool bcolumn[8], 
	       bool bMain_diagonal[15],bool bSub_diagonal[15])
{
	if (row == num)
	{
		putout(queen,num);
		return;
	}
	for (int column = 0; column < num; column++)//从第0列开始放置皇后
	{
		int md = row - column + num - 1;
		int sd = row + column;
		if (!bcolumn[column] && !bMain_diagonal[md] && !bSub_diagonal[sd])//如果可以放置就放进去
		{
			queen[row][column] = 'X';//放置皇后
			bcolumn[column] = bMain_diagonal[md] = bSub_diagonal[sd] = true;
			place(row + 1, num, queen, bcolumn,bMain_diagonal, bSub_diagonal);
			//回退
			queen[row][column] = '0';
			bcolumn[column] = bMain_diagonal[md] = bSub_diagonal[sd] = false;
		}
	}
}
void putout(char queen[8][8],int num)
{
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
			cout << queen[i][j] << " ";
		cout << endl;
	}
	cout << endl << endl;
}
