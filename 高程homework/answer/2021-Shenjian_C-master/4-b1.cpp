/*1953609 ��� ���͢*/
#include <iostream>
#include<math.h>
using namespace std;

/* �ɸ�����Ҫ�����Ӧ������ */

/***************************************************************************
  �������ƣ�
  ��    �ܣ������д��0~9
  ���������
  �� �� ֵ��
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
				cout << "��";
			break;
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
			cout << "error";
			break;
	}
}

/* �ɸ�����Ҫ�Զ�����������(Ҳ���Բ�����) */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	/* ������� */
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
	const int yuan = static_cast<int>(floor((a / 10.0 - floor(a / 10)) * 10 + 1e-7));
	const int jiao = static_cast<int>(round((a - floor(a)) * 100)) / 10 % 10;
	const int fen = static_cast<int>(round((a - floor(a)) * 100)) % 10;
	daxie(billion,0);
	if (billion != 0)
	{
		cout << "ʰ";
		if (hundred_million == 0)
			cout << "��";
	}
	daxie(hundred_million, 0);
	if(hundred_million!=0)
		cout << "��";
	if (ten_million != 0)
	{
		daxie(ten_million, 0);
		cout << "Ǫ";
		if (million == 0 && hundred_thousand == 0 && ten_thousand == 0)
			cout << "��";
	}
	else
		tag = 1;
	if (million != 0)
	{
		if (hundred_million != 0 || billion != 0)
			daxie(0, tag);
		daxie(million, tag);
		cout << "��";
		if (hundred_thousand == 0 && ten_thousand == 0)
			cout << "��";
		tag = 0;
	}
	else
		tag = 1;
	if (hundred_thousand != 0)
	{
		if (hundred_million != 0 || billion != 0 || million != 0)
			daxie(0, tag);
		daxie(hundred_thousand, tag);
		cout << "ʰ";
		if (ten_thousand == 0)
			cout << "��";
		tag = 0;
	}
	else
		tag = 1;
	if (ten_thousand != 0)
	{
		if (hundred_million != 0 || billion != 0 || million != 0|| hundred_thousand != 0)
			daxie(0, tag);
		daxie(ten_thousand, tag);
		cout << "��";
		tag = 0;
	}
	tag = 0;
	if (thousand != 0)
	{
		daxie(thousand, 0);
		cout << "Ǫ";
	}
	else
		tag = 1;
	if (hundred != 0)
	{
		if (billion != 0 || hundred_million != 0 || ten_million != 0 || million != 0 || hundred_thousand != 0 || ten_thousand != 0|| thousand != 0)
			daxie(0, tag);
		daxie(hundred, tag);
		cout << "��";
		tag = 0;
	}
	else
		tag = 1;
	if (ten != 0)
	{
		if (billion != 0 || hundred_million != 0 || ten_million != 0 || million != 0 || hundred_thousand != 0 || ten_thousand != 0 || thousand != 0||hundred!=0)
			daxie(0, tag);
		daxie(ten, tag);
		cout << "ʰ";
		tag = 0;
	}
	else
		tag = 1;
	int tag_yuan = 0;
	if (yuan != 0 || billion != 0 || hundred_million != 0 || ten_million != 0 || million != 0 || hundred_thousand != 0 || ten_thousand != 0 || thousand != 0 || hundred != 0 || ten != 0)
	{
		tag_yuan = 1;
	}
	if (yuan != 0)
	{
		if (billion != 0 || hundred_million != 0 || ten_million != 0 || million != 0 || hundred_thousand != 0 || ten_thousand != 0 || thousand != 0 || hundred != 0 || ten != 0)
			daxie(0, tag);
		daxie(yuan, tag);
		cout << "Բ";
	}
	else if (tag_yuan == 1)
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
						daxie(0, 1);
						cout << "Բ";
					}
				}
			}
		}
		cout << "��";
	}
	tag = 0;
	if (jiao != 0)
	{
		daxie(jiao, tag);
		cout << "��";
	}
	else if (jiao == 0 && fen != 0)
	{
		if (tag_yuan == 1)
			daxie(0,1);
	}
	if (fen != 0)
	{
		daxie(fen, tag);
		cout << "��";
	}
	else if (fen == 0 && jiao != 0)
		cout << "��";
	cout << endl;
	return 0;
}
