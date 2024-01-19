/* 软工 2250420 陈君 */
#include<iostream>
#include<string>
#include<time.h>
using namespace std;
static const char other[] = "!@#$%^&*-_=+,.?";
void create(int length, int upword, int lowword, int number, int others)
{
	int c_length = 0;
	int c_upword = 0;
	int c_lowword = 0;
	int c_number = 0;
	int c_others = 0;
	while (c_length < length)
	{
		switch (rand() % 4)
		{
		case 0:
			if (c_upword > upword)
				break;
			else {
				cout << (char)('A' + rand() % 26);
				c_upword++;
				c_length++;
			}
			break;
		case 1:
			if (c_lowword > lowword)
				break;
			else {
				cout << (char)('a' + rand() % 26);
				c_lowword++;
				c_length++;
			}
			break;
		case 2:
			if (c_number > number)
				break;
			else {
				cout << (char)('0' + rand() % 10);
				c_number++;
				c_length++;
			}
			break;
		case 3:
			if (c_others > others)
				break;
			else {
				cout << other[rand() % 15];
				c_others++;
				c_length++;
			}
			break;
		}
	}
	cout << endl;


}
int main()
{
	srand((unsigned int)time(0));
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	int length, upword, lowword, number, others;

	cin >> length;
	if (!cin.good())
	{
		cout << "输入非法" << endl;
		exit(1);
	}
	cin >> upword;
	if (!cin.good())
	{
		cout << "输入非法" << endl;
		exit(1);
	}
	cin >> lowword;
	if (!cin.good())
	{
		cout << "输入非法" << endl;
		exit(1);
	}
	cin >> number;
	if (!cin.good())
	{
		cout << "输入非法" << endl;
		exit(1);
	}
	cin >> others;
	if (!cin.good())
	{
		cout << "输入非法" << endl;
		exit(1);
	}
	if (length > 16 || length < 12)
	{
		cout << "密码长度[" << length << "]不正确" << endl;
		exit(1);
	}
	if (upword < 2)
	{
		cout << "大写字母个数[" << upword << "]不正确" << endl;
		exit(1);
	}
	if (upword < 2)
	{
		cout << "大写字母个数[" << upword << "]不正确" << endl;
		exit(1);
	}
	if (lowword < 2)
	{
		cout << "小写字母个数[" << lowword << "]不正确" << endl;
		exit(1);
	}
	if (number < 2)
	{
		cout << "数字个数[" << number << "]不正确" << endl;
		exit(1);
	}
	if (others < 2)
	{
		cout << "其它符号个数[" << others << "]不正确" << endl;
		exit(1);
	}
	if (upword + lowword + number + others > length)
	{
		cout << "所有字符类型之和[" << upword << "+" << lowword << "+" << number << "+" << others << "]大于总密码长度[" << length << "]" << endl;
		exit(1);
	}
	for (int i = 0; i < 10; i++)
	{
		create(length, upword, lowword, number, others);
	}

	return 0;
}