/* 2250420 �¾� ��*/
#include <iostream>
using namespace std;

/***************************************************************************
  �������ƣ�judge
  ��    �ܣ��ж�������Ƿ��ǻ�������
  ���������int num,int base
  �� �� ֵ�����ر�base��ʣ�µ���
  ˵    ����
***************************************************************************/
int judge(int n, int base)
{
	int temp=1;
	while (n!=temp&&n>temp)
	{
		temp=temp*base;
	}
	if(temp==n)
	return 1;
	else 
	return 0;
}
int main()
{
	int n, base;
	int num = 0;

	int array[10000];
	for (int i = 0; i < 10000; i++)//��ʼ������ 
		array[i] = 0;
	cout << "���������ݵĸ���[1..10000]" << endl;
	cin >> n;
	cout << "������" << n << "��������" << endl;
	for (int i = 0; i < n; i++)//�������� 
		cin >> array[i];
	cout << "���������[2..9]" << endl;
	cin >> base;

	for (int i = 0; i < n; i++)
		if (judge(array[i], base) == 1)
			num++;
	cout << n << "�����л���8���ݵĸ��� : " << num << endl;
	return 0;
}

