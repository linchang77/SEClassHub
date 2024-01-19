#include<iostream>
using namespace std;
#define INT_MAX 2147483647
struct side
{
	char start;
	char end;
	int cost;
};
class Net;
class Net
{
public:
	void prim();
	void update_lowcost(int p);
	void setpointnum(int n) { pointnum = n; }
	int getpointnum() { return pointnum; }
	void createpoint();
	void add_sides();
	int findbyname(char name);
	void putout();
private:
	int net[100][100] = { INT_MAX };//ʹ���ڽӾ�������ŵ���ͼ
	int  lowcost[100] ;//��¼��ǰ�Լ���Ľ�㵽������������̾���
	int pointnum = 0;
	char names[100] = {0};
	int namelength=0;
	side mintree[100] = {};
	int mintreenum = 0;
};
void setup();
int main()
{
	setup();
	Net net;
	char num;
	while (1)
	{
		cout << "��ѡ�������";
		cin >> num;
		switch (num)
		{
		case 'A':
			net.createpoint();
			break;
		case 'B':
			net.add_sides();
			break;
		case 'C':
			net.prim();
			break;
		case 'D':
			net.putout();
			break;
		case 'E':
			exit(1);
		}
	}

}
void setup()
{
	cout << "**          �������ģ��ϵͳ        **" << endl;
	cout << "======================================" << endl;
	cout << "**          A --- ������������      **" << endl;
	cout << "**          B --- ��ӵ����ı�      **" << endl;
	cout << "**          C --- ������С������    **" << endl;
	cout << "**          D --- ��ʾ��С������    **" << endl;
	cout << "**          E--- �˳�����           **" << endl;
	cout << "======================================" << endl;
}
void Net::createpoint()
{
	cout << "�����붥��ĸ�����";
	cin >> pointnum;
	cout << "�������������������ƣ�" << endl;
	for (int i = 0; i < pointnum; i++)
	{
		cin >> names[i];
		namelength++;
	}
	for (int i = 0; i < pointnum; i++)
		for (int j = 0; j < pointnum; j++)
			net[i][j] = INT_MAX;
}
void Net::add_sides()
{
	char a, b;
	int row, column;
	do {
		cout << "�������������㼰�ߣ�";
		cin >> a >> b;
		row = findbyname(a);
		column = findbyname(b);
		if (row < 0 || column < 0)
		{
			cout << "���㲻����" << endl;
			return;
		}

		cin >> net[row][column];
		net[column][row]= net[row][column];
	} while (a!='?'&&b!='?'&& net[row][column] !=0);
}
int Net::findbyname(char name)
{
	for (int i = 0; i < namelength; i++)
	{
		if (name == names[i])
			return i;
	}
	return -1;
}
void Net::prim()
{
	for (int j = 0; j < pointnum; j++)
		lowcost[j] = INT_MAX;
	cout << "��������ʼ���㣺";
	char point;
	cin >> point;
	int start = findbyname(point);
	update_lowcost(start);
	for (int i = 0; i < pointnum-1; i++)
	{
		int v, u;//vΪ�����ӵĶ��㣬uΪ��v����������ӵĶ���
		int min = INT_MAX;
		for (int j = 0; j < pointnum; j++)
			if (lowcost[j] < min && lowcost[j] != 0)
			{
				v = j ;
				min = lowcost[j];
			}
		for (int j = 0; j < pointnum; j++)//����u
			if (net[v][j] == min)
				u = j;
		update_lowcost( v);
		side newside;
		newside.start = names[u];
		newside.end = names[v];
		newside.cost = net[u][v];
		mintree[mintreenum] = newside;
		mintreenum++;
	}
	cout << "����prim��С������"<<endl;
}
void Net::update_lowcost(int p)
{
	lowcost[p] = 0;
	for (int i = 0; i < pointnum; i++)
	{
		//�����������㵽������ľ������
		if (net[p][i] < lowcost[i])
			lowcost[i] = net[p][i];
	}
}
void Net::putout()
{
	cout << "��С�������Ķ���ͱ�Ϊ��" << endl << endl;
	for (int i = 0; i < mintreenum; i++)
	{
		cout << mintree[i].start << "-(" << mintree[i].cost << ")-" << mintree[i].end << "      ";
		if ((i + 1) % 5 == 0)
			cout << endl;
	}
	cout << endl;
}