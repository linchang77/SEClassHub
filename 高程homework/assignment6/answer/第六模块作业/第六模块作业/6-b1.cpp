/* 2250420 �¾� �� */
#include <iostream>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
	cout << "�����������������������ֵ��ַ���" << endl;
	gets_s(str);
	p = str;
	pa = a;
	is_num = 0;
	while (*p != '\0' && pa < a + 10)
	{
		if (*p >= '0' && *p <= '9' )
		{
			if (is_num == 0)
			{
				is_num = 1;
				*pa = *p-'0';
			}
			else
			{
				*pa = *pa *10+ *p - '0';
			}
			
		}
		else
		{
			if (is_num == 1)
			{
				is_num = 0;
				pa++;
			}
		}	
		p++;
	}
	if (pa >= a + 10)
		pa--;
	cout << "����" << pa - a+1 << "������" << endl;
	pnum = a;
	while (1)
	{
		cout << *pnum<<" ";
		if (pnum == pa)
			break;	
		pnum++;
	}
	cout << endl;
	return 0;
}