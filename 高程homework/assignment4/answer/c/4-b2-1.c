/*2250420 软工 陈君*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdbool.h>
/***************************************************************************
  函数名称：zeller 
  功    能：输出星期 
  输入参数：
  返 回 值：int 
  说    明：输入年月日转化为星期 
***************************************************************************/
int zeller(int y,int m,int d)
{
	int c;
	if(m<3)
	{
		y--;
		m=m+12;
		c=y/100;
	    y=y%100;
	}
	else
	{
		c=y/100;
	    y=y%100;
	}
	
	int w=y+(y/4)+c/4-2*c+13*(m+1)/5+d-1;
	while(1)
	{
		if(w>0)
		break;
		w=w+7;
		
	}
	return w%7;
 } 
 int main()
 {
    int year,month,day,week;
	
	int flag_year=0;
	int flag_month=0;
	int flag_day=0;
	int flag=0;
	bool leap;
	while (1) 
	{
		printf("请输入年[1900-2100]、月、日：\n");
		int tags=scanf("%d%d%d",&year,&month,&day);
		leap=((year % 4 == 0 && year % 100 != 0 )|| year % 400 == 0);
		if(tags!=3) 
			flag=1;
		else if(year<1900||year> 2100)
			flag_year=1;
		else if(month < 1 || month>12)
			flag_month=1;
		else if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)&&(day < 1 || day>31))
		    flag_day=1;
		else if((month == 4 || month == 6 || month == 9 || month == 11)&&(day < 1 || day>30))
		    flag_day=1;
		else if(month==2&&leap&&(day < 1 || day>29))
		    flag_day=1;
		else if(!leap&&month==2&&(day<1||day>28))
		    flag_day=1;
		if(flag==0&&flag_year==0&&flag_month==0&&flag_day==0)
		    break;
		if(flag==1)
		    printf("输入错误，请重新输入\n");
		else if(flag_year==1)
			printf("年份不正确，请重新输入\n");
		else if(flag_month==1)
		    printf("月份不正确，请重新输入\n");
		else if(flag_day==1)
	        printf("日不正确，请重新输入\n");
	    while (getchar() != '\n')
					;
		 flag_year=0;
	     flag_month=0;
	     flag_day=0;
	     flag=0;
	 	continue;
	}						
	int n= zeller(year,month,day);
	switch (n%7)
	{
			case 0:
				printf("星期日\n");
				break;
			case 1:
				printf("星期一\n");
				break;
			case 2:
				printf("星期二\n");
				break;
			case 3:
				printf("星期三\n");
				break;
			case 4:
				printf("星期四\n");
				break;
			case 5:
				printf("星期五\n");
				break;
			case 6:
				printf("星期六\n");
				break;
			default:
				break;
		}
	return 0;
 }
