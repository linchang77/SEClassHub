/* 2250420 �¾� �� */
#include <iostream>
using namespace std;

int main()
{
	 int tag=0;
	int temp[1000];
	for(int i=0;i<1000;i++)
	    temp[i]=-1; 
	int array[101];
	for(int i=0;i<101;i++)
	    array[i]=0; 
	cout<<"������ɼ������1000������������������"<<endl;
	for(int i=0;i<1000;i++)
	{
		int a;
		cin>>a;
		if(a<0)
		break;
		temp[i]=a;
	}
	printf("���������Ϊ:\n");
	for(int i=0;i<1000;i++)
	{
		if(temp[i]<0)
		{
			if(i%10==0)
			tag=1;
			break;
		} 
		cout<<temp[i]<<" ";
		if((i+1)%10==0)
		    cout<<endl;
	}
	if(tag==0)
	cout<<endl;
	cout<<"���������εĶ�Ӧ��ϵΪ:"<<endl;
	for(int i=0;i<1000;i++)
	{
	    if(temp[i]<0)
	        break;
		array[temp[i]]++;	
	}
	int rank=1;
	for(int i=100;i>=0;i--)
	{
		if(array[i]!=0)
		{
			for(int j=0;j<array[i];j++)
		    {
		    	cout<<i<<" "<<rank<<endl;
			} 
			rank=rank+array[i];
		}
	}	
	return 0;
}
/*
�������ݣ��ɸ��ƺ�ճ�������д�����
87 86 56 76 87 92 76 0 96 98 0 23 -1

87 86 56 76 87 92 76 96 98 23 55 56 34 23 -1
*/

