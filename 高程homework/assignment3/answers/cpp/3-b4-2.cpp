/*2250420 �� �¾�*/
#include"iostream"
#include"cmath"
#include"iomanip"
#define PI 3.14159
using namespace std;

int main()
{
	int a;
	int b;
	double angle;
	cout<<"�����������ε����߼���н�(�Ƕ�)"<<endl;
	cin>>a>>b>>angle;
	cout<<"���������Ϊ : "<<setprecision(3)<<setiosflags(ios::fixed)
	    <<a*b*sin(angle*PI/180)/2<<endl;
	
	return 0;
 } 
