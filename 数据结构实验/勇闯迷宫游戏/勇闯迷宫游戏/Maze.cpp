#include<iostream>
#include<iomanip>
#define wall '#'//定义墙
#define road '0'//定义路
#define mark 'x'//定义标记
#define start 's'//定义开始
#define outer 'o'//定义出口
using namespace std;
struct Point
{
	int x ;
	int y ;
};
class Maze
{
public:
	void show();//展示迷宫
	void showtrack();
	bool isOutter(Point point) { return map[point.x][point.y] == outer; }//判断是否在出口
	bool iswall(Point point) {return map[point.x][point.y] == wall;}//判断该位置是否是墙
	bool ismark(Point point) { return map[point.x][point.y] == mark; }//判断这个位子是不是被标记了
	void markroad(Point point) { map[point.x][point.y] = mark; }//将这个位置做标记
	void rmvmark(Point point) { map[point.x][point.y] = road; }//将这个位置标记删除
	
private:
	char map[7][7] = { {'#','#','#','#','#','#','#'}//地图
					  ,{'#','s','#','0','0','0','#'}
					  ,{'#','0','#','0','#','#','#'}
					  ,{'#','0','0','0','0','0','#'}
					  ,{'#','0','0','#','#','0','#'}
					  ,{'#','0','#','0','0','0','#'}
					  ,{'#','#','#','#','#','o','#'}
	};
};
bool findway(Maze &maze,  Point point);
int main()
{
	Maze maze;
	Point point;
	point.x = 1;
	point.y = 1;
	if (findway(maze, point))
	{
		maze.show();
		maze.showtrack();
	}
	else
		cout << "无法走出迷宫" << endl;
	system("pause");
	
}
void Maze::show()
{
	cout << "        0列    1列    2列    3列    4列    5列    6列"<<endl;
	for (int i = 0; i < 7; i++)
	{
		cout << i << "行" << "     ";
		for (int j = 0; j < 7; j++)
			cout << map[i][j] << "      ";
		cout << endl<<endl;
	}
}
void Maze::showtrack()
{
	cout << "迷宫路径:" << endl;
	cout << "<1,1> ";
	for (int i = 1; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (i == 1 && i == j)
				continue;
			if (map[i][j] == mark)
				cout << "---> <" << i << ',' << j << "> ";
		}
	}
	cout << endl;
}
Point move(Point point, string str)//移动位置函数
{
	if (str == "east")
	{
		point.y++;
		return point;
	}
	if (str == "west")
	{
		point.y--;
		return point;
	}
	if (str == "south")
	{
		point.x++;
		return point;
	}
	if (str == "north")
	{
		point.x--;
		return point;
	}
}
bool findway(Maze &maze,Point point)
{
	//判断当前节点是不是出口或者是墙或者是之前走过的路
	if (maze.isOutter(point))
		return 1;
	if (maze.iswall(point))
		return 0;
	if (maze.ismark(point))
		return 0;
	maze.markroad(point);//point是路就把这个路标记一下
	//开始向下一个地点前进
	if(findway(maze,move(point,"east")))//向东探索
		return 1;
	if (findway(maze, move(point, "north")))//向南探索
		return 1;
	if (findway(maze, move(point, "west")))//向西探索
		return 1;
	if (findway(maze, move(point, "south")))//向北探索
		return 1;
	maze.rmvmark(point);//如果当前位置走不下去了就把当前位置的标记删除然后返回零到上一个函数
	return 0;
}