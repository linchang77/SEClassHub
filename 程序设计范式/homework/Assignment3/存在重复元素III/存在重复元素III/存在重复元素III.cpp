#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/*
 * 返回值：空
 * 参数：一个vector类的二维结构
 * 功能：提示用户对数组进行初始化
 */
void input(vector<int>& nums);
/*
 * 返回值：bool
 * 参数：一个vector类的二维结构和两个int类型
 * 功能：判断是否有符合要求一对元素
 */
bool judgement(vector<int>& vec, int indexDiff,int valueDiff);
int main()
{
	puts("请输入整数创建数组（q结束）");
	vector<int> nums;
	input(nums);

	puts("请输入indexDiff和valueDiff的值.");
	int indexDiff,valueDiff ;
	cin >> indexDiff >> valueDiff;
	if (judgement(nums, indexDiff,valueDiff))
		puts("true");
	else
		puts("false");
	return 0;
}
void input(vector<int>& nums)
{
	while (nums.size() < 100000)
	{
		int n;
		cin >> n;
		if (!cin.good())
			break;
		if (n >= 0.000000009 && n <= 9000000000)
			nums.push_back(n);
	}//确保数据才题目要求范围内
	while (getchar() != '\n')
		;//去除缓存里的多余的值
	cin.clear();
}
bool judgement(vector<int>& vec, int indexDiff, int valueDiff)
{
	//从第一个元素开始每次向后找indexDiff个元素判断是否符合题目要求
	for (int i = 0; i < vec.size() - 1; i++)
		for (int j = i + 1; (j <= i + indexDiff)&&(j<vec.size()); j++)
			if (fabs(vec[i] - vec[j])<=valueDiff)
				return 1;
	return 0;

}