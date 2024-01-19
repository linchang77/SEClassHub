/*2250420 软工 陈君*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

int main()
{   double a;
    cout << "请输入[0-100亿)之间的数字: " << endl;
    cin >> a;
	int a1 = (int)(a/10);//将这个数十位之前的数取出来 
	cout << setw(7)<< setiosflags(ios::left) << "十亿位" << ": " << a1 / 100000000 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "亿位" << ": "   << a1 / 10000000 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "千万位" << ": " << a1 / 1000000 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "百万位" << ": " << a1 / 100000 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "十万位" << ": " << a1 / 10000 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "万位" << ": "   << a1 / 1000 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "千位" << ": "   << a1 / 100 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "百位" << ": "   << a1 / 10 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "十位" << ": "   << a1 % 10 << endl;
	int a2 = round((a/10-a1)*1000);
	cout << setw(7)<< setiosflags(ios::left) << "圆" << ": " << a2 / 100 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "角" << ": " << a2 / 10 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "分" << ": " << a2  % 10 << endl<<endl;

	return 0;
}


