/* 2250420 陈君 软工 */
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
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	fgets(str, N, stdin);
	*(str + strlen(str) - 1) = '\0';//处理回车
	if (judge(str))
		cout << "yes";
	else
		cout << "no";
	cout << endl;
	return 0;
}