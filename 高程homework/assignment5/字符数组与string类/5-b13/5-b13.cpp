/* 软工 2250420 陈君 */
#include <iostream>
#include <string>
#include<cmath> 
#include<time.h>
using namespace std;

//产生地雷
bool creatbomb(char bomb[][26])
{
	
	int row = rand() % 10;
	int column = rand() % 26;
	if (bomb[row][column] == '*')
		return false;
	else
	{
		bomb[row][column] = '*';
		return true;
	}
}
int countbomb(int i, int j,char bomb[][26])
{
	int sum = 0;
    int tag = 0;
	for (int n = i - 1; (n <= (i + 1)) && (n < 10); n++)//确保行不超边界
	{
		if (n < 0)//如果n超出棋盘下一个
			continue;
		for (int m = j - 1; m <= j + 1 && m < 26; m++)//确保列不越界
		{
			if (m < 0 || (n == i && m == j))//如果n超出棋盘或者等于原来的棋子就下一个
				continue;
			if (bomb[n][m] == '*')
				sum++;
		}
	}
	return sum;              
}
void creatflag(int i, int j, char bomb[][26])
{
	if (bomb[i][j] != '*')//如果该位置不是炸弹
	{
		bomb[i][j] = countbomb(i,j,bomb)+'0';
	}
}
int main()
{
	srand((unsigned)time(NULL));//初始化种子
	char bomb[10][26] = { 0 };
	for (int i = 0; i < 50; i++)
		if (!creatbomb(bomb))//如果生成失败就将i-1
			i--;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 26; j++)
			creatflag(i, j, bomb);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 26; j++)
			cout << char(bomb[i][j])<< " ";
		cout << endl;
	}
	return 0;
}