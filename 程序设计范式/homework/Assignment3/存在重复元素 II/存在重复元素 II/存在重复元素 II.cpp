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
 * ������һ��vector��Ķ�ά�ṹ��һ��int����
 * ���ܣ��ж��Ƿ����ظ���Ԫ��
 */
bool judgement(vector<int>& vec,int k);
int main()
{
	puts("�����������������飨q������");
	vector<int> nums;
	input(nums);
	
	puts("������k��ֵ.");
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
	}//ȷ���������������ȷ�ķ�Χ��
	while(getchar()!='\n')
		;//ȥ��������Ķ����ֵ
	cin.clear();
}
bool judgement(vector<int>& vec,int k)
{   //�ӵ�һ��Ԫ�ؿ�ʼ��ÿ�������k��Ԫ�ؽ��бȽ�
	for (int i = 0; i < vec.size()-1; i++)
		for (int j = i + 1; (j <= i + k)&& (j <vec.size()) ; j++)
			if (vec[i] == vec[j])
				return 1;
	return 0;
	
}