/* 2250420 �¾� �� */
#include <iostream>
using namespace std;

#define  N  80	

bool judge(char str[N])
{
	char* pre = str;
	char* last = str + strlen(str) - 1;
	while (pre < last)
	{
		if (*pre != *last)
			return false;
		pre++;
		last--;
	}
	return true;
}

int main()
{

	char str[80];
	cout << "������һ������С��80���ַ��������Ĵ���" << endl;
	fgets(str, N, stdin);
	*(str + strlen(str) - 1) = '\0';//����س�
	if (judge(str))
		cout << "yes";
	else
		cout << "no";
	cout << endl;
	return 0;
}