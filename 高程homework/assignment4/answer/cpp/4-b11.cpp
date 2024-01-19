/*2250420 软工 陈君*/
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
        允许   ：1、按需增加一个或多个函数（包括递归函数），但是所有增加的函数中不允许任何形式的循环
                 2、定义符号常量
                 3、定义const型变量

        不允许 ：1、定义全局变量
                 2、除print_tower之外的其他函数中不允许定义静态局部变量 
   ----------------------------------------------------------------------------------- */
/***************************************************************************
  函数名称：
  功    能：打印= 
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
char print(char ch,int n)//打印n个连续ch的头一个 
{
	if(n==1)
	return ch;
	cout<<ch;
	print(ch,n-1);
} 
 /***************************************************************************
  函数名称：
  功    能：打印字母序列 
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
void print(char start,char end)//打印顺序 
{
	if(start==end)
	{
		cout<<end;
		return;
	}
	cout<<start;
	if(start<end)
	print(start+1,end);	
	else if(start>end)
	print(start-1,end);
} 
void printchar(char ch, int n)
{
	if(n==0)
	return ;
	cout<<ch;
	printchar(ch,n-1);
}
void print_up_tower(char start,char end,char final_end)//n提示在地第几行
{
	if(end==final_end)
	{
	    print('A',end); 
	    if(end!=start)
        print(end-1,'A'); 
        cout<<endl;
        return;
	}
	else
	{
		printchar(' ',final_end-end);
	    print(start,end);
	    if(start!=end)
	    print(end-1,start);
	    cout<<endl;
	    print_up_tower(start,end+1,final_end);
	}
} 

void print_down_tower(char start,char end,char final_end)
{
	if(end==start)
	{
	    printchar(' ',final_end-end);
	    print(start,end);
	    cout<<endl;
	    return;
	}	    
	    printchar(' ',final_end-end);
	    print(start,end);
	    print(end-1,start);
	    cout<<endl;
	    print_down_tower(start,end-1,final_end);
}
/***************************************************************************
  函数名称：
  功    能：打印字母塔
  输入参数：
  返 回 值：
  说    明：形参按需设置
            提示：有一个参数order，指定正序/倒序 
***************************************************************************/
void print_tower(int tag,char ch)
{
	/* 允许按需定义最多一个静态局部变量（也可以不定义） */

	/* 按需实现，函数中不允许任何形式的循环，函数允许调用其它函数 */
	if(tag==1)
	    print_up_tower('A','A',ch);
	else if(tag==2)
		print_down_tower('A',ch,ch);
	else if(tag==3)
	{
	    if(ch=='A')
			return;
	    print_down_tower('A',ch-1,ch);	
	} 
}
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效，为避免循环出现，不处理输入错误) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}

	/* 正三角字母塔(两边为A) */
	cout <<print('=',(end_ch-'A')*2+1)<< endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "正三角字母塔(A->" << end_ch << ")" << endl;
	cout <<print('=',(end_ch-'A')*2+1)<< endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(1,end_ch); //正序打印 A~结束字符 
	cout << endl;

	/* 倒三角字母塔(两边为A) */
	cout << print('=',(end_ch-'A')*2+1) << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "倒三角字母塔(A->" << end_ch << ")" << endl;
	cout << print('=',(end_ch-'A')*2+1) << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(2,end_ch); //逆序打印 A~结束字符 
	cout << endl;

	/* 合起来就是漂亮的菱形（外侧为A） */
	cout << print('=',(end_ch-'A')*2+1) << endl;/* 按字母塔最大宽度输出= */
	cout << "菱形(A->" << end_ch << ")" << endl;
	cout << print('=',(end_ch-'A')*2+1) << endl;/* 按字母塔最大宽度输出= */
	print_tower(1,end_ch);   //打印 A~结束字符的正三角 
	print_tower(3,end_ch);   //打印 A~结束字符-1的倒三角 
	cout << endl;

	return 0;
}
