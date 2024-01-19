/* 2250420 陈君 软工*/
#include <iostream>
using namespace std;

/***************************************************************************
  函数名称：judge
  功    能：判断这个数是否是基数的幂
  输入参数：int num,int base
  返 回 值：返回被base除剩下的数
  说    明：
***************************************************************************/
int judge(int n, int base)
{
	int temp=1;
	while (n!=temp&&n>temp)
	{
		temp=temp*base;
	}
	if(temp==n)
	return 1;
	else 
	return 0;
}
int main()
{
	int n, base;
	int num = 0;

	int array[10000];
	for (int i = 0; i < 10000; i++)//初始化数组 
		array[i] = 0;
	cout << "请输入数据的个数[1..10000]" << endl;
	cin >> n;
	cout << "请输入" << n << "个正整数" << endl;
	for (int i = 0; i < n; i++)//输入数字 
		cin >> array[i];
	cout << "请输入基数[2..9]" << endl;
	cin >> base;

	for (int i = 0; i < n; i++)
		if (judge(array[i], base) == 1)
			num++;
	cout << n << "个数中基数8的幂的个数 : " << num << endl;
	return 0;
}

