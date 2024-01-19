#include <iostream>
#include<vector>
using namespace std;
struct side//����ߵĽṹ��
{
	int head;
	int tail;
	int cost;
};
void sort(vector<side*> &sides)
{
	for (int i = 0; i < sides.size()-1; i++)
	{
		for (int j = sides.size() - 1; j > i; j--)
		{
			if (sides[j]->cost < sides[j - 1]->cost)
			{
				side* temp = sides[j];
				sides[j] = sides[j - 1];
				sides[j - 1] = temp;
			}
		}
	}
}
int find(int head, vector<int>points)
{
	while (points[head - 1] != -1)
	{
		head = points[head - 1] + 1;
	}
	return head - 1;
}
bool inpoints(int head, int tail, vector<int> points)
{
	return find(head, points) == find(tail, points);
}
int Kruskal(int v, int n, vector<side*>& sides)
{
	int sum = 0;
	vector<int> points;
	for (int i = 1; i <= n; i++)//��ʼ�����鼯
	{
		points.push_back(-1);
	}
	int pointnum = 0;
	int index = 0;
	while (pointnum<n-1)
	{
		int head = sides[index]->head;
		int tail = sides[index]->tail;
		if (!inpoints(head, tail,points))//�ж��¼���ı��Ƿ���ͬһ����������
		{
			//��������ߣ�Ȼ����²��鼯��Ҫ�����������Ƚӵ�ǰ��ĵ���
			points[find(tail, points)] = head - 1;
			cout << "��С�ķ��ǣ�" << head << "��" << tail<<endl;
			pointnum++;
			sum += sides[index]->cost;
		}
		index++;
	}
	return sum;
}

int main()
{
	int n, m;
	int u, v, w;
	cout << "����������ͼ�Ķ�����Ŀ�ͱߵ���Ŀ(�Կո�ָ�����������������0����):" << endl;//��������Ķ�����Ŀ�ͱ���
	while (1)
	{
		cin >> n >> m;
		if (m != 0 && n != 0)
		{
			vector<side*> sides;
			cout << "�����������ߵĽڵ�����Լ����ǵ�Ȩֵ(�Կո�ָ�������):" << endl;
			while (m--)	      //�������б����Լ����ǵ�Ȩֵ
			{
				side* newside = new side;
				cin >> u >> v >> w; //��������Լ����ǵ�Ȩֵ
				newside->cost = w;
				newside->head = u;
				newside->tail = v;
				sides.push_back(newside);
			}
			sort(sides);
			
			cout << "��С����Ϊ" << Kruskal(1, n,sides) << endl;
			cout << endl;
			cout << "����������ͼ�Ķ�����Ŀ�ͱߵ���Ŀ(�Կո�ָ�����������������0����):" << endl;//��������Ķ�����Ŀ�ͱ���
		}
		else if (n == 0 && m == 0)
			break;
	}
	return 0;
}
