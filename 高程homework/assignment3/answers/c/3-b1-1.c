/*2250420 �� �¾�*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define PI 3.14159
int main()
{
	double hight, radius;
	printf("������뾶�͸߶�\n");
	scanf("%lf %lf", &hight, &radius);
	printf("Բ�ܳ�     : %.2lf\n", 2 * PI*radius);
	printf("Բ���     : %.2lf\n", radius * radius * PI);
	printf("Բ������ : %.2lf\n", 4 * radius * radius * PI);
	printf("Բ�����   : %.2lf\n", PI * radius * radius * radius * 4 / 3);
	printf("Բ�����   : %.2lf", radius * radius * PI * hight);


	return 0;
}
