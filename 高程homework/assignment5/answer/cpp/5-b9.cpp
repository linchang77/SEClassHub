/* 2250420 陈君 软工 */
#include<iostream>
#include<iomanip>
using namespace std;
bool judge_small(int array[][9], int x, int y);
bool judge(int array[][9])
{

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			int temp[9] = { 1,2,3,4,5,6,7,8,9 };
			if (temp[array[i][j] - 1] != 0)
				temp[array[i][j] - 1] = 0;
			else
				return 0;
		}
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			int temp[9] = { 1,2,3,4,5,6,7,8,9 };
			if (temp[array[j][i] - 1] != 0)
				temp[array[j][i] - 1] = 0;
			else
				return 0;
		}
	for (int i = 0; i < 9; i = i + 3)
		for (int j = 0; j < 9; j = j + 3)
			if (!judge_small(array, i, j))
				return 0;
	return 1;
}
bool judge_small(int array[][9], int x, int y)
{
	
			int temp[9] = { 1,2,3,4,5,6,7,8,9 };
			for (int m = x; m < x + 3; m++)
				for (int n = y; n < y + 3; n++)
					if (temp[array[m][n] - 1] != 0)
						temp[array[m][n] - 1] = 0;
					else
						return 0;
	return 1;
}
int main()
{
	int array[9][9];
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			while (1)
			{
				cin >> array[i][j];
				if (!cin.good())
				{
					while (getchar() != 13)
						;
					continue;
				}
				if (array[i][j] <= 9 || array[i][j] >= 0)
					break;
			}
		}
	if (judge(array))
		cout << "是数独的解" << endl;
	else
		cout << "不是数独的解" << endl;

	return 0;
}

