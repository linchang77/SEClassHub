/*2250420 �� �¾�*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ret, x;

	while (1) {
		printf("������x��ֵ[0-100] : ");
		ret = scanf("%d", &x); //����x�ķ�ʽ������scanf�Ҹ�ʽ��Ϊ%d����׼�÷�scanf
		if(ret!=1||x>100||x<0)
		{
			while(getchar()!='\n')
			;
		}
		else if( ret==1&&(x<=100&&x>=0)) 
		    break;

		printf("�����д�[ret=%d x=%d],����������\n", ret, x); //ȷ��һ�£�ret��ֵ����scanf�ķ���ֵ����ʲô���壿 
	}

	printf("ret=%d x=%d\n", ret, x);

	return 0;
}

