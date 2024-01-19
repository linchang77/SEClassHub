/*2250420 软工 陈君*/
#include<iostream>
using namespace std; 
int main()
{
	int year,month,day;
	cout<<"请输入年，月，日"<<endl;
	cin>>year>>month>>day;
	bool leap_year=((year%4==0&&year%100!=0)||(year%400==0));
	if(leap_year)
	{
		switch(month)
		{
			case 1:
				if(day<=0||day>31)
			    {
					cout<<"输入错误-日与月的关系非法"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day << "天" << endl;
				break; 
			case 2:
				if(day<=0||day>29)
			    {
					cout<<"输入错误-日与月的关系非法"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day+31 << "天" << endl;
				break; 
			case 3:
				if(day<=0||day>31)
			    {
					cout<<"输入错误-日与月的关系非法"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 29 << "天" << endl;
				break; 
			case 4:
				if(day<=0||day>30)
			    {
					cout<<"输入错误-日与月的关系非法"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 29 + 31 << "天" << endl;
				break;  
			case 5:
				if(day<=0||day>31)
			    {
					cout<<"输入错误-日与月的关系非法"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 29 + 31 + 30 << "天" << endl;
				break;  
			case 6:
				if(day<=0||day>30)
			    {
					cout<<"输入错误-日与月的关系非法"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 29 + 31 + 30 + 31 << "天" << endl;
				break;  
			case 7:
				if(day<=0||day>31)
			    {
					cout<<"输入错误-日与月的关系非法"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 29 + 31 + 30 + 31 + 30 << "天" << endl;
				break;  
			case 8:
				if(day<=0||day>31)
			    {
					cout<<"输入错误-日与月的关系非法"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 29 + 31 + 30 + 31 + 30 + 31 << "天" << endl;
				break;  
			case 9:
				if(day<=0||day>30)
			    {
					cout<<"输入错误-日与月的关系非法"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31  << "天" << endl;
				break;  
			case 10:
				if(day<=0||day>31)
			    {
					cout<<"输入错误-日与月的关系非法"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 << "天" << endl;
				break; 
			case 11:
				if(day<=0||day>30)
			    {
					cout<<"输入错误-日与月的关系非法"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 << "天" << endl;
				break;  
			case 12:
				if(day<=0||day>31)
			    {
					cout<<"输入错误-日与月的关系非法"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 << "天" << endl;
				break;  
			default:
				cout<<"输入错误-月份不正确"<<endl;					
		}						
	}
	else
	{
		switch(month)
		{
			case 1:
				if(day<=0||day>31)
			    {
					cout<<"输入错误-日与月的关系非法"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day << "天" << endl;
				break; 
			case 2:
				if(day<=0||day>28)
			    {
					cout<<"输入错误-日与月的关系非法"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day+31 << "天" << endl;
				break; 
			case 3:
				if(day<=0||day>31)
			    {
					cout<<"输入错误-日与月的关系非法"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 28 << "天" << endl;
				break; 
			case 4:
				if(day<=0||day>30)
			    {
					cout<<"输入错误-日与月的关系非法"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 28 + 31 << "天" << endl;
				break;  
			case 5:
				if(day<=0||day>31)
			    {
					cout<<"输入错误-日与月的关系非法"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 28 + 31 + 30 << "天" << endl;
				break;  
			case 6:
				if(day<=0||day>30)
			    {
					cout<<"输入错误-日与月的关系非法"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 28 + 31 + 30 + 31 << "天" << endl;
				break;  
			case 7:
				if(day<=0||day>31)
			    {
					cout<<"输入错误-日与月的关系非法"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 28 + 31 + 30 + 31 + 30 << "天" << endl;
				break;  
			case 8:
				if(day<=0||day>31)
			    {
					cout<<"输入错误-日与月的关系非法"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 28 + 31 + 30 + 31 + 30 + 31 << "天" << endl;
				break;  
			case 9:
				if(day<=0||day>30)
			    {
					cout<<"输入错误-日与月的关系非法"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31  << "天" << endl;
				break;  
			case 10:
				if(day<=0||day>31)
			    {
					cout<<"输入错误-日与月的关系非法"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 << "天" << endl;
				break; 
			case 11:
				if(day<=0||day>30)
			    {
					cout<<"输入错误-日与月的关系非法"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 << "天" << endl;
				break;  
			case 12:
				if(day<=0||day>31)
			    {
					cout<<"输入错误-日与月的关系非法"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 << "天" << endl;
				break;  
			default:
				cout<<"输入错误-月份不正确"<<endl;					
		}						
}
return 0;
}
