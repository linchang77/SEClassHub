/*1953609 ��� ���͢*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double pi = 3.14159;
	cout << "������뾶�͸߶�" << endl;
	double r, h, c, s, s_surface, v_ball, v_cylinder;
	cin >> r >> h;
	c = 2 * pi * r;
	s = pi * r * r;
	s_surface = 4 * pi * r * r;
	v_ball = 4.0 / 3 * pi * r * r * r;
	v_cylinder = pi * r * r * h;
	cout << setiosflags(ios::fixed) << setprecision(2) << setw(11)
		<< setiosflags(ios::left) << "Բ�ܳ�" << ": " << c << endl;
	cout << setiosflags(ios::fixed) << setprecision(2) << setw(11)
		<< setiosflags(ios::left) << "Բ���" << ": " << s << endl;
	cout << setiosflags(ios::fixed) << setprecision(2) << setw(11)
		<< setiosflags(ios::left) << "Բ������" << ": " << s_surface << endl;
	cout << setiosflags(ios::fixed) << setprecision(2) << setw(11)
		<< setiosflags(ios::left) << "Բ�����" << ": " << v_ball << endl;
	cout << setiosflags(ios::fixed) << setprecision(2) << setw(11)
		<< setiosflags(ios::left) << "Բ�����" << ": " << v_cylinder << endl;

	return 0;
}
