#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
class List;
class listnode {
	int num;
	listnode* next; 
	friend List;
public:
	listnode();//默认构造函数
};
/*
*链表类，存储每个结点
*/
class List {
private:
	listnode* first;
	listnode* last;
	int n;
	int start;
	int dead_num;
	int survior_num;
public:
	List(int n, int start, int dead_num, int survior_num);//构造函数,你在创建一个类的实例的时候自动调用的
	List();//默认构造函数
	~List();//析构函数，释放空间
	void count();//根据所给数据开始游戏
	void putout();//输出幸存者
};
int main()
{
	cout << "现有N人围成一圈，从第S个人开始一次报数，报M的人出局，再由下一个人开是报数，如此循环，直至剩下K个人为止" << endl;
	int N, S, M, K;
	cout << "请输入生死游戏的总人数N：" << endl;
	while (1)
	{
         
		 cin >> N;
		 if (!cin.good() || N <= 0)
			 cerr << "请输入大于0的整数" << endl;
		 else
			 break;
		 while (getchar() != '\n')
			 ;
		 cin.clear();
	}//输入N（含错误判断）
	cout << "请输入游戏开始的位置S：" << endl;
	while (1)
	{
		cin >> S;
		if (!cin.good() || S <= 0||S>N)
			cerr << "请输入大于0且小于等于N的整数" << endl;
		else
			break;
		while (getchar() != '\n')
			;
		cin.clear();
	}//输入S（含错误判断）
	cout << "请输入死亡数字M：" << endl;
	while (1)
	{
		cin >> M;
		if (!cin.good() || M <= 0 )
			cerr << "请输入大于0的整数" << endl;
		else
			break;
		while (getchar() != '\n')
			;
		cin.clear();
	}//输入S（含错误判断）
	cout << "请输入剩余的死者人数K：" << endl;
	while (1)
	{
		cin >>K;
		if (!cin.good() || K <= 0 || K > N)
			cerr << "请输入大于0且小于等于N的整数" << endl;
		else
			break;
		while (getchar() != '\n')
			;
		cin.clear();
	}//输入S（含错误判断）
	List people(N,S,M,K);
	people.count();
	cout << "最后剩下:     " << K << "人" << endl;
	people.putout();
	system("pause");
	return 0;
}
listnode::listnode() {
	num = 0;
	next = NULL;
}
List::List()
{
	first = NULL;
	last = first;
	start =0;
	dead_num=0;
	survior_num=0;
	n = 0;
}
List::List(int xn, int xstart, int xdead_num, int xsurvior_num)
{
	start = xstart;
	dead_num = xdead_num;
	survior_num = xsurvior_num;
	n = xn;
	first = new listnode;
	first->num = 1;
	last = first;
	last->next = first;
	for (int i = 2; i <= n; i++)
	{
		listnode* node = new listnode;
		node->num = i;
		last->next = node;
		last = node;
		last->next = first;
	}
}
void List::putout()
{
	cout << "剩余死者位置为：";
	listnode* p = first;
	do {
		cout <<setw(8)<< p->num;
		p = p->next;
	} while (p != first);
}
List::~List()
{
//删去链表中的所有其他结点
	listnode* p;
	while (first!= last)
	{
		p = first;
		first = first->next;
		delete p;
	}
	delete first;//修改表尾指针
}
void List::count()
{
	listnode* p = first;
	for (int i = 0; i < start - 1; i++)
		p = p->next;
	for (int i = 1; i <= n-survior_num; i++)
	{
		for (int j = 0; j < dead_num - 2; j++)
			p = p->next;//找到要杀死的人的前一个位置p
		listnode* q = p->next;//开始删除p结点后的那个结点
		if (q == last)//判断删除的是否为尾结点
			last = p;
        p->next = q->next;
	    p = p->next;
		if (q == first)//判断删除的是否为头节点
            first = p;
		cout << "第" <<setw(2)<< i << "个死者的位置是:          " << q->num << endl;
		delete q;		
	}
}
