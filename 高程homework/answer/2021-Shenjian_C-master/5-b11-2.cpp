/*1953609 ��� ���͢*/
#include <iostream>
#include <string>
#include<math.h>
using namespace std;
//�ɰ���������Ҫ��ͷ�ļ�

const char chistr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
string result;  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/
void daxie(int num, int flag_of_zero)
{
	switch (num) {
		case 0:
			if (flag_of_zero)
			{
				result.push_back(chistr[0]);
				result.push_back(chistr[1]);
			}
			break;
		case 1:
			result.push_back(chistr[2]);
			result.push_back(chistr[3]);
			break;
		case 2:
			result.push_back(chistr[4]);
			result.push_back(chistr[5]);
			break;
		case 3:
			result.push_back(chistr[6]);
			result.push_back(chistr[7]);
			break;
		case 4:
			result.push_back(chistr[8]);
			result.push_back(chistr[9]);
			break;
		case 5:
			result.push_back(chistr[10]);
			result.push_back(chistr[11]);
			break;
		case 6:
			result.push_back(chistr[12]);
			result.push_back(chistr[13]);
			break;
		case 7:
			result.push_back(chistr[14]);
			result.push_back(chistr[15]);
			break;
		case 8:
			result.push_back(chistr[16]);
			result.push_back(chistr[17]);
			break;
		case 9:
			result.push_back(chistr[18]);
			result.push_back(chistr[19]);
			break;
		default:
			break;
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
    /* --���������Ҫ������ --*/
	const char cha[] = "ʰ��Ǫ����Բ�Ƿ���";
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
	daxie(billion, 0);
	if (billion != 0)
	{
		result.push_back(cha[0]);
		result.push_back(cha[1]);
		if (hundred_million == 0)
		{
			result.push_back(cha[8]);
			result.push_back(cha[9]);
		}
	}
	daxie(hundred_million, 0);
	if (hundred_million != 0)
	{
		result.push_back(cha[8]);
		result.push_back(cha[9]);
	}
	if (ten_million != 0)
	{
		daxie(ten_million, 0);
		result.push_back(cha[4]);
		result.push_back(cha[5]);
		if (million == 0 && hundred_thousand == 0 && ten_thousand == 0)
		{
			result.push_back(cha[6]);
			result.push_back(cha[7]);
		}
	}
	else
		tag = 1;
	if (million != 0)
	{
		if (hundred_million != 0 || billion != 0)
		{
			daxie(0, tag);
		}
		daxie(million, tag);
		result.push_back(cha[2]);
		result.push_back(cha[3]);
		if (hundred_thousand == 0 && ten_thousand == 0)
		{
			result.push_back(cha[6]);
			result.push_back(cha[7]);
		}
		tag = 0;
	}
	else
		tag = 1;
	if (hundred_thousand != 0)
	{
		if (hundred_million != 0 || billion != 0 || million != 0)
		{
			daxie(0, tag);
		}
		daxie(hundred_thousand, tag);
		result.push_back(cha[0]);
		result.push_back(cha[1]);
		if (ten_thousand == 0)
		{
			result.push_back(cha[6]);
			result.push_back(cha[7]);
		}
		tag = 0;
	}
	else
		tag = 1;
	if (ten_thousand != 0)
	{
		if (hundred_million != 0 || billion != 0 || million != 0 || hundred_thousand != 0)
		{
			daxie(0, tag);
		}
		daxie(ten_thousand, tag);
		result.push_back(cha[6]);
		result.push_back(cha[7]);
		tag = 0;
	}
	tag = 0;
	if (thousand != 0)
	{
		daxie(thousand, 0);
		result.push_back(cha[4]);
		result.push_back(cha[5]);
	}
	else
		tag = 1;
	if (hundred != 0)
	{
		if (billion != 0 || hundred_million != 0 || ten_million != 0 || million != 0 || hundred_thousand != 0 || ten_thousand != 0 || thousand != 0)
		{
			daxie(0, tag);
		}
		daxie(hundred, tag);
		result.push_back(cha[2]);
		result.push_back(cha[3]);
		tag = 0;
	}
	else
		tag = 1;
	if (ten != 0)
	{
		if (billion != 0 || hundred_million != 0 || ten_million != 0 || million != 0 || hundred_thousand != 0 || ten_thousand != 0 || thousand != 0 || hundred != 0)
		{
			daxie(0, tag);
		}
		daxie(ten, tag);
		result.push_back(cha[0]);
		result.push_back(cha[1]);
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
		{
			daxie(0, tag);
		}
		daxie(yuan, tag);
		result.push_back(cha[10]);
		result.push_back(cha[11]);
	}
	else if (tag_yuan == 1)
	{
		result.push_back(cha[10]);
		result.push_back(cha[11]);
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
						result.push_back(cha[10]);
						result.push_back(cha[11]);
					}
				}
			}
		}
		result.push_back(cha[16]);
		result.push_back(cha[17]);
	}
	tag = 0;
	if (jiao != 0)
	{
		daxie(jiao, tag);
		result.push_back(cha[12]);
		result.push_back(cha[13]);
	}
	else if (jiao == 0 && fen != 0)
	{
		if (tag_yuan == 1)
		{
			daxie(0, 1);
		}
	}
	if (fen != 0)
	{
		daxie(fen, tag);
		result.push_back(cha[14]);
		result.push_back(cha[15]);
	}
	else if (fen == 0 && jiao != 0)
	{
		result.push_back(cha[16]);
		result.push_back(cha[17]);
	}
    cout << result << endl;  /* ת���õ��Ĵ�д�����ֻ�����ñ���������֮ǰ�������κ���ʽ�Ĳ������ */
    return 0;
}

