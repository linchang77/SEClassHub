/*
 * File: 看电影3
 * ---------------
 * 合并所有重叠的播放时间，并返回 ⼀个不重叠的播放时间数组，该数组需恰好覆盖输⼊中的所有时间
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
void input(vector<vector<int>>& interval);


/*
 * 返回值：空
 * 参数：两个vector类的二维结构
 * 功能：获得优化后的电影排片
 */
void combine(vector<vector<int>>&interval, vector<vector<int>>&new_interval);

/*
 * 返回值：空
 * 参数：一个vector类的二维结构，和这个二维结构一维中含有的元素个数
 * 功能：将每部电影按照开始时间从早到晚排序。
 */
void sort(vector<vector<int>>& interval, int n);
int main()
{
	vector<vector<int>>interval;//声明一个两维的结构

	input(interval);//初始化
	vector<vector<int>>new_interval;//用于储存合并后的电影
	sort(interval,interval.size());
	combine(interval,new_interval);
	cout << "[";//打印合并后的数组
	for (int i = 0; i < new_interval.size()-1; i++)
		cout << "[" << new_interval[i][0] << "," << new_interval[i][1] << "]" << ",";
	cout << "[" << new_interval[new_interval.size()-1][0] << "," << new_interval[new_interval.size()-1][1] << "]" << "]" << endl;

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
		if (interval[n][0] < 0 || interval[n][0] > interval[n][1] || interval[n][1] >= 10000) {
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
void combine(vector<vector<int>>& interval, vector<vector<int>>& new_interval)
{
	vector<int> newtime(2);
	
	newtime[0] = interval[0][0];
	newtime[1] = interval[0][1];
	new_interval.push_back(newtime);//初始化new_interval
	int k = 0;//用于确定new_interval最后一部电影的位置
	for (int i = 1; i < interval.size(); i++)//从数组的第一个开始依次与new_interval数组中最后一部电影比较
	{
		if (interval[i][0] <= new_interval[k][1] && interval[i][1] >= new_interval[k][1])//部分重合
			new_interval[k][1] = interval[i][1];//用interval中电影的结束时间替代new_interval数组中的结束时间
		else if (interval[i][1] <= interval[k][1])//后面一个完全嵌套再前面一个
			;//直接跳过
		else//两部电影时间没有重合
		{
			newtime[0] = interval[i][0];
			newtime[1] = interval[i][1];
			new_interval.push_back(newtime);
			k++;//直接将电影放入new_interval中，并让k+1.
		}
	}
}
void sort(vector<vector<int>>& interval, int n)
{
	int temp;
	for (int i = n - 1; i > 0; i--)
		for (int j = 0; j < i - 1; j++)
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
/*测试数据
*3 5 2 6 8 9 -1
*1 5 2 6 3 7 4 8 -1
*1 20 2 3 4 28 22 30 -1
*/