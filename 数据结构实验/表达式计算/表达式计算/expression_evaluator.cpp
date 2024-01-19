#include<iostream>
#include<string.h>
using namespace std;
struct Op
{
	char ch[10];
	int piorty = -1;
};
struct Node
{
	Node* Lnode = NULL;
	Node* Rnode = NULL;
	Op * op;
};
class Mystack
{
public:
	bool pop();
	bool push(Node * op);
	Node* gettop() { return top==-1 ? NULL:ops[top]; }
	void putout() {
		for (int i = 0; i <= top; i++)
			cout << ops[i]->op->ch;
		cout << "#"<<endl;
	}
private:
	Node * ops[20];
	int top = -1;
};
class Mytree
{
public:
	void init();
	void construct();
	void getop(Op* & op,int &i);
	void preorder(Node* root);
	void lastorder(Node* root);
	void midorder(Node* root);
	Node* getroot() { return root; }
private:
	Node* root;
	char exp[100];
};
int main()
{
	Mytree mytree;
	mytree.init();
	mytree.construct();
	cout << "波兰表达式：      ";
	mytree.preorder(mytree.getroot());
	cout << endl;
	cout << "中缀表达式：      ";
	mytree.midorder(mytree.getroot());
	cout << endl;
	cout << "逆波兰表达式：      ";
	mytree.lastorder(mytree.getroot());
	cout << endl;
	system("pause");
}
void Mytree::init()
{
	cout << "请输入表达式：";
	cin >> exp;
}
void Mytree::construct()
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
					Node* newnode = new Node;
					newnode->Rnode = stack1.gettop();
					stack1.pop();
					newnode->Lnode = stack1.gettop();
					stack1.pop();
					newnode->op = stack2.gettop()->op;
					stack1.push(newnode);
					stack2.pop();
				}
				stack2.pop();//将左括号退出
			}
			else
			{
				//清栈
				while (stack2.gettop() != NULL && op->piorty <= stack2.gettop()->op->piorty)
				{
					//取出stack1中的两个栈顶元素
					Node* newnode = new Node;
					newnode->Rnode = stack1.gettop();
					stack1.pop();
					newnode->Lnode = stack1.gettop();
					stack1.pop();
					newnode->op = stack2.gettop()->op;
					stack1.push(newnode);
					stack2.pop();
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
		//取出stack1中的两个栈顶元素
		Node* newnode = new Node;
		newnode->Rnode = stack1.gettop();
		stack1.pop();
		newnode->Lnode = stack1.gettop();
		stack1.pop();
		newnode->op = stack2.gettop()->op;
		stack1.push(newnode);
		stack2.pop();
	}
	root = stack1.gettop();
}
void Mytree::getop(Op*& op,int &i)
{
	char number[10];
	if (exp[i] < '0' || exp[i]>'9')
	{
		number[0] = exp[i];
		number[1] = '\0';
		strcpy_s(op->ch, number);
		switch (exp[i])
		{
		case '+':
			op->piorty = 5;
			break;
		case '-':
			op->piorty = 5;
			break;
		case '*':
			op->piorty = 6;
			break;
		case '/':
			op->piorty = 6;
			break;
		case '(':
			op->piorty = 15;
			break;
		case ')':
			op->piorty = 0;
			break;
		default:
			break;
		}
		i++;
	}
	else
	{
		int j = 0;
		for (; exp[i] >= '0' && exp[i] <= '9'; i++, j++)
			number[j] = exp[i];
		number[j] = '\0';
		strcpy_s(op->ch, number);
		op->piorty = -1;//代表为非操作符
	}
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
bool Mystack::push(Node *op)
{
	if (top == 100)
		return 0;
	ops[++top] = op;
	return 1;
}
void Mytree::preorder(Node* root)
{
	if (root == NULL)
		return;
	cout << root->op->ch;
	preorder(root->Lnode);
	preorder(root->Rnode);
}
void Mytree::lastorder(Node* root)
{
	if (root == NULL)
		return;
	lastorder(root->Lnode);
	lastorder(root->Rnode);
	cout << root->op->ch;
}
void Mytree::midorder(Node* root)
{
	if (root == NULL)
		return;
    midorder(root->Lnode);
	cout << root->op->ch;
	midorder(root->Rnode);
}