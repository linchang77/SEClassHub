/*2250420 �� �¾�*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{   double a;
    printf("������[0-100��)֮�������:\n") ;
    scanf("%lf",&a);
	int a1 = (int)(a/10);//�������ʮλ֮ǰ����ȡ���� 
	int b1 = a1 / 100000000;//ʮ�� 
	int b2 = a1 / 10000000 % 10;//�� 
	int b3 = a1 / 1000000 % 10;//ǧ�� 
	int b4 = a1 / 100000 % 10;//���� 
	int b5 = a1 / 10000 % 10;//ʮ�� 
	int b6 = a1 / 1000 % 10;//�� 
	int b7 = a1 / 100 % 10;//ǧ 
	int b8 = a1 / 10 % 10;//�� 
	int b9 = a1 % 10;//ʮ 
	int a2 = round((a/10-a1)*1000);
	int b10 = a2 / 100 % 10;//Բ 
	int b11 = a2 / 10 % 10;//�� 
	int b12 = a2  % 10;//��
//ȡ��ÿһλ������

    printf("��д�����:\n");
	switch(b1)
	{
		case 1:
			printf("ʰ");
			break; 
		case 2:
		    printf("��ʰ");
			break; 
		case 3:
			printf("��ʰ");
			break;
		case 4:
			printf("��ʰ");
			break;
		case 5:
			printf("��ʰ");
			break;
		case 6:
			printf("½ʰ");
			break;
		case 7:
			printf("��ʰ");
			break;
		case 8:
			printf("��ʰ");
			break;
		case 9:
			printf("��ʰ");
			break;
	}
	switch(b2)
	{
		case 1:
			printf("Ҽ��");
			break; 
		case 2:
		    printf("����");
			break; 
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("����");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("����");
			break;
		case 8:
			printf("����");
			break;
		case 9:
			printf("����");
			break;
		case 0:
			if(b1==0&&b2==0)
			;
			else
			printf("��");
			break; 
	}
	switch(b3)
	{
		case 1:
			printf("ҼǪ");
			break; 
		case 2:
		    printf("��Ǫ");
			break; 
		case 3:
			printf("��Ǫ");
			break;
		case 4:
			printf("��Ǫ");
			break;
		case 5:
			printf("��Ǫ");
			break;
		case 6:
			printf("½Ǫ");
			break;
		case 7:
			printf("��Ǫ");
			break;
		case 8:
			printf("��Ǫ");
			break;
		case 9:
			printf("��Ǫ");
			break;
		case 0:
		if(b1==0&&b2==0)
		    break;
		if(b4!=0) 
		{
			printf("��");
		    break; 
		} 
	}
	switch(b4)
	{
		case 1:
			printf("Ҽ��");
			break; 
		case 2:
		    printf("����");
			break; 
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("���");
			break;
		case 8:
			printf("�ư�");
			break;
		case 9:
			printf("����");
			break;
		case 0:
		if(b1==0&&b2==0&&b3==0)
	        break;
		if(b5!=0) 
		{
		printf("��");
		break; 
		}
	}
	switch(b5)
	{
		case 1:
			if(b4==0&&b1==0&&b2==0&&b3==0)
			{
		        printf("ʰ");
			    break;
			} 
			else
			{
				printf("Ҽʰ");
			    break;
			 } 
		case 2:
		    printf("��ʰ");
			break; 
		case 3:
			printf("��ʰ");
			break;
		case 4:
			printf("��ʰ");
			break;
		case 5:
			printf("��ʰ");
			break;
		case 6:
			printf("½ʰ");
			break;
		case 7:
			printf("��ʰ");
			break;
		case 8:
			printf("��ʰ");
			break;
		case 9:
			printf("��ʰ");
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0)
	        break;
		    if(b6!=0) 
		    {
		        printf("��");
		        break; 
		    } 
	}
	switch(b6)
	{
		case 1:
			printf("Ҽ��");
			break;
		case 2:
		    printf("����");
			break; 
		case 3:
			printf("����"); 
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("����");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("����");
			break;
		case 8:
			printf("����");
			break;
		case 9:
			printf("����");
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0)
	        ;
		    else
			printf("��");
			
	}
		switch(b7)
	{
		case 1:
			printf("ҼǪ");
			break; 
		case 2:
		    printf("��Ǫ");
			break; 
		case 3:
			printf("��Ǫ");
			break;
		case 4:
			printf("��Ǫ");
			break;
		case 5:
			printf("��Ǫ");
			break;
		case 6:
			printf("½Ǫ");
			break;
		case 7:
			printf("��Ǫ");
			break;
		case 8:
			printf("��Ǫ");
			break;
		case 9:
			printf("��Ǫ");
			break;
		case 0:
		if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0)
		    break;
		if(b8!=0) 
		{
			printf("��");
		    break; 
		}
	}
	switch(b8)
	{
		case 1:
			printf("Ҽ��");
			break; 
		case 2:
		    printf("����");
			break; 
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("���");
			break;
		case 8:
			printf("�ư�");
			break;
		case 9:
			printf("����");
			break;
		case 0:
		if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0)
	        break;
		if(b9!=0) 
		{
		printf("��");
		break; 
		}
	}
	switch(b9)
	{
		case 1:
			if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0&&b8==0)
			{
		        printf("ʰ");
			    break;
			} 
			else
			{
				printf("Ҽʰ");
			    break;
			 } 
		case 2:
		    printf("��ʰ");
			break; 
		case 3:
			printf("��ʰ");
			break;
		case 4:
			printf("��ʰ");
			break;
		case 5:
			printf("��ʰ");
			break;
		case 6:
			printf("½ʰ");
			break;
		case 7:
			printf("��ʰ");
			break;
		case 8:
			printf("��ʰ");
			break;
		case 9:
			printf("��ʰ");
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0&&b8==0)
	        break;
		    if(b10!=0) 
		    {
		        printf("��");
		        break; 
		    } 
	}
	switch(b10)
	{
		case 1:
			printf("ҼԲ");
			break; 
		case 2:
		    printf("��Բ");
			break; 
		case 3:
			printf("��Բ");
			break;
		case 4:
			printf("��Բ");
			break;
		case 5:
			printf("��Բ");
			break;
		case 6:
			printf("½Բ");
			break;
		case 7:
			printf("��Բ");
			break;
		case 8:
			printf("��Բ");
			break;
		case 9:
			printf("��Բ");
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0&&b8==0&&b9==0)
	        break;
		    else
			printf("Բ"); 
	}
	switch(b11)
	{
		case 1:
			printf("Ҽ��");
			break; 
		case 2:
		    printf("����");
			break; 
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("���");
			break;
		case 8:
			printf("�ƽ�");
			break;
		case 9:
			printf("����");
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0&&b8==0&&b9==0&&b10==0)
	        break;
		    if(b12!=0)
			printf("��"); 		 
	}
	switch(b12)
	{
		case 1:
			printf("Ҽ��");
			break; 
		case 2:
		    printf("����");
			break; 
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 7:

			printf("���");
			break;
		case 8:
			printf("�Ʒ�");
			break;
		case 9:
			printf("����");
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0&&b8==0&&b9==0&&b10==0&&b11==0)
		    {
				printf("��Բ"); 
		    	break;
			} 		 
	}
		if(b12==0)
	    printf("��\n"); 
	return 0;
}

