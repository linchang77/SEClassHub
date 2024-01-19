/*2250420 Èí¹¤ ³Â¾ı*/
#include"iostream"
using namespace std;
int main()
{
	int i,j,k,sum=0;
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			for(k=0;k<4;k++)
			{
				cout<<'*';
				sum++;
			}
			cout<<' ';
		}
		cout<<endl;
	 } 
	 k=k-1;
	 cout<<"sum="<<sum<<endl;
	 cout<<"i="<<i<<endl;
	 cout<<"j="<<j<<endl;
	 cout<<"k="<<k<<endl; 
	return 0;
}
