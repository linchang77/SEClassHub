/*2250420 �� �¾�*/
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
		printf("�������꣬�£���\n");
	scanf("%d%d%d",&year,&month,&day);
	bool leap_year=((year%4==0&&year%100!=0)||(year%400==0));
	if(month>12||month<1)
	{
	    printf("�������-�·ݲ���ȷ\n");
		return 0;		
    }    	
	if(array[leap_year][month-1]<day||day<=0)
	{
		printf("�������-�����µĹ�ϵ�Ƿ�\n");
		return 0;
	}
	printf("%d-%d-%-d��%d��ĵ�%d��\n",year,month,day,year,days(leap_year,month,day));
	
return 0;
}
