/* 修改版 */ 
#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include<time.h>
#include<string.h>
#include<iomanip>
#define BOARD_SIZE 12
#define EMPTY 0
#define BLACK 1
#define WHITE 2
#define TRUE 1
#define FALSE 0
#define START "START"
#define PLACE "PLACE"
#define TURN "TURN"
#define END "END"
#define infinity          1000000000
//定义各种棋型的得分
#define MY_FIVE           100000000
#define ENEMY_FIVE       -400000000//如果算到对方能够直接连成五个子的情况，肯定不行
#define MY_LIVE_FOUR      100500
#define ENEMY_LIVE_FOUR  -100000
#define MY_GO_FOUR        10500
#define ENEMY_GO_FOUR    -10000
#define MY_JUMP_FIVE      1050
#define ENEMY_JUMP_FIVE  -1050
#define MY_JUMP_FOUR      1000
#define ENEMY_JUMP_FOUR  -1000
#define MY_LIVE_THREE     1050
#define ENEMY_LIVE_THREE -1000
#define MY_LIVE_TWO       11
#define ENEMY_LIVE_TWO   -10
using namespace std;
int m = 0;
int n = 0;
int myFlag;//我方棋子的颜色，1为黑，2为白 
int enemyFlag;//敌方棋子的颜色，1为黑，2为白  
int turn = 0;//记录棋局所走步数
char board[BOARD_SIZE][BOARD_SIZE] = { 0 };
class Node;
class Point;
/*
* 排序函数，根据这个点的得分降序排序 
*/
void sort(vector<Point>& list);
void swap(int i, int j, vector<Point>& list);
class Point {
public:
    friend Node;
    int  get_x() { return x; }
    int  get_y() { return y; }
    int  get_vaule() { return value; }
    int  get_score() { return score; }
    Point(int x, int y, int value)
    {
        this->x = x;
        this->y = y;
        this->value = value;
        score = 0;
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
        value = 0;
        score = 0;
    }
    Point()
    {
        x = 0;
        y = 0;
        value = 0;
        score = 0;
    }
    void new_point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
private:
    int x;
    int y;
    int value;//这个落子的得分
    int score;
};
class Node
{
public:
    void update_point(int x, int y);//更新当前棋盘的得分
    void get_the_score();//算出当前棋盘每个落子的得分
    void copyboard(int tree_board[BOARD_SIZE][BOARD_SIZE]);//带有棋盘的构造函数
    void my_find_point();//我方的启发函数
    void enemy_find_point();//敌方的启发函数
    void place_enemychess(Point point)//敌方落子
    {
        tree_board[point.get_x()][point.get_y()] = enemyFlag;
    }
    void place_mychess(Point point)//我方落子
    {
        tree_board[point.get_x()][point.get_y()] = myFlag;
    }
    void renew_point();//重置落子点，因为算出一次落子之后这个root结点里面的point不会重置
    Point max(int depth);//计算这结点的值，他的子节点在最大层
    Point min(int depth);//计算这结点的值，他的子节点在最小层
    int evaluate();//评估函数
    void push(Point point)
    {
        already_point.push_back(point);
    }
    void copypoint(vector<Point> vec)//拷贝落子数组
    {
        already_point = vec;
    }
    Node();
    void show();
private:

    int tree_board[BOARD_SIZE][BOARD_SIZE];//这个结点的棋盘
    queue<Point> posible_point;//记录这个结点可能的落子点
    vector<Point> already_point;//存放已经落好的子
    int Get_Nums1(Point point);//寻找上方的五元组并打分
    int Get_Nums2(Point point);//寻找左边的五元组
    int Get_Nums3(Point point);//寻找右上的五元组
    int Get_Nums4(Point point);//寻找左上的五元组
    Point best_point;//最佳落子
    int father_point;//存放这个结点的上一个结点的值，在Max层初始值为-infinity，在Min层初始值为infinity
};


