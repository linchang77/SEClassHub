/*1953609 ��� ���͢*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
int main()
{
	double a;
	int tag = 0;
	cout << "������[0,100�ڣ�֮�������:" << endl;
	cin >> a;
	cout << "��д����ǣ�" << endl;
	const int a1 = static_cast<int>(a / 10);
	const int billion = a1 / 100000000;
	const int hundred_million = a1 / 10000000 % 10;
	const int ten_million = a1 / 1000000 % 10;
	const int million = a1 / 100000 % 10;
	const int hundred_thousand = a1 / 10000 % 10;
	const int ten_thousand = a1 / 1000 % 10;
	const int thousand = a1 / 100 % 10;
	const int hundred = a1 / 10 % 10;
	const int ten = a1 % 10;
	const int yuan = static_cast<int>(floor((a / 10.0 - floor(a / 10)) * 10+1e-7));
	const int jiao = static_cast<int>(round((a - floor(a)) * 100)) / 10 % 10;
	const int fen = static_cast<int>(round((a - floor(a)) * 100)) % 10;
	if (billion != 0)
	{
		switch (billion)
		{
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
			default:
				break;
		}
		cout << "ʰ";
		if (hundred_million == 0)
			cout << "��";
	}
	if (hundred_million != 0)
	{
		switch (hundred_million)
		{
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
			default:
				break;
		}
		cout << "��";
	}
	if (ten_million != 0)
	{
		switch (ten_million)
		{
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
			default:
				break;
		}
		cout << "Ǫ";
		if (million == 0 && hundred_thousand == 0 && ten_thousand == 0)
			cout << "��";
	}
	else if ((million != 0 || hundred_thousand != 0 || ten_thousand != 0))
		if(hundred_million!=0||billion!=0)
		cout << "��";
	if (million != 0)
	{
		switch (million)
		{
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
			default:
				break;
		}
		cout << "��";
		if (hundred_thousand== 0&&ten_thousand==0)
	        cout << "��";
	}
	else if (ten_million != 0)
		if (hundred_thousand != 0 || ten_thousand != 0)
		    cout << "��";
	if (hundred_thousand != 0)
	{
		switch (hundred_thousand)
		{
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
			default:
				break;
		}
		cout << "ʰ";
		if (ten_thousand == 0)
			cout << "��";
	}
	else if (million != 0 && ten_thousand != 0)
		cout << "��";
	if (ten_thousand != 0)
	{
		switch (ten_thousand)
		{
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
			default:
				break;
		}
		cout << "��";
	}
	if (thousand != 0)
	{
		switch (thousand)
		{
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
			default:
				break;
		}
		cout << "Ǫ";
	}
	else if (hundred != 0 || ten != 0 || yuan != 0)
		if(billion!=0||hundred_million!=0||ten_million!=0|| million != 0 || hundred_thousand != 0 || ten_thousand != 0)
	        cout << "��";
	if (hundred != 0)
	{
		switch (hundred)
		{
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
			default:
				break;
		}
		cout << "��";
	}
	else if(thousand!=0)
		if(ten!=0||yuan!=0)
		cout << "��";
	if (ten != 0)
	{
		switch (ten)
		{
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
			default:
				break;
		}
		cout << "ʰ";
	}
	else if (hundred != 0 && yuan!=0)
		cout << "��";
	if (yuan != 0 || billion != 0 || hundred_million != 0 || ten_million != 0 || million != 0 || hundred_thousand != 0 || ten_thousand != 0 || thousand != 0 || hundred != 0 || ten != 0)
	{
		tag = 1;
	}
	if (yuan != 0)
	{
		switch (yuan)
		{
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
			default:
				break;
		}
		cout << "Բ";
	}
	else if (tag==1)
	{
        cout << "Բ";
	}	
	if (jiao == 0 && fen == 0)
	{
		if (yuan == 0)
		{
			if (billion == 0 && hundred_million == 0 && ten_million == 0)
			{
				if (million == 0 && hundred_thousand == 0 && ten_thousand == 0)
				{
					if (thousand == 0 && hundred == 0 && ten == 0)
					{
						cout << "��Բ";
					}
				}
			}
		}
		cout << "��";
	}
	if (jiao != 0)
	{
		switch (jiao)
		{
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
			default:
				break;
		}
		cout << "��";
	}
	else if (jiao == 0 && fen != 0)
	{
		if (tag == 1 || yuan != 0)
			cout << "��";
	}
	if (fen != 0)
	{
		switch (fen)
		{
			case 1:
				cout << "Ҽ";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "½";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "��";
				break;
			case 9:
				cout << "��";
				break;
			default:
				break;
		}
		cout << "��";
	}
	else if (fen == 0 && jiao != 0)
		cout << "��";
	cout << endl;
	return 0;
}
