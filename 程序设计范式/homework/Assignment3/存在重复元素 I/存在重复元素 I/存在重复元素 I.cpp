#include<iostream>
#include<vector>
using namespace std;
/*
 * ����ֵ����
 * ������һ��vector��Ķ�ά�ṹ
 * ���ܣ���ʾ�û���������г�ʼ��
 */
void input(vector<int>& nums);
/*
 * ����ֵ��bool
 * ������һ��vector��Ķ�ά�ṹ
 * ���ܣ��ж��Ƿ����ظ���Ԫ��
 */
bool judgement(vector<int> &vec);
int main()
{
	puts("�����������������飨q������");
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
	}//ȷ��������Ҫ��Χ��
}
bool judgement(vector<int>& vec)
{
	//�ӵ�һ��Ԫ�ؿ�ʼ�ͺ����Ԫ�ؽ��бȽ������ֱͬ�ӷ���1
	for (int i = 0; i < vec.size(); i++)
		for (int j = i+1; j < vec.size(); j++)
			if (vec[i] == vec[j])
				return 1;
	return 0;
}