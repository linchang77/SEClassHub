/* 1953609 ��� ���͢ */
#define _CRT_SECURE_NO_WARNINGS
/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#include <stdio.h>

#define MAX_STU_NUM			150	//Լ���������Ϊ150�ˣ����ֵ��ܺͣ�������ѡ����ѡ��
#define MAX_NAME_LEN			20	//��������󳤶Ȳ�����9������
#define MAX_FILENAME_LEN		256	//�ļ�������󳤶�

/* ������Ҫ�Ķ��� */

/* ����stu_list�Ķ��� */
struct stu_list {
	int  stu_no;			//ѧ��
	char stu_name[MAX_NAME_LEN];	//����
	int condi_fro;
	int condi_aft;
};

/* ����������Ҫ�ĺ�����ʵ�� */
int get_sum(const struct stu_list *list)
{
	int sum;
	for (sum=0; list[sum].stu_no != 0; sum++)
		;
	return sum;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������append : 0 : ���Ƿ�ʽ
					 1 : ׷�ӷ�ʽ
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int read_stulist(const char* filename, struct stu_list* list, const int append)
{
	FILE * fin;
	fin = fopen(filename, "r");
	if ((fin = fopen(filename, "r")) == NULL)
	{
		printf("�ļ�[%s]��ʧ��\n", filename);
		return -1;
	}
	int sum;
	if (append != 0)
	{
		int tag = 0;
		int i = 0;
		sum = get_sum(list);
		for (; tag != 1; i++)
		{
			int a;
			int b;
			b=fscanf(fin,"%d",&a);
			if (b < 1)
				break;
			int seek = 0;
			for (int n = 0; n < sum; n++)
			{
				if (list[n].stu_no == a)
				{
					list[n].condi_aft = 1;
					seek = 1;
					break;
				}
			}
			int j = 0;
			fgetc(fin);
			for (;; j++)
			{
				char ch;
				ch = fgetc(fin);
				if (ch == '\n')
					break;
				else if (ch == EOF)
				{
					tag = 1;
					break;
				}
				else
				{
					if (seek == 0)
					{
						list[sum].stu_name[j] = ch;
					}
				}
			}
			if (seek == 0)
			{
				list[sum].stu_no = a;
				list[sum].condi_aft = 1;
				list[sum].stu_name[j] = '\0';
				sum++;
			}
		}
	}
	else
	{
		int tag = 0;
		int i = 0;
		for (; tag != 1; i++)
		{
			int a;
			int b;
			b = fscanf(fin, "%d", &a);
			if (b < 1)
				break;
			list[i].stu_no = a;
			int j = 0;
			fgetc(fin);
			for (;; j++)
			{
				char ch;
				ch = fgetc(fin);
				if (ch == '\n')
					break;
				else if (ch == EOF)
				{
					tag = 1;
					break;
				}
				else
				{
					list[i].stu_name[j] = ch;
				}
			}
			list[i].stu_name[j] = '\0';
			list[i].condi_fro = 1;
		}
	}
	sum = get_sum(list);
	for (int k = 0; k < sum; k++)
	{
		for (int m = 0; m < sum - k - 1; m++)
		{
			if (list[m].stu_no > list[m + 1].stu_no)//�Ӻ��浽i��Ԫ�������Ƚϣ���С�Ĳ����϶�
			{
				struct stu_list tmp;
				tmp = list[m];
				list[m] = list[m + 1];
				list[m + 1] = tmp;
			}
		}
	}
	fclose(fin);
	return 1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int print_stulist(const struct stu_list* const list, const char* prompt)
{
	int sum = get_sum(list);
	printf("%s\n", prompt);
	printf("===========================================\n");
	printf("��� ѧ��    ����             ��һ�� �ڶ���\n");
	printf("===========================================\n");
	int num = 1;
	for (int i = 0; i < sum; i++, num++)
	{
		printf("%-5d %d %-17s", num, list[i].stu_no, list[i].stu_name);
		if (list[i].condi_fro == 1)
			printf("Y      ");
		else
			printf("/      ");
		if (list[i].condi_aft == 0)
		{
			if (list[i].condi_fro == 1)
				printf("�˿�\n");
		}
		else
		{
			if (list[i].condi_fro == 1)
				printf("Y\n");
			else
				printf("��ѡ\n");
		}
	}
	printf("===========================================\n");
	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	printf("������ǰһ��ѡ�ε������ļ� : ");
	scanf("%s", file1);
	printf("�������һ��ѡ�ε������ļ� : ");
	scanf("%s", file2);

	struct stu_list list[MAX_STU_NUM + 1] = { 0 };

	if (read_stulist(file1, list, 0) < 0)
		return -1;
#if 0
	/* ������궨�壬���Դ�ӡ���ֶ����ѡ�����������ڵ��� */
	print_stulist(list, "ǰһ��ѡ������");
	printf("\n\n");
#endif

	if (read_stulist(file2, list, 1) < 0)
		return -1;

	print_stulist(list, "����ѡ������");

	return 0;
}