void debug(const char* str)
{
    printf("DEBUG %s\n", str);
    fflush(stdout);//清空缓存区
}
int isInBound(int x, int y)
{
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}
void end(int x)
{
    exit(0);
}
void loop()
{
    Node root;//建立根结点
    char tag[10] = { 0 };
    Point point(0, 0);
    int status;
    while (TRUE)
    {
        memset(tag, 0, sizeof(tag));
        cin >> tag;
        if (strcmp(tag, START) == 0)
        {
            cin >> myFlag;
            enemyFlag = 3 - myFlag;
            printf("OK\n");
            fflush(stdout);
        }
        else if (strcmp(tag, PLACE) == 0)
        {
            int x, y;
            cin >> x >> y;
            point.new_point(x, y);
            root.place_enemychess(point);//更新根结点的棋盘
            root.push(point);//放到队列里面
            turn++;
        }
        else if (strcmp(tag, TURN) == 0)
        {
            turn++;
            if (turn == 1 && myFlag == 1)//写死开局
            {
                Point best_point(4, 4);
                root.place_mychess(best_point);
                root.push(best_point);//放到队列里面
                //printf("DEBUG %d %d %d\n", best_point.get_x(), best_point.get_y(), best_point.get_vaule());
                //cout << best_point.get_vaule() << endl;
                //root.show();
                //cout << "m=" << m;
                //cout << "n=" << n << endl;
                root.renew_point();//重置参数
                cout << best_point.get_x() << " " << best_point.get_y() << endl;
            }
            else
            {
                Point best_point = root.max(1);
                root.place_mychess(best_point);
                root.push(best_point);//放到队列里面
               // printf("DEBUG %d %d %d\n", best_point.get_x(), best_point.get_y(), best_point.get_vaule());
               // cout << best_point.get_vaule() << endl;
               // root.show();
                //cout << "m=" << m;
                //cout << "n=" << n << endl;
                root.renew_point();//重置参数
                cout << best_point.get_x() << " " << best_point.get_y() << endl;
            }
        }
        else if (strcmp(tag, END) == 0)
        {
            cin >> status;
            end(status);
        }
    }
}
int main(int argc, char* argv[])
{
    loop();
    return 0;
}
Node::Node()//结点的初始化，构造函数
{
    best_point.value = -infinity;
    int middlePlace = BOARD_SIZE / 2;
    memset(tree_board, 0, sizeof(tree_board));
    tree_board[middlePlace - 1][middlePlace - 1] = WHITE;
    tree_board[middlePlace][middlePlace] = WHITE;
    tree_board[middlePlace - 1][middlePlace] = BLACK;
    tree_board[middlePlace][middlePlace - 1] = BLACK;
    Point point1(5, 5);
    Point point2(6, 6);
    Point point3(6, 5);
    Point point4(5, 6);
    already_point.push_back(point1);
    already_point.push_back(point2);
    already_point.push_back(point3);
    already_point.push_back(point4);
    father_point = infinity;
}
void Node::enemy_find_point()//敌方寻找可能的落子点写到队列里面,*启发函数*
{
    vector<Point> temp;//临时存储待排序的点
    /*具体思路
    * 目标是计算可能的落子点，放到Node类里面的posible——point数组里面
    * 遍历棋盘，如果这个格子是0，且周围九宫格内至少有一个棋子，就加入到可能落子的数组里
    * 同时计算落下这个子后，敌方落子的得分，方便后面排序。
    */
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
        {
            if (tree_board[i][j] == 0)
            {
                int tag = 0;
                int n = i - 1;
                int m1 = (n <= i + 1);
                int m2 = n < 12;
                for (int n = i - 1; (n <= (i + 1)) && (n < 12); n++)
                {
                    if (n < 0)//如果n超出棋盘下一个
                        continue;
                    for (int m = j - 1; m <= j + 1 && m < 12; m++)
                    {
                        if (m < 0 || (n == i && m == j))//如果n超出棋盘或者等于原来的棋子就下一个
                            continue;
                        if (tree_board[n][m] != 0)
                        {
                            tag = 1;
                            break;
                        }
                    }
                    if (tag == 1)
                    {
                        Point point(i, j);
                        tree_board[i][j] = enemyFlag;
                        point.score = -Get_Nums1(point)
                            - Get_Nums2(point)
                            - Get_Nums3(point)
                            - Get_Nums4(point);
                        tree_board[i][j] = 0;
                        temp.push_back(point);
                        break;
                    }
                }
            }
        }
    //对temp按照得分降序排序
    sort(temp);
    //赋值给possible_point
    for (int i = 0; i < temp.size() - 1; i++)
        posible_point.push(temp[i]);
}
void Node::my_find_point()//我方寻找可能的落子点写到队列里面,*启发函数*
{
    vector<Point> temp;//临时存储待排序的点
    /*具体思路
    * 目标是计算可能的落子点，放到Node类里面的posible——point数组里面
    * 遍历棋盘，如果这个格子是0，且周围九宫格内至少有一个棋子，就加入到可能落子的数组里
    * 同时计算落下这个子后，敌方落子的得分，方便后面排序。
    */
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
        {
            if (tree_board[i][j] == 0)
            {
                int tag = 0;
                int n = i - 1;
                int m1 = (n <= i + 1);
                int m2 = n < 12;
                for (int n = i - 1; (n <= (i + 1)) && (n < 12); n++)
                {
                    if (n < 0)//如果n超出棋盘下一个
                        continue;
                    for (int m = j - 1; m <= j + 1 && m < 12; m++)
                    {
                        if (m < 0 || (n == i && m == j))//如果n超出棋盘或者等于原来的棋子就下一个
                            continue;
                        if (tree_board[n][m] != 0)
                        {
                            tag = 1;
                            break;
                        }
                    }
                    if (tag == 1)
                    {
                        Point point(i, j);
                        tree_board[i][j] = myFlag;
                        point.score = Get_Nums1(point)
                            + Get_Nums2(point)
                            + Get_Nums3(point)
                            + Get_Nums4(point);
                        tree_board[i][j] = 0;
                        temp.push_back(point);
                        break;
                    }
                }
            }
        }
    //对temp按照得分降序排序
    sort(temp);
    //赋值给possible_point
    for (int i = 0; i < temp.size(); i++)
        posible_point.push(temp[i]);
}
void sort(vector<Point>& list)
{
    for (int i = 0; i < list.size() - 1; i++)
        for (int j = list.size() - 1; j > i; j--)
            if (list[j].get_score() > list[j - 1].get_score())
                swap(j, j - 1, list);
}
void swap(int i, int j, vector<Point>& list)
{
    Point  temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}
