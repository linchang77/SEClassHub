/* �� 2250420 �¾� */
#include<iostream>
using namespace std;
void input(char words[3][128])
{
	for (int i = 0; i < 3; i++)
	{
		cout << "�������"<<i+1<<"��" << endl;
		cin.getline(words[i],128,'\n');
	}
}

int main()
{
	char words[3][128];
	input(words);
	int upword = 0;
	int lowword = 0;
	int number = 0;
	int space = 0;
	int others = 0;
	for (int i = 0; i < 3; i ++ )
	{
		for (int j = 0; words[i][j] != '\0'; j++)
		{
			if (words[i][j] >= 'A' && words[i][j] <= 'Z')
				upword++;
			else if (words[i][j] <= 'z' && words[i][j] >= 'a')
				lowword++;
			else if (words[i][j] <= '9' && words[i][j] >= '0')
				number++;
			else if (words[i][j] == ' ')
				space++;
			else
				others++;

		}
	}
	cout << "��д : " << upword<<endl;
	cout << "Сд : " << lowword<<endl;
	cout << "���� : " << number<<endl;
	cout << "�ո� : " << space<<endl;
	cout << "���� : " << others<<endl;
	return 0;
}