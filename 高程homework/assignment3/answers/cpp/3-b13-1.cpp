/*2250420 软工 陈君*/
#include<iostream>
#include<iomanip>
using namespace std; 
int main()
{
	int year,month;
	int week,count;
	 
	while (1) {
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> year>>month;   
		if(cin.good()==0||year>2030||year<2000||month>12||month<0)
		{
			while(getchar()!='\n')
			     ;
		    cin.clear();
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
		cout<<"请输入"<<year<<"年"<<month<<"月1日的星期(0-6表示星期日-星期六) : ";
		cin >> week;   
		if(cin.good()==0||week<0||week>6)
		{
			while(getchar()!='\n')
			     ;
		    cin.clear();
		    cout << "输入非法，请重新输入" << endl;
		}
		else 
		{
			while(getchar()!='\n')
			     ;
			break;
		}
	}
	cout<<endl; 
	bool leap_year=((year%4==0&&year%100!=0)||(year%400==0));
	cout<<year<<"年"<<month<<"月的月历为:"<<endl;
	if(leap_year&&month==2)
	    count=29;
	else if(!leap_year&&month==2)
	    count=28;
	else if(month==1||month==3||month==5||month==7||
	        month==8||month==10||month==12)
			count=31;
	else
	    count=30;
	cout<<"星期日  星期一  星期二  星期三  星期四  星期五  星期六"<<endl;
	int i=1;
	cout<<setw(8*week+4)<<i;
	i++;
	for(int j=0;j<6-week;j++)
        {
            cout<<setw(8)<<i;
            i++;
		}
    count=count-7+week;
    int n=0;
    while(count>0)
    {
    	if(n%7==0)
        {
        	cout << "    "<<endl << setw(4)<<i;
        	i++;
        	count--;
        	n++;
		}
		if(count<=0)
		break;
		cout << setw(8) << i;
        i++;
        count--;
        n++;
	}
	cout<<"    ";
	cout<<endl;
return 0;
}
