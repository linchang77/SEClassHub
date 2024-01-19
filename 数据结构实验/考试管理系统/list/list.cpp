#include<iostream>
#include<iomanip>
using namespace std;
/*
*�������࣬�洢��������
*/
class List;
class listnode {
	
public:
	char number[100] = {0};//����
	char name[100] = { 0 };//����
	char sex[100] = { 0 };//�Ա�
	int age;//����
	char creear[100] = { 0 };//ְҵ
	listnode* next; //�������
	friend List;
	/***���������,ֱ���������listnode***/
	friend ostream& operator<<(ostream& os, listnode& list1)//���������������һ��Ҫ����Ԫ������Ȼ������ȫ����
	{
		return  os << setw(8) << setiosflags(ios::left) << list1.number << setw(8) << list1.name
			<< setw(8) << list1.sex << setw(8) << list1.age << setw(8) << list1.creear << endl;
	}
	friend istream& operator>>(istream& input, listnode& list1)
	{
		return input >> list1.number >> list1.name >> list1.sex >> list1.age >> list1.creear;
	}
	listnode()
	{
		age = 0;
		next = NULL;
	}
};
/*
*�����࣬�洢ÿ�����
*/
class List
{ //������
public:
	List(int n);//���캯��
	List();//Ĭ�Ϲ��캯��
	void putout();//��ȡ��
	int insert(char str[100]);//���빦��
	int delete_node(char str[100]);//ɾ������
	void reset(char str[100]);//�޸Ĺ���
	int getsize() {
		return size;
	}//��ȡ�����С
	void search(char str[100]);//���ҹ���
	listnode* getfirst() { return first; }
	~List() {
		delete first;
	}
	//LinkList������������ͨ������MakeEmpty()ʵ�ֶ��ڴ�Ļ���

private:
	listnode* first, * last; //��ͷ�ͱ�βָ��
	int size;
};
int main()
{
	cout << "�����뽨��������Ϣϵͳ��" << endl;
	cout << "�����뿼������" << endl;
	int n;
	cin >> n;
	while (1)
	{
		if (n <= 0 || !cin.good())
		{
			cout << "���������Ŀ�����";
			while (getchar() != '\n')
				;
		}
		else
			break;
		cin.clear();
		cin >> n;	
	}
	List list = List(n);
	list.putout();
	cout << "��ѡ����Ҫ���еĲ�����1Ϊ���룬2Ϊɾ����3Ϊ���ң�4Ϊ�޸ģ�5Ϊͳ��,0Ϊȡ��������" << endl;
	cout << endl;
	while (1)
	{
		cout << "��ѡ����Ҫ���еĲ���:" << endl;
		int num;
		cin >> num;
		switch (num)
		{
		case 1:
		{
			cout << "��������Ҫ����Ŀ���λ��(����λ��Ϊ���뿼��ѧ�ŵĺ�һλ��������ͷλ�ò���������0��" << endl;
			char str[100] = { 0 };
			cin >> str;
			list.insert(str);
			break;
		}
		case 2:
		{
			cout << "��������Ҫɾ���Ŀ���λ��" << endl;
			char str[100] = { 0 };
			cin >> str;
			list.delete_node(str);
			break;
		}
		case 3:
		{
			cout << "��������Ҫ���ҵĿ�������" << endl;
			char str[100];
			cin >> str;
			list.search(str);
			break;
		}
		case 4:
		{
			cout << "��������Ҫ�޸ĵĿ�������" << endl;
			char str[100];
			cin >> str;
			list.reset(str);
			break;
		}
		case 5:
		{
			cout << "������ϢΪ��" << endl;
			list.putout();
			break;
		}
		case 0:exit(1);
		default:
		{
			cerr << "��������ȷ�Ĳ�����" << endl;
			exit(1);
		}
		}
		cout << "��ѡ����Ҫ���еĲ�����1Ϊ���룬2Ϊɾ����3Ϊ���ң�4Ϊ�޸ģ�5Ϊͳ��,0Ϊȡ��������" << endl;
		cout << endl;
	}
	delete list.getfirst();
	return 0;
}
List::List(int n)
{
	first = new listnode;
	last = first;
	last->next = NULL;
	size = 0;
	cout << "���������뿼���Ŀ��š��������Ա����估�������!" << endl;
	for (int i = 0; i < n; i++)
	{
		listnode* newnode = new listnode;
		cin >> *newnode;//*****�ᱨ��
		//cin >> newnode->number >> newnode->name >> newnode->sex >> newnode->age >> newnode->creear;
		last->next = newnode;//3����
		last = newnode;
		last->next = NULL;
		size++;//ǧ��Ҫ�ٴ������ˣ������������ڱ���������size���ͣ�����private������޷����¡�
	}
}
List::List()
{
	first = new listnode;
	last = first;
	last->next = NULL;
	size = 0;
}
void List::putout()
{
	cout << endl;
	cout << "����    ����    �Ա�    ����    �������" << endl;
	listnode* node = first;
	for (int i = 0; i < size; i++)
	{
		node = node->next;
		cout << *node;
	}
}
int List::insert(char str[100]) {
	//��ѧ��str�������µ���
	listnode* p = first;
	if (strcmp(str,"0")==0)
	{
		cout << "������������Ҫ���뿼���Ŀ��š��������Ա����估�������!" << endl;
		listnode* newnode = new listnode;
		cin >> *newnode;
		newnode->next = p->next;
		p->next = newnode;
		size++;
		putout();
		return 1;
	}
	while (p != NULL && str != p->number)
	{
		p = p->next;
	} //�ҵ�i-1�����
	if (p == NULL && first != NULL) {
		cout << "��Ч�Ĳ���λ��" << endl;
		return 0;
	}
	else
	{
		cout << "������������Ҫ���뿼���Ŀ��š��������Ա����估�������!" << endl;
		listnode* newnode = new listnode;
		cin >> *newnode;
		newnode->next = p->next;
		p->next = newnode;
		size++;
	}
	putout();
	return 1;
}
int List::delete_node(char str[100])
{
	listnode* p = first;
	listnode* pre = first;
	while (p != NULL && strcmp(str, p->number) != 0)
	{
		pre = p;
		p = p->next;
	} //�ҵ���Ҫɾ���Ľ��
	
	if (p == NULL && first != NULL) {
		cout << "δ�ҵ���Ҫɾ���Ŀ���" << endl;
		return 0;
	}
	else
	{
		cout << "��ɾ���Ŀ�����Ϣ�ǣ�" << *p;
		pre->next = p->next;
		delete p;
		size--;
	}
	putout();
	return 1;
}
void List::reset(char str[100])
{
	listnode* p = first;
	while (p != NULL && strcmp(str, p->number) != 0)
	{
		p = p->next;
	} //�ҵ���Ҫ�޸ĵĽ��
	if (p == NULL && first != NULL) {
		cout << "δ�ҵ������޸ĵĿ���" << endl;
	}
	else
	{
		cout << "�������������õ�ֵ" << endl;
		cin >> *p;
	}
	putout();
}
void List::search(char str[100])
{
	listnode* p = first;
	while (p != NULL && strcmp(str, p->number) != 0)
	{
		p = p->next;
	}
	if (p == NULL && first != NULL) {
		cout << "δ����Ҫ���ҵĿ���" << endl;
	}
	else
		cout << *p;
}