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
 * 参数：一个vector类的二维结构和一个int类型
 * 功能：判断是否有重复的元素
 */
bool judgement(vector<int>& vec,int k);
int main()
{
	puts("请输入整数创建数组（q结束）");
	vector<int> nums;
	input(nums);
	
	puts("请输入k的值.");
	int k;
	cin >> k;
	if (judgement(nums,k))
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
	}//确保输入的数据在正确的范围内
	while(getchar()!='\n')
		;//去除缓存里的多余的值
	cin.clear();
}
bool judgement(vector<int>& vec,int k)
{   //从第一个元素开始，每次向后找k个元素进行比较
	for (int i = 0; i < vec.size()-1; i++)
		for (int j = i + 1; (j <= i + k)&& (j <vec.size()) ; j++)
			if (vec[i] == vec[j])
				return 1;
	return 0;
	
}