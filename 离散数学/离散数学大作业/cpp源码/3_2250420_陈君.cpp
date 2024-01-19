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
	void Reflexive();
	void symmetry();
	void transfer();
	void add(Matrix& m1, Matrix m2);
	void multiply(Matrix& m1, Matrix m2);
	int getnum(Matrix m1, Matrix m2, int row, int column);
private:
	int row;
	int column;
	vector<vector<int>> vec;//��ž���
	vector < vector<int>> temp;
};
int main()
{
	int row, column;
	cout << "��������������:" ;
	cin >> row;
	cout << "��������������:" ;
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
	cout << "�����ϵ����Ϊ:" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
			cout << temp[i][j]<<' ';
		cout << endl;
	}
}
void Matrix::select()
{
	int z;
	cout << endl;
	cout << "�����Ӧ���ѡ���㷨" << endl << "1:�Է��հ�" << endl
		<< "2:���ݱհ�"<<endl<<"3: �ԳƱհ�"<<endl<<"4: �˳�" << endl;
	cin >> z;
	switch (z)
	{
	case 1:Reflexive(); break;
	case 2:transfer(); break;
	case 3:symmetry(); break;
	case 4:exit(1); break;
	}
}
void Matrix::Reflexive()//�Է������㷨
{
	temp= vec;
	for (int i = 0; i < column; i++)
		temp[i][i] = 1;
	show();
	select();
}

void Matrix::symmetry()//�Գƾ����㷨
{
	temp = vec;//����ʱ��һ��ʸ��������
	for (int i = 0; i < row; i++)//�ȵõ�vec����
		for (int j = 0; j < column; j++)
			temp[j][i] = vec[i][j];
	for (int i = 0; i < row; i++)//Ȼ��vec��vec�����߼����
		for (int j = 0; j < column; j++)
		{
			temp[i][j] = temp[i][j] + vec[i][j];
			if (temp[i][j] > 1)
				temp[i][j] = 1;
		}
	show();//չʾ�ԳƱհ��Ĺ�ϵ����
	select();
}

void Matrix::transfer()
{
	Matrix mtemp=*this;
	for (int i = 2; i <=row; i++)
	{
		Matrix m1 = *this;//����һ��
		for (int j = 2; j <= i; j++)
		{
			Matrix m2 = *this;
			multiply(m1, m2);//m1*m2
		}	
		add(mtemp, m1);
	}
	temp = mtemp.vec;
	show();
	select();
}
void Matrix::add(Matrix& m1, Matrix m2)
{
	for (int i = 0; i < m1.row; i++)
	{
		for (int j = 0; j < m1.column; j++)
		{
			m1.vec[i][j] = m1.vec[i][j] + m2.vec[i][j];
			if (m1.vec[i][j] > 1)
				m1.vec[i][j] = 1;
		}
	}
}
void Matrix::multiply(Matrix& m1, Matrix m2)
{
	Matrix temp=m1;
	for (int i = 0; i < m1.row; i++)
	{
		for (int j = 0; j < m1.column; j++)
		{
			m1.vec[i][j] = getnum(temp, m2, i, j);
		}
	}
}
int Matrix::getnum(Matrix m1, Matrix m2,int row,int column)
{
	int sum = 0;
	for (int i = 0; i < m1.row; i++)
	{
		sum += m1.vec[row][i] * m2.vec[i][column];
	}
	if (sum >= 1)
		return 1;
	else
		return 0;
}