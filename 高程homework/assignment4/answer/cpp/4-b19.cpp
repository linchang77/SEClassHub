/*2250420 �� �¾�*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
int min(int a=INT_MAX,int b=INT_MAX,int c=INT_MAX,int d=INT_MAX) 
{
	if(a<b)
	{
		if(a<c)
		return a<d ? a:d;
		else 
		return c<d ? c:d; 
	}
	else
	{
		if(b<c)
		return b<d ? b:d;
		else 
		return c<d ? c:d;
	}
}
int main()
{
	int n,a,b,c,d;
	while(1)
	{
		cout<<"���������num��num����������"<<endl;
		cin>>n;
		if(!cin.good())//�������
		{
			cin.clear();
			while(getchar()!='\n')
			; 
			continue;
		} 
		if(n>4||n<2)
		{
			cout<<"�����������"<<endl;
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
				cout<<"min="<<min(a,b)<<endl;
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
				cout<<"min="<<min(a,b,c)<<endl;
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
				cout<<"min="<<min(a,b,c,d)<<endl;
				return 0;
			}
			break;
	}
}
}






