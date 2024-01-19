#include<iostream>
#include<cmath>
#include "conio.h"
#include "math.h"
#include<string.h>
#define N 50 
using namespace std;
struct Op
{
	char ch;
	int piorty = -1;
};
struct letter
{
	char ch;
	int value;
};
struct Node
{
	Node* Lnode = NULL;
	Node* Rnode = NULL;
	Op* op;
};
class Mystack
{
public:
	bool pop();
	bool push(Node* op);
	Node* gettop() { return top == -1 ? NULL : ops[top]; }
	void putout() {
		for (int i = 0; i <= top; i++)
			cout << char(((ops[i]->op->ch<=1) ? (ops[i]->op->ch+'0'): ops[i]->op->ch));
		cout << "#" << endl;
	}
private:
	Node* ops[20];
	int top = -1;
};
class Mytree
{
public:
	void init();
	void calculate();
	void getop(Op*& op, int& i);
	char findnum(char ch);
	int getoutcome();
	void setletters(int i);
	void calculatenums(Mystack& stack1, Mystack& stack2);
	void putoutexp();
	Node* getroot() { return root; }
private:
	Node* root;
	char exp[100];
	letter letters[20];//�洢�ַ�
	int letternum = 0;
	int xq[2000];//�洢��ȡ��ʽ
	int x = 0;
	int hq[2000];//�洢��ȡ��ʽ
	int h = 0;
};
int main()
{
	Mytree mytree;
	mytree.init();
	mytree.calculate();
	//�����ʽ
	mytree.putoutexp();//�����ʽ
	cout << endl << endl << "��ӭ�´��ٴ�ʹ��!" << endl;
	system("pause");
	return 0;
}
bool Mystack::pop()
{
	if (top == -1)
		return 0;
	else
	{
		ops[top] = NULL;
		top--;
	}
	return 1;
}
bool Mystack::push(Node* op)
{
	if (top == 100)
		return 0;
	ops[++top] = op;
	return 1;
}
void Mytree::init()
{
	cout << "***************************************" << endl;
	cout << "**                                   **" << endl;
	cout << "**         ��ӭ�����߼��������      **" << endl;
	cout << "**   (��������ֵ��,����ʽ,֧������)  **" << endl;
	cout << "**                                   **" << endl;
	cout << "**              ��!��ʾ��            **" << endl;
	cout << "**              ��&��ʾ��            **" << endl;
	cout << "**              ��|��ʾ��            **" << endl;
	cout << "**             ��^��ʾ�̺�           **" << endl;
	cout << "**             ��~��ʾ��ֵ           **" << endl;
	cout << "**                                   **" << endl;
	cout << "***************************************" << endl;
	cout << endl;
	cout << "������һ���Ϸ������⹫ʽ:" << endl; //����ʽ��
	cin >> exp;
	for (unsigned i1 = 0; i1 < strlen(exp); i1++)
	{
		int tag = 1;
		if (exp[i1] >= 'a' && exp[i1] <= 'z' || exp[i1] >= 'A' && exp[i1] <= 'Z')
		{
			for (int i2 = 0; i2 < letternum; i2++)  //�жϲ����������
				if (letters[i2].ch == exp[i1])  //ȥ���ظ�����
					tag = 0;
			if (tag == 1)
			{
				letters[letternum++].ch = exp[i1];
			}
			tag = 1;
		}
	}
	cout << endl;
	cout << "��ʽ���еı�������Ϊ:" << letternum << endl;
	cout << endl << "�����ֵ������:" << endl << endl;
	//��������������
	for (int i1 = 0; i1 <letternum; i1++)
		cout << letters[i1].ch << " ";
	cout << "  ";
	puts(exp);
	cout << endl;
	
}
void Mytree :: calculate()
{
	for (int i = 0; i < (int)pow(2.0, letternum ); i++)
	{
		setletters(i);//�ȸ�letters��ֵ
		int outcome = getoutcome();  //�ú�������
		if ( outcome== 0)  //���Ϊ0����ȡ��1
			hq[h++] = i;
		else  //������ȡ��1
			xq[x++] = i;
		for (int i1 = 0; i1 < letternum; i1++)
			cout << letters[i1].value << " ";
		cout << "  " << outcome << endl;

	}
}
void Mytree::setletters(int i)
{
	int j = letternum-1;
	while( i > 0)
	{
		letters[j].value = i % 2;
		j--;
		i = i / 2;
	}
	while (j >= 0)
	{
		letters[j].value = 0;
		j--;
	}
}
int Mytree::getoutcome()
{
	Mystack stack1, stack2;//��������ջ��Ų������Ͳ�����
	for (int i = 0; exp[i] != '\0';)
	{
		Op *op =new Op;
		Node* newnode = new Node;
		getop(op,i);
		if (op->piorty == -1)//�ǲ�����ֱ��ѹջ
		{
			newnode->op = op;
			stack1.push(newnode);
		}
		else
		{
			if (op->piorty == 15)//�������Ž��е�������
			{
				op->piorty = 0;
				newnode->op = op;
				stack2.push(newnode);
			}
			else if (op->piorty == 0)//�������ŵ�������
			{
				while (stack2.gettop()->op->piorty!=0)//����������Ϊֹ
				{
					//ȡ��stack1�е�����ջ��Ԫ��
					calculatenums(stack1, stack2);//����ջ��Ԫ��
					
				}
				stack2.pop();//���������˳�
			}
			else
			{
				//��ջ
				while (stack2.gettop() != NULL && op->piorty <= stack2.gettop()->op->piorty)
				{
					calculatenums(stack1, stack2);//����ջ��Ԫ��

					
				}
				//��ջ
				newnode->op = op;
				stack2.push(newnode);
			}
		}
	}
	//����֮����ջ
	while (stack2.gettop() != NULL )//�������ջ��գ����������ջֻ��ʣ��һ������Ǹ����Ǹ��ڵ�
	{
		calculatenums(stack1, stack2);//����ջ��Ԫ��
	}
	return stack1.gettop()->op->ch;
}
void Mytree::getop(Op*& op, int& i)
{
	op->ch = findnum(exp[i]);//������������ͻ�ȡ0��1�������������ͷ���������ַ�
	switch (exp[i])
	{
	case '|':
		op->piorty = 8;
		break;
	case '&':
		op->piorty = 9;
		break;
	case '!':
		//���ȼ�������⴦��
		op->ch = findnum(exp[++i]) == 0 ? 1:0;//��ȡ��һλ��������
		op->piorty = -1;
		break;
	case '^':
		op->piorty = 7;
		break;
	case '~':
		op->piorty = 6;
		break;
	case '(':
		op->piorty = 15;
		break;
	case ')':
		op->piorty = 0;
		break;
	default:
		op->piorty = -1;//����Ϊ�ǲ�����
		break;
	}
	i++;
}
char Mytree::findnum(char ch)
{
	for (int i = 0; i < letternum; i++)
		if (ch == letters[i].ch)
			return letters[i].value;
	return  ch;
}
void Mytree::calculatenums(Mystack &stack1, Mystack &stack2)
{
	int a = stack1.gettop()->op->ch;
	stack1.pop();
	int b= stack1.gettop()->op->ch;
	stack1.pop();
	switch (stack2.gettop()->op->ch)
	{
	case '|':
		stack2.gettop()->op->ch = a || b;
		break;
	case '&':
		stack2.gettop()->op->ch = a && b;
		break;
	case '^':
		stack2.gettop()->op->ch = (!b) || a;
		break;
	case '~':
		stack2.gettop()->op->ch = ((!a) || b) && ((!b) || a);
		break;
	}
	stack1.push(stack2.gettop());
	stack2.pop();
}
void Mytree::putoutexp()
{
	if (h == 0)  //�����ں�ȡ��ʽʱ
		cout << endl << "�����⹫ʽ����������ȡ��ʽ." << endl;
	else
	{
		cout << endl << "�����⹫ʽ������ȡ��ʽ:" << endl;
		//printf("\n\n\t");
		for (int i1 = 0; i1 < h; i1++)
		{
			if (i1 > 0)  //�жϲ���ӷ���
				cout << "\\/";
			cout << "M(" << hq[i1] << ")"; //�������ȡ��ʽ
		}
	}
	if (x==0)  //��������ȡ��ʽʱ
		cout << endl << "�����⹫ʽ����������ȡ��ʽ." << endl;
	else
	{
		cout << endl << endl << "�����⹫ʽ������ȡ��ʽ:" << endl;
		for (int i1 = 0; i1 < x; i1++)
		{
			if (i1 > 0)  //�жϲ���ӷ��š�
				cout << "/\\";
			cout << "m(" << xq[i1] << ")";  //�������ȡ��ʽ
		}
	}
}
