#include<iostream>
#include<vector>
using namespace std;
/*
 * 返回值：空
 * 参数：一个vector类的二维结构
 * 功能：提示用户对数组进行初始化
 */
void input(vector<int>& nums);
/*
 * 返回值：bool
 * 参数：一个vector类的二维结构
 * 功能：判断是否有重复的元素
 */
bool judgement(vector<int> &vec);
int main()
{
	puts("请输入整数创建数组（q结束）");
	vector<int> nums;
	input(nums);
	if (judgement(nums))
		puts("true");
	else
		puts("false");
	return 0;
}
void input(vector<int>& nums)
{
	while (nums.size()<100000)
	{
		int n;
		cin >> n;
		if (!cin.good())
			break;
		if(n>=0.000000009&&n<=9000000000)
		nums.push_back(n);
	}//确保数据在要求范围内
}
bool judgement(vector<int>& vec)
{
	//从第一个元素开始和后面的元素进行比较如果相同直接返回1
	for (int i = 0; i < vec.size(); i++)
		for (int j = i+1; j < vec.size(); j++)
			if (vec[i] == vec[j])
				return 1;
	return 0;
}