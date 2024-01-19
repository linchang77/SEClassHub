/*2250420 软工 陈君*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
int days(int leap_year,int month,int day)
{
	int array[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},
	                  {31,29,31,30,31,30,31,31,30,31,30,31}};
	int sum=0;
	for(int i=0;i<month-1;i++)
	    sum+=array[leap_year][i];
	return sum+=day;
}
int main()
{
	int array[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},
	                  {31,29,31,30,31,30,31,31,30,31,30,31}};
	int year,month,day;
		printf("请输入年，月，日\n");
	scanf("%d%d%d",&year,&month,&day);
	bool leap_year=((year%4==0&&year%100!=0)||(year%400==0));
	if(month>12||month<1)
	{
	    printf("输入错误-月份不正确\n");
		return 0;		
    }    	
	if(array[leap_year][month-1]<day||day<=0)
	{
		printf("输入错误-日与月的关系非法\n");
		return 0;
	}
	printf("%d-%d-%-d是%d年的第%d天\n",year,month,day,year,days(leap_year,month,day));
	
return 0;
}
