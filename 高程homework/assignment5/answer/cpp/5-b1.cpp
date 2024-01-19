/*2250420 软工 陈君*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

int main()
{
    int array[21];
    int num=0;
    cout<<"请输入任意个正整数（升序，最多20个），0或负数结束输入"<<endl;
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
		cout<<"无有效输入"<<endl;
		return 0;
	}
	cout<<"原数组为："<<endl;
	for(int i=0;i<num;i++)
	cout<<array[i]<<" ";
	cout<<endl;
	cout<<"请输入要插入的正整数"<<endl;
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
	cout<<"插入后的数组为："<<endl;
	for(int i=0;i<num+1;i++)
	cout<<array[i]<<" ";
	cout<<endl;
	
}






