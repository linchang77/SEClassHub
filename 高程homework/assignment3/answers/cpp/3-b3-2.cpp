/*2250420 �� �¾�*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

int main()
{   double a;
    cout << "������[0-100��)֮�������: " << endl;
    cin >> a;
	int a1 = (int)(a/10);//�������ʮλ֮ǰ����ȡ���� 
	cout << setw(7)<< setiosflags(ios::left) << "ʮ��λ" << ": " << a1 / 100000000 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "��λ" << ": "   << a1 / 10000000 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "ǧ��λ" << ": " << a1 / 1000000 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "����λ" << ": " << a1 / 100000 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "ʮ��λ" << ": " << a1 / 10000 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "��λ" << ": "   << a1 / 1000 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "ǧλ" << ": "   << a1 / 100 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "��λ" << ": "   << a1 / 10 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "ʮλ" << ": "   << a1 % 10 << endl;
	int a2 = round((a/10-a1)*1000);
	cout << setw(7)<< setiosflags(ios::left) << "Բ" << ": " << a2 / 100 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "��" << ": " << a2 / 10 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "��" << ": " << a2  % 10 << endl<<endl;

	return 0;
}


