/*2250420 软工 陈君*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
int plate[3][10];
int num[3];//记录柱子上的盘子数
int step = 0;
void putout()//输出当前数组情况
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
		cout << "第" << setiosflags(ios::right) << setw(4) << step << " 步" << "(" <<
			setiosflags(ios::right) << setw(2) << "1" << "): " << src << "-->" << dst ;
		move(src, dst);
		putout();
		return;
	}
	hanoi(n - 1, src, dst, tmp);
	step++;
	cout << "第" << setiosflags(ios::right) << setw(4) << step << " 步" << "(" <<
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
		cout << "请输入汉诺塔的层数(1-10)" << endl;
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
		cout << "请输入起始柱(A-C)" << endl;
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
		cout << "请输入目标柱(A-C)" << endl;
		cin >> dst;
		if (dst == src)
		{
			while (getchar() != '\n')
				;
			cout << "目标柱(A)不能与起始柱(A)相同" << endl;
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
	cout << "初始:               ";
	putout();
	hanoi(n, src, tmp, dst);
	return 0;
}






