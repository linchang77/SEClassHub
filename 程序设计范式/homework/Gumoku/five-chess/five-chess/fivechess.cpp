/* �޸İ� */ 
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
//����������͵ĵ÷�
#define MY_FIVE           100000000
#define ENEMY_FIVE       -400000000//����㵽�Է��ܹ�ֱ����������ӵ�������϶�����
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
int myFlag;//�ҷ����ӵ���ɫ��1Ϊ�ڣ�2Ϊ�� 
int enemyFlag;//�з����ӵ���ɫ��1Ϊ�ڣ�2Ϊ��  
int turn = 0;//��¼������߲���
char board[BOARD_SIZE][BOARD_SIZE] = { 0 };
class Node;
class Point;
/*
* �����������������ĵ÷ֽ������� 
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
    int value;//������ӵĵ÷�
    int score;
};
class Node
{
public:
    void update_point(int x, int y);//���µ�ǰ���̵ĵ÷�
    void get_the_score();//�����ǰ����ÿ�����ӵĵ÷�
    void copyboard(int tree_board[BOARD_SIZE][BOARD_SIZE]);//�������̵Ĺ��캯��
    void my_find_point();//�ҷ�����������
    void enemy_find_point();//�з�����������
    void place_enemychess(Point point)//�з�����
    {
        tree_board[point.get_x()][point.get_y()] = enemyFlag;
    }
    void place_mychess(Point point)//�ҷ�����
    {
        tree_board[point.get_x()][point.get_y()] = myFlag;
    }
    void renew_point();//�������ӵ㣬��Ϊ���һ������֮�����root��������point��������
    Point max(int depth);//���������ֵ�������ӽڵ�������
    Point min(int depth);//���������ֵ�������ӽڵ�����С��
    int evaluate();//��������
    void push(Point point)
    {
        already_point.push_back(point);
    }
    void copypoint(vector<Point> vec)//������������
    {
        already_point = vec;
    }
    Node();
    void show();
private:

    int tree_board[BOARD_SIZE][BOARD_SIZE];//�����������
    queue<Point> posible_point;//��¼��������ܵ����ӵ�
    vector<Point> already_point;//����Ѿ���õ���
    int Get_Nums1(Point point);//Ѱ���Ϸ�����Ԫ�鲢���
    int Get_Nums2(Point point);//Ѱ����ߵ���Ԫ��
    int Get_Nums3(Point point);//Ѱ�����ϵ���Ԫ��
    int Get_Nums4(Point point);//Ѱ�����ϵ���Ԫ��
    Point best_point;//�������
    int father_point;//������������һ������ֵ����Max���ʼֵΪ-infinity����Min���ʼֵΪinfinity
};


void debug(const char* str)
{
    printf("DEBUG %s\n", str);
    fflush(stdout);//��ջ�����
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
    Node root;//���������
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
            root.place_enemychess(point);//���¸���������
            root.push(point);//�ŵ���������
            turn++;
        }
        else if (strcmp(tag, TURN) == 0)
        {
            turn++;
            if (turn == 1 && myFlag == 1)//д������
            {
                Point best_point(4, 4);
                root.place_mychess(best_point);
                root.push(best_point);//�ŵ���������
                //printf("DEBUG %d %d %d\n", best_point.get_x(), best_point.get_y(), best_point.get_vaule());
                //cout << best_point.get_vaule() << endl;
                //root.show();
                //cout << "m=" << m;
                //cout << "n=" << n << endl;
                root.renew_point();//���ò���
                cout << best_point.get_x() << " " << best_point.get_y() << endl;
            }
            else
            {
                Point best_point = root.max(1);
                root.place_mychess(best_point);
                root.push(best_point);//�ŵ���������
               // printf("DEBUG %d %d %d\n", best_point.get_x(), best_point.get_y(), best_point.get_vaule());
               // cout << best_point.get_vaule() << endl;
               // root.show();
                //cout << "m=" << m;
                //cout << "n=" << n << endl;
                root.renew_point();//���ò���
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
Node::Node()//���ĳ�ʼ�������캯��
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
void Node::enemy_find_point()//�з�Ѱ�ҿ��ܵ����ӵ�д����������,*��������*
{
    vector<Point> temp;//��ʱ�洢������ĵ�
    /*����˼·
    * Ŀ���Ǽ�����ܵ����ӵ㣬�ŵ�Node�������posible����point��������
    * �������̣�������������0������Χ�Ź�����������һ�����ӣ��ͼ��뵽�������ӵ�������
    * ͬʱ������������Ӻ󣬵з����ӵĵ÷֣������������
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
                    if (n < 0)//���n����������һ��
                        continue;
                    for (int m = j - 1; m <= j + 1 && m < 12; m++)
                    {
                        if (m < 0 || (n == i && m == j))//���n�������̻��ߵ���ԭ�������Ӿ���һ��
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
    //��temp���յ÷ֽ�������
    sort(temp);
    //��ֵ��possible_point
    for (int i = 0; i < temp.size() - 1; i++)
        posible_point.push(temp[i]);
}
void Node::my_find_point()//�ҷ�Ѱ�ҿ��ܵ����ӵ�д����������,*��������*
{
    vector<Point> temp;//��ʱ�洢������ĵ�
    /*����˼·
    * Ŀ���Ǽ�����ܵ����ӵ㣬�ŵ�Node�������posible����point��������
    * �������̣�������������0������Χ�Ź�����������һ�����ӣ��ͼ��뵽�������ӵ�������
    * ͬʱ������������Ӻ󣬵з����ӵĵ÷֣������������
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
                    if (n < 0)//���n����������һ��
                        continue;
                    for (int m = j - 1; m <= j + 1 && m < 12; m++)
                    {
                        if (m < 0 || (n == i && m == j))//���n�������̻��ߵ���ԭ�������Ӿ���һ��
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
    //��temp���յ÷ֽ�������
    sort(temp);
    //��ֵ��possible_point
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
* ��������
*/
void Node::copyboard(int tree_board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            this->tree_board[i][j] = tree_board[i][j];
}
/*
* ���ĺ��������ֵ����
* ��������Ķ������ӷ����������
* �ݹ������������������ȴﵽ4��ʱ��ʼ���㵱ǰ���̵ĵ÷֣�
* ��������÷ֵ����Ӵ��ݸ���һ�㡣
* ����ʵ�֣�
* ���ȵ���������������ȡ����
* ��ʼ������Щ����
* ÿ�λ������������ܹ���õ���Ѿ���ĵ÷�
* ����������÷��ж��ܲ��ܼ�֦�������֦������һ�������
* ������÷�����һ���������ӵĵ÷ֱȽϣ����������÷ִ���滻����������
* �������ӱ�����󷵻��������������
*/
Point Node::max(int depth)//���������ֵ�������ӽڵ�������
{
    this->my_find_point();//��ʼ����������
    if (depth == 1)//��ʼ����֮ǰ�ȿ�����ǰ�����ܲ���ֱ�������������֪��Ϊɶ������ǳ�����Щʱ��᲻�����
    {
        queue<Point> temp = posible_point;
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp.front().score >= MY_FIVE)
                return temp.front();
            temp.pop();
        }
    }
    if (posible_point.size() == 1)//����������ӵĵ�ֻ��һ���Ļ�ֱ�ӿ�ʼ����,���ٽ������µ�����
        depth = 5;
    if (depth == 5)
    {
        //���Ŀǰ����ÿ�����ӵĵ÷�
        this->get_the_score();
        while (!this->posible_point.empty())
        {
            Node node;//����һ���µĽ��
            n++;
            node.copyboard(this->tree_board);//������������copy��ȥ
            node.copypoint(this->already_point);//�����ڵ����������copy��ȥ
            node.place_mychess(this->posible_point.front());//����
            node.push(this->posible_point.front());//�����µ�����
            node.update_point(this->posible_point.front().x, this->posible_point.front().y);//�ֲ�ˢ�����ӵ÷�
            this->posible_point.front().value = node.evaluate();//����������γɵľ�����
            if (this->posible_point.front().value >= this->father_point)//��֦
            {
                m++;
                return this->posible_point.front();
            }

            if (this->posible_point.front().value > this->best_point.value)
            {
                this->best_point = this->posible_point.front();//��������Ӹ�ֵ��root
            }
            this->posible_point.pop();
        }
        return this->best_point;
    }
    depth++;
    while (!this->posible_point.empty())
    {
        Node node;//����һ���µĽ��
        n++;
        node.best_point.value = infinity;
        node.father_point = this->best_point.value;//���²�������father_point
        node.copyboard(this->tree_board);//������������copy��ȥ
        node.copypoint(this->already_point);//�����ڵ����������copy��ȥ
        node.place_mychess(this->posible_point.front());//����
        node.push(this->posible_point.front());//�����µ�����
        this->posible_point.front().value = node.min(depth).value;//����min������������ӵ����ŵ÷������
        if (this->posible_point.front().value >= this->father_point)
        {
            m++;
            return this->posible_point.front();
        }
        if (this->posible_point.front().value > this->best_point.value)//��������֮���ⲽ��ĵ÷ֲ���root�ıȽ��ж��Ƿ�Ҫ����root��ֵ
        {
            this->best_point = this->posible_point.front();//���ⲽ���ӷŵ�best_point����ȥ
        }
        this->posible_point.pop();
    }
    return this->best_point;
}
/*
* ���ĺ�������Сֵ����
* ��������Ķ������ӷ����������
* �ݹ������������������ȴﵽ4��ʱ��ʼ���㵱ǰ���̵ĵ÷֣�
* ��������÷ֵ����Ӵ��ݸ���һ�㡣
* ����ʵ�֣�
* ���ȵ���������������ȡ����
* ��ʼ������Щ����
* ÿ�λ������������ܹ���õ���Ѿ���ĵ÷�
* ����������÷��ж��ܲ��ܼ�֦�������֦������һ�������
* ������÷�����һ���������ӵĵ÷ֱȽϣ����������÷�С���滻����������
* �������ӱ�����󷵻��������������
*/
Point Node::min(int depth)//���������ֵ�������ӽڵ�����С��
{
    this->enemy_find_point();//��ʼ����������
    if (posible_point.size() == 1)//����������ӵĵ�ֻ��һ���Ļ�ֱ�ӿ�ʼ����
        depth = 4;
    if (depth == 4)
    {
        //���Ŀǰ����ÿ�����ӵĵ÷�
        this->get_the_score();
        while (!this->posible_point.empty())
        {
            Node node;//����һ���µĽ��
            n++;
            node.best_point.value = -infinity;
            node.father_point = this->best_point.value;
            node.copyboard(this->tree_board);//������������copy��ȥ
            node.copypoint(this->already_point);//�����ڵ����������copy��ȥ
            node.place_enemychess(this->posible_point.front());//����
            node.push(this->posible_point.front());//�����µ�����
            node.update_point(this->posible_point.front().x, this->posible_point.front().y);//�ֲ�ˢ�����ӵ÷�
            this->posible_point.front().value = node.evaluate();//����min������������ӵ����ŵ÷������
            if (this->posible_point.front().value <= this->father_point)//��֦
                return this->posible_point.front();
            if (this->posible_point.front().value < this->best_point.value)//��������֮���ⲽ��ĵ÷ֲ���root�ıȽ��ж��Ƿ�Ҫ����root��ֵ
                this->best_point = this->posible_point.front();//���ⲽ���ӷŵ�best_point����ȥ
            this->posible_point.pop();
        }
        return this->best_point;
    }
    depth++;
    while (!this->posible_point.empty())
    {
        Node node;//����һ���µĽ��
        n++;
        node.best_point.value = -infinity;
        node.father_point = this->best_point.value;
        node.copyboard(this->tree_board);//������������copy��ȥ
        node.copypoint(this->already_point);//�����ڵ����������copy��ȥ
        node.place_enemychess(this->posible_point.front());//����
        node.push(this->posible_point.front());//�����µ�����
        this->posible_point.front().value = node.max(depth).value;//����min������������ӵ����ŵ÷������
        if (this->posible_point.front().value <= this->father_point)
            return this->posible_point.front();
        if (this->posible_point.front().value < this->best_point.value)//��������֮���ⲽ��ĵ÷ֲ���root�ıȽ��ж��Ƿ�Ҫ����root��ֵ
            this->best_point = this->posible_point.front();//���ⲽ���ӷŵ�best_point����ȥ
        this->posible_point.pop();
    }
    return this->best_point;
}
//������ӵ�󣬸��³�ʼֵ
void Node::renew_point()
{
    best_point.value = -infinity;
}
//չʾ���̣��������
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
* ��Ҫһ��vector<point>//���Ѿ��źõ�����
* �����������
* Ȼ����һ��get_point_value������ȡ���ӵĵ÷֣�����Ǻ��ӵö�������ǰ��ӵö���
* ��þͼӵ��ܵķ������õ��ܷ�
*/
//�����̵�ÿ�����ӵĵ÷ּ���������
int Node::evaluate()//��������
{
    int sum = 0;
    for (unsigned int i = 0; i < already_point.size(); i++)
        sum = sum + already_point[i].score;
    return sum;
}
/*
* �����㷨������ÿ�����ӵĵ÷�
* ��������ӵ��ĸ������ϵĵ÷���ӣ�����ĸ������ϵ÷ֲ�ȫΪ1��
* ��ʱ���ƱȽ��ţ��ͽ��ĸ�����ĵ÷���ˡ�
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
* �Ż��㷨���ֲ�ˢ�����̵ĵ÷�
* ���Ӻ�����ӣ�ֻ�����ĸ������ϵ����ӵĵ÷���Ӱ��
* ����ֻ�ø�����Щ������Ӱ�쵽�����ӵ÷־Ϳ��Եõ�
* �µ��������ӵ÷֡�
*/
void Node::update_point(int x, int y)
{
    for (unsigned int i = 0; i < already_point.size(); i++)
    {
        if ((already_point[i].x == x && already_point[i].y > y - 4 && already_point[i].y < y + 4)//ˮƽ�����ϵĵ�
            || (already_point[i].y == y && already_point[i].x > x - 4 && already_point[i].x < x + 4)//��ֱ������
            || (abs(already_point[i].y - y) == abs(already_point[i].x - x) && abs(already_point[i].x - x) <= 4))//�Խ����ϵ�
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
* ���ĸ�������Ѱ�����ӵ��Ƿ�����ض������ͱ���������Ļ����
* ���ص÷�
*/
// ���������ʵ�����Ż���һ��������������һ�������࣬ʹ��forѭ��Ѱ���ĸ�����
// ������д�����˾������ɣ��İ��и������ͦ�õ�
int Node::Get_Nums1(Point point)//��ֱѰ��
{
    int tag = 0;//�ж�����ӱ��������ӵĸ���
    int num = 1;
    int jump = 0;//�ж���������Ƿ������������
    int flag = tree_board[point.x][point.y];
    Point temp(point.x - 1, point.y);
    for (int i = 0; i < 4; i++)//����Ѱ��
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
        else if (num == 4 && jump == 1)//����
            return MY_JUMP_FIVE;
        else if (num == 3 && tag == 0 && jump == 1)//����
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
        else if (num == 4 && jump == 1)//����
            return ENEMY_JUMP_FIVE;
        else if (num == 3 && tag == 0 && jump == 1)//����
            return ENEMY_JUMP_FOUR;

        else if (num == 3 && tag == 0 && jump == 0)
            return ENEMY_LIVE_THREE;
        else if (num == 2 && tag == 0 && jump == 0)
            return ENEMY_LIVE_TWO;
        else
            return -1;
    }
}
int Node::Get_Nums2(Point point)//��ˮƽ����Ѱ��
{
    int tag = 0;//�ж�����ӱ��������ӵĸ���
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
        else if (num == 4 && jump == 1)//����
            return MY_JUMP_FIVE;
        else if (num == 3 && tag == 0 && jump == 1)//����
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
        else if (num == 4 && jump == 1)//����
            return ENEMY_JUMP_FIVE;
        else if (num == 3 && tag == 0 && jump == 1)//����
            return ENEMY_JUMP_FOUR;

        else if (num == 3 && tag == 0 && jump == 0)
            return ENEMY_LIVE_THREE;
        else if (num == 2 && tag == 0 && jump == 0)
            return ENEMY_LIVE_TWO;
        else
            return -1;
    }
}
int Node::Get_Nums3(Point point)//��\Ѱ�����Խ��߷���
{
    int tag = 0;//�ж�����ӱ��������ӵĸ���
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
        else if (num == 4 && jump == 1)//����
            return MY_JUMP_FIVE;
        else if (num == 3 && tag == 0 && jump == 1)//����
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
        else if (num == 4 && jump == 1)//����
            return ENEMY_JUMP_FIVE;
        else if (num == 3 && tag == 0 && jump == 1)//����
            return ENEMY_JUMP_FOUR;
        else if (num == 3 && tag == 0 && jump == 0)
            return ENEMY_LIVE_THREE;
        else if (num == 2 && tag == 0 && jump == 0)
            return ENEMY_LIVE_TWO;
        else
            return -1;
    }
}
int Node::Get_Nums4(Point point)//��/Ѱ�Ҹ��Խ��߷���
{
    int tag = 0;//�ж�����ӱ��������ӵĸ���
    int num = 1;
    int jump = 0;
    int flag = tree_board[point.x][point.y];
    Point temp(point.x + 1, point.y - 1);
    for (int i = 0; i < 4; i++)//Ѱ������
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
    for (int i = 0; i < 4; i++)//Ѱ������
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
        else if (num == 4 && jump == 1)//����
            return MY_JUMP_FIVE;
        else if (num == 3 && tag == 0 && jump == 1)//����
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
        else if (num == 4 && jump == 1)//����
            return ENEMY_JUMP_FIVE;
        else if (num == 3 && tag == 0 && jump == 1)//����
            return ENEMY_JUMP_FOUR;

        else if (num == 3 && tag == 0 && jump == 0)
            return ENEMY_LIVE_THREE;
        else if (num == 2 && tag == 0 && jump == 0)
            return ENEMY_LIVE_TWO;
        else
            return -1;
    }
}
