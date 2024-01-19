#include<iostream>
#include<string>
using namespace std;
int get_the_best_profit(int * prices,int length);
int main()
{
    int length;
	int * prices;
	int profit;
	cout<<"Enter the length of the array"<<endl;
	while(1)
	{
	cin>>length;
	if (length >= 1 && length <= 105) break;
		cerr << "please enter the length between 1 and 105." << endl;
    }
	prices=new int[length];
	cout<<"Enter the price."<<endl;
	for(int i=0;i<length;i++)
	{
		while (1) 
	{
	cin >> prices[i];
	if (prices[i] >= 0&& prices[i] <= 104) 
	    break;
	cerr << "please enter the price between 0 and 104." << endl;
    }//make sure the stock price is between 0 and 104	
	}
	
	profit=get_the_best_profit(prices,length);
	cout<<profit;
		
	return 0;
	
 } 
int get_the_best_profit(int * prices,int length)
 {
    int profit=0;
 	for(int i=0;i<length;i++)
 		for(int j=i+1;j<length;j++)
 			if(profit<prices[j]-prices[i])
			profit=prices[j]-prices[i];
	 return profit;
 }
 
