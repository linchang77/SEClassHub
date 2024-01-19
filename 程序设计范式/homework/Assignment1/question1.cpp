#include<iostream>
#include<string>
using namespace std;
int * get_answer(int * prices,int length);
int main()
{
	int length;
	int * prices;
	int * answer;
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
	if (prices[i] >= 30&& prices[i] <= 100) 
	    break;
	cerr << "please enter the price between 30 and 100." << endl;
    }//make sure the stock price is between 30 and 100	
	}
	answer=get_answer(prices,length);
	for(int i=0;i<length;i++)
		cout<<answer[i];
		
	return 0;
	
 } 
 int * get_answer(int * prices,int length)
 {
 
 	for(int i=0;i<length;i++)
 	{
	 	int days=0;
 		for(int j=i+1;j<length;j++)
 		{
 			if(prices[i]<prices[j]){
			days=j-i;
 			prices[i]=days;
 			break;
			}
		 }	
	 }
	 prices[length-1]=0;
	 return prices;
 }
