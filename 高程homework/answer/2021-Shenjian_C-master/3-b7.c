/*��� 1953609 ���͢*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	double a;
	int tag = 0;
	printf("������[0,100�ڣ�֮�������:\n");
	scanf("%lf",&a);
	printf("��д����ǣ�\n");
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
	if (billion != 0)
	{
		switch (billion)
		{
			case 1:
				printf("Ҽ");
				break;
			case 2:
				printf("��");
				break;
			case 3:
				printf("��");
				break;
			case 4:
				printf("��");
				break;
			case 5:
				printf("��");
				break;
			case 6:
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
			default:
				break;
		}
		printf("ʰ");
		if (hundred_million == 0)
			printf("��");
	}
	if (hundred_million != 0)
	{
		switch (hundred_million)
		{
			case 1:
				printf("Ҽ");
				break;
			case 2:
				printf("��");
				break;
			case 3:
				printf("��");
				break;
			case 4:
				printf("��");
				break;
			case 5:
				printf("��");
				break;
			case 6:
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
			default:
				break;
		}
		printf("��");
	}
	if (ten_million != 0)
	{
		switch (ten_million)
		{
			case 1:
				printf("Ҽ");
				break;
			case 2:
				printf("��");
				break;
			case 3:
				printf("��");
				break;
			case 4:
				printf("��");
				break;
			case 5:
				printf("��");
				break;
			case 6:
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
			default:
				break;
		}
		printf("Ǫ");
		if (million == 0 && hundred_thousand == 0 && ten_thousand == 0)
			printf("��");
	}
	else if ((million != 0 || hundred_thousand != 0 || ten_thousand != 0))
		if (hundred_million != 0 || billion != 0)
			printf("��");
	if (million != 0)
	{
		switch (million)
		{
			case 1:
				printf("Ҽ");
				break;
			case 2:
				printf("��");
				break;
			case 3:
				printf("��");
				break;
			case 4:
				printf("��");
				break;
			case 5:
				printf("��");
				break;
			case 6:
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
			default:
				break;
		}
		printf("��");
		if (hundred_thousand == 0 && ten_thousand == 0)
			printf("��");
	}
	else if (ten_million != 0)
		if (hundred_thousand != 0 || ten_thousand != 0)
			printf("��");
	if (hundred_thousand != 0)
	{
		switch (hundred_thousand)
		{
			case 1:
				printf("Ҽ");
				break;
			case 2:
				printf("��");
				break;
			case 3:
				printf("��");
				break;
			case 4:
				printf("��");
				break;
			case 5:
				printf("��");
				break;
			case 6:
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
			default:
				break;
		}
		printf("ʰ");
		if (ten_thousand == 0)
			printf("��");
	}
	else if (million != 0 && ten_thousand != 0)
		printf("��");
	if (ten_thousand != 0)
	{
		switch (ten_thousand)
		{
			case 1:
				printf("Ҽ");
				break;
			case 2:
				printf("��");
				break;
			case 3:
				printf("��");
				break;
			case 4:
				printf("��");
				break;
			case 5:
				printf("��");
				break;
			case 6:
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
			default:
				break;
		}
		printf("��");
	}
	if (thousand != 0)
	{
		switch (thousand)
		{
			case 1:
				printf("Ҽ");
				break;
			case 2:
				printf("��");
				break;
			case 3:
				printf("��");
				break;
			case 4:
				printf("��");
				break;
			case 5:
				printf("��");
				break;
			case 6:
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
			default:
				break;
		}
		printf("Ǫ");
	}
	else if (hundred != 0 || ten != 0 || yuan != 0)
		if (billion != 0 || hundred_million != 0 || ten_million != 0 || million != 0 || hundred_thousand != 0 || ten_thousand != 0)
			printf("��");
	if (hundred != 0)
	{
		switch (hundred)
		{
			case 1:
				printf("Ҽ");
				break;
			case 2:
				printf("��");
				break;
			case 3:
				printf("��");
				break;
			case 4:
				printf("��");
				break;
			case 5:
				printf("��");
				break;
			case 6:
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
			default:
				break;
		}
		printf("��");
	}
	else if (thousand != 0)
		if (ten != 0 || yuan != 0)
			printf("��");
	if (ten != 0)
	{
		switch (ten)
		{
			case 1:
				printf("Ҽ");
				break;
			case 2:
				printf("��");
				break;
			case 3:
				printf("��");
				break;
			case 4:
				printf("��");
				break;
			case 5:
				printf("��");
				break;
			case 6:
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
			default:
				break;
		}
		printf("ʰ");
	}
	else if (hundred != 0 && yuan != 0)
		printf("��");
	if (yuan != 0 || billion != 0 || hundred_million != 0 || ten_million != 0 || million != 0 || hundred_thousand != 0 || ten_thousand != 0 || thousand != 0 || hundred != 0 || ten != 0)
	{
		tag = 1;
	}
	if (yuan != 0)
	{
		switch (yuan)
		{
			case 1:
				printf("Ҽ");
				break;
			case 2:
				printf("��");
				break;
			case 3:
				printf("��");
				break;
			case 4:
				printf("��");
				break;
			case 5:
				printf("��");
				break;
			case 6:
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
			default:
				break;
		}
		printf("Բ");
	}
	else if (tag == 1)
	{
		printf("Բ");
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
						printf("��Բ");
					}
				}
			}
		}
		printf("��");
	}
	if (jiao != 0)
	{
		switch (jiao)
		{
			case 1:
				printf("Ҽ");
				break;
			case 2:
				printf("��");
				break;
			case 3:
				printf("��");
				break;
			case 4:
				printf("��");
				break;
			case 5:
				printf("��");
				break;
			case 6:
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
			default:
				break;
		}
		printf("��");
	}
	else if (jiao == 0 && fen != 0)
	{
		if (tag == 1 || yuan != 0)
			printf("��");
	}
	if (fen != 0)
	{
		switch (fen)
		{
			case 1:
				printf("Ҽ");
				break;
			case 2:
				printf("��");
				break;
			case 3:
				printf("��");
				break;
			case 4:
				printf("��");
				break;
			case 5:
				printf("��");
				break;
			case 6:
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
			default:
				break;
		}
		printf("��");
	}
	else if (fen == 0 && jiao != 0)
		printf("��");
	printf("\n");
	return 0;//3-b7��Ӧ��cpp��ʽ��ҵ�ı����ʽ����
}
//3-b7��Ӧ��cpp��ʽ��ҵ�ı����ʽ����
