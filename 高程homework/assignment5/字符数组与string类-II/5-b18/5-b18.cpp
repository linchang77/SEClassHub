/* Èí¹¤ 2250420 ³Â¾ý */
#include<iostream>
using namespace std;
void input(char words[10][17])
{
	for (int i = 0; i < 10; i++)
	{
		cin.getline(words[i], 20, '\n');
	}
}
bool judge(char words[10][17], int length, int upword, int lowword, int number, int others)
{
	for (int i = 0; i < 10; i++)
	{
		int c_length = 0;
		int c_upword = 0;
		int c_lowword = 0;
		int c_number = 0;
		int c_others = 0;
		for (int j = 0; words[i][j] != '\0'; j++)
		{
			if (words[i][j] >= 'A' && words[i][j] <= 'Z')
				c_upword++;
			else if (words[i][j] <= 'z' && words[i][j] >= 'a')
				c_lowword++;
			else if (words[i][j] <= '9' && words[i][j] >= '0')
				c_number++;
			else
				c_others++;
			c_length++;
		}
		if (c_length != length || c_upword < upword || c_lowword < lowword || c_number < number || c_others < others)
			return false;
	}
	return true;
}
int main()
{

	char words[10][17];
	while (getchar() != '\n')
		;
	int length = 0;
	int upword = 0;
	int lowword = 0;
	int number = 0;
	int others = 0;
	cin >> length;
	if (!cin.good())
	{
		cout << "´íÎó" << endl;
		exit(1);
	}
	cin >> upword;
	if (!cin.good())
	{
		cout << "´íÎó" << endl;
		exit(1);
	}
	cin >> lowword;
	if (!cin.good())
	{
		cout << "´íÎó" << endl;
		exit(1);
	}
	cin >> number;
	if (!cin.good())
	{
		cout << "´íÎó" << endl;
		exit(1);
	}
	cin >> others;
	if (!cin.good())
	{
		cout << "´íÎó" << endl;
		exit(1);
	}
	while (getchar() != '\n')
		;
	if (length > 16 || length < 12)
	{
		cout << "´íÎó" << endl;
		exit(1);
	}
	if (upword < 2)
	{
		cout << "´íÎó" << endl;
		exit(1);
	}
	if (upword < 2)
	{
		cout << "´íÎó" << endl;
		exit(1);
	}
	if (lowword < 2)
	{
		cout << "´íÎó" << endl;
		exit(1);
	}
	if (number < 2)
	{
		cout << "´íÎó" << endl;
		exit(1);
	}
	if (others < 2)
	{
		cout << "´íÎó" << endl;
		exit(1);
	}
	if (upword + lowword + number + others > length)
	{
		cout << "´íÎó" << endl;
		exit(1);
	}
	input(words);
	if (judge(words, length, upword, lowword, number, others))
		cout<<"ÕýÈ·"<<endl;
	else 
		cout << "´íÎó" << endl;
	
	return 0;
}
/*ÇëÊäÈëÃÜÂë³¤¶È(12-16)£¬ ´óÐ´×ÖÄ¸¸öÊý(¡Ý2)£¬ Ð¡Ð´×ÖÄ¸¸öÊý(¡Ý2)£¬ Êý×Ö¸öÊý(¡Ý2)£¬ ÆäËü·ûºÅ¸öÊý(¡Ý2)
12 2 2 2 2
12 2 2 2 2
1v4MY!E*6tEc
%WMyR26?,ul7
O9_vgWQwQ9$%
rNh298@6JYF@
NMzfT$83xl$T
k8A&*uFKfi6t
GL7BF$FPm=x2
W?u78E@vlA5U
l9db_UQ^8#JN
eF9N@K^G%5hl*/