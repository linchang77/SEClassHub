/*2250420 �� �¾�*/
#include<iostream>
#include<iomanip>
using namespace std; 
int main()
{
	int year,month;
	int week,count;
	 
	while (1) {
		cout << "���������(2000-2030)���·�(1-12) : ";
		cin >> year>>month;   
		if(cin.good()==0||year>2030||year<2000||month>12||month<0)
		{
			while(getchar()!='\n')
			     ;
		    cin.clear();
		    puts("����Ƿ�������������");
		}
		else 
		{
			while(getchar()!='\n')
			     ;
			break;
		}
	}
	
	while (1) {
		cout<<"������"<<year<<"��"<<month<<"��1�յ�����(0-6��ʾ������-������) : ";
		cin >> week;   
		if(cin.good()==0||week<0||week>6)
		{
			while(getchar()!='\n')
			     ;
		    cin.clear();
		    cout << "����Ƿ�������������" << endl;
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
	cout<<year<<"��"<<month<<"�µ�����Ϊ:"<<endl;
	if(leap_year&&month==2)
	    count=29;
	else if(!leap_year&&month==2)
	    count=28;
	else if(month==1||month==3||month==5||month==7||
	        month==8||month==10||month==12)
			count=31;
	else
	    count=30;
	cout<<"������  ����һ  ���ڶ�  ������  ������  ������  ������"<<endl;
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
