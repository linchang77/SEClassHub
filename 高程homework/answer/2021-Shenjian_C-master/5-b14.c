/* 1953609 ��� ���͢ */
/* ����֤ 1950679 �Ϸ��ࡢ1953348 Ҷ�����1951748 �����š�1951459 �����š�1951220 ��Х��ɨ���ڲ����� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int tag = -1;
	const int MAX_X = 10;
	const int MAX_Y = 26;
	int sum = 0;
	char map[11][27] = { '0' };
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            scanf("%c", &map[i][j]);
            if (map[i][j] < '0' || map[i][j]>'8')
                if (map[i][j] != '*')
                {
                    while (map[i][j] < '0' || map[i][j]>'8')
                    {
                        map[i][j] = getchar();
                        if (map[i][j] == '*')
                            break;
                    }
                }
        }
    }
	while (1)
	{
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 26; j++)
			{
				if (map[i][j] == '*')
					sum++;
			}
		if (sum != 50)
		{
			printf("����1\n");
			break;
		}
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                int num = 0;
                if (map[i][j] != '*')
                {
                    if (i >= 1 && j >= 1)
                        if (map[i - 1][j - 1] == '*')
                            num++;
                    if (i >= 1)
                        if (map[i - 1][j] == '*')
                            num++;
                    if (j >= 1)
                        if (map[i][j - 1] == '*')
                            num++;
                    if (i >= 1 && j < MAX_Y)
                        if (map[i - 1][j + 1] == '*')
                            num++;
                    if (j < MAX_Y)
                        if (map[i][j + 1] == '*')
                            num++;
                    if (i < MAX_X && j >= 1)
                        if (map[i + 1][j - 1] == '*')
                            num++;
                    if (i < MAX_X)
                        if (map[i + 1][j] == '*')
                            num++;
                    if (i < MAX_X && j < MAX_Y)
                        if (map[i + 1][j + 1] == '*')
                            num++;
                    if (map[i][j] != num + '0')
                    {
                        printf("����2\n");
                        tag = 1;
                        break;
                    }
                }
            }
            if (tag == 1)
                break;
        }
        if (tag != 1)
        {
            printf("��ȷ\n");
            break;
        }
        else
            break;
	}
	return 0;
}