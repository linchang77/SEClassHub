/*2250420 软工 陈君*/
#include"iostream"
#include "iomanip"
#include <windows.h> 
#include <cstdio>
using namespace std;
int main()
{
	LARGE_INTEGER tick, begin, end;
	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数
	int i1,i2,i3,j1,j2,j3,k1,k2,k3;
	int k=0; 
	int n=0;
	for (int i = 123; i <= 598; i++)
	{
		int i1 = i / 10 % 10;
	    int i2 = i / 100;
		int i3 = i % 10;
		if (i1 == i2 || i1 == i3 || i2 == i3 || i1 == 0 || i2 == 0 || i3 == 0)
			continue;
		for (int j = i + 1; j <= 897; j++)
		    {
		        int j1 = j / 10 % 10;
	            int j2 = j / 100;
		        int j3 = j % 10;
				if (j1 == i1 || j1 == i2 || j1 == i3
				  ||j2 == i1 || j2 == i2 || j2 == i3
				  ||j3 == i1 || j3 == i2 || j3 == i3
				  ||j1 == 0  || j2 == 0  || j3 == 0
				  ||j1 == j2 || j1 == j3 || i2 == j3 )
				    continue;	
				k=1953-i-j;
				if(k>j&&k<=987)
				{
					int k1 = k / 10 % 10;
	                int k2 = k / 100;
		            int k3 = k % 10;
		            if (k1 == i1 || k1 == i2 || k1 == i3
				      ||k2 == i1 || k2 == i2 || k2 == i3
				      ||k3 == i1 || k3 == i2 || k3 == i3
				      ||k1 == 0  || k2 == 0  || k3 == 0
					  ||k1 == j1 || k1 == j2 || k1 == j3
				      ||k2 == j1 || k2 == j2 || k2 == j3
				      ||k3 == j1 || k3 == j2 || k3 == j3
					  ||k1 == k2 || k1 == k3 || k2 == k3 )
				        continue;
				    else{
				    	n++;
				        cout<<"No."<<setw(3)<<n<<" : "<<i<<"+"<<j<<"+"<<k<<"=1953"<<endl;	
					}
				    
				}else
				continue;
			}
    }
	cout << "total=" << n << endl;
	QueryPerformanceCounter(&end);
	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;																					           		
	return 0;
}
