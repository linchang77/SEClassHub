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
	letter letters[20];//存储字符
	int letternum = 0;
	int xq[2000];//存储合取范式
	int x = 0;
	int hq[2000];//存储析取范式
	int h = 0;
};
int main()
{
	Mytree mytree;
	mytree.init();
	mytree.calculate();
	//输出范式
	mytree.putoutexp();//输出范式
	cout << endl << endl << "欢迎下次再次使用!" << endl;
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
	cout << "**         欢迎进入逻辑运算软件      **" << endl;
	cout << "**   (可运算真值表,主范式,支持括号)  **" << endl;
	cout << "**                                   **" << endl;
	cout << "**              用!表示非            **" << endl;
	cout << "**              用&表示与            **" << endl;
	cout << "**              用|表示或            **" << endl;
	cout << "**             用^表示蕴含           **" << endl;
	cout << "**             用~表示等值           **" << endl;
	cout << "**                                   **" << endl;
	cout << "***************************************" << endl;
	cout << endl;
	cout << "请输入一个合法的命题公式:" << endl; //输入式子
	cin >> exp;
	for (unsigned i1 = 0; i1 < strlen(exp); i1++)
	{
		int tag = 1;
		if (exp[i1] >= 'a' && exp[i1] <= 'z' || exp[i1] >= 'A' && exp[i1] <= 'Z')
		{
			for (int i2 = 0; i2 < letternum; i2++)  //判断并储存变量。
				if (letters[i2].ch == exp[i1])  //去除重复变量
					tag = 0;
			if (tag == 1)
			{
				letters[letternum++].ch = exp[i1];
			}
			tag = 1;
		}
	}
	cout << endl;
	cout << "该式子中的变量个数为:" << letternum << endl;
	cout << endl << "输出真值表如下:" << endl << endl;
	//先输出结果的首行
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
		setletters(i);//先给letters赋值
		int outcome = getoutcome();  //用函数求结果
		if ( outcome== 0)  //结果为0，合取加1
			hq[h++] = i;
		else  //否则，析取加1
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
	Mystack stack1, stack2;//建立两个栈存放操作数和操作符
	for (int i = 0; exp[i] != '\0';)
	{
		Op *op =new Op;
		Node* newnode = new Node;
		getop(op,i);
		if (op->piorty == -1)//是操作数直接压栈
		{
			newnode->op = op;
			stack1.push(newnode);
		}
		else
		{
			if (op->piorty == 15)//对左括号进行单独处理
			{
				op->piorty = 0;
				newnode->op = op;
				stack2.push(newnode);
			}
			else if (op->piorty == 0)//对右括号单独处理
			{
				while (stack2.gettop()->op->piorty!=0)//清理到左括号为止
				{
					//取出stack1中的两个栈顶元素
					calculatenums(stack1, stack2);//计算栈顶元素
					
				}
				stack2.pop();//将左括号退出
			}
			else
			{
				//清栈
				while (stack2.gettop() != NULL && op->piorty <= stack2.gettop()->op->piorty)
				{
					calculatenums(stack1, stack2);//计算栈顶元素

					
				}
				//进栈
				newnode->op = op;
				stack2.push(newnode);
			}
		}
	}
	//结束之后清栈
	while (stack2.gettop() != NULL )//将运算符栈清空，最后运算数栈只会剩下一个结点那个就是根节点
	{
		calculatenums(stack1, stack2);//计算栈顶元素
	}
	return stack1.gettop()->op->ch;
}
void Mytree::getop(Op*& op, int& i)
{
	op->ch = findnum(exp[i]);//如果是运算数就获取0或1，如果是运算符就返回运算符字符
	switch (exp[i])
	{
	case '|':
		op->piorty = 8;
		break;
	case '&':
		op->piorty = 9;
		break;
	case '!':
		//优先级最高特殊处理
		op->ch = findnum(exp[++i]) == 0 ? 1:0;//获取下一位的运算数
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
		op->piorty = -1;//代表为非操作符
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
	if (h == 0)  //不存在合取范式时
		cout << endl << "该命题公式不存在主合取范式." << endl;
	else
	{
		cout << endl << "该命题公式的主合取范式:" << endl;
		//printf("\n\n\t");
		for (int i1 = 0; i1 < h; i1++)
		{
			if (i1 > 0)  //判断并添加符号
				cout << "\\/";
			cout << "M(" << hq[i1] << ")"; //输出主合取范式
		}
	}
	if (x==0)  //不存在析取范式时
		cout << endl << "该命题公式不存在主析取范式." << endl;
	else
	{
		cout << endl << endl << "该命题公式的主析取范式:" << endl;
		for (int i1 = 0; i1 < x; i1++)
		{
			if (i1 > 0)  //判断并添加符号、
				cout << "/\\";
			cout << "m(" << xq[i1] << ")";  //输出主析取范式
		}
	}
}
