#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/*
 * ����ֵ����
 * ������һ��vector��Ķ�ά�ṹ
 * ���ܣ���ʾ�û���������г�ʼ��
 */
void input(vector<int>& nums);
/*
 * ����ֵ��bool
 * ������һ��vector��Ķ�ά�ṹ������int����
 * ���ܣ��ж��Ƿ��з���Ҫ��һ��Ԫ��
 */
bool judgement(vector<int>& vec, int indexDiff,int valueDiff);
int main()
{
	puts("�����������������飨q������");
	vector<int> nums;
	input(nums);

	puts("������indexDiff��valueDiff��ֵ.");
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
	}//ȷ�����ݲ���ĿҪ��Χ��
	while (getchar() != '\n')
		;//ȥ��������Ķ����ֵ
	cin.clear();
}
bool judgement(vector<int>& vec, int indexDiff, int valueDiff)
{
	//�ӵ�һ��Ԫ�ؿ�ʼÿ�������indexDiff��Ԫ���ж��Ƿ������ĿҪ��
	for (int i = 0; i < vec.size() - 1; i++)
		for (int j = i + 1; (j <= i + indexDiff)&&(j<vec.size()); j++)
			if (fabs(vec[i] - vec[j])<=valueDiff)
				return 1;
	return 0;

}