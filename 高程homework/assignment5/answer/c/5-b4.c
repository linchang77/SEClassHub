/*2250420 软工 陈君*/
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
	printf("请输入成绩（最多1000个），负数结束输入\n");
	for(int i=0;i<1000;i++)
	{
		int a;
		scanf("%d",&a);
		if(a<0)
		break;
		temp[i]=a;
	}
	printf("输入的数组为:\n");
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
	printf("分数与人数的对应关系为:\n");
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
