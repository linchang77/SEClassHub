/*2250420 �� �¾�*/
#include<iostream>
#include<cmath> 
using namespace std;
int main()
{
	cout << "����������ֵ��" << endl;
	double cash;
	cin >> cash;
	if(cash<0.01||cash>=100)
	{
	cout<<"�����������������"<<endl;
		return 0;
	}
	int a = (int)cash;
	int b = round((cash - a) * 100);
	int count = 0;

	int a1 = a / 50;
	int a2 = a % 50 / 20;
	int a3 = a % 50 % 20 / 10;
	int a4 = a % 50 % 20 % 10 / 5;
	int a5 = a % 50 % 20 % 10 % 5;

	int b1 = b / 50;
	int b2 = b % 50 / 10;
	int b3 = b % 50 % 10 / 5;
	int b4 = b % 50 % 10 % 5 / 2;
	int b5 = b % 50 % 10 % 5 % 2;

	if (a1 != 0)
		count+=a1;
	if (a2 != 0)
		count += a2;
	if (a3 != 0)
		count += a3;
	if (a4 != 0)
		count += a4;
	if (a5 != 0)
		count += a5;
	if (b1 != 0)
		count+=b1;
	if (b2 != 0)
		count += b2;
	if (b3 != 0)
		count += b3;
	if (b4 != 0)
		count+=b4;
	if (b5 != 0)
		count+=b5;
	cout << "��" << count << "�����㣬�������£�" << endl;
	if (a1 != 0)
		cout << "50Ԫ : " << a1 << "��" << endl;
	if (a2 != 0)
		cout << "20Ԫ : " << a2 << "��" << endl;
	if (a3 != 0)
		cout << "10Ԫ : " << a3 << "��" << endl;
	if (a4 != 0)
		cout << "5Ԫ  : " << a4 << "��" << endl;
	if (a5 != 0)
		cout << "1Ԫ  : " << a5 << "��" << endl;
	if (b1 != 0)
		cout << "5��  : " << b1 << "��" << endl;
	if (b2 != 0)
		cout << "1��  : " << b2 << "��" << endl;
	if (b3 != 0)
		cout << "5��  : " << b3 << "��" << endl;
	if (b4 != 0)
		cout << "2��  : " << b4 << "��" << endl;
	if (b5 != 0)
		cout << "1��  : " << b5 << "��" << endl;

	return 0;
}
