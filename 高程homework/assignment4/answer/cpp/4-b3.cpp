/*2250420 �� �¾�*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
/***************************************************************************
  �������ƣ�zeller 
  ��    �ܣ�������� 
  ���������
  �� �� ֵ��int 
  ˵    ��������������ת��Ϊ���� 
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
 void calendar(int year,int month,bool leap_year,int week)
 {
 	int count;
 	cout<<endl;
 	cout<<year<<"��"<<month<<"��"<<endl;
	if(leap_year&&month==2)
	    count=29;
	else if(!leap_year&&month==2)
	    count=28;
	else if(month==1||month==3||month==5||month==7||
	        month==8||month==10||month==12)
			count=31;
	else
	    count=30;
	cout<<"======================================================"<<endl;
	cout<<"������  ����һ  ���ڶ�  ������  ������  ������  ������"<<endl;
	cout<<"======================================================"<<endl;
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
 }
 int main()
 {
    int year,month;
	
	int flag_year=0;
	int flag_month=0;
	int flag=0;
	bool leap;
	while (1) //�������� 
	{
		cout << "��������[1900-2100]����"<<endl;
		cin >> year >> month;
		leap=((year % 4 == 0 && year % 100 != 0 )|| year % 400 == 0);
		if(!cin.good()) 
			flag=1;
		else if(year<1900||year> 2100)
			flag_year=1;
		else if(month < 1 || month>12)
			flag_month=1;
		if(flag==0&&flag_year==0&&flag_month==0)
		    break;
		if(flag==1)
		    cout << "�����������������" << endl;
		else if(flag_year==1)
		    cout << "��ݲ���ȷ������������" << endl;
		else if(flag_month==1)
		    cout << "�·ݲ���ȷ������������" << endl;
	    while (getchar() != '\n')
					;
				cin.clear();
			
		 flag_year=0;
	     flag_month=0;
	     flag=0;
	 	continue;
	}						
	int n= zeller(year,month,1);
	calendar(year,month,leap,n);
  	cout<<endl;
	return 0;
 }
