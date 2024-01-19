/*2250420 软工 陈君*/
#include"iostream"
#include "iomanip"
#define PI 3.14159
using namespace std;
int main()
{
	double hight,radius;
	cout<<"请输入半径和高度"<<endl;
	cin>>radius>>hight;
	cout<<setw(11)<<setiosflags(ios::left)<<"圆周长"<<':'<<" "<<setprecision(2)
	    <<setiosflags(ios::fixed)<<2*PI*radius<<endl;
	cout<<setw(11)<<"圆面积"<<':'<<" "<<setprecision(2)
	    <<setiosflags(ios::fixed)<<radius*radius*PI<<endl;
	cout<<setw(11)<<"圆球表面积"<<':'<<" "<<setprecision(2)
	    <<setiosflags(ios::fixed)<<4*radius*radius*PI<<endl;
	cout<<setw(11)<<"圆球体积"<<':'<<" "<<setprecision(2)
	    <<setiosflags(ios::fixed)<<PI*radius*radius*radius*4/3<<endl;
	cout<<setw(11)<<"圆柱体积"<<':'<<" "<<setprecision(2)
	    <<setiosflags(ios::fixed)<<radius*radius*PI*hight;
	
	return 0;
 } 
