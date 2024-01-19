/*2250420 软工 陈君*/
#include"iostream"
#include"iomanip"
using namespace std;

int main()
{
	int a;
	int b;
	cout<<"请输入一个[1..30000]间的整数:"<<endl;
	cin>>a;
	cout<<setw(5)<<setiosflags(ios::left)<<"万位"<<':'<<" "<<a/10000<<endl;
	b=a/1000%10;
	cout<<setw(5)<<"千位"<<':'<<" "<<b<<endl;
	b=a/100%10;
	cout<<setw(5)<<"百位"<<':'<<" "<<b<<endl;
	b=a/10%10;
	cout<<setw(5)<<"十位"<<':'<<" "<<b<<endl;
	b=a%10;
	cout<<setw(5)<<"个位"<<':'<<" "<<b;
	
	return 0;
 } 
