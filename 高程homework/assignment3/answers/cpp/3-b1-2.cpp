/*2250420 �� �¾�*/
#include"iostream"
#include "iomanip"
#define PI 3.14159
using namespace std;
int main()
{
	double hight,radius;
	cout<<"������뾶�͸߶�"<<endl;
	cin>>radius>>hight;
	cout<<setw(11)<<setiosflags(ios::left)<<"Բ�ܳ�"<<':'<<" "<<setprecision(2)
	    <<setiosflags(ios::fixed)<<2*PI*radius<<endl;
	cout<<setw(11)<<"Բ���"<<':'<<" "<<setprecision(2)
	    <<setiosflags(ios::fixed)<<radius*radius*PI<<endl;
	cout<<setw(11)<<"Բ������"<<':'<<" "<<setprecision(2)
	    <<setiosflags(ios::fixed)<<4*radius*radius*PI<<endl;
	cout<<setw(11)<<"Բ�����"<<':'<<" "<<setprecision(2)
	    <<setiosflags(ios::fixed)<<PI*radius*radius*radius*4/3<<endl;
	cout<<setw(11)<<"Բ�����"<<':'<<" "<<setprecision(2)
	    <<setiosflags(ios::fixed)<<radius*radius*PI*hight;
	
	return 0;
 } 
