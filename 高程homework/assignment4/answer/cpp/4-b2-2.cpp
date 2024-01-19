/*2250420 软工 陈君*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
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
		cout << "请输入年[1900-2100]、月、日："<<endl;
		cin >> year >> month >> day;
		leap=((year % 4 == 0 && year % 100 != 0 )|| year % 400 == 0);
		if(!cin.good()) 
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
		    cout << "输入错误，请重新输入" << endl;
		else if(flag_year==1)
		    cout << "年份不正确，请重新输入" << endl;
		else if(flag_month==1)
		    cout << "月份不正确，请重新输入" << endl;
		else if(flag_day==1)
	        cout << "日不正确，请重新输入" << endl;
	    while (getchar() != '\n')
					;
				cin.clear();
			
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
				cout << "星期日" << endl;
				break;
			case 1:
				cout << "星期一" << endl;
				break;
			case 2:
				cout << "星期二" << endl;
				break;
			case 3:
				cout << "星期三" << endl;
				break;
			case 4:
				cout << "星期四" << endl;
				break;
			case 5:
				cout << "星期五" << endl;
				break;
			case 6:
				cout << "星期六" << endl;
				break;
			default:
				break;
		}
	return 0;
 }
