/*1953609 �� ���͢*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

int main()
{
    double a;
    cout << "������[0,100�ڣ�֮�������:" << endl;
    cin >> a;
	int a1 = static_cast<int>(a/10);
	cout << setw(7)<< setiosflags(ios::left) << "ʮ��λ" << ": " << a1/ 100000000 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "��λ" << ": " << a1 / 10000000%10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "ǧ��λ" << ": " << a1 / 1000000 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "����λ" << ": " << a1 / 100000 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "ʮ��λ" << ": " << a1 / 10000 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "��λ" << ": " << a1 / 1000 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "ǧλ" << ": " << a1 / 100 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "��λ" << ": " << a1 / 10 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "ʮλ" << ": " << a1 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "Բ" << ": " << floor((a / 10 - floor(a / 10)) * 10) << endl;
	cout << setw(7)<< setiosflags(ios::left) << "��" << ": " << static_cast<int>(round((a - floor(a)) * 100))/10% 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "��" << ": " << static_cast<int>(round((a - floor(a))*100))%10<< endl;
	//��׼��ֻ��С��������λ�����������С�������λ��������Ϊ��������

	return 0;
}

