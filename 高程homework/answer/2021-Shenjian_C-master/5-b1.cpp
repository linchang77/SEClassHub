/*1953609 ��� ���͢*/
#include <iostream>
using namespace std;
int main()
{
    int a[22];
    cout << "��������������������������20��������-1����" << endl;
	int i = 0, b = 0, m = 0,k=0;
	for (int j = 0; j < 22; j++)
		a[j] = 1;
    while (a[i] >0&&i<=21)
    {
		if (i != 0)
			i++;
        for(;i < 21;++i)
        {
            cin >> a[i];
			if (a[0] <0)
			{
				cout << "����Ч����" << endl;
				break;
			}
			if (getchar() == '\n')
				break;
        }     
    }
	if (i >= 20)
	{
		i = 20;
		if (getchar() != '\n')
			cin.ignore(2147483647, '\n');
	}
	if (a[0]>0)
	{
		cout << "ԭ����Ϊ:" << endl;
		for (int j = 0; j < i; j++)
		{
			cout << a[j] << " ";
		}
		cout << endl;
		cout << "������Ҫ�����������" << endl;
		cin >> b;
		int low = 0, high = i - 1;
		while (low <= high)
		{
			m = (low + high) / 2;
			if (b >= a[m])
			{
				low = m + 1;
			}
			else
			{
				high = m - 1;
			}
		}
		for (k=i-1; k>high; k--)
			a[k + 1] = a[k];
		a[k+1] = b;
		cout << "����������Ϊ:" << endl;
		for (int j = 0; j <= i; j++)
		{
			cout << a[j] << " ";
		}
		cout << endl;
	}
    return 0;
}

