/* �� 2250420 �¾� */
#include<iostream>
#include<string>
using namespace std;
void input(string num[10], string name[10], int score[10])
{
	for (int i = 0; i < 10; i++)
	{
		cout << "�������" << i + 1 << "���˵�ѧ�š��������ɼ�" << endl;
		cin >> num[i];
		cin >> name[i];
		cin >> score[i];
	}
}
void swap(string num[10], string name[10], int score[10], int x, int y)
{
	string temp_num;
	string temp_name;
	int temp_score;
	temp_num = num[x];
	num[x] = num[y];
	num[y] = temp_num;

	temp_name = name[x];
	name[x] = name[y];
	name[y] = temp_name;

	temp_score = score[x];
	score[x] = score[y];
	score[y] = temp_score;
}
void sort(string num[10], string name[10], int score[10])
{
	for (int i = 0; i < 9; i++)
		for (int j = 9; j > i; j--)
			if (num[j]< num[j - 1])
				swap(num, name, score, j, j - 1);
}
void putout(string num[10], string name[10], int score[10])
{
	cout << "ȫ��ѧ��(ѧ������):" << endl;
	for (int i = 0; i < 10; i++)
		cout << name[i] << " " << num[i] << " " << score[i] << endl;
}
int main()
{
	string num[10];
	string name[10];
	int score[10];
	input(num, name, score);
	sort(num, name, score);
	cout << endl;
	putout(num, name, score);
	return 0;
}