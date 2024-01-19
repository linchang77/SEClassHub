/*2250420 软工 陈君*/
#include<iostream>
#include<cmath> 
using namespace std;
int main()
{
	cout << "请输入找零值：" << endl;
	double cash;
	cin >> cash;
	if(cash<0.01||cash>=100)
	{
	cout<<"输入错误，请重新输入"<<endl;
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
	cout << "共" << count << "张找零，具体如下：" << endl;
	if (a1 != 0)
		cout << "50元 : " << a1 << "张" << endl;
	if (a2 != 0)
		cout << "20元 : " << a2 << "张" << endl;
	if (a3 != 0)
		cout << "10元 : " << a3 << "张" << endl;
	if (a4 != 0)
		cout << "5元  : " << a4 << "张" << endl;
	if (a5 != 0)
		cout << "1元  : " << a5 << "张" << endl;
	if (b1 != 0)
		cout << "5角  : " << b1 << "张" << endl;
	if (b2 != 0)
		cout << "1角  : " << b2 << "张" << endl;
	if (b3 != 0)
		cout << "5分  : " << b3 << "张" << endl;
	if (b4 != 0)
		cout << "2分  : " << b4 << "张" << endl;
	if (b5 != 0)
		cout << "1分  : " << b5 << "张" << endl;

	return 0;
}
