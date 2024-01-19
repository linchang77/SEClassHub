#include<iostream>
using namespace std;
void place(int row, int num, char queen[8][8], bool bcolumn[8],
	bool bMain_diagonal[15], bool bSub_diagonal[15]);
void putout(char queen[8][8],int num);
int main()
{
	char queen[8][8];
	//�ĸ���������
	bool bcolumn[8];
	bool bMain_diagonal[15];
	bool bSub_diagonal[15];
	//��ʼ��
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
	cout << "����N��N�����̣�����N���ʺ�Ҫ�����лʺ���ͬһ�У��к�ͬһб����!" << endl << endl;
	cout << "������ʺ�ĸ���:";
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
	for (int column = 0; column < num; column++)//�ӵ�0�п�ʼ���ûʺ�
	{
		int md = row - column + num - 1;
		int sd = row + column;
		if (!bcolumn[column] && !bMain_diagonal[md] && !bSub_diagonal[sd])//������Է��þͷŽ�ȥ
		{
			queen[row][column] = 'X';//���ûʺ�
			bcolumn[column] = bMain_diagonal[md] = bSub_diagonal[sd] = true;
			place(row + 1, num, queen, bcolumn,bMain_diagonal, bSub_diagonal);
			//����
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