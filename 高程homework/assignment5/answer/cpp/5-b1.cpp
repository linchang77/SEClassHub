/*2250420 �� �¾�*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

int main()
{
    int array[21];
    int num=0;
    cout<<"��������������������������20������0������������"<<endl;
	for(int i=0;i<20;i++)
	{
		int a;
		cin>>a;
		if(a<=0)
		break;
		array[i]=a;	
		num++;
	} 
	while(getchar()!='\n')
	;
	if(num==0)
	{
		cout<<"����Ч����"<<endl;
		return 0;
	}
	cout<<"ԭ����Ϊ��"<<endl;
	for(int i=0;i<num;i++)
	cout<<array[i]<<" ";
	cout<<endl;
	cout<<"������Ҫ�����������"<<endl;
	int n;
	cin>>n;
	int i=0;
	for(;i<num;i++)
	{
		if(n<array[i])	
		break;
	}
	for(int j=num;j>i;j--)
	{
		array[j]=array[j-1];
	}
	array[i]=n;
	cout<<"����������Ϊ��"<<endl;
	for(int i=0;i<num+1;i++)
	cout<<array[i]<<" ";
	cout<<endl;
	
}






