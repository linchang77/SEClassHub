#include<iostream>
#include<iomanip>
using namespace std;
class List;
class listnode {
	int num;
	listnode* next; 
	friend List;
public:
	listnode();//Ĭ�Ϲ��캯��
};
/*
*�����࣬�洢ÿ�����
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
	List(int n, int start, int dead_num, int survior_num);//���캯��,���ڴ���һ�����ʵ����ʱ���Զ����õ�
	List();//Ĭ�Ϲ��캯��
	~List();//�����������ͷſռ�
	void count();//�����������ݿ�ʼ��Ϸ
	void putout();//����Ҵ���
};
int main()
{
	cout << "����N��Χ��һȦ���ӵ�S���˿�ʼһ�α�������M���˳��֣�������һ���˿��Ǳ��������ѭ����ֱ��ʣ��K����Ϊֹ" << endl;
	int N, S, M, K;
	cout << "������������Ϸ��������N��" << endl;
	while (1)
	{
         
		 cin >> N;
		 if (!cin.good() || N <= 0)
			 cerr << "���������0������" << endl;
		 else
			 break;
		 while (getchar() != '\n')
			 ;
		 cin.clear();
	}//����N���������жϣ�
	cout << "��������Ϸ��ʼ��λ��S��" << endl;
	while (1)
	{
		cin >> S;
		if (!cin.good() || S <= 0||S>N)
			cerr << "���������0��С�ڵ���N������" << endl;
		else
			break;
		while (getchar() != '\n')
			;
		cin.clear();
	}//����S���������жϣ�
	cout << "��������������M��" << endl;
	while (1)
	{
		cin >> M;
		if (!cin.good() || M <= 0 )
			cerr << "���������0������" << endl;
		else
			break;
		while (getchar() != '\n')
			;
		cin.clear();
	}//����S���������жϣ�
	cout << "������ʣ�����������K��" << endl;
	while (1)
	{
		cin >>K;
		if (!cin.good() || K <= 0 || K > N)
			cerr << "���������0��С�ڵ���N������" << endl;
		else
			break;
		while (getchar() != '\n')
			;
		cin.clear();
	}//����S���������жϣ�
	List people(N,S,M,K);
	people.count();
	cout << "���ʣ��:     " << K << "��" << endl;
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
	cout << "ʣ������λ��Ϊ��";
	listnode* p = first;
	do {
		cout <<setw(8)<< p->num;
		p = p->next;
	} while (p != first);
}
List::~List()
{
//ɾȥ�����е������������
	listnode* p;
	while (first!= last)
	{
		p = first;
		first = first->next;
		delete p;
	}
	delete first;//�޸ı�βָ��
}
void List::count()
{
	listnode* p = first;
	for (int i = 0; i < start - 1; i++)
		p = p->next;
	for (int i = 1; i <= n-survior_num; i++)
	{
		for (int j = 0; j < dead_num - 2; j++)
			p = p->next;//�ҵ�Ҫɱ�����˵�ǰһ��λ��p
		listnode* q = p->next;//��ʼɾ��p������Ǹ����
		if (q == last)//�ж�ɾ�����Ƿ�Ϊβ���
			last = p;
        p->next = q->next;
	    p = p->next;
		if (q == first)//�ж�ɾ�����Ƿ�Ϊͷ�ڵ�
            first = p;
		cout << "��" <<setw(2)<< i << "�����ߵ�λ����:          " << q->num << endl;
		delete q;		
	}
}