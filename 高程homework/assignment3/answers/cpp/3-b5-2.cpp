/*2250420 �� �¾�*/
#include<iostream>
using namespace std; 
int main()
{
	int year,month,day;
	cout<<"�������꣬�£���"<<endl;
	cin>>year>>month>>day;
	bool leap_year=((year%4==0&&year%100!=0)||(year%400==0));
	if(leap_year)
	{
		switch(month)
		{
			case 1:
				if(day<=0||day>31)
			    {
					cout<<"�������-�����µĹ�ϵ�Ƿ�"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day << "��" << endl;
				break; 
			case 2:
				if(day<=0||day>29)
			    {
					cout<<"�������-�����µĹ�ϵ�Ƿ�"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day+31 << "��" << endl;
				break; 
			case 3:
				if(day<=0||day>31)
			    {
					cout<<"�������-�����µĹ�ϵ�Ƿ�"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 29 << "��" << endl;
				break; 
			case 4:
				if(day<=0||day>30)
			    {
					cout<<"�������-�����µĹ�ϵ�Ƿ�"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 29 + 31 << "��" << endl;
				break;  
			case 5:
				if(day<=0||day>31)
			    {
					cout<<"�������-�����µĹ�ϵ�Ƿ�"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 29 + 31 + 30 << "��" << endl;
				break;  
			case 6:
				if(day<=0||day>30)
			    {
					cout<<"�������-�����µĹ�ϵ�Ƿ�"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 29 + 31 + 30 + 31 << "��" << endl;
				break;  
			case 7:
				if(day<=0||day>31)
			    {
					cout<<"�������-�����µĹ�ϵ�Ƿ�"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 29 + 31 + 30 + 31 + 30 << "��" << endl;
				break;  
			case 8:
				if(day<=0||day>31)
			    {
					cout<<"�������-�����µĹ�ϵ�Ƿ�"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 29 + 31 + 30 + 31 + 30 + 31 << "��" << endl;
				break;  
			case 9:
				if(day<=0||day>30)
			    {
					cout<<"�������-�����µĹ�ϵ�Ƿ�"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31  << "��" << endl;
				break;  
			case 10:
				if(day<=0||day>31)
			    {
					cout<<"�������-�����µĹ�ϵ�Ƿ�"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 << "��" << endl;
				break; 
			case 11:
				if(day<=0||day>30)
			    {
					cout<<"�������-�����µĹ�ϵ�Ƿ�"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 << "��" << endl;
				break;  
			case 12:
				if(day<=0||day>31)
			    {
					cout<<"�������-�����µĹ�ϵ�Ƿ�"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 << "��" << endl;
				break;  
			default:
				cout<<"�������-�·ݲ���ȷ"<<endl;					
		}						
	}
	else
	{
		switch(month)
		{
			case 1:
				if(day<=0||day>31)
			    {
					cout<<"�������-�����µĹ�ϵ�Ƿ�"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day << "��" << endl;
				break; 
			case 2:
				if(day<=0||day>28)
			    {
					cout<<"�������-�����µĹ�ϵ�Ƿ�"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day+31 << "��" << endl;
				break; 
			case 3:
				if(day<=0||day>31)
			    {
					cout<<"�������-�����µĹ�ϵ�Ƿ�"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 28 << "��" << endl;
				break; 
			case 4:
				if(day<=0||day>30)
			    {
					cout<<"�������-�����µĹ�ϵ�Ƿ�"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 28 + 31 << "��" << endl;
				break;  
			case 5:
				if(day<=0||day>31)
			    {
					cout<<"�������-�����µĹ�ϵ�Ƿ�"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 28 + 31 + 30 << "��" << endl;
				break;  
			case 6:
				if(day<=0||day>30)
			    {
					cout<<"�������-�����µĹ�ϵ�Ƿ�"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 28 + 31 + 30 + 31 << "��" << endl;
				break;  
			case 7:
				if(day<=0||day>31)
			    {
					cout<<"�������-�����µĹ�ϵ�Ƿ�"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 28 + 31 + 30 + 31 + 30 << "��" << endl;
				break;  
			case 8:
				if(day<=0||day>31)
			    {
					cout<<"�������-�����µĹ�ϵ�Ƿ�"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 28 + 31 + 30 + 31 + 30 + 31 << "��" << endl;
				break;  
			case 9:
				if(day<=0||day>30)
			    {
					cout<<"�������-�����µĹ�ϵ�Ƿ�"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31  << "��" << endl;
				break;  
			case 10:
				if(day<=0||day>31)
			    {
					cout<<"�������-�����µĹ�ϵ�Ƿ�"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 << "��" << endl;
				break; 
			case 11:
				if(day<=0||day>30)
			    {
					cout<<"�������-�����µĹ�ϵ�Ƿ�"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 << "��" << endl;
				break;  
			case 12:
				if(day<=0||day>31)
			    {
					cout<<"�������-�����µĹ�ϵ�Ƿ�"<<endl;
			        break;
				}
				cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 << "��" << endl;
				break;  
			default:
				cout<<"�������-�·ݲ���ȷ"<<endl;					
		}						
}
return 0;
}
