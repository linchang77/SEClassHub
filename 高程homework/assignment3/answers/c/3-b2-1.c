/*2250420 软工 陈君*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a;
	int b;
	printf("请输入一个[1..30000]间的整数:\n"); 
	scanf("%d",&a);
	printf("万位 : %d\n",a/10000);
	b=a/1000%10;
	printf("千位 : %d\n",b);
	b=a/100%10;
	printf("百位 : %d\n",b);
	b=a/10%10;
	printf("十位 : %d\n",b);
	b=a%10;
	printf("个位 : %d",b);
	
	return 0;
 } 
