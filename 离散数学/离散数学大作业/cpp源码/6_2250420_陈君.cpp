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
	cout << "��������������:";
	cin >> row;
	cout << "��������������:";
	cin >> column;
	Matrix matrix(row, column);
	matrix.select();
	return 0;
}
Matrix::Matrix(int row1, int column1)
{
	row = row1;
	column = column1;
	cout << "�������ϵ����:" << endl;
	for (int i = 0; i < row; i++)
	{
		vector<int> temp;
		cout << endl << "���������ĵ�" << i << "��Ԫ��(Ԫ���Կո�ָ�) :";
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
	cout << "ʹ��warshall�㷨�õ��Ĵ��ݱհ�Ϊ" << endl;
	transfer();
}


void Matrix::transfer()
{
	temp = vec;
	for (int i = 0; i < row; i++)//�ӵ�i�п�ʼ
	{
		for (int j = 0; j < row; j++)//����i�е�ÿ��Ԫ��
			if (temp[j][i] == 1)//������Ԫ��Ϊ1���Ͱѵ�i�е�Ԫ���߼��ӵ���j�е�Ԫ����
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
