/*2250420 �� �¾�*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h> 
int main()
{
	printf("����������ֵ��\n");
	double cash;
	scanf("%lf",&cash);
	if(cash<0.01||cash>=100)
	{
		printf("�����������������\n");
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
	printf("��%d�����㣬�������£�\n",count);
	if (a1 != 0)
	    printf("50Ԫ : %d��\n",a1);
	if (a2 != 0)
	    printf("20Ԫ : %d��\n",a2);
	if (a3 != 0)
		printf("10Ԫ : %d��\n",a3);
	if (a4 != 0)
		printf("5Ԫ  : %d��\n",a4);
	if (a5 != 0)
		printf("1Ԫ  : %d��\n",a5);
	if (b1 != 0)
		printf("5��  : %d��\n",b1);
	if (b2 != 0)
		printf("1��  : %d��\n",b2);
	if (b3 != 0)
		printf("5��  : %d��\n",b3);
	if (b4 != 0)
		printf("2��  : %d��\n",b4);
	if (b5 != 0)
		printf("1��  : %d��\n",b5);

	return 0;
}
