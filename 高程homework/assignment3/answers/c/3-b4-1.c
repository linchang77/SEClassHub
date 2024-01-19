/*2250420 软工 陈君*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#define PI 3.14159
int main()
{
	int a;
	int b;
	double angle;
	printf("请输入三角形的两边及其夹角(角度)\n");
	scanf("%d %d %lf",&a,&b,&angle);
	printf("三角形面积为 :%.3lf\n",a*b*sin(angle*PI/180)/2);
	return 0;
 } 
