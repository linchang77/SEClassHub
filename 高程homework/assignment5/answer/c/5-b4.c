/*2250420 �� �¾�*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
int main()
{
	int tag=0;
	int temp[1000];
	for(int i=0;i<1000;i++)
	    temp[i]=-1; 
	int array[101];
	for(int i=0;i<101;i++)
	    array[i]=0; 
	printf("������ɼ������1000������������������\n");
	for(int i=0;i<1000;i++)
	{
		int a;
		scanf("%d",&a);
		if(a<0)
		break;
		temp[i]=a;
	}
	printf("���������Ϊ:\n");
	for(int i=0;i<1000;i++)
	{
		if(temp[i]<0)
		{
			if(i%10==0)
			tag=1;
			break;
		} 
		printf("%d ",temp[i]);
		if((i+1)%10==0)
		    printf("\n");
	}
	if(tag==0)
	printf("\n");
	printf("�����������Ķ�Ӧ��ϵΪ:\n");
	for(int i=0;i<1000;i++)
	{
	    if(temp[i]<0)
	        break;
		array[temp[i]]++;	
	}
	for(int i=100;i>=0;i--)
	    if(array[i]!=0)
	        printf("%d %d\n",i,array[i]);
	
	
return 0;
}
