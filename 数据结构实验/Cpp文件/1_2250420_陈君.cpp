#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
/*
*链表结点类，存储考生数据
*/
class List;
class listnode {
	
public:
	char number[100] = {0};//考号
	char name[100] = { 0 };//姓名
	char sex[100] = { 0 };//性别
	int age;//年龄
	char creear[100] = { 0 };//职业
	listnode* next; //结点数据
	friend List;
	/***重载运算符,直接输入输出listnode***/
	friend ostream& operator<<(ostream& os, listnode& list1)//重载左移运算符，一般要用友元函数，然后定义在全局中
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
*链表类，存储每个结点
*/
class List
{ //链表类
public:
	List(int n);//构造函数
	List();//默认构造函数
	void putout();//提取器
	int insert(char str[100]);//插入功能
	int delete_node(char str[100]);//删除功能
	void reset(char str[100]);//修改功能
	int getsize() {
		return size;
	}//获取链表大小
	void search(char str[100]);//查找功能
	listnode* getfirst() { return first; }
	~List() {
		delete first;
	}
	//LinkList的析构函数，通过调用MakeEmpty()实现对内存的回收

private:
	listnode* first, * last; //表头和表尾指针
	int size;
};
int main()
{
	cout << "首先请建立考生信息系统！" << endl;
	cout << "请输入考生人数" << endl;
	int n;
	cin >> n;
	while (1)
	{
		if (n <= 0 || !cin.good())
		{
			cout << "请输入正的考生数";
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
	cout << "请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计,0为取消操作）" << endl;
	cout << endl;
	while (1)
	{
		cout << "请选择您要进行的操作:" << endl;
		int num;
		cin >> num;
		switch (num)
		{
		case 1:
		{
			cout << "请输入需要插入的考生位置(插入位置为输入考生学号的后一位，若想在头位置插入请输入0）" << endl;
			char str[100] = { 0 };
			cin >> str;
			list.insert(str);
			break;
		}
		case 2:
		{
			cout << "请输入需要删除的考生位置" << endl;
			char str[100] = { 0 };
			cin >> str;
			list.delete_node(str);
			break;
		}
		case 3:
		{
			cout << "请输入需要查找的考生考号" << endl;
			char str[100];
			cin >> str;
			list.search(str);
			break;
		}
		case 4:
		{
			cout << "请输入需要修改的考生考号" << endl;
			char str[100];
			cin >> str;
			list.reset(str);
			break;
		}
		case 5:
		{
			cout << "整体信息为：" << endl;
			list.putout();
			break;
		}
		case 0:exit(1);
		default:
		{
			cerr << "请输入正确的操作数" << endl;
			exit(1);
		}
		}
		cout << "请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计,0为取消操作）" << endl;
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
	cout << "请依次输入考生的考号、姓名、性别、年龄及报考类别!" << endl;
	for (int i = 0; i < n; i++)
	{
		listnode* newnode = new listnode;
		cin >> *newnode;//*****会报错
		//cin >> newnode->number >> newnode->name >> newnode->sex >> newnode->age >> newnode->creear;
		last->next = newnode;//3步走
		last = newnode;
		last->next = NULL;
		size++;//千万不要再次声明了，这样声明会遮蔽中括号外size类型，导致private里面的无法更新。
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
	cout << "考号    姓名    性别    年龄    报考类别" << endl;
	listnode* node = first;
	for (int i = 0; i < size; i++)
	{
		node = node->next;
		cout << *node;
	}
}
int List::insert(char str[100]) {
	//在学号str处插入新的人
	listnode* p = first;
	if (strcmp(str,"0")==0)
	{
		cout << "请依次输入需要插入考生的考号、姓名、性别、年龄及报考类别!" << endl;
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
	} //找第i-1个结点
	if (p == NULL && first != NULL) {
		cout << "无效的插入位置" << endl;
		return 0;
	}
	else
	{
		cout << "请依次输入需要插入考生的考号、姓名、性别、年龄及报考类别!" << endl;
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
	} //找到需要删除的结点
	
	if (p == NULL && first != NULL) {
		cout << "未找到需要删除的考生" << endl;
		return 0;
	}
	else
	{
		cout << "你删除的考生信息是：" << *p;
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
	} //找到需要修改的结点
	if (p == NULL && first != NULL) {
		cout << "未找到你想修改的考生" << endl;
	}
	else
	{
		cout << "请输入重新设置的值" << endl;
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
		cout << "未找需要查找的考生" << endl;
	}
	else
		cout << *p;
}
