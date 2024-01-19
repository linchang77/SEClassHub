/*2250420 软工 陈君*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
int plate[3][10];
int num[3];//记录柱子上的盘子数
int step = 0;
void putout()//输出当前数组情况
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
		printf("第%4d 步( 1): %c-->%c",step,src,dst);
		move(src, dst);
		putout();
		return;
	}
	hanoi(n - 1, src, dst, tmp);
	step++;
	printf("第%4d 步(%2d): %c-->%c",step,n,src,dst);
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
		printf("请输入汉诺塔的层数(1-10)\n");
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
		printf("请输入起始柱(A-C)\n");
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
		printf("请输入目标柱(A-C)\n");
        scanf("%c",&dst);
		if (dst == src)
		{
			while (getchar() != '\n')
				;
			printf("目标柱(A)不能与起始柱(A)相同\n");
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
	printf("初始:               ");
	putout();
	hanoi(n, src, tmp, dst);
	return 0;
}






