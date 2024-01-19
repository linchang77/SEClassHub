/*2250420 软工 陈君*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int year,month;
	int week,count;
	 
	while (1) {
		printf("请输入年份(2000-2030)和月份(1-12) : ") ;		 
		if(scanf("%d%d",&year,&month)!=2||year>2030||year<2000||month>12||month<0)
		{
			while(getchar()!='\n')
			     ;
		    puts("输入非法，请重新输入");
		}
		else 
		{
			while(getchar()!='\n')
			     ;
			break;
		}
	}
	
	while (1) {
		printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ",year,month);
		if(scanf("%d",&week)!=1||week<0||week>6)
		{
			while(getchar()!='\n')
			     ;
		    printf("输入非法，请重新输入\n");
		}
		else 
		{
			while(getchar()!='\n')
			     ;
			break;
		}
	}
	printf("\n"); 
	int leap_year=((year%4==0&&year%100!=0)||(year%400==0));
    printf("%d年%d月的月历为:\n",year,month);
	if(leap_year&&month==2)
	    count=29;
	else if(!leap_year&&month==2)
	    count=28;
	else if(month==1||month==3||month==5||month==7||
	        month==8||month==10||month==12)
			count=31;
	else
	    count=30;
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
	int i=1;
	for(int j=0;j<week;j++)
	    printf("        "); 
	printf("%4d",i);
	i++;
	for(int j=0;j<6-week;j++)
        {
            printf("%8d",i);
            i++;
		}
    count=count-7+week;
    int n=0;
    while(count>0)
    {
    	if(n%7==0)
        {
        	printf("    \n%4d",i);
        	i++;
        	count--;
        	n++;
		}
		if(count<=0)
		break;
		printf("%8d",i);
        i++;
        count--;
        n++;
	}
	printf("    \n"); 
return 0;
}
