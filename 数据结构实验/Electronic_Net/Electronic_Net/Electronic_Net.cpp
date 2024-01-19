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
	int net[100][100] = { INT_MAX };//使用邻接矩阵来存放电网图
	int  lowcost[100] ;//记录当前以加入的结点到达其他结点的最短距离
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
		cout << "请选择操作：";
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
	cout << "**          电网造价模拟系统        **" << endl;
	cout << "======================================" << endl;
	cout << "**          A --- 创建电网顶点      **" << endl;
	cout << "**          B --- 添加电网的边      **" << endl;
	cout << "**          C --- 构造最小生成树    **" << endl;
	cout << "**          D --- 显示最小生成树    **" << endl;
	cout << "**          E--- 退出程序           **" << endl;
	cout << "======================================" << endl;
}
void Net::createpoint()
{
	cout << "请输入顶点的个数：";
	cin >> pointnum;
	cout << "请依次输入各顶点的名称：" << endl;
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
		cout << "请输入两个顶点及边：";
		cin >> a >> b;
		row = findbyname(a);
		column = findbyname(b);
		if (row < 0 || column < 0)
		{
			cout << "顶点不存在" << endl;
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
	cout << "请输入起始顶点：";
	char point;
	cin >> point;
	int start = findbyname(point);
	update_lowcost(start);
	for (int i = 0; i < pointnum-1; i++)
	{
		int v, u;//v为新增加的顶点，u为与v相连的已添加的顶点
		int min = INT_MAX;
		for (int j = 0; j < pointnum; j++)
			if (lowcost[j] < min && lowcost[j] != 0)
			{
				v = j ;
				min = lowcost[j];
			}
		for (int j = 0; j < pointnum; j++)//搜索u
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
	cout << "生成prim最小生成树"<<endl;
}
void Net::update_lowcost(int p)
{
	lowcost[p] = 0;
	for (int i = 0; i < pointnum; i++)
	{
		//遍历新增顶点到其他点的距离更新
		if (net[p][i] < lowcost[i])
			lowcost[i] = net[p][i];
	}
}
void Net::putout()
{
	cout << "最小生成树的顶点和边为：" << endl << endl;
	for (int i = 0; i < mintreenum; i++)
	{
		cout << mintree[i].start << "-(" << mintree[i].cost << ")-" << mintree[i].end << "      ";
		if ((i + 1) % 5 == 0)
			cout << endl;
	}
	cout << endl;
}