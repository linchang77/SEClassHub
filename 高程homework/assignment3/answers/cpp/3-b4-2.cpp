/*2250420 软工 陈君*/
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
	cout<<"请输入三角形的两边及其夹角(角度)"<<endl;
	cin>>a>>b>>angle;
	cout<<"三角形面积为 : "<<setprecision(3)<<setiosflags(ios::fixed)
	    <<a*b*sin(angle*PI/180)/2<<endl;
	
	return 0;
 } 
