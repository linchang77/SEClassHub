/*��� 1953609 ���͢*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x;
	int tag;
	while (1) {
		printf("������x��ֵ[0-100] : ");
		tag=scanf("%d", &x); //����x�ķ�ʽ������scanf�Ҹ�ʽ��Ϊ%d����׼�÷�scanf
		if (tag<=0)
		{
			while (getchar() != '\n')
				;
			continue;
		}
		if (x >= 0 && x <= 100)
			break;
	}
	printf("x=%d\n", x);

	return 0;
}
