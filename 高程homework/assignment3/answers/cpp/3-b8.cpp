/*2250420 软工 陈君*/
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
		puts("请输入x的值[-10 ~ +65]");
		cin >> x;
		if (x < -10 || x>65)

			cout << "输入非法，请重新输入" << endl;
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
