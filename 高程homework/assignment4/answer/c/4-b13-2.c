/* 2250420 �¾� �� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
static int step=0;
/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2��������һ��ȫ�ֱ������������徲̬�ֲ�����
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
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	static int step=0;
	if (n == 1) //A   B   C
	{	
	    ++step; 
	    printf("%5d:  1# %c-->%c\n",step,src,dst);
		return;
	}
	hanoi(n - 1, src, dst, tmp);
	++step;
	printf("%5d:%3d# %c-->%c\n",step,n,src,dst);
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
		printf("�����뺺ŵ���Ĳ���(1-16)\n");
        int tag=scanf("%d",&n);	
		 if (n <= 16 && n >= 1&&tag==1)
		 {
			 while (getchar() != '\n')
				 ;
			 break;
		 }
		 while (getchar() != '\n')
			 ;
	}
	while (1)
	{
		printf("��������ʼ��(A-C)\n");
		int tag=scanf("%c",&src);
		if (src >= 'a' && src <= 'c'&&tag==1)
		{
			src = src - 32;
			while (getchar() != '\n')
				;
			break;
		}
		if (src >= 'A' && src <= 'C'&&tag==1)
		{
			while (getchar() != '\n')
				;
			break;
		}
		while (getchar() != '\n')
			;
	}
	while (1)
	{
		printf("������Ŀ����(A-C)\n");
		int tag=scanf("%c",&dst);
		if (dst == src)
		{
			while (getchar() != '\n')
				;
			printf("Ŀ����(A)��������ʼ��(A)��ͬ\n");
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
		while (getchar() != '\n')
			;
	}
	
	tmp = 'A' + 'B' + 'C' - src - dst;
	printf("�ƶ�����Ϊ:\n");
	hanoi(n, src, tmp, dst);
	return 0;
}
