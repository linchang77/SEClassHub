/*1953609 �� ���͢*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

int main()
{
	double pi = 3.14159;
	int a,b,angle;
	cout << "�����������ε����߼���нǣ��Ƕȣ�:" << endl;
	cin >> a >> b>>angle;
	double s = 0.5 * a * b * sin(angle/180.0*pi);
	cout << setiosflags(ios::fixed) << setprecision(3) << setw(13)
		<< setiosflags(ios::left) << "���������Ϊ" << ": " << static_cast<float>(s) << endl;

	return 0;
}