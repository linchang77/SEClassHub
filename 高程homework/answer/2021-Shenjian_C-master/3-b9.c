/*��� 1953609 ���͢*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    for (int i = 2; i < 1000; i++)
    {
        int a = 0;
        for (int j = 1; j <= i / 2; j++)
        {
            if (i % j == 0)
                a += j;
            if (a == i && j == i / 2)
            {
                printf("%d,its factors are ",a);
                for (int k = 1; k <= a / 2; k++)
                {
                    if (a % k == 0 && k != a / 2)
                        printf("%d,",k);
                    else if (a % k == 0)
                        printf("%d\n", k);
                }
            }
        }
    }
    return 0;//3-b9��Ӧ��cpp��ʽ��ҵ�ı����ʽ����
}
//3-b9��Ӧ��cpp��ʽ��ҵ�ı����ʽ����

