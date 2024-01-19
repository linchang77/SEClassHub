/*2250420 �� �¾�*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
int plate[3][10];
int num[3];//��¼�����ϵ�������
int step = 0;
void putout()//�����ǰ�������
{
	printf(" A:");
	for (int i = 0; i < 10; i++)
		if (plate[0][i] > 0)
		printf("%2d",plate[0][i]);
		else
		printf("  ");
	printf(" B:");
	for (int i = 0; i < 10; i++)
		if (plate[1][i] > 0)
		printf("%2d",plate[1][i]);
		else
		printf("  ");
	printf(" C:");
	for (int i = 0; i < 10; i++)
		if (plate[2][i] > 0)
		printf("%2d",plate[2][i]);
		else
		printf("  ");
    printf("\n");
}
void move(char src, char dst)
{
	plate[dst - 'A'][num[dst - 'A']] = plate[src - 'A'][num[src - 'A']-1];
	plate[src - 'A'][num[src - 'A'] - 1] = 0;
	num[dst - 'A']++;
	num[src - 'A']--;
	
}
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1) //A   B   C
	{
		step++;
		printf("��%4d ��( 1): %c-->%c",step,src,dst);
		move(src, dst);
		putout();
		return;
	}
	hanoi(n - 1, src, dst, tmp);
	step++;
	printf("��%4d ��(%2d): %c-->%c",step,n,src,dst);
	move(src, dst);
	putout();
	hanoi(n - 1, tmp, src, dst);
}
int main()
{
	int n;
	char src, tmp, dst;
	while (1)
	{
		printf("�����뺺ŵ���Ĳ���(1-10)\n");
		scanf("%d",&n);
		if (n <= 10 && n >= 1)
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
		scanf("%c",&src);
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
		while (getchar() != '\n')
			;
	}
	while (1)
	{
		printf("������Ŀ����(A-C)\n");
        scanf("%c",&dst);
		if (dst == src)
		{
			while (getchar() != '\n')
				;
			printf("Ŀ����(A)��������ʼ��(A)��ͬ\n");
			continue;
		}
		if (dst >= 'a' && dst <= 'c' && dst != src)
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
	for (int i = 0; i < n; i++)
			plate[src-'A'][i] = n - i;
	num[src - 'A'] = n;
	tmp = 'A' + 'B' + 'C' - src - dst;
	printf("��ʼ:               ");
	putout();
	hanoi(n, src, tmp, dst);
	return 0;
}






