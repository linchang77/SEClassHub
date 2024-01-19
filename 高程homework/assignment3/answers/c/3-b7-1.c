/*2250420 软工 陈君*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h> 
int main()
{
	printf("请输入找零值：\n");
	double cash;
	scanf("%lf",&cash);
	if(cash<0.01||cash>=100)
	{
		printf("输入错误，请重新输入\n");
		return 0;
	}
	int a = (int)cash;
	int b = round((cash - a) * 100);
	int count = 0;

	int a1 = a / 50;
	int a2 = a % 50 / 20;
	int a3 = a % 50 % 20 / 10;
	int a4 = a % 50 % 20 % 10 / 5;
	int a5 = a % 50 % 20 % 10 % 5;

	int b1 = b / 50;
	int b2 = b % 50 / 10;
	int b3 = b % 50 % 10 / 5;
	int b4 = b % 50 % 10 % 5 / 2;
	int b5 = b % 50 % 10 % 5 % 2;

	if (a1 != 0)
		count+=a1;
	if (a2 != 0)
		count += a2;
	if (a3 != 0)
		count += a3;
	if (a4 != 0)
		count += a4;
	if (a5 != 0)
		count += a5;
	if (b1 != 0)
		count+=b1;
	if (b2 != 0)
		count += b2;
	if (b3 != 0)
		count += b3;
	if (b4 != 0)
		count+=b4;
	if (b5 != 0)
		count+=b5;
	printf("共%d张找零，具体如下：\n",count);
	if (a1 != 0)
	    printf("50元 : %d张\n",a1);
	if (a2 != 0)
	    printf("20元 : %d张\n",a2);
	if (a3 != 0)
		printf("10元 : %d张\n",a3);
	if (a4 != 0)
		printf("5元  : %d张\n",a4);
	if (a5 != 0)
		printf("1元  : %d张\n",a5);
	if (b1 != 0)
		printf("5角  : %d张\n",b1);
	if (b2 != 0)
		printf("1角  : %d张\n",b2);
	if (b3 != 0)
		printf("5分  : %d张\n",b3);
	if (b4 != 0)
		printf("2分  : %d张\n",b4);
	if (b5 != 0)
		printf("1分  : %d张\n",b5);

	return 0;
}
