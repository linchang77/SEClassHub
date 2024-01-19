/*2250420 �� �¾�*/
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
        ����   ��1����������һ�����������������ݹ麯�����������������ӵĺ����в������κ���ʽ��ѭ��
                 2��������ų���
                 3������const�ͱ���

        ������ ��1������ȫ�ֱ���
                 2����print_tower֮������������в������徲̬�ֲ����� 
   ----------------------------------------------------------------------------------- */
/***************************************************************************
  �������ƣ�
  ��    �ܣ���ӡ= 
  ���������
  �� �� ֵ��
  ˵    ����main�����е�...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
char print(char ch,int n)//��ӡn������ch��ͷһ�� 
{
	if(n==1)
	return ch;
	cout<<ch;
	print(ch,n-1);
} 
 /***************************************************************************
  �������ƣ�
  ��    �ܣ���ӡ��ĸ���� 
  ���������
  �� �� ֵ��
  ˵    ����main�����е�...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
void print(char start,char end)//��ӡ˳�� 
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
void print_up_tower(char start,char end,char final_end)//n��ʾ�ڵصڼ���
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
  �������ƣ�
  ��    �ܣ���ӡ��ĸ��
  ���������
  �� �� ֵ��
  ˵    �����βΰ�������
            ��ʾ����һ������order��ָ������/���� 
***************************************************************************/
void print_tower(int tag,char ch)
{
	/* �����趨�����һ����̬�ֲ�������Ҳ���Բ����壩 */

	/* ����ʵ�֣������в������κ���ʽ��ѭ����������������������� */
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

	/* ������������ַ�(����д��Ч��Ϊ����ѭ�����֣��������������) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();			//����������һ���ַ�
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "�����ַ����Ǵ�д��ĸ" << endl;
		return -1;
	}

	/* ��������ĸ��(����ΪA) */
	cout <<print('=',(end_ch-'A')*2+1)<< endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(A->" << end_ch << ")" << endl;
	cout <<print('=',(end_ch-'A')*2+1)<< endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(1,end_ch); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ��������ĸ��(����ΪA) */
	cout << print('=',(end_ch-'A')*2+1) << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(A->" << end_ch << ")" << endl;
	cout << print('=',(end_ch-'A')*2+1) << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(2,end_ch); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ����������Ư�������Σ����ΪA�� */
	cout << print('=',(end_ch-'A')*2+1) << endl;/* ����ĸ����������= */
	cout << "����(A->" << end_ch << ")" << endl;
	cout << print('=',(end_ch-'A')*2+1) << endl;/* ����ĸ����������= */
	print_tower(1,end_ch);   //��ӡ A~�����ַ��������� 
	print_tower(3,end_ch);   //��ӡ A~�����ַ�-1�ĵ����� 
	cout << endl;

	return 0;
}
