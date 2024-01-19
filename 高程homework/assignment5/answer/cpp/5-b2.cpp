/*2250420 Èí¹¤ ³Â¾ı*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

int main()
{
    int array[101];
    for(int i=0;i<101;i++)
    array[i]=0;
    for(int i=1;i<=100;i++)
    {
    	for(int j=i;j<=100;j=j+i)
    	    array[j]=array[j]==0 ? 1:0;
	}
	for(int i=0;i<100;i++)
	    if(array[i]==1)
	        cout<<i<<" ";     
	if(array[100]==1)
	cout<<100<<endl;   
}






