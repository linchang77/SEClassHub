#include<iostream>
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
	BST() :root(NULL) {};//Ĭ�Ϲ��캯��
	void build_BST();//����һ��BST
	void  insert(int num);//���빦��
	node* _search(int num,node* &p,node*root);//���ҹ��ܵĵݹ���ú���
	node*  search(int num,node* &p); //���ҹ���
	void inorder_traversal(void); //��������ݹ���ú���
	void _inorder_traversal(node* root); //��������ݹ����
private:
	node* root;
};
void initializeio();//��ʼ��io����
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
		default:cout << "��������ȷ��ѡ��" << endl;
			while (getchar() != '\n')
				;
		}
	}
}
void initializeio()//��ʼ��io����
{
	cout << endl;
	cout << "**          ����������            **" << endl;
	cout << "====================================" << endl;
	cout << "**        1 --- ��������������    **" << endl;
	cout << "**        2 --- ����Ԫ��          **" << endl;
	cout << "**        3 --- ��ѯԪ��          **" << endl;
	cout << "**        4 --- �˳�����          **" << endl;
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
			cout << "�����������������" << endl;
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
		cout << "����ʧ��" <<n<<"�Ѿ�����" << endl;
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