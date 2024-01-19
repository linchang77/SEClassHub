/*2250420 �� �¾�*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
int plate[3][10];
int num[3];//��¼�����ϵ�������
int step = 0;
void putout()//�����ǰ�������
{
	cout << " A:";
	for (int i = 0; i < 10; i++)
		if (plate[0][i] > 0)
			cout << setw(2)<<plate[0][i] ;
		else
			cout << "  ";
	cout << " B:";
	for (int i = 0; i < 10; i++)
		if (plate[1][i] > 0)
			cout << setw(2)<<plate[1][i] ;
		else
			cout << "  ";
	cout << " C:";
	for (int i = 0; i < 10; i++)
		if (plate[2][i] > 0)
			cout << setw(2)<<plate[2][i];
		else
			cout << "  ";
	cout << endl;
}
void move(char src, char dst)
{
	plate[dst - 'A'][num[dst - 'A']] = plate[src - 'A'][num[src - 'A']-1];
	plate[src - 'A'][num[src - 'A'] - 1] = 0;
	num[dst - 'A']++;
	num[src - 'A']--;
	
}
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1) //A   B   C
	{
		step++;
		cout << "��" << setiosflags(ios::right) << setw(4) << step << " ��" << "(" <<
			setiosflags(ios::right) << setw(2) << "1" << "): " << src << "-->" << dst ;
		move(src, dst);
		putout();
		return;
	}
	hanoi(n - 1, src, dst, tmp);
	step++;
	cout << "��" << setiosflags(ios::right) << setw(4) << step << " ��" << "(" <<
		setiosflags(ios::right) << setw(2) << n <<  "): " << src << "-->" << dst  ;
	move(src, dst);
	putout();
	hanoi(n - 1, tmp, src, dst);
}
int main()
{
	int n;
	char src, tmp, dst;
	while (1)
	{
		cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
		cin >> n;
		if (n <= 10 && n >= 1)
		{
			while (getchar() != '\n')
				;
			break;
		}
		cin.clear();
		while (getchar() != '\n')
			;
	}
	while (1)
	{
		cout << "��������ʼ��(A-C)" << endl;
		cin >> src;
		if (src >= 'a' && src <= 'c')
		{
			src = src - 32;
			while (getchar() != '\n')
				;
			break;
		}
		if (src >= 'A' && src <= 'C')
		{
			while (getchar() != '\n')
				;
			break;
		}

		cin.clear();
		while (getchar() != '\n')
			;
	}

	while (1)
	{
		cout << "������Ŀ����(A-C)" << endl;
		cin >> dst;
		if (dst == src)
		{
			while (getchar() != '\n')
				;
			cout << "Ŀ����(A)��������ʼ��(A)��ͬ" << endl;
			continue;
		}
		if (dst >= 'a' && dst <= 'c' && dst != src)
		{
			dst = dst - 32;
			while (getchar() != '\n')
				;
			break;
		}
		if (dst >= 'A' && dst <= 'C' && dst != src)
		{
			while (getchar() != '\n')
				;
			break;
		}

		cin.clear();
		while (getchar() != '\n')
			;
	}
	for (int i = 0; i < n; i++)
			plate[src-'A'][i] = n - i;
	num[src - 'A'] = n;
	tmp = 'A' + 'B' + 'C' - src - dst;
	cout << "��ʼ:               ";
	putout();
	hanoi(n, src, tmp, dst);
	return 0;
}






