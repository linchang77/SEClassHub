/*
 * File: 看电影2
 * ---------------
 * 请你算一算要排下所有电影最少需要几个放映厅。
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*
 * 返回值：空
 * 参数：一个vector类的二维结构
 * 功能：提示用户对电影起始时间进行初始化
 */
void input(vector<vector<int>>& interval);


/*
 * 返回值：空
 * 参数：一个vector类的二维结构，和这个二维结构一维中含有的元素个数
 * 功能：将每部电影按照开始时间从早到晚排序。
 */
void sort(vector<vector<int>>& interval, int n);


/*
 * 返回值：int类型
 * 参数：一个vector类的二维结构
 * 功能：算出需要放映厅的最少个数。
 */
int get_the_min(vector<vector<int>>& interval);
int main()
{
	vector<vector<int>>interval;//声明一个两维的结构

	input(interval);//初始化
	sort(interval, interval.size());
	cout << "最少需要" << get_the_min(interval) << "个放映厅" << endl;
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
		    cin>>film[1];
			if (film[1] == -1)
				break;
			interval.push_back(film);
			if (interval[n][0] < 0 || interval[n][0] > interval[n][1]|| interval[n][1] >= 1000000) {
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
void sort(vector<vector<int>>& interval, int n)
{
	int temp;
	for (int i = n - 1; i > 0; i--)
		for (int j = 0; j < i ; j++)
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
int get_the_min(vector<vector<int>>&interval)
{
	vector<vector<int>>new_interval;//声明一个新的二维vector，代表额外需要的放映厅
	vector<int> film(2);//vector里面的元素
	for (int i = 0; i < interval.size()-1; )
		for (int j = i + 1; j < interval.size(); j++)
		{
			if (interval[i][1] >= interval[j][0])//比较前一个电影的结束时间和后一个电影的开始时间是否冲突
			{
				new_interval.push_back(interval[j]); //冲突的话将冲突的电影排到额外的放映厅里面
				if (j == interval.size()-1)//如果发现比到最后一个电影了还是冲突就将j赋给i结束循环
					i = j;
			}
			else
			{
				i = j;//不冲突就不排进新的放映厅，然后从第j个开始比较
				break;
			}
		}
	int count = 1;
	while (1)//得到的新的数组再看一看需不需要新的放映厅
	{
		if (new_interval.size() == 0)//循环终止条件：无法再产生新的数组，即不用再需要放映厅排排不下的电影
			break;
		interval = new_interval;
		new_interval.clear();//重新腾出放映厅
		for (int i = 0; i < interval.size() - 1; )//和上面一样，把排不下的电影放到新的放映厅中
			for (int j = i + 1; j < interval.size(); j++)
			{
				if (interval[i][1] >= interval[j][0])
				{
					new_interval.push_back(interval[j]);
					if (j == interval.size() - 1)
						i = j;
				}
				else
				{
					i = j;
					break;
				}
			}
		count++;
	}
	return count;
}
/*测试数据
*3 5 2 6 8 9 -1
*1 5 2 6 3 7 4 8 -1
*1 20 2 3 4 28 22 30 -1
*/