/*1953609 ��� ���͢*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
//�ɰ���������Ҫ��ͷ�ļ�
const char chistr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
char result[256];  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/
int daxie(int num, int flag_of_zero, int wei)
{
	switch (num) {
		case 0:
			if (flag_of_zero)
			{
				result[wei] = chistr[0];
				result[++wei] = chistr[1];
				return wei+1;
			}
			break;
		case 1:
			result[wei] = chistr[2];
			result[++wei] = chistr[3];
			return wei+1;
			break;
		case 2:
			result[wei] = chistr[4];
			result[++wei] = chistr[5];
			return wei+1;
			break;
		case 3:
			result[wei] = chistr[6];
			result[++wei] = chistr[7];
			return wei+1;
			break;
		case 4:
			result[wei] = chistr[8];
			result[++wei] = chistr[9];
			return wei+1;
			break;
		case 5:
			result[wei] = chistr[10];
			result[++wei] = chistr[11];
			return wei+1;
			break;
		case 6:
			result[wei] = chistr[12];
			result[++wei] = chistr[13];
			return wei+1;
			break;
		case 7:
			result[wei] = chistr[14];
			result[++wei] = chistr[15];
			return wei+1;
			break;
		case 8:
			result[wei] = chistr[16];
			result[++wei] = chistr[17];
			return wei+1;
			break;
		case 9:
			result[wei] = chistr[18];
			result[++wei] = chistr[19];
			return wei+1;
			break;
		default:
			break;
	}
	return wei;
}
int main()
{
	const char cha[] = "ʰ��Ǫ����Բ�Ƿ���";
	double a;
	int tag = 0, wei = 0;
	printf("������[0,100�ڣ�֮�������:\n");
	scanf("%lf", &a);
	printf("��д�����:\n");
	const int a1 = (int)(a / 10);
	const int billion = a1 / 100000000;
	const int hundred_million = a1 / 10000000 % 10;
	const int ten_million = a1 / 1000000 % 10;
	const int million = a1 / 100000 % 10;
	const int hundred_thousand = a1 / 10000 % 10;
	const int ten_thousand = a1 / 1000 % 10;
	const int thousand = a1 / 100 % 10;
	const int hundred = a1 / 10 % 10;
	const int ten = a1 % 10;
	const int yuan = (int)(floor((a / 10.0 - floor(a / 10)) * 10 + 1e-7));
	const int jiao = (int)(round((a - floor(a)) * 100)) / 10 % 10;
	const int fen = (int)(round((a - floor(a)) * 100)) % 10;
	wei=daxie(billion, 0, wei);
	if (billion != 0)
	{
		result[wei] = cha[0];
		result[++wei] = cha[1];
		wei++;
		if (hundred_million == 0)
		{
			result[wei] = cha[8];
			result[++wei] = cha[9];
			wei++;
		}
	}
	wei=daxie(hundred_million, 0, wei);
	if (hundred_million != 0)
	{
		result[wei] = cha[8];
		result[++wei] = cha[9];
		wei++;
	}
	if (ten_million != 0)
	{
		wei=daxie(ten_million, 0, wei);
		result[wei] = cha[4];
		result[++wei] = cha[5];
		wei++;
		if (million == 0 && hundred_thousand == 0 && ten_thousand == 0)
		{
			result[wei] = cha[6];
			result[++wei] = cha[7];
			wei++;
		}
	}
	else
		tag = 1;
	if (million != 0)
	{
		if (hundred_million != 0 || billion != 0)
		{
			wei=daxie(0, tag, wei);
		}
		wei=daxie(million, tag, wei);
		result[wei] = cha[2];
		result[++wei] = cha[3];
		wei++;
		if (hundred_thousand == 0 && ten_thousand == 0)
		{
			result[wei] = cha[6];
			result[++wei] = cha[7];
			wei++;
		}
		tag = 0;
	}
	else
		tag = 1;
	if (hundred_thousand != 0)
	{
		if (hundred_million != 0 || billion != 0 || million != 0)
		{
			wei=daxie(0, tag, wei);
		}
		wei=daxie(hundred_thousand, tag, wei);
		result[wei] = cha[0];
		result[++wei] = cha[1];
		wei++;
		if (ten_thousand == 0)
		{
			result[wei] = cha[6];
			result[++wei] = cha[7];
			wei++;
		}
		tag = 0;
	}
	else
		tag = 1;
	if (ten_thousand != 0)
	{
		if (hundred_million != 0 || billion != 0 || million != 0 || hundred_thousand != 0)
		{
			wei=daxie(0, tag, wei);
		}
		wei=daxie(ten_thousand, tag, wei);
		result[wei] = cha[6];
		result[++wei] = cha[7];
		wei++;
		tag = 0;
	}
	tag = 0;
	if (thousand != 0)
	{
		wei=daxie(thousand, 0, wei);
		result[wei] = cha[4];
		result[++wei] = cha[5];
		wei++;
	}
	else
		tag = 1;
	if (hundred != 0)
	{
		if (billion != 0 || hundred_million != 0 || ten_million != 0 || million != 0 || hundred_thousand != 0 || ten_thousand != 0 || thousand != 0)
		{
			wei=daxie(0, tag, wei);
		}
		wei=daxie(hundred, tag, wei);
		result[wei] = cha[2];
		result[++wei] = cha[3];
		wei++;
		tag = 0;
	}
	else
		tag = 1;
	if (ten != 0)
	{
		if (billion != 0 || hundred_million != 0 || ten_million != 0 || million != 0 || hundred_thousand != 0 || ten_thousand != 0 || thousand != 0 || hundred != 0)
		{
			wei=daxie(0, tag, wei);
		}
		wei=daxie(ten, tag, wei);
		result[wei] = cha[0];
		result[++wei] = cha[1];
		wei++;
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
			wei=daxie(0, tag, wei);
		}
		wei=daxie(yuan, tag, wei);
		result[wei] = cha[10];
		result[++wei] = cha[11];
		wei++;
	}
	else if (tag_yuan == 1)
	{
		result[wei] = cha[10];
		result[++wei] = cha[11];
		wei++;
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
						wei=daxie(0, 1, wei);
						result[wei] = cha[10];
						result[++wei] = cha[11];
						wei++;
					}
				}
			}
		}
		result[wei] = cha[16];
		result[++wei] = cha[17];
		wei++;
	}
	tag = 0;
	if (jiao != 0)
	{
		wei=daxie(jiao, tag, wei);
		result[wei] = cha[12];
		result[++wei] = cha[13];
		wei++;
	}
	else if (jiao == 0 && fen != 0)
	{
		if (tag_yuan == 1)
		{
			wei=daxie(0, 1, wei);
		}
	}
	if (fen != 0)
	{
		wei=daxie(fen, tag, wei);
		result[wei] = cha[14];
		result[++wei] = cha[15];
		wei++;
	}
	else if (fen == 0 && jiao != 0)
	{
		result[wei] = cha[16];
		result[++wei] = cha[17];
		wei++;
	}
	printf("%s\n", result);  /* ת���õ��Ĵ�д�����ֻ�����ñ���������֮ǰ�������κ���ʽ�Ĳ������ */
	return 0;
}
