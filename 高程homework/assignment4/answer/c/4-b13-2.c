/* 2250420 陈君 软工 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
static int step=0;
/* ----具体要求----
   1、不允许添加其它头文件
   2、允许定义一个全局变量、不允许定义静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */


/***************************************************************************
  函数名称：
  功    能：打印n层汉诺塔的移动顺序
  输入参数：int n：层数
            char src：起始柱
            char tmp：中间柱
            char dst：目标柱
  返 回 值：
  说    明：1、函数名、形参、返回类型均不准动
            2、本函数不允许出现任何形式的循环
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	static int step=0;
	if (n == 1) //A   B   C
	{	
	    ++step; 
	    printf("%5d:  1# %c-->%c\n",step,src,dst);
		return;
	}
	hanoi(n - 1, src, dst, tmp);
	++step;
	printf("%5d:%3d# %c-->%c\n",step,n,src,dst);
	hanoi(n - 1, tmp, src, dst);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
	int n;
	char src, tmp, dst;
	while (1)
	{
		printf("请输入汉诺塔的层数(1-16)\n");
        int tag=scanf("%d",&n);	
		 if (n <= 16 && n >= 1&&tag==1)
		 {
			 while (getchar() != '\n')
				 ;
			 break;
		 }
		 while (getchar() != '\n')
			 ;
	}
	while (1)
	{
		printf("请输入起始柱(A-C)\n");
		int tag=scanf("%c",&src);
		if (src >= 'a' && src <= 'c'&&tag==1)
		{
			src = src - 32;
			while (getchar() != '\n')
				;
			break;
		}
		if (src >= 'A' && src <= 'C'&&tag==1)
		{
			while (getchar() != '\n')
				;
			break;
		}
		while (getchar() != '\n')
			;
	}
	while (1)
	{
		printf("请输入目标柱(A-C)\n");
		int tag=scanf("%c",&dst);
		if (dst == src)
		{
			while (getchar() != '\n')
				;
			printf("目标柱(A)不能与起始柱(A)相同\n");
			continue;
		}
		if (dst >= 'a' && dst <= 'c'&&dst!=src)
		{
			dst = dst - 32;
			while (getchar() != '\n')
				;
			break;
		}
		if (dst >= 'A' && dst <= 'C' && dst != src)
		{
			while (getchar() != '\n')
				;
			break;
		}
		while (getchar() != '\n')
			;
	}
	
	tmp = 'A' + 'B' + 'C' - src - dst;
	printf("移动步骤为:\n");
	hanoi(n, src, tmp, dst);
	return 0;
}
