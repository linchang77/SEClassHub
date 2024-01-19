#include<iostream>
#include<iomanip>
#define wall '#'//����ǽ
#define road '0'//����·
#define mark 'x'//������
#define start 's'//���忪ʼ
#define outer 'o'//�������
using namespace std;
struct Point
{
	int x ;
	int y ;
};
class Maze
{
public:
	void show();//չʾ�Թ�
	void showtrack();
	bool isOutter(Point point) { return map[point.x][point.y] == outer; }//�ж��Ƿ��ڳ���
	bool iswall(Point point) {return map[point.x][point.y] == wall;}//�жϸ�λ���Ƿ���ǽ
	bool ismark(Point point) { return map[point.x][point.y] == mark; }//�ж����λ���ǲ��Ǳ������
	void markroad(Point point) { map[point.x][point.y] = mark; }//�����λ�������
	void rmvmark(Point point) { map[point.x][point.y] = road; }//�����λ�ñ��ɾ��
	
private:
	char map[7][7] = { {'#','#','#','#','#','#','#'}//��ͼ
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
		cout << "�޷��߳��Թ�" << endl;
	system("pause");
	
}
void Maze::show()
{
	cout << "        0��    1��    2��    3��    4��    5��    6��"<<endl;
	for (int i = 0; i < 7; i++)
	{
		cout << i << "��" << "     ";
		for (int j = 0; j < 7; j++)
			cout << map[i][j] << "      ";
		cout << endl<<endl;
	}
}
void Maze::showtrack()
{
	cout << "�Թ�·��:" << endl;
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
Point move(Point point, string str)//�ƶ�λ�ú���
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
	//�жϵ�ǰ�ڵ��ǲ��ǳ��ڻ�����ǽ������֮ǰ�߹���·
	if (maze.isOutter(point))
		return 1;
	if (maze.iswall(point))
		return 0;
	if (maze.ismark(point))
		return 0;
	maze.markroad(point);//point��·�Ͱ����·���һ��
	//��ʼ����һ���ص�ǰ��
	if(findway(maze,move(point,"east")))//��̽��
		return 1;
	if (findway(maze, move(point, "north")))//����̽��
		return 1;
	if (findway(maze, move(point, "west")))//����̽��
		return 1;
	if (findway(maze, move(point, "south")))//��̽��
		return 1;
	maze.rmvmark(point);//�����ǰλ���߲���ȥ�˾Ͱѵ�ǰλ�õı��ɾ��Ȼ�󷵻��㵽��һ������
	return 0;
}