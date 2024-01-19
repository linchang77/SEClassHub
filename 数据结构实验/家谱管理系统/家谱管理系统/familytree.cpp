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
	Family();//Ĭ�Ϲ��캯��
	~Family();//��������
	listnode* find(char str[100], listnode* p);//���Һ�����Ѱ�����������λ��
	void improve_family();//���Ƽ���
	void add_member();//��Ӽ�ͥ��Ա
	void release_member();//��ɢ�ֲ���ͥ
	void reset_member();//���ļ�ͥ��Ա����
	listnode* get_root() { return root; }//��ȡ�����ĵ�ַ
	void show_family_tree(listnode* current);
	void show_family_tree_layer(listnode* root);
private:
	listnode* root;
};
void initializeio();//��ʼ��io����
int main()
{
	
	initializeio();
	cout << "������";
	Family family;
	char ch;
	listnode* root = family.get_root();
	while(1)
	{
		 cout <<endl;
         cout << "��ѡ��Ҫִ�еĲ�����";
		 cin >> ch;
		 switch (ch)
		 {
		 case 'A':family.improve_family(); break;
		 case 'B':family.add_member(); break;
		 case 'C':family.release_member(); break;
		 case 'D':family.reset_member(); break; 
		 case 'E':family.show_family_tree_layer(root); exit(1);
		 default:cout << "��������ȷ��ѡ��" << endl;
			 while (getchar() != '\n')
				 ;
		 }
	}
	
}
void initializeio()//��ʼ��io����
{
	cout << endl;
	cout << "**          ���׹���ϵͳ          **" << endl;
	cout << "====================================" << endl;
	cout << "**     ��ѡ��Ҫִ�еĲ��� :       **" << endl;
	cout << "**        A --- ���Ƽ���          **" << endl;
	cout << "**        B --- ��Ӽ�ͥ��Ա      **" << endl;
	cout << "**        C --- ��ɢ�ֲ���ͥ      **" << endl;
	cout << "**        D --- ���ļ�ͥ��Ա����  **" << endl;
	cout << "**        E --- �˳�����          **" << endl;
	cout << "====================================" << endl;
	cout << "���Ƚ���һ�����ף�" << endl;
	
}
Family::Family()//Ĭ�Ϲ��캯��
{
	char str[100];
	cout << "���������ȵ�������" ;
	cin >> str;
	cout << "�˼��׵������ǣ�" << str << endl;
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
	listnode* current;//Ҫ������ͥ���˵ĵ�ַ
	
	cout << "������Ҫ������ͥ���˵�������";
	cin >> str;
	current = find(str, root);
	if (current == NULL)
	{
		cout << "δ�ҵ�����ˡ�" << endl;
		return;
	}
	cout << "������" << str << "�Ķ�Ů������";
	cin >> n;
	current->childrennum = n;
	cout << "����������" << str << "�Ķ�Ů��������";
	for (int i = 0; i < n; i++)
	{
		listnode* newnode = new listnode;
		cin >> newnode->name;
		current->children[i]=newnode;
	}
	//���������ҵ�������ͥ����
	for (int i = 0; i < n; i++)
		cout << current->children[i]->name << "   ";
	cout << endl;
}
listnode* Family::find(char str[100],listnode* p)//���Һ�����Ѱ�����������λ��
{
	if (strcmp(p->name , str)==0)
		return p;
	if (p->children[0] == NULL)
		return NULL;
	for (int i = 0; i < p->childrennum; i++)
	{
		listnode* temp = find(str, p->children[i]);
		if (temp == NULL)//�����ǰ�����Ǿ�ȥѰ����������ӽڵ�
			continue;
		else
			return temp;//��֮˵���ҵ��˾ͷ������ָ��
	}
		
	return NULL;//������Ӷ��������˻���û���ҵ��ͷ��ؿ�ֵ
}
void Family::add_member()
{
	char str[100];
	cout << "������Ҫ��Ӷ��ӣ���Ů�������˵�������";
	cin >> str;
	while (getchar() != '\n')
		;
	cout << "������" << str << "����ӵĶ��ӣ���Ů������������";
	listnode* current = find(str, root);//�ҵ�Ҫ��ӵ��˵�λ��
	if (current == NULL)
	{
		cout << "δ�ҵ�����ˡ�" << endl;
		return;
	}
	listnode* newnode = new listnode;
	cin >> newnode->name;
	if (current->children[0] == NULL)
	{
		current->children[0] = newnode;//������˼ӽ�ȥ
		current->childrennum++;
	}
	else
		current->children[current->childrennum++]=newnode;
	cout << str << "�ĵ�һ��������";
	for (int i = 0; i < current->childrennum; i++)
		cout << current->children[i]->name << "   ";
	cout << endl;
}
void Family::release_member()//��ɢ�ֲ���ͥ
{
	cout << "������Ҫ��ɢ��ͥ���˵�����";
	char str[100];
	cin >> str;
	listnode* current = find(str, root);//�ҵ�Ҫ��ӵ��˵�λ��
	if (current == NULL)
	{
		cout << "δ�ҵ�����ˡ�" << endl;
		return;
	}
	cout << "Ҫ��ɢ��ͥ�����ǣ�" << str << endl;
	cout << str << "�ĵ�һ��������";
	for (int i = 0; i < current->childrennum; i++)
		cout << current->children[i]->name << "   ";
	cout << endl;
	delete current;
}
void Family::reset_member()//���ļ�ͥ��Ա����
{
	cout << "������Ҫ�����������˵�Ŀǰ������";
	char str[100];
	char new_str[100];
	cin >> str;
	cout << "��������ĺ��������";
	cin >> new_str;
	listnode* current = find(str, root);//�ҵ�Ҫ��ӵ��˵�λ��
	if (current == NULL)//�����ж�
	{
		cout << "δ�ҵ�����ˡ�" << endl;
		return;
	}
	strcpy_s(current->name , new_str);
	cout << str << "�Ѹ���Ϊ" << new_str;
	cout << endl;
}
void Family::show_family_tree(listnode* current)//ǰ�����
{
	 if (current == NULL)
		 return;
	 for (int i = 0; i < current->childrennum; i++)
		 show_family_tree(current->children[i]);
		 cout << current->get_name() << "   ";
}
void Family::show_family_tree_layer(listnode* root)//�������   ����ʵ�֣���Ҫһ�����У���һ�����Ͱ�������ĺ��ӽ��ȫ�Ž����У�ѭ����������������Ϊ��
{
	listnode* q[100];
	int top = -1;
	if (root == NULL)
	{
		cout << "����";
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