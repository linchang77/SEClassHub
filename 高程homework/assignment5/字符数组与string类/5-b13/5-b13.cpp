/* �� 2250420 �¾� */
#include <iostream>
#include <string>
#include<cmath> 
#include<time.h>
using namespace std;

//��������
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
	for (int n = i - 1; (n <= (i + 1)) && (n < 10); n++)//ȷ���в����߽�
	{
		if (n < 0)//���n����������һ��
			continue;
		for (int m = j - 1; m <= j + 1 && m < 26; m++)//ȷ���в�Խ��
		{
			if (m < 0 || (n == i && m == j))//���n�������̻��ߵ���ԭ�������Ӿ���һ��
				continue;
			if (bomb[n][m] == '*')
				sum++;
		}
	}
	return sum;              
}
void creatflag(int i, int j, char bomb[][26])
{
	if (bomb[i][j] != '*')//�����λ�ò���ը��
	{
		bomb[i][j] = countbomb(i,j,bomb)+'0';
	}
}
int main()
{
	srand((unsigned)time(NULL));//��ʼ������
	char bomb[10][26] = { 0 };
	for (int i = 0; i < 50; i++)
		if (!creatbomb(bomb))//�������ʧ�ܾͽ�i-1
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