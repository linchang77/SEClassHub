/* 软工 2250420 陈君 */
#include<iostream>
using namespace std;
void input(char words[3][128])
{
	for (int i = 0; i < 3; i++)
	{
		cout << "请输入第"<<i+1<<"行" << endl;
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
	cout << "大写 : " << upword<<endl;
	cout << "小写 : " << lowword<<endl;
	cout << "数字 : " << number<<endl;
	cout << "空格 : " << space<<endl;
	cout << "其它 : " << others<<endl;
	return 0;
}