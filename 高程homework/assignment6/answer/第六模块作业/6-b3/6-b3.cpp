/* 2250420 陈君 软工 */
#include <iostream>
using namespace std;

#define  N  34

unsigned int power(int base, int i)
{
	unsigned int temp = 1;
	if (i == 0)
		return 1;
	for (; i > 0; i--)
		temp *= base;
	return temp;
}
void change(char* str)
{
	unsigned int temp = 0;
	char* p = str + strlen(str) - 1;//取到str的最后一位
	int i = 0;
	while (1)
	{
		temp += (*p-'0') * power(2, i);
		i++;
		if (p == str)
			break;
		p--;
	}
	//输出temp
	while (temp > 0)
	{
		*str = (temp % 10+'0');
		temp=temp / 10;
		str++;
	}
	*str = '\0';
}
int main()
{

	char str[80];
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	fgets(str, N, stdin);
	*(str + strlen(str) - 1) = '\0';//处理回车
	change(str);
	char* p = str + strlen(str) - 1;//取到str的最后一位
	while (1)
	{
		cout << *p;
		if (p == str)
			break;
		p--;
	}
	cout << endl;
	return 0;
}