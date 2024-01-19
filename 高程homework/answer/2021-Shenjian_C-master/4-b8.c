/*1953609 ��� ���͢*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
static int sum = 1;
/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2��������һ��ȫ�ֱ������������徲̬�ֲ�����
   3������������������������ʼ/Ŀ�����ĺ���������������ʹ��ѭ�������������
   4����������ú������У���main�в���������κ���ʽ��ѭ����while��do-while��for��if-goto��
      ���������main�н��У���main���������ѭ��
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
    if (n == 1)
    {
        printf("%5d:%3d# %c-->%c\n", sum, n, src, dst);
        sum++;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        printf("%5d:%3d# %c-->%c\n", sum, n, src, dst);
        sum++;
        hanoi(n - 1, tmp, src, dst);
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����������(��������뺯��)�����õݹ麯��
***************************************************************************/
int main()
{
    int n;
    while (1)
    {
        printf("�����뺺ŵ���Ĳ�����1-16��\n");
        const int tag=scanf("%d",&n);
        if (tag<=0|| n > 16 || n < 1)
        {
            while (getchar() != '\n')
                ;
            continue;
        }
        else
        {
            while (getchar() != '\n')
                ;
            break;
        }
    }
    char start, end;
    while (1)
    {
        printf("��������ʼ����A-C��\n");
        const int tag=scanf("%c",&start);
        if (tag <= 0 || start > 99 || start < 65 || (start < 97 && start>67))
        {
            while (getchar() != '\n')
                ;
            continue;
        }
        else
        {
            if (start > 96)
                start -= 32;
            while (getchar() != '\n')
                ;
            break;
        }
    }
    while (1)
    {
        printf("������Ŀ������A-C��\n");
        const int tag=scanf("%c",&end);
        if (tag <= 0 || end > 99 || end < 65 || (end < 97 && end>67))
        {
            while (getchar() != '\n')
                ;
            continue;
        }
        else if (end > 96)
        {
            end -= 32;
            if (end == start)
            {
                printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n",start,end);
                continue;
            }
        }
        else
        {
            if (end == start)
            {
                printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n", start, end);
                continue;
            }
        }
        while (getchar() != '\n')
            ;
        break;
    }
    char tmp = '0';
    if ((start == 65 && end == 66) || (end == 65 && start == 66))
        tmp = 'C';
    else if ((start == 65 && end == 67) || (end == 65 && start == 67))
        tmp = 'B';
    else if ((start == 66 && end == 67) || (end == 66 && start == 67))
        tmp = 'A';
    printf("�ƶ�����Ϊ:\n");
    hanoi(n, start, tmp, end);
    return 0;
}
