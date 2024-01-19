#include<iostream>
using namespace std;
#define N 13

struct Node
{
	int num;
	struct Node* Lnode;
	struct Node* Rnode;
};    
class Tree
{
public:
	void setleaf();//����Ҷ�ӽ��
	void construct_tree();//�����������
	void preorder();  //������ 
	void Preorder(Node* node, int depth);
	void sort();//��Ҷ�ӽ�㰴��Ȩֵ����
private:
	Node* root = NULL;//���ĸ����
	Node* leaf[80];
	int leafnum;
	char key[80];
	int keynum = 0;
};
int main()
{
	Tree tree;
	
	tree.setleaf();
	struct tree* head;
	tree.sort();
	tree.construct_tree();  //���������� 
	tree.preorder();  //������ 
	system("pause"); 
		return 0;
}
void Tree::setleaf()
{
	cout << "������ڵ����(������������):";
	cin >> leafnum;
	cout << "������ڵ�(�Կո�ָ�):";
	for (int i = 0; i < leafnum; i++)
	{
		Node* newnode = new Node;
		leaf[i] = newnode;
		cin >> leaf[i]->num;
		leaf[i]->Lnode = NULL;
		leaf[i]->Rnode = NULL;
	}
}
void Tree :: construct_tree()
{
	for (int n = 1; n < leafnum; n++)
	{
		int min = leafnum-n;
		int submin =leafnum-n-1 ;
		Node* newnode = new Node;
		newnode->num = leaf[min]->num + leaf[submin]->num;
		newnode->Lnode = leaf[min]; 
		newnode->Rnode = leaf[submin];
		//������Ҷ�ӽ��
		int position = 0;
		while (leaf[position]->num >= newnode->num)
		{
			position++;
		}
		while (min > position)
		{
			leaf[min] = leaf[min-1];
			min--;
		}
		leaf[position] = newnode;
	}
	root = leaf[0];
}
void Tree::sort()
{
	for(int i=0;i<leafnum;i++)
		for (int j = leafnum-1; j > i; j--)
		{
			if (leaf[j]->num > leaf[j - 1]->num)
			{
				int temp = leaf[j]->num;
				leaf[j]->num = leaf[j - 1]->num;
				leaf[j - 1]->num = temp;
			}
		}
}
void Tree::preorder()
{
	key[keynum] = '0';
	keynum++;
	Preorder(root,1);
}
void Tree::Preorder(Node* node,int depth)
{
	if (node->Lnode == NULL && node->Rnode == NULL)//�����Ҷ���ˣ����
	{
		cout << node->num << ":   ";
		for (int i = 0; i < depth; i++)
			cout << key[i];
		cout << endl;
		return;
	}
	key[depth] = '0';
	Preorder(node->Lnode, depth+1);
	key[depth] = '1';
	Preorder(node->Rnode, depth+1);
}
