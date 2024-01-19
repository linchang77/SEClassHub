#include<iostream>
using namespace std;
#define NUM 100
class Family;
class listnode
{
public:
	char* get_name() { return name; }
private:
	friend Family;
	listnode* children[100] = {NULL};
	char name[100];
	int childrennum = 0;
};
class Family
{
public:
	Family();//默认构造函数
	~Family();//析构函数
	listnode* find(char str[100], listnode* p);//查找函数，寻找这个人所在位置
	void improve_family();//完善家谱
	void add_member();//添加家庭成员
	void release_member();//解散局部家庭
	void reset_member();//更改家庭成员姓名
	listnode* get_root() { return root; }//获取根结点的地址
	void show_family_tree(listnode* current);
	void show_family_tree_layer(listnode* root);
private:
	listnode* root;
};
void initializeio();//初始化io界面
int main()
{
	
	initializeio();
	cout << "请输入";
	Family family;
	char ch;
	listnode* root = family.get_root();
	while(1)
	{
		 cout <<endl;
         cout << "请选择要执行的操作：";
		 cin >> ch;
		 switch (ch)
		 {
		 case 'A':family.improve_family(); break;
		 case 'B':family.add_member(); break;
		 case 'C':family.release_member(); break;
		 case 'D':family.reset_member(); break; 
		 case 'E':family.show_family_tree_layer(root); exit(1);
		 default:cout << "请输入正确的选项" << endl;
			 while (getchar() != '\n')
				 ;
		 }
	}
	
}
void initializeio()//初始化io界面
{
	cout << endl;
	cout << "**          家谱管理系统          **" << endl;
	cout << "====================================" << endl;
	cout << "**     请选择要执行的操作 :       **" << endl;
	cout << "**        A --- 完善家谱          **" << endl;
	cout << "**        B --- 添加家庭成员      **" << endl;
	cout << "**        C --- 解散局部家庭      **" << endl;
	cout << "**        D --- 更改家庭成员姓名  **" << endl;
	cout << "**        E --- 退出程序          **" << endl;
	cout << "====================================" << endl;
	cout << "首先建立一个家谱！" << endl;
	
}
Family::Family()//默认构造函数
{
	char str[100];
	cout << "请输入祖先的姓名：" ;
	cin >> str;
	cout << "此家谱的祖先是：" << str << endl;
	listnode* newnode = new listnode;
	strcpy_s(newnode->name , str);
	root = newnode;
}
Family::~Family()
{
	if (root != NULL)
		delete root;
}
void Family::improve_family()
{
	char str[100];
	int n;
	listnode* current;//要建立家庭的人的地址
	
	cout << "请输入要建立家庭的人的姓名：";
	cin >> str;
	current = find(str, root);
	if (current == NULL)
	{
		cout << "未找到这个人。" << endl;
		return;
	}
	cout << "请输入" << str << "的儿女人数：";
	cin >> n;
	current->childrennum = n;
	cout << "请依次输入" << str << "的儿女的姓名：";
	for (int i = 0; i < n; i++)
	{
		listnode* newnode = new listnode;
		cin >> newnode->name;
		current->children[i]=newnode;
	}
	//遍历家谱找到建立家庭的人
	for (int i = 0; i < n; i++)
		cout << current->children[i]->name << "   ";
	cout << endl;
}
listnode* Family::find(char str[100],listnode* p)//查找函数，寻找这个人所在位置
{
	if (strcmp(p->name , str)==0)
		return p;
	if (p->children[0] == NULL)
		return NULL;
	for (int i = 0; i < p->childrennum; i++)
	{
		listnode* temp = find(str, p->children[i]);
		if (temp == NULL)//如果当前结点别是就去寻找这个结点的子节点
			continue;
		else
			return temp;//反之说明找到了就返回这个指针
	}
		
	return NULL;//如果孩子都遍历完了还是没有找到就返回空值
}
void Family::add_member()
{
	char str[100];
	cout << "请输入要添加儿子（或女儿）的人的姓名：";
	cin >> str;
	while (getchar() != '\n')
		;
	cout << "请输入" << str << "新添加的儿子（或女儿）的姓名：";
	listnode* current = find(str, root);//找到要添加的人的位置
	if (current == NULL)
	{
		cout << "未找到这个人。" << endl;
		return;
	}
	listnode* newnode = new listnode;
	cin >> newnode->name;
	if (current->children[0] == NULL)
	{
		current->children[0] = newnode;//将这个人加进去
		current->childrennum++;
	}
	else
		current->children[current->childrennum++]=newnode;
	cout << str << "的第一代子孙是";
	for (int i = 0; i < current->childrennum; i++)
		cout << current->children[i]->name << "   ";
	cout << endl;
}
void Family::release_member()//解散局部家庭
{
	cout << "请输入要解散家庭的人的姓名";
	char str[100];
	cin >> str;
	listnode* current = find(str, root);//找到要添加的人的位置
	if (current == NULL)
	{
		cout << "未找到这个人。" << endl;
		return;
	}
	cout << "要解散家庭的人是：" << str << endl;
	cout << str << "的第一代子孙是";
	for (int i = 0; i < current->childrennum; i++)
		cout << current->children[i]->name << "   ";
	cout << endl;
	delete current;
}
void Family::reset_member()//更改家庭成员姓名
{
	cout << "请输入要更改姓名的人的目前姓名：";
	char str[100];
	char new_str[100];
	cin >> str;
	cout << "请输入更改后的姓名：";
	cin >> new_str;
	listnode* current = find(str, root);//找到要添加的人的位置
	if (current == NULL)//错误判断
	{
		cout << "未找到这个人。" << endl;
		return;
	}
	strcpy_s(current->name , new_str);
	cout << str << "已更名为" << new_str;
	cout << endl;
}
void Family::show_family_tree(listnode* current)//前序遍历
{
	 if (current == NULL)
		 return;
	 for (int i = 0; i < current->childrennum; i++)
		 show_family_tree(current->children[i]);
		 cout << current->get_name() << "   ";
}
void Family::show_family_tree_layer(listnode* root)//按层遍历   具体实现，需要一个队列，读一个结点就把这个结点的孩子结点全放进队列，循环结束条件：队列为空
{
	listnode* q[100];
	int top = -1;
	if (root == NULL)
	{
		cout << "空树";
		return;
	}
	top++;
	q[top] = root;
	while (top <0)
	{
		cout << q[top]->name << "  ";
		if (q[top]->children[0] != NULL)
			for (int i = 0; i < q[top]->childrennum; i++)
				q[top++]=(q[top]->children[i]);
		q[top] = NULL;
		top--;
	}
}