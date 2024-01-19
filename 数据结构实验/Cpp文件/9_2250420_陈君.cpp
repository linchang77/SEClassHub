#include<iostream>
#include<cstring>
using namespace std;
class BST;
class node
{
public:
	node();
	node(int n);
	int get_key();
private:
	friend BST;
	node* leftchild;
	node* rightchild;
	int key;
};
class BST
{
public:
	BST() :root(NULL) {};//默认构造函数
	void build_BST();//构建一个BST
	void  insert(int num);//插入功能
	node* _search(int num,node* &p,node*root);//查找功能的递归调用函数
	node*  search(int num,node* &p); //查找功能
	void inorder_traversal(void); //中序遍历递归调用函数
	void _inorder_traversal(node* root); //中序遍历递归调用
private:
	node* root;
};
void initializeio();//初始化io界面
int main()
{

	initializeio();
	BST tree;
	int n;
	while (1)
	{
		cout << endl;
		cout << "Please select: ";
		cin >> n;
		switch (n)
		{
		case 1:tree.build_BST(); break;
		case 2:
			int m;
			cout << "Please input key which inserted: ";
			cin >> m;
			tree.insert(m); 
			tree.inorder_traversal();
			break;
		case 3:
			int x;
			cout << "Please input key which searched: ";
			cin >> x;
			node* p;
			if (tree.search(x, p) == NULL)
				cout << x << " not exist!" << endl;
			else
				cout << "search success!" << endl;
			break;
		case 4:
			exit(1);
			break;
		default:cout << "请输入正确的选项" << endl;
			while (getchar() != '\n')
				;
		}
	}
}
void initializeio()//初始化io界面
{
	cout << endl;
	cout << "**          二叉排序树            **" << endl;
	cout << "====================================" << endl;
	cout << "**        1 --- 建立二叉排序树    **" << endl;
	cout << "**        2 --- 插入元素          **" << endl;
	cout << "**        3 --- 查询元素          **" << endl;
	cout << "**        4 --- 退出程序          **" << endl;
	cout << "====================================" << endl;
}
node::node()
{
	rightchild = NULL;
	leftchild = NULL;
	key = 0;
}
node::node(int n)
{
	rightchild = NULL;
	leftchild = NULL;
	key = n;
}
int node::get_key()
{
	return key;
}
void BST::build_BST()
{
	cout << "Please input key to creat Bsort_Tree:(0 to quit)" << endl;
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0)
			break;
		else if (!cin.good())
		{
			cout << "输入错误，请重新输入" << endl;
			break;
		}
		else
			insert(n);
	}
	inorder_traversal();
	system("pause");
}
void BST::insert(int n)
{
	node* p = NULL;
	node* newnode = new node(n);
	if (root == NULL)
	{
		root = newnode;
		return;
	}
	if (search(n, p) != NULL)
		cout << "插入失败" <<n<<"已经存在" << endl;
	else
	{
		if (n > p->key)
			p->rightchild = newnode;
		else
			p->leftchild = newnode;	
	}
}
node* BST::search(int n,node*& p)
{
	return _search( n,p,root);
}
node* BST::_search(int n, node*& p, node* root)
{
	if (root == NULL)
		return NULL;
	if (root->key == n)
		return root;
	else if (root->key < n)
	{
		p = root;
		return _search(n, p, root->rightchild);
	}
	else 
	{
		p = root;
		return _search(n, p, root->leftchild); 
	}
}
void BST::inorder_traversal()
{
	_inorder_traversal(root);
	cout << endl;
	return;
}
void BST:: _inorder_traversal(node* root)
{
	if (root == NULL)
		return;
	_inorder_traversal(root->leftchild);
	cout << root->key << "->";
	_inorder_traversal(root->rightchild);
	return;
}
