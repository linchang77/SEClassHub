/*2250420 �� �¾�*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a;
	int b;
	printf("������һ��[1..30000]�������:\n"); 
	scanf("%d",&a);
	printf("��λ : %d\n",a/10000);
	b=a/1000%10;
	printf("ǧλ : %d\n",b);
	b=a/100%10;
	printf("��λ : %d\n",b);
	b=a/10%10;
	printf("ʮλ : %d\n",b);
	b=a%10;
	printf("��λ : %d",b);
	
	return 0;
 } 
