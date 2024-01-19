#include<iostream>
#include<string>
#include <vector>
using namespace std;
int get_the_best_profit(vector<int> & prices);
int main()
{
    int profit; 
	int length;
	int * answer;
	
	
	cout<<"Enter the length of the array"<<endl;
	while(1){
		cin>>length;
		if (length >= 1 && length <= 1000) break;
			cerr << "please enter the length between 1 and 105." << endl;
	}//make sure the length is between 1 and 1000 
		vector <int> prices(length);
	cout<<"Enter the price."<<endl;
	for(int i=0;i<length;i++)
	{
		while (1) {
			cin >> prices[i];
			if (prices[i] >= 0&& prices[i] <= 1000) break;
				cerr << "please enter the price between 0 and 104." << endl;
		}//make sure the stock price is between 0 and 1000	
	}
	
	profit=get_the_best_profit(prices);
	cout<<"The max profit is:"<<profit<<endl;
		
	return 0;
	
 } 
int get_the_best_profit(vector<int>& prices)
 {
        int n = prices.size();
        // f[i][0]: ���ϳ��й�Ʊ���������
        // f[i][1]: ���ϲ����й�Ʊ�����Ҵ����䶳���е��ۼ��������
        // f[i][2]: ���ϲ����й�Ʊ�����Ҳ����䶳���е��ۼ��������
       vector<vector<int>> f(n, vector<int>(3));
        f[0][0] = -prices[0];//��ʼ��
		f[0][1] = 0;
		f[0][2] = 0;
        for (int i = 1; i < n; ++i) {
            f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i]);//�����й�Ʊ��������� Ҫô����һ�챣���ģ�f[i-1][0] Ҫô����һ�����f[i-1][2]-prices[i]
            f[i][1] = f[i - 1][0] + prices[i];//�����䶳��  ˵����һ�����˹�Ʊ������f[i][1]=f[i - 1][0] + prices[i]
            f[i][2] = max(f[i - 1][1], f[i - 1][2]); //û���Ʊ��ֻ������һ��f1��f2�������
			cout << f[i][0]<<"  " << f[i][1] << "  " << f[i][2] << endl;
        }
        return max(f[n - 1][1], f[n - 1][2]);
		//��һ������
		/*vector<vector<int>> dp(prices.size(), vector<int>(2));
		dp[0][0] = -prices[0];
		dp[1][0] = max(-prices[0], -prices[1]);
		dp[1][1] = max(0, prices[1] - prices[0]);
		for (int i = 2; i < prices.size(); i++) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 2][1] - prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
		}
		return dp[prices.size() - 1][1];*/
}


//ʹ�õ�һ������ 
/*
15 69 53 15 62 85 74 23 15 36
-15  54  0
-15  38  54
39  0  54
39  101  54
39  124  101
39  113  124
101  62  124*/