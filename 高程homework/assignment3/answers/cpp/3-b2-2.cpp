/*2250420 �� �¾�*/
#include"iostream"
#include"iomanip"
using namespace std;

int main()
{
	int a;
	int b;
	cout<<"������һ��[1..30000]�������:"<<endl;
	cin>>a;
	cout<<setw(5)<<setiosflags(ios::left)<<"��λ"<<':'<<" "<<a/10000<<endl;
	b=a/1000%10;
	cout<<setw(5)<<"ǧλ"<<':'<<" "<<b<<endl;
	b=a/100%10;
	cout<<setw(5)<<"��λ"<<':'<<" "<<b<<endl;
	b=a/10%10;
	cout<<setw(5)<<"ʮλ"<<':'<<" "<<b<<endl;
	b=a%10;
	cout<<setw(5)<<"��λ"<<':'<<" "<<b;
	
	return 0;
 } 
