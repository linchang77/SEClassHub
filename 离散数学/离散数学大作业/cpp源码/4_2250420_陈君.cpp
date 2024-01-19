#include <iostream>
#include<vector>
using namespace std;
struct side//定义边的结构体
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
	for (int i = 1; i <= n; i++)//初始化并查集
	{
		points.push_back(-1);
	}
	int pointnum = 0;
	int index = 0;
	while (pointnum<n-1)
	{
		int head = sides[index]->head;
		int tail = sides[index]->tail;
		if (!inpoints(head, tail,points))//判断新加入的边是否在同一个集合里面
		{
			//输出这条边，然后更新并查集，要将后面点的祖先接到前面的点上
			points[find(tail, points)] = head - 1;
			cout << "最小耗费是：" << head << "和" << tail<<endl;
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
	cout << "请输入所求图的顶点数目和边的数目(以空格分隔各个数，输入两个0结束):" << endl;//输入所求的顶点数目和边数
	while (1)
	{
		cin >> n >> m;
		if (m != 0 && n != 0)
		{
			vector<side*> sides;
			cout << "请输入两条边的节点序号以及它们的权值(以空格分隔各个数):" << endl;
			while (m--)	      //输入所有边数以及它们的权值
			{
				side* newside = new side;
				cin >> u >> v >> w; //输入边数以及它们的权值
				newside->cost = w;
				newside->head = u;
				newside->tail = v;
				sides.push_back(newside);
			}
			sort(sides);
			
			cout << "最小花费为" << Kruskal(1, n,sides) << endl;
			cout << endl;
			cout << "请输入所求图的顶点数目和边的数目(以空格分隔各个数，输入两个0结束):" << endl;//输入所求的顶点数目和边数
		}
		else if (n == 0 && m == 0)
			break;
	}
	return 0;
}