/*
* 复制棋盘
*/
void Node::copyboard(int tree_board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            this->tree_board[i][j] = tree_board[i][j];
}
/*
* 核心函数，最大值搜索
* 计算这结点的对优落子返回这个落子
* 递归结束条件：当参数深度达到4层时开始计算当前棋盘的得分，
* 并将这个得分的落子传递给上一层。
* 具体实现：
* 首先调用启发函数，获取落子
* 开始遍历这些落子
* 每次获得这个落子所能够获得的最佳局面的得分
* 首先用这个得分判断能不能剪枝，如果剪枝就跳过一层的搜索
* 将这个得分与这一层的最佳落子的得分比较，如果比这个得分大就替换这个最佳落子
* 所有落子遍历完后返回这个层的最佳落子
*/
Point Node::max(int depth)//计算这结点的值，他的子节点在最大层
{
    this->my_find_point();//初始化启发函数
    if (depth == 1)//开始搜索之前先看看当前局面能不能直接连成五个，不知道为啥这个弱智程序有些时候会不连五个
    {
        queue<Point> temp = posible_point;
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp.front().score >= MY_FIVE)
                return temp.front();
            temp.pop();
        }
    }
    if (posible_point.size() == 1)//如果可以落子的点只有一个的话直接开始评估,不再进行向下的搜索
        depth = 5;
    if (depth == 5)
    {
        //算出目前棋盘每个落子的得分
        this->get_the_score();
        while (!this->posible_point.empty())
        {
            Node node;//产生一个新的结点
            n++;
            node.copyboard(this->tree_board);//将根结点的棋盘copy过去
            node.copypoint(this->already_point);//将根节点的棋盘落子copy过去
            node.place_mychess(this->posible_point.front());//落子
            node.push(this->posible_point.front());//加入新的落子
            node.update_point(this->posible_point.front().x, this->posible_point.front().y);//局部刷新落子得分
            this->posible_point.front().value = node.evaluate();//给这个落子形成的局面打分
            if (this->posible_point.front().value >= this->father_point)//剪枝
            {
                m++;
                return this->posible_point.front();
            }

            if (this->posible_point.front().value > this->best_point.value)
            {
                this->best_point = this->posible_point.front();//将这个落子赋值给root
            }
            this->posible_point.pop();
        }
        return this->best_point;
    }
    depth++;
    while (!this->posible_point.empty())
    {
        Node node;//产生一个新的结点
        n++;
        node.best_point.value = infinity;
        node.father_point = this->best_point.value;//存新产生结点的father_point
        node.copyboard(this->tree_board);//将根结点的棋盘copy过去
        node.copypoint(this->already_point);//将根节点的棋盘落子copy过去
        node.place_mychess(this->posible_point.front());//落子
        node.push(this->posible_point.front());//加入新的落子
        this->posible_point.front().value = node.min(depth).value;//调用min函数将这个落子的最优得分算出来
        if (this->posible_point.front().value >= this->father_point)
        {
            m++;
            return this->posible_point.front();
        }
        if (this->posible_point.front().value > this->best_point.value)//计算落子之后这步棋的得分并和root的比较判断是否要更新root的值
        {
            this->best_point = this->posible_point.front();//将这步落子放到best_point里面去
        }
        this->posible_point.pop();
    }
    return this->best_point;
}
/*
* 核心函数，最小值搜索
* 计算这结点的对优落子返回这个落子
* 递归结束条件：当参数深度达到4层时开始计算当前棋盘的得分，
* 并将这个得分的落子传递给上一层。
* 具体实现：
* 首先调用启发函数，获取落子
* 开始遍历这些落子
* 每次获得这个落子所能够获得的最佳局面的得分
* 首先用这个得分判断能不能剪枝，如果剪枝就跳过一层的搜索
* 将这个得分与这一层的最佳落子的得分比较，如果比这个得分小就替换这个最佳落子
* 所有落子遍历完后返回这个层的最佳落子
*/
Point Node::min(int depth)//计算这结点的值，他的子节点在最小层
{
    this->enemy_find_point();//初始化启发函数
    if (posible_point.size() == 1)//如果可以落子的点只有一个的话直接开始评估
        depth = 4;
    if (depth == 4)
    {
        //算出目前棋盘每个落子的得分
        this->get_the_score();
        while (!this->posible_point.empty())
        {
            Node node;//产生一个新的结点
            n++;
            node.best_point.value = -infinity;
            node.father_point = this->best_point.value;
            node.copyboard(this->tree_board);//将根结点的棋盘copy过去
            node.copypoint(this->already_point);//将根节点的棋盘落子copy过去
            node.place_enemychess(this->posible_point.front());//落子
            node.push(this->posible_point.front());//加入新的落子
            node.update_point(this->posible_point.front().x, this->posible_point.front().y);//局部刷新落子得分
            this->posible_point.front().value = node.evaluate();//调用min函数将这个落子的最优得分算出来
            if (this->posible_point.front().value <= this->father_point)//剪枝
                return this->posible_point.front();
            if (this->posible_point.front().value < this->best_point.value)//计算落子之后这步棋的得分并和root的比较判断是否要更新root的值
                this->best_point = this->posible_point.front();//将这步落子放到best_point里面去
            this->posible_point.pop();
        }
        return this->best_point;
    }
    depth++;
    while (!this->posible_point.empty())
    {
        Node node;//产生一个新的结点
        n++;
        node.best_point.value = -infinity;
        node.father_point = this->best_point.value;
        node.copyboard(this->tree_board);//将根结点的棋盘copy过去
        node.copypoint(this->already_point);//将根节点的棋盘落子copy过去
        node.place_enemychess(this->posible_point.front());//落子
        node.push(this->posible_point.front());//加入新的落子
        this->posible_point.front().value = node.max(depth).value;//调用min函数将这个落子的最优得分算出来
        if (this->posible_point.front().value <= this->father_point)
            return this->posible_point.front();
        if (this->posible_point.front().value < this->best_point.value)//计算落子之后这步棋的得分并和root的比较判断是否要更新root的值
            this->best_point = this->posible_point.front();//将这步落子放到best_point里面去
        this->posible_point.pop();
    }
    return this->best_point;
}
//算出落子点后，更新初始值
void Node::renew_point()
{
    best_point.value = -infinity;
}
//展示棋盘，方便调试
void Node::show()
{
    cout << "   0 1 2 3 4 5 6 7 8 9 A B " << endl;
    for (int i = 0; i < 12; i++)
    {
        cout << setiosflags(ios::left) << setw(3) << i;
        for (int j = 0; j < 12; j++)
            cout << tree_board[i][j] << ' ';
        cout << endl;
    }
}
/*
* 需要一个vector<point>//存已经放好的棋子
* 遍历这个队列
* 然后用一个get_point_value函数获取落子的得分：如果是黑子得多少如果是白子得多少
* 算好就加到总的分数最后得到总分
*/
//将棋盘的每个棋子的得分加起来返回
int Node::evaluate()//评估函数
{
    int sum = 0;
    for (unsigned int i = 0; i < already_point.size(); i++)
        sum = sum + already_point[i].score;
    return sum;
}
/*
* 核心算法：评估每个棋子的得分
* 将这个棋子的四个方向上的得分相加，如果四个方向上得分不全为1，
* 此时局势比较优，就将四个方向的得分相乘。
*/
void Node::get_the_score()
{
    for (unsigned int i = 0; i < already_point.size(); i++)
    {
        int a = Get_Nums1(already_point[i]);
        int b = Get_Nums2(already_point[i]);
        int c = Get_Nums3(already_point[i]);
        int d = Get_Nums4(already_point[i]);
        int tag = a >= 0 ? 1 : -1;
        if (a * b * c * d >= MY_LIVE_THREE * MY_LIVE_THREE)
            already_point[i].score = tag * abs(a * b * c * d) / 100;
        else
            already_point[i].score = a + b + c + d;
    }

}
/*
* 优化算法：局部刷新棋盘的得分
* 落子后的棋子，只对他四个方向上的棋子的得分有影响
* 所以只用更新这些被落子影响到的棋子得分就可以得到
* 新的棋盘棋子得分。
*/
void Node::update_point(int x, int y)
{
    for (unsigned int i = 0; i < already_point.size(); i++)
    {
        if ((already_point[i].x == x && already_point[i].y > y - 4 && already_point[i].y < y + 4)//水平方向上的点
            || (already_point[i].y == y && already_point[i].x > x - 4 && already_point[i].x < x + 4)//竖直方向上
            || (abs(already_point[i].y - y) == abs(already_point[i].x - x) && abs(already_point[i].x - x) <= 4))//对角线上的
        {
            int a = Get_Nums1(already_point[i]);
            int b = Get_Nums2(already_point[i]);
            int c = Get_Nums3(already_point[i]);
            int d = Get_Nums4(already_point[i]);
            int tag = a >= 0 ? 1 : -1;
            if (a * b * c * d >= MY_LIVE_THREE * MY_LIVE_THREE)
                already_point[i].score = tag * abs(a * b * c * d) / 100;
            else
                already_point[i].score = a + b + c + d;
        }
    }

}
/*
* 从四个方向上寻找棋子的是否存在特定的棋型比如活三活四活二等
* 返回得分
*/
// 这里代码其实可以优化成一个函数，即加上一个方向类，使用for循环寻找四个方向，
// 但是我写不动了就这样吧，四百行复制黏贴挺好的
int Node::Get_Nums1(Point point)//向垂直寻找
{
    int tag = 0;//判断这个子边上其他子的个数
    int num = 1;
    int jump = 0;//判断这个方向是否存在跳的类型
    int flag = tree_board[point.x][point.y];
    Point temp(point.x - 1, point.y);
    for (int i = 0; i < 4; i++)//向上寻找
    {
        if (temp.x < 0)
        {
            tag++;
            break;
        }
        if (tree_board[point.x][point.y] == tree_board[temp.x][temp.y])
            num++;
        else if (tree_board[temp.x][temp.y] == 0)
        {
            if (tree_board[temp.x - 1][temp.y] == tree_board[point.x][point.y] && jump == 0)
            {
                jump = 1;
                num++;
                temp.x--;
                i++;
            }
            else
                break;
        }
        else
        {
            tag++;
            break;
        }
        temp.x--;
    }
    temp.x = point.x + 1;
    for (int i = 0; i < 4; i++)
    {
        if (temp.x >= 12)
        {
            tag++;
            break;
        }
        if (tree_board[point.x][point.y] == tree_board[temp.x][temp.y])
            num++;
        else if (tree_board[temp.x][temp.y] == 0)
            if (tree_board[temp.x + 1][temp.y] == tree_board[point.x][point.y] && jump == 0)
            {
                jump = 1;
                num++;
                temp.x++;
                i++;
            }
            else
                break;
        else
        {
            tag++;
            break;
        }
        temp.x++;
    }
    if (flag == myFlag)
    {
        if (num == 5)
            return MY_FIVE;
        else if (num == 4 && tag == 0 && jump == 0)
            return MY_LIVE_FOUR;
        else if (num == 4 && tag == 1 && jump == 0)
            return MY_GO_FOUR;
        else if (num == 4 && jump == 1)//跳五
            return MY_JUMP_FIVE;
        else if (num == 3 && tag == 0 && jump == 1)//跳四
            return MY_JUMP_FOUR;
        else if (num == 3 && tag == 0 && jump == 0)
            return MY_LIVE_THREE;
        else if (num == 2 && tag == 0 && jump == 0)
            return MY_LIVE_TWO;
        else
            return 1;
    }
    else
    {
        if (num == 5)
            return ENEMY_FIVE;
        else if (num == 4 && tag == 0 && jump == 0)
            return ENEMY_LIVE_FOUR;
        else if (num == 4 && tag == 1 && jump == 0)
            return ENEMY_GO_FOUR;
        else if (num == 4 && jump == 1)//跳五
            return ENEMY_JUMP_FIVE;
        else if (num == 3 && tag == 0 && jump == 1)//跳四
            return ENEMY_JUMP_FOUR;

        else if (num == 3 && tag == 0 && jump == 0)
            return ENEMY_LIVE_THREE;
        else if (num == 2 && tag == 0 && jump == 0)
            return ENEMY_LIVE_TWO;
        else
            return -1;
    }
}
int Node::Get_Nums2(Point point)//向水平方向寻找
{
    int tag = 0;//判断这个子边上其他子的个数
    int num = 1;
    int jump = 0;
    int flag = tree_board[point.x][point.y];
    Point temp(point.x, point.y - 1);
    for (int i = 0; i < 4; i++)
    {
        if (temp.y < 0)
        {
            tag++;
            break;
        }
        if (flag == tree_board[temp.x][temp.y])
            num++;
        else if (tree_board[temp.x][temp.y] == 0)
            if (tree_board[temp.x][temp.y - 1] == tree_board[point.x][point.y] && jump == 0)
            {
                jump = 1;
                num++;
                temp.y--;
                i++;
            }
            else
                break;
        else
        {
            tag++;
            break;
        }
        temp.y--;
    }
    temp.y = point.y + 1;
    for (int i = 0; i < 4; i++)
    {
        if (temp.y >= 12)
        {
            tag++;
            break;
        }
        if (tree_board[point.x][point.y] == tree_board[temp.x][temp.y])
            num++;
        else if (tree_board[temp.x][temp.y] == 0)
            if (tree_board[temp.x][temp.y + 1] == tree_board[point.x][point.y] && jump == 0)
            {
                jump = 1;
                num++;
                temp.y++;
                i++;
            }
            else
                break;
        else
        {
            tag++;
            break;
        }
        temp.y++;
    }
    if (flag == myFlag)
    {
        if (num == 5)
            return MY_FIVE;
        else if (num == 4 && tag == 0 && jump == 0)
            return MY_LIVE_FOUR;
        else if (num == 4 && tag == 1 && jump == 0)
            return MY_GO_FOUR;
        else if (num == 4 && jump == 1)//跳五
            return MY_JUMP_FIVE;
        else if (num == 3 && tag == 0 && jump == 1)//跳四
            return MY_JUMP_FOUR;
        else if (num == 3 && tag == 0 && jump == 0)
            return MY_LIVE_THREE;
        else if (num == 2 && tag == 0 && jump == 0)
            return MY_LIVE_TWO;
        else
            return 1;
    }
    else
    {
        if (num == 5)
            return ENEMY_FIVE;
        else if (num == 4 && tag == 0 && jump == 0)
            return ENEMY_LIVE_FOUR;
        else if (num == 4 && tag == 1 && jump == 0)
            return ENEMY_GO_FOUR;
        else if (num == 4 && jump == 1)//跳五
            return ENEMY_JUMP_FIVE;
        else if (num == 3 && tag == 0 && jump == 1)//跳四
            return ENEMY_JUMP_FOUR;

        else if (num == 3 && tag == 0 && jump == 0)
            return ENEMY_LIVE_THREE;
        else if (num == 2 && tag == 0 && jump == 0)
            return ENEMY_LIVE_TWO;
        else
            return -1;
    }
}
int Node::Get_Nums3(Point point)//向\寻找主对角线方向
{
    int tag = 0;//判断这个子边上其他子的个数
    int num = 1;
    int jump = 0;
    int flag = tree_board[point.x][point.y];
    Point temp(point.x - 1, point.y - 1);
    for (int i = 0; i < 4; i++)
    {
        if (temp.y < 0 || temp.x < 0)
        {
            tag++;
            break;
        }
        if (flag == tree_board[temp.x][temp.y])
            num++;
        else if (tree_board[temp.x][temp.y] == 0)
            if (tree_board[temp.x - 1][temp.y - 1] == tree_board[point.x][point.y] && jump == 0)
            {
                jump = 1;
                num++;
                temp.y--;
                temp.x--;
                i++;
            }
            else
                break;
        else
        {
            tag++;
            break;
        }
        temp.y--;
        temp.x--;
    }
    temp.y = point.y + 1;
    temp.x = point.x + 1;
    for (int i = 0; i < 4; i++)
    {
        if (temp.y >= 12 || temp.x >= 12)
        {
            tag++;
            break;
        }
        if (tree_board[point.x][point.y] == tree_board[temp.x][temp.y])
            num++;
        else if (tree_board[temp.x][temp.y] == 0)
            if (tree_board[temp.x + 1][temp.y + 1] == tree_board[point.x][point.y] && jump == 0)
            {
                jump = 1;
                num++;
                temp.y++;
                temp.x++;
                i++;
            }
            else
                break;
        else
        {
            tag++;
            break;
        }
        temp.y++;
        temp.x++;
    }
    if (flag == myFlag)
    {
        if (num == 5)
            return MY_FIVE;
        else if (num == 4 && tag == 0 && jump == 0)
            return MY_LIVE_FOUR;
        else if (num == 4 && tag == 1 && jump == 0)
            return MY_GO_FOUR;
        else if (num == 4 && jump == 1)//跳五
            return MY_JUMP_FIVE;
        else if (num == 3 && tag == 0 && jump == 1)//跳四
            return MY_JUMP_FOUR;
        else if (num == 3 && tag == 0 && jump == 0)
            return MY_LIVE_THREE;
        else if (num == 2 && tag == 0 && jump == 0)
            return MY_LIVE_TWO;
        else
            return 1;
    }
    else
    {
        if (num == 5)
            return ENEMY_FIVE;
        else if (num == 4 && tag == 0 && jump == 0)
            return ENEMY_LIVE_FOUR;
        else if (num == 4 && tag == 1 && jump == 0)
            return ENEMY_GO_FOUR;
        else if (num == 4 && jump == 1)//跳五
            return ENEMY_JUMP_FIVE;
        else if (num == 3 && tag == 0 && jump == 1)//跳四
            return ENEMY_JUMP_FOUR;
        else if (num == 3 && tag == 0 && jump == 0)
            return ENEMY_LIVE_THREE;
        else if (num == 2 && tag == 0 && jump == 0)
            return ENEMY_LIVE_TWO;
        else
            return -1;
    }
}
int Node::Get_Nums4(Point point)//向/寻找副对角线方向
{
    int tag = 0;//判断这个子边上其他子的个数
    int num = 1;
    int jump = 0;
    int flag = tree_board[point.x][point.y];
    Point temp(point.x + 1, point.y - 1);
    for (int i = 0; i < 4; i++)//寻找左下
    {
        if (temp.y < 0 || temp.x >= 12)
        {
            tag++;
            break;
        }
        if (flag == tree_board[temp.x][temp.y])
            num++;
        else if (tree_board[temp.x][temp.y] == 0)
            if (tree_board[temp.x + 1][temp.y - 1] == tree_board[point.x][point.y] && jump == 0)
            {
                jump = 1;
                num++;
                temp.y--;
                temp.x++;
                i++;
            }
            else
                break;
        else
        {
            tag++;
            break;
        }
        temp.y--;
        temp.x++;
    }
    temp.y = point.y + 1;
    temp.x = point.x - 1;
    for (int i = 0; i < 4; i++)//寻找右上
    {
        if (temp.y >= 12 || temp.x < 0)
        {
            tag++;
            break;
        }
        if (tree_board[point.x][point.y] == tree_board[temp.x][temp.y])
            num++;
        else if (tree_board[temp.x][temp.y] == 0)
            if (tree_board[temp.x - 1][temp.y + 1] == tree_board[point.x][point.y] && jump == 0)
            {
                jump = 1;
                num++;
                temp.y++;
                temp.x--;
                i++;
            }
            else
                break;
        else
        {
            tag++;
            break;
        }
        temp.y++;
        temp.x--;
    }
    if (flag == myFlag)
    {
        if (num == 5)
            return MY_FIVE;
        else if (num == 4 && tag == 0 && jump == 0)
            return MY_LIVE_FOUR;
        else if (num == 4 && tag == 1 && jump == 0)
            return MY_GO_FOUR;
        else if (num == 4 && jump == 1)//跳五
            return MY_JUMP_FIVE;
        else if (num == 3 && tag == 0 && jump == 1)//跳四
            return MY_JUMP_FOUR;
        else if (num == 3 && tag == 0 && jump == 0)
            return MY_LIVE_THREE;
        else if (num == 2 && tag == 0 && jump == 0)
            return MY_LIVE_TWO;
        else
            return 1;
    }
    else
    {
        if (num == 5)
            return ENEMY_FIVE;
        else if (num == 4 && tag == 0 && jump == 0)
            return ENEMY_LIVE_FOUR;
        else if (num == 4 && tag == 1 && jump == 0)
            return ENEMY_GO_FOUR;
        else if (num == 4 && jump == 1)//跳五
            return ENEMY_JUMP_FIVE;
        else if (num == 3 && tag == 0 && jump == 1)//跳四
            return ENEMY_JUMP_FOUR;

        else if (num == 3 && tag == 0 && jump == 0)
            return ENEMY_LIVE_THREE;
        else if (num == 2 && tag == 0 && jump == 0)
            return ENEMY_LIVE_TWO;
        else
            return -1;
    }
}
