/*1953609 �� ���͢*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int integer;
	cout << "������һ��[1..30000]�������:" << endl;
	cin >> integer;
	cout << setw(5)<< setiosflags(ios::left) << "��λ" << ": " << integer / 10000 << endl;
	cout << setw(5)<< setiosflags(ios::left) << "ǧλ" << ": " << integer / 1000 % 10 << endl;
	cout << setw(5)<< setiosflags(ios::left) << "��λ" << ": " << integer / 100 % 10 << endl;
	cout << setw(5)<< setiosflags(ios::left) << "ʮλ" << ": " << integer / 10 %10<< endl;
	cout << setw(5)<< setiosflags(ios::left) << "��λ" << ": " << integer % 10 << endl;

	return 0;
}
