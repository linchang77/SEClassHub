#include<iostream>
#include<vector>
using namespace std;
class Matrix
{
public:
	Matrix(int row, int column);
	Matrix();
	void select();
	void show();
	void transfer();
private:
	int row;
	int column;
	vector<vector<int>> vec;
	vector < vector<int>> temp;
};
int main()
{
	int row, column;
	cout << "请输入矩阵的行数:";
	cin >> row;
	cout << "请输入矩阵的列数:";
	cin >> column;
	Matrix matrix(row, column);
	matrix.select();
	return 0;
}
Matrix::Matrix(int row1, int column1)
{
	row = row1;
	column = column1;
	cout << "请输入关系矩阵:" << endl;
	for (int i = 0; i < row; i++)
	{
		vector<int> temp;
		cout << endl << "请输入矩阵的第" << i << "行元素(元素以空格分隔) :";
		for (int j = 0; j < column; j++)
		{
			int n;
			cin >> n;
			temp.push_back(n);
		}
		vec.push_back(temp);
	}
}
Matrix::Matrix()
{
	row = 0;
	column = 0;
	vector<int> temp(0);
	vec.push_back(temp);
}
void Matrix::show()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
			cout << temp[i][j] << ' ';
		cout << endl;
	}
}
void Matrix::select()  
{
	cout << endl;
	cout << "使用warshall算法得到的传递闭包为" << endl;
	transfer();
}


void Matrix::transfer()
{
	temp = vec;
	for (int i = 0; i < row; i++)//从第i行开始
	{
		for (int j = 0; j < row; j++)//检查第i列的每个元素
			if (temp[j][i] == 1)//如果这个元素为1，就把第i行的元素逻辑加到第j行的元素上
			{
				for (int n = 0; n < column; n++)
				{
					temp[j][n] = temp[j][n] + vec[i][n];
					if (temp[j][n] > 1)
						temp[j][n] = 1;
				}
			}
	}
	show();
}
