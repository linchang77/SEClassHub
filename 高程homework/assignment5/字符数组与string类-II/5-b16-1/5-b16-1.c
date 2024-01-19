/*2250420 软工 陈君*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
void input(char num[10][8], char name[10][9], int score[10])
{
	for (int i = 0; i < 10; i++)
	{
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		scanf("%s %s %d", num[i], name[i], &score[i]);
	}
}
void swap(char num[10][8], char name[10][9], int score[10], int x, int y)
{
	char temp_num[8];
	char temp_name[9];
	int temp_score;
	strcpy(temp_num, num[x]);
	strcpy(num[x], num[y]);
	strcpy(num[y], temp_num);
	strcpy(temp_name, name[x]);
	strcpy(name[x], name[y]);
	strcpy(name[y], temp_name);
	temp_score = score[x];
	score[x] = score[y];
	score[y] = temp_score;
}
void sort(char num[10][8], char name[10][9], int score[10])
{
	for (int i = 0; i < 9; i++)
		for (int j = 9; j > i; j--)
			if (strcmp(num[j], num[j - 1])>0)
				swap(num, name, score, j, j - 1);
}
void putout(char num[10][8], char name[10][9], int score[10])
{
	printf("及格名单(学号降序):\n");
	for (int i = 0; i < 10; i++)
		if(score[i]>=60)
		    printf("%s %s %d\n", name[i], num[i], score[i]);
}
int main()
{
	char num[10][8];
	char name[10][9];
	int score[10];
	input(num, name, score);
	sort(num, name, score);
	printf("\n");
	putout(num, name, score);
	return 0;
}