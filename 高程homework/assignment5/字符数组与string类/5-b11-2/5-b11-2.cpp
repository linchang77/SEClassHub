/* �� 2250420 �¾� */
#include <iostream>
#include <string>
#include<cmath> 
//�ɰ���������Ҫ��ͷ�ļ�
using namespace std;

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
string result;  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void daxie(int num, int flag_of_zero, string& result)
{
	if (flag_of_zero && 0 == num)
	{
		result += chnstr[num * 2];
		result += chnstr[num * 2 + 1];
	}
	else if (num >= 1 && num <= 9)
	{
		result += chnstr[num * 2];
		result += chnstr[num * 2 + 1];
	}
}
int main()
{
	/* --���������Ҫ������ --*/
	double a;
	int flag_of_zero = 0;
	std::cout << "������[0-100��)֮�������:" << endl;
	cin >> a;
	int a1 = (int)(a / 10);//�������ʮλ֮ǰ����ȡ���� 
	int b1 = a1 / 100000000;//ʮ�� 
	int b2 = a1 / 10000000 % 10;//�� 
	int b3 = a1 / 1000000 % 10;//ǧ�� 
	int b4 = a1 / 100000 % 10;//���� 
	int b5 = a1 / 10000 % 10;//ʮ�� 
	int b6 = a1 / 1000 % 10;//�� 
	int b7 = a1 / 100 % 10;//ǧ 
	int b8 = a1 / 10 % 10;//�� 
	int b9 = a1 % 10;//ʮ 
	int a2 = round((a / 10 - a1) * 1000);
	int b10 = a2 / 100 % 10;//Բ 
	int b11 = a2 / 10 % 10;//�� 
	int b12 = a2 % 10;//��
	//ȡ��ÿһλ������
	cout << "��д�����:" << endl;
	if (b1 != 0)
	{
		daxie(b1, flag_of_zero, result);
		result += "ʰ";
	}

	switch (b2)
	{
	case 0:
		if (b1 == 0 && b2 == 0)
			;
		else
			result += "��";
		break;
	default:
		daxie(b2, flag_of_zero, result);
		result += "��";
	}
	switch (b3)
	{
	case 0:
		if (b1 == 0 && b2 == 0)
			break;
		if (b4 != 0)
		{
			daxie(0, 1, result);
			break;
		}
		break;
	default:
		daxie(b3, flag_of_zero, result);
		result += "Ǫ";
	}
	switch (b4)
	{
	case 0:
		if (b1 == 0 && b2 == 0 && b3 == 0)
			break;
		if (b5 != 0)
		{
			daxie(0, 1, result);
			break;
		}
		break;
	default:
		daxie(b4, flag_of_zero, result);
		result += "��";
	}
	switch (b5)
	{
	case 1:
		if (b4 == 0 && b1 == 0 && b2 == 0 && b3 == 0)
		{
			result += "ʰ";
			break;
		}
		else
		{
			daxie(1, flag_of_zero, result);
			result += "ʰ";
			break;
		}
		break;
	case 0:
		if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0)
			break;
		if (b6 != 0)
		{
			result += "��";
			break;
		}
		break;
	default:
		daxie(b5, flag_of_zero, result);
		result += "ʰ";
	}
	switch (b6)
	{
	case 0:
		if (b3 == 0 && b4 == 0 && b5 == 0 && b6 == 0)
			;
		else
			result += "��";
		break;
	default:
		daxie(b6, flag_of_zero, result);
		result += "��";
	}
	switch (b7)
	{
	case 0:
		if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0 && b5 == 0 && b6 == 0)
			break;
		if (b8 != 0)
		{
			daxie(0, 1, result);
			break;
		}
		break;
	default:
		daxie(b7, flag_of_zero, result);
		result += "Ǫ";
	}
	switch (b8)
	{
	case 0:
		if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0 && b5 == 0 && b6 == 0 && b7 == 0)
			break;
		if (b9 != 0)
		{
			daxie(0, 1, result);
			break;
		}
		break;
	default:
		daxie(b8, flag_of_zero, result);
		result += "��";
	}
	switch (b9)
	{
	case 0:
		if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0 && b5 == 0 && b6 == 0 && b7 == 0 && b8 == 0)
			break;
		if (b10 != 0)
		{
			result += "��";
			break;
		}
		break;
	default:
		daxie(b9, flag_of_zero, result);
		result += "ʰ";
	}
	switch (b10)
	{
	case 0:
		if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0 && b5 == 0 && b6 == 0 && b7 == 0 && b8 == 0 && b9 == 0)
			break;
		else
			result += "Բ";
		break;
	default:
		daxie(b10, flag_of_zero, result);
		result += "Բ";
	}
	switch (b11)
	{
	case 0:
		if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0 && b5 == 0 && b6 == 0 && b7 == 0 && b8 == 0 && b9 == 0 && b10 == 0)
			break;
		if (b12 != 0)
			daxie(0, 1, result);
		break;
	default:
		daxie(b11, flag_of_zero, result);
		result += "��";
	}
	switch (b12)
	{
	case 0:
		if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0 && b5 == 0 && b6 == 0 && b7 == 0 && b8 == 0 && b9 == 0 && b10 == 0 && b11 == 0)
		{
			daxie(0, 1, result);
			result += "Բ";
			break;
		}
		break;
	default:
		daxie(b12, flag_of_zero, result);
		result += "��";
	}
	if (b12 == 0)
		result += "��";
	cout << result << endl;  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
	return 0;
}