/*
 * File: 看电影1
 * ---------------
 * 请你判断⼀个⼈是否能够看完这⾥⾯的全部电影，不错过任何⼀部。
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

/**
 * 返回值：空
 * 参数：一个vector类的二维结构
 * 功能：提示用户对电影起始时间进行初始化
 */
void input(vector<vector<int>>& interval);

/**
 * 返回值：bool类型
 * 参数：一个vector类的二维结构，和这个二维结构一维中含有的元素个数
 * 功能：判断⼀个⼈是否能够看完这⾥⾯的全部电影，不错过任何⼀部。
 */
	bool judge(vector<vector<int>>& interval, int n);

int main()
{
	vector<vector<int>>interval;//声明一个两维的结构

	input(interval);//初始化
	if (judge(interval,interval.size()))//做判断
		cout << "true";
	else
		cout << "false";
	return 0;
}
void input(vector<vector<int>>& interval)
{

	cout << "请依次输入电影的起始时间和结束时间(输入-1结束)" << endl;
	int n = 0;
	while (1)
	{

		vector<int> film(2);
		cin >> film[0];
		if (film[0] == -1)
			break;
		cin >> film[1];
		if (film[1] == -1)
			break;
		interval.push_back(film);
		if (interval[n][0] < 0 || interval[n][0] > interval[n][1] || interval[n][1] >= 1000000) {
			cerr << "请输入正确的参数" << endl;
			interval.clear();
			n = 0;
			break;
		}
		n++;
		if (n > 10000)
		{
			cerr << "请确保电影部数在10000以内" << endl;
			interval.clear();
			n = 0;
			break;
		}  //确保电影部数在10000以内
			//确保输入正确的数据		
	}
}//初始化vector
bool judge(vector<vector<int>>& interval, int n)
{
	int i = 0;
	for (; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if ((interval[i][0] > interval[j][0] && interval[i][0] < interval[j][1])
				|| (interval[i][1] > interval[j][0] && interval[i][1] < interval[j][1])
				|| (interval[j][0] >= interval[i][0] && interval[j][1] <= interval[i][1]))
				/*不能看完的情况有三种
				* 一部电影的开始在另一部电影放映时间内
				* 一部电影的开始在另一部电影放映时间内
				* 一部电影放映的时间段是另一部电影的子集
				*/
				return false;
	return true;
}