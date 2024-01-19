/*2250420 软工 陈君*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define PI 3.14159
int main()
{
	double hight, radius;
	printf("请输入半径和高度\n");
	scanf("%lf %lf", &hight, &radius);
	printf("圆周长     : %.2lf\n", 2 * PI*radius);
	printf("圆面积     : %.2lf\n", radius * radius * PI);
	printf("圆球表面积 : %.2lf\n", 4 * radius * radius * PI);
	printf("圆球体积   : %.2lf\n", PI * radius * radius * radius * 4 / 3);
	printf("圆柱体积   : %.2lf", radius * radius * PI * hight);


	return 0;
}
