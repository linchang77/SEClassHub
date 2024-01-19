/* 2250420 �¾� �� */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�����������hanoi�ж���һ����̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
  ���������int n������
            char src����ʼ��
            char tmp���м���
            char dst��Ŀ����
  �� �� ֵ��
  ˵    ����1�����������βΡ��������;���׼��
            2������������������κ���ʽ��ѭ��
            3��������һ����̬�ֲ�����
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	static int step=0;
	if (n == 1) //A   B   C
	{	
	    ++step; 
		cout <<setw(5)<<step<<":"<< "  1# " << src << "-->" << dst << endl;
	
		return;
	}
	hanoi(n - 1, src, dst, tmp);
	++step;
	cout <<setw(5)<<step<<":"<< setiosflags(ios::right) << setw(3) << n << "# " << src << "-->" << dst << endl;
	
	hanoi(n - 1, tmp, src, dst);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
            2�������������ʱ������ʹ��ѭ��
            3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
		int n;
	char src, tmp, dst;
	while (1)
	{
		cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
         cin >> n;	
		 if (n <= 16 && n >= 1)
		 {
			 while (getchar() != '\n')
				 ;
			 break;
		 }
		 cin.clear();
		 while (getchar() != '\n')
			 ;
	}
	while (1)
	{
		cout << "��������ʼ��(A-C)" << endl;
		cin >> src;
		if (src >= 'a' && src <= 'c')
		{
			src = src - 32;
			while (getchar() != '\n')
				;
			break;
		}
		if (src >= 'A' && src <= 'C')
		{
			while (getchar() != '\n')
				;
			break;
		}
			
		cin.clear();
		while (getchar() != '\n')
			;
	}
	
	while (1)
	{
		cout << "������Ŀ����(A-C)" << endl;
		cin >> dst;
		if (dst == src)
		{
			while (getchar() != '\n')
				;
			cout << "Ŀ����(A)��������ʼ��(A)��ͬ" << endl;
			continue;
		}
		if (dst >= 'a' && dst <= 'c'&&dst!=src)
		{
			dst = dst - 32;
			while (getchar() != '\n')
				;
			break;
		}
		if (dst >= 'A' && dst <= 'C' && dst != src)
		{
			while (getchar() != '\n')
				;
			break;
		}
		
		cin.clear();
		while (getchar() != '\n')
			;
	}
	
	tmp = 'A' + 'B' + 'C' - src - dst;
	cout << "�ƶ�����Ϊ:" << endl;
	hanoi(n, src, tmp, dst);
	return 0;
}
