/*
 * File: 看电影2
 * ---------------
 * 请你判断⼀个⼈是否能够看完这⾥⾯的全部电影，不错过任何⼀部。
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*
 * 返回值：空
 * 参数：一个vector类的二维结构，和这个二维结构一维中含有的元素个数
 * 功能：提示用户对电影起始时间进行初始化
 */
void input(vector<vector<int>>& interval, int n);


/*
 * 返回值：空
 * 参数：一个vector类的二维结构，和这个二维结构一维中含有的元素个数
 * 功能：将每部电影按照开始时间从早到晚排序。
 */

void sort(vector<vector<int>>& interval, int n);


vector<vector<int>> new_interval(vector<vector<int>>& interval);
int get_the_min(vector<vector<int>>& interval, int n);
int main()
{
	int n;
	cout << "请问有多少部电影要播放？" << endl;
	while (1){
		cin >> n;
		if (n >= 0 && 0 <= 10000) break;
		cerr << "请输入10000以内的正整数" << endl;
	}//确保输入正确的数据
	vector<vector<int> > interval(n, vector<int>(2));//声明一个二维结构
	input(interval, n);//初始化
	/*for (int i = 0; i < n; i++)
		cout << interval[i][0] << " " << interval[i][1] << "   ";
	cout << endl;*/
	cout << "最少需要" << get_the_min(interval, n) << "个放映厅" << endl;
	return 0;
}
void input(vector<vector<int>>& interval, int n)
{

	cout << "请依次输入电影的起始时间和结束时间" << endl;
	for (int i = 0; i < n; i++)
		while (1)
		{
			cin >> interval[i][0] >> interval[i][1];
			if (interval[i][0] >= 0 && interval[i][0] < interval[i][1] && interval[i][1] <= 100000) break;
			cerr << "请输入正确的参数" << endl;
		}//确保输入正确的数据
	
}
int get_the_min(vector<vector<int>>& interval, int n)
{
	sort(interval, n);
	int count = 0;
	while (1)//得到一个新的数组
	{
		interval = new_interval(interval, interval.size());
		count++;
		if (interval.size() == 0)
			break;
	}
	return count;
}
void sort(vector<vector<int>>& interval, int n)
{
	int temp;
	for(int i=n-1;i>0;i--)
		for (int j = 0; j < i-1; j++)
			if (interval[j][0] > interval[j + 1][0])
			{
				temp = interval[j][0];
				interval[j][0] = interval[j + 1][0];
				interval[j + 1][0] = temp;
				temp = interval[j][1];
				interval[j][1] = interval[j + 1][1];
				interval[j + 1][1] = temp;
			}
			
}