/*2250420 �� �¾�*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#define PI 3.14159
int main()
{
	int a;
	int b;
	double angle;
	printf("�����������ε����߼���н�(�Ƕ�)\n");
	scanf("%d %d %lf",&a,&b,&angle);
	printf("���������Ϊ :%.3lf\n",a*b*sin(angle*PI/180)/2);
	return 0;
 } 
