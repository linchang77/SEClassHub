/*2250420 软工 陈君*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
int max(int a,int b)
{
	if(a>b)
	return a;
	else 
	return b;
}
int max(int a,int b,int c)
{
	if(a>b)
	return a>c ? a:c;
	else 
	return b>c ? b:c;
}
int max(int a,int b,int c,int d)
{
	if(a>b)
	{
		if(a>c)
		return a>d ? a:d;
		else 
		return c>d ? c:d;
	}
	else 
	{
		if(b>c)
		return b>d ? b:d;
		else 
		return c>d ? c:d;
	}
}
int main()
{
	int n,a,b,c,d;
	while(1)
	{
		cout<<"请输入个数num及num个正整数："<<endl;
		cin>>n;
		if(!cin.good())//输入错误
		{
			cin.clear();
			while(getchar()!='\n')
			; 
			continue;
		} 
		if(n>4||n<2)
		{
			cout<<"个数输入错误"<<endl;
			return 0;
		}
    switch(n)
    {
    	case 2:
    		while(1)
    		{
    			cin>>a>>b;
    			if(!cin.good())
    			{
    				cin.clear();
    				while(getchar()!='\n')
    				;
    				break;
				}
				cout<<"max="<<max(a,b)<<endl;
				return 0;
			}
			break;	
        case 3:
        	while(1)
    		{
    			cin>>a>>b>>c;
    			if(!cin.good())
    			{
    				cin.clear();
    				while(getchar()!='\n')
    				;
    				break;
				}
				cout<<"max="<<max(a,b,c)<<endl;
				return 0;
			}
			break;	
        case 4:
        	while(1)
    		{
    			cin>>a>>b>>c>>d;
    			if(!cin.good())
    			{
    				cin.clear();
    				while(getchar()!='\n')
    				;
    				break;
				}
				cout<<"max="<<max(a,b,c,d)<<endl;
				return 0;
			}
			break;
	}
}
}






