/*2250420 �� �¾�*/
#include"iostream"
#include "iomanip"
#include"cmath"
using namespace std;
int main()
{
	int x;
	int n = 0;
	long long fenzi = 1;
	long long fenmu = 1;
	double sum = 1;
	while (1)
	{
		puts("������x��ֵ[-10 ~ +65]");
		cin >> x;
		if (x < -10 || x>65)

			cout << "����Ƿ�������������" << endl;
		else
			break;
	}
	while (fabs((double)fenzi / (double)fenmu) >= 0.000001)
	{
		n++;
		fenzi *= x;
		fenmu *= n;
		sum += (double)fenzi / (double)fenmu;
	}
	cout << "e^" << x << '=' << setprecision(10) << sum<<endl;
	return 0;
}
