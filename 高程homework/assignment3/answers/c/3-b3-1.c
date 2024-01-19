/*2250420 软工 陈君*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
int main()
{
	int year,month,day;
	printf("请输入年，月，日\n");
	scanf("%d%d%d",&year,&month,&day);
	bool leap_year=((year%4==0&&year%100!=0)||(year%400==0));
	if(leap_year)
	{
		switch(month)
		{
			case 1:
				if(day<=0||day>=31)
			    {
					printf("输入错误-日与月的关系非法\n");
			        break;
				}
				printf("%d-%d-%-d是%d年的第%d天\n",year,month,day,year,0+day);
				break; 
			case 2:
				if(day<=0||day>=29)
			    {
				    printf("输入错误-日与月的关系非法\n");
			        break;
				} 
				printf("%d-%d-%-d是%d年的第%d天\n",year,month,day,year,31+day);
				break; 
			case 3:
				if(day<=0||day>=31)
			    {
				    printf("输入错误-日与月的关系非法\n");
			        break;
				} 
				printf("%d-%d-%-d是%d年的第%d天\n",year,month,day,year,31+29+day);
				break; 
			case 4:
				if(day<=0||day>=30)
			    {
				    printf("输入错误-日与月的关系非法\n");
			        break;
				} 
				printf("%d-%d-%-d是%d年的第%d天\n",year,month,day,year,31+29+31+day);
				break; 
			case 5:
				if(day<=0||day>=31)
			    {
				    printf("输入错误-日与月的关系非法\n");
			        break;
				} 
				printf("%d-%d-%-d是%d年的第%d天\n",year,month,day,year,31+29+31+30+day);
				break; 
			case 6:
				if(day<=0||day>=30)
			    {
				    printf("输入错误-日与月的关系非法\n");
			        break;
				} 
				printf("%d-%d-%-d是%d年的第%d天\n",year,month,day,year,31+29+31+30+31+day);
				break; 
			case 7:
				if(day<=0||day>=31)
			    {
				    printf("输入错误-日与月的关系非法\n");
			        break;
				} 
				printf("%d-%d-%-d是%d年的第%d天\n",year,month,day,year,31+29+31+30+31+30+day);
				break; 
			case 8:
				if(day<=0||day>=31)
			    {
				    printf("输入错误-日与月的关系非法\n");
			        break;
				} 
				printf("%d-%d-%-d是%d年的第%d天\n",year,month,day,year,31+29+31+30+31+30+31+day);
				break; 
			case 9:
				if(day<=0||day>=30)
			    {
				    printf("输入错误-日与月的关系非法\n");
			        break;
				} 
				printf("%d-%d-%-d是%d年的第%d天\n",year,month,day,year,31+29+31+30+31+30+31+31+day);
				break; 
			case 10:
				if(day<=0||day>=31)
			    {
				    printf("输入错误-日与月的关系非法\n");
			        break;
				} 
				printf("%d-%d-%-d是%d年的第%d天\n",year,month,day,year,31+29+31+30+31+30+31+31+30+day);
				break; 
			case 11:
				if(day<=0||day>=30)
			    {
				    printf("输入错误-日与月的关系非法\n");
			        break;
				} 
				printf("%d-%d-%-d是%d年的第%d天\n",year,month,day,year,31+29+31+30+31+30+31+31+30+31+day);
				break; 
			case 12:
				if(day<=0||day>=31)
			    {
				    printf("输入错误-日与月的关系非法\n");
			        break;
				} 
				printf("%d-%d-%-d是%d年的第%d天\n",year,month,day,year,31+29+31+30+31+30+31+31+30+31+30+day);
				break; 
			default:
				printf("输入错误-月份不正确\n");						
		}
	}
	else
	{
		switch(month)
		{
			case 1:
				if(day<=0||day>=31)
			    {
					printf("输入错误-日与月的关系非法\n");
			        break;
				}
			        break;
				printf("%d-%d-%-d是%d年的第%d天\n",year,month,day,year,0+day);
				break; 
			case 2:
				if(day<=0||day>=28)
			    {
				    printf("输入错误-日与月的关系非法\n");
			        break;
				} 
				printf("%d-%d-%-d是%d年的第%d天\n",year,month,day,year,31+day);
				break; 
			case 3:
				if(day<=0||day>=31)
			    {
				    printf("输入错误-日与月的关系非法\n");
			        break;
				} 
				printf("%d-%d-%-d是%d年的第%d天\n",year,month,day,year,31+28+day);
				break; 
			case 4:
				if(day<=0||day>=30)
			    {
				    printf("输入错误-日与月的关系非法\n");
			        break;
				} 
				printf("%d-%d-%-d是%d年的第%d天\n",year,month,day,year,31+28+31+day);
				break; 
			case 5:
				if(day<=0||day>=31)
			    {
				    printf("输入错误-日与月的关系非法\n");
			        break;
				} 
				printf("%d-%d-%-d是%d年的第%d天\n",year,month,day,year,31+28+31+30+day);
				break; 
			case 6:
				if(day<=0||day>=30)
			    {
				    printf("输入错误-日与月的关系非法\n");
			        break;
				} 
				printf("%d-%d-%-d是%d年的第%d天\n",year,month,day,year,31+28+31+30+31+day);
				break; 
			case 7:
				if(day<=0||day>=31)
			    {
				    printf("输入错误-日与月的关系非法\n");
			        break;
				} 
				printf("%d-%d-%-d是%d年的第%d天\n",year,month,day,year,31+28+31+30+31+30+day);
				break; 
			case 8:
				if(day<=0||day>=31)
			    {
				    printf("输入错误-日与月的关系非法\n");
			        break;
				} 
				printf("%d-%d-%-d是%d年的第%d天\n",year,month,day,year,31+28+31+30+31+30+31+day);
				break; 
			case 9:
				if(day<=0||day>=30)
			    {
				    printf("输入错误-日与月的关系非法\n");
			        break;
				} 
				printf("%d-%d-%-d是%d年的第%d天\n",year,month,day,year,31+28+31+30+31+30+31+31+day);
				break; 
			case 10:
				if(day<=0||day>=31)
			    {
				    printf("输入错误-日与月的关系非法\n");
			        break;
				} 
				printf("%d-%d-%-d是%d年的第%d天\n",year,month,day,year,31+28+31+30+31+30+31+31+30+day);
				break; 
			case 11:
				if(day<=0||day>=30)
			    {
				    printf("输入错误-日与月的关系非法\n");
			        break;
				} 
				printf("%d-%d-%-d是%d年的第%d天\n",year,month,day,year,31+28+31+30+31+30+31+31+30+31+day);
				break; 
			case 12:
				if(day<=0||day>=31)
			    {
				    printf("输入错误-日与月的关系非法\n");
			        break;
				} 
				printf("%d-%d-%-d是%d年的第%d天\n",year,month,day,year,31+28+31+30+31+30+31+31+30+31+30+day);
				break; 
			default:
			    printf("输入错误-月份不正确\n");						
		}						
}
return 0;
}
