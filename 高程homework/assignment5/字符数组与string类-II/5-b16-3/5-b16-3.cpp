/* 软工 2250420 陈君 */
#include<iostream>
#include<string>
using namespace std;
void input(string num[10], string name[10], int score[10])
{
	for (int i = 0; i < 10; i++)
	{
		cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
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
	cout << "全部学生(学号升序):" << endl;
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