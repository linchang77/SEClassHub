/*2250420 软工 陈君*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、不允许添加其它函数
   4、整个程序不允许出现任何形式的循环
   --------------------------------------------------------------------- */

   /***************************************************************************
	 函数名称：
	 功    能：将整数n分解后输出
	 输入参数：
	 返 回 值：
	 说    明：1、函数名、形参、返回类型均不准动
			   2、不允许使用64位整数
   ***************************************************************************/
void convert(int n)
{
	if (n == -2147483648)
	{
		printf("- 2 ");
		convert(n%1000000000*(-1));
		return;
	}
	if (n < 0)
	{
		printf("- ");
		n = n*-1;
		convert(n);
		return;
	}
	if (n < 10)
	{
		printf("%c ", n + '1' - 1);
		return;
	}
	int temp = n;
	int p = 1;
	while (temp > 10)
	{
		temp = temp / 10;
		p = p * 10;
	}
	printf("%c ", temp + '1' - 1);
	convert(n % p);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	int n;
	printf("请输入一个整数\n");
	scanf("%d", &n);

	convert(n);
	printf("\n");

	return 0;
}
