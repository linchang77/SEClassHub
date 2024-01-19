/* 软工 2250420 陈君 */
/* 2150346 王科琦 2153097 许子鸣 2152482 鄂俊伍 2251875 陈晓坤 1953393 刘晓辰 2251356 高鑫*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdbool.h>
int countbomb(int i, int j, char bomb[][26])
{
	int sum = 0;
	int tag = 0;
	for (int n = i - 1; (n <= (i + 1)) && (n < 10); n++)//确保列不超边界
	{
		if (n < 0)//如果n超出棋盘下一个
			continue;
		for (int m = j - 1; m <= j + 1 && m < 26; m++)//确保行不越界
		{
			if (m < 0 || (n == i && m == j))//如果n超出棋盘或者等于原来的棋子就下一个
				continue;
			if (bomb[n][m] == '*')
				sum++;
		}
	}
	return sum;
}
int count_bomb(char bomb[][26])
{
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 26; j++)
			if (bomb[i][j] == '*')
				count++;
	}
	return count;
}
bool find_fault(char bomb[][26])
{
	if (count_bomb(bomb) != 50)
	{
		printf("错误1\n");
			return false;
	}
	char new_bomb[10][26];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 26; j++)
			if (bomb[i][j] == '*')
				new_bomb[i][j] = '*';
			else
				new_bomb[i][j] = countbomb(i, j, bomb) + '0';
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 26; j++)
			if (bomb[i][j] != new_bomb[i][j])
			{
				printf("错误2\n");
				return false;
			}		
	}
	return true;
}
void get_data(char bomb[][26])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			while (1)
			{
				bomb[i][j] = getchar();
				if ((bomb[i][j]  < '9' && bomb[i][j] >= '0') || bomb[i][j] == '*')
					break;
			}
		}
	}
}
int main()
{
	char bomb[10][26];
	//获取数组
	get_data(bomb);
	if (find_fault(bomb))
		printf("正确\n");
	return 0;
}
/*0 1 1 2 1 1 0 1 1 1 0 0 0 0 1 1 2 * 2 1 1 0 1 1 2 1
2 3 * 3 * 2 0 1 * 2 1 1 0 0 1 * 2 1 2 * 2 1 1 * 2 *
* * 2 3 * 3 1 2 2 3 * 1 1 1 2 2 3 2 3 4 * 2 1 1 2 1
* 5 3 2 2 * 1 1 * 3 2 1 1 * 2 2 * * 2 * * 2 0 0 0 0
2 * * 2 2 2 1 1 2 * 1 1 2 2 2 * 3 2 2 2 2 1 0 0 0 0
1 2 2 2 * 1 1 2 4 3 2 1 * 1 2 2 3 1 2 1 1 1 1 1 0 0
1 2 2 3 2 3 2 * * * 2 2 1 1 2 * 3 * 2 * 1 2 * 2 0 0
2 * * 2 * 3 * 4 4 3 * 1 0 0 3 * 4 1 2 1 1 2 * 2 0 0
* 4 4 4 4 * 4 * 1 1 1 1 0 0 2 * 3 1 1 0 0 1 2 2 1 0
1 2 * * 3 * 3 1 1 0 0 0 0 0 1 1 2 * 1 0 0 0 1 * 1 0*/