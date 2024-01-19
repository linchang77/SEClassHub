#include<iostream>
#include<time.h>
#include <windows.h> //取系统时间
#include<iomanip>
using namespace std;
class List;
class List
{
public:
	List();//默认析构函数
	List(int n);//析构函数
	void Bouble_sort();//冒泡排序
	void Selection_sort();//选择排序
	void Insertion_sort();//直接插入排序
	void Shell_sort();//希尔排序
	void Insertion_sort(int i, int j);
	void QKsort();//调用递归函数的函数
	void Merge_sort();
	void QKsort(int start, int end);
	void Heap_sort();//堆排序
	void Merge_sort(int start, int end);//归并排序
	void Radix_sort();//基数排序
	void sort_two_list(int start1, int start2, int end1, int end2);//对两个已经排好序的数列进行合并
	int maxbit(int n);
	void put();
	void ajust_Max(int i);//用于构造最大堆
	int get_list_size() { return listnum; }
	int get_temp_size() { return tempnum; }
	int get_time() { return time; }
	int get_num() { return num; }
    void puttemp();
	void reset_num() { num = 0; }
	void copylist(int list[10000], int temp[10000]);
private:
	void swap(int a, int b);
	int list[10000] = {-1};
	int temp[10000] = {-1};
	double time;//记录运行时间
	int num;//记录交换时间
	int listnum = 0;
	int tempnum = 0;
};
void setup();
int main()
{
	srand(time(nullptr));
	int n;
	setup();
	while (1)
	{
		cin >> n;
		if (n <= 0)
		{
			cout << "输入错误"<<endl;
			cout << "请输入要产生的随机数的个数：";
			continue;
		}
		if (n > 0)
			break;
	}

	class List list(n);
	int num;
	//list.put();
	while (1)
	{
		//list.puttemp();
		list.reset_num();
		cout << "请选择排序算法：";
		cin >> num;
		switch (num)
		{
		    case 1:
				list.Bouble_sort();
				break;
		    case 2:
				list.Selection_sort();
				break;
			case 3:
				list.Insertion_sort();
				break;
			case 4:
				list.Shell_sort();
				break;
			case 5:
				list.QKsort();
				break;
			case 6:
				list.Heap_sort();
				break;
			case 7:
				list.Merge_sort();
				break;
			case 8:
				list.Radix_sort();
				break;
			case 9:
				exit(1);
		}
	}
	
}
void setup()
{
	cout << "**          排序算法比较            **" << endl;
	cout << "======================================" << endl;
	cout << "**          1 --- 冒泡排序          **" << endl;
	cout << "**          2 --- 选择排序          **" << endl;
	cout << "**          3 --- 直接插入排序      **" << endl;
	cout << "**          4 --- 希尔排序          **" << endl;
	cout << "**          5 --- 快速排序          **" << endl;
	cout << "**          6 --- 堆排序            **" << endl;
	cout << "**          7 --- 归并排序          **" << endl;
	cout << "**          8 --- 基数排序          **" << endl;
	cout << "**          9 --- 退出程序          **" << endl;
	cout << "======================================" << endl;
	cout << "请输入要产生的随机数的个数：";
}
List::List()//默认析构函数
{
	num = 0;
	time = 0;
}
List::List(int n)
{
	num = 0;
	time = 0;
	for (int i = 0; i < n; i++)
	{
		list[i] = rand() % n;
		listnum++;
	}
}
void List::swap(int i, int j)
{
	int n = temp[i];
	temp[i] = temp[j];
	temp[j] = n;
	num++;
}
void List::put()
{
	for (int i = 0; i < listnum; i++)
		cout << list[i] << " ";
	cout << endl;
}
void List::puttemp()
{
	for (int i = 0; i < tempnum; i++)
		cout << temp[i] << " ";
	cout << endl;
}
void List::Bouble_sort()
{
	copylist(list,temp);
	LARGE_INTEGER tick, begin, end;
	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数
	/* 此处是你的程序开始 */
	 for(int i=0;i< tempnum -1;i++)
		for (int j= tempnum -1 ; j >i; j--)
			if (temp[j] < temp[j-1])
				swap(j, j-1);
	/* 此处是你的程序结束 */
	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数
	cout << "冒泡排序所用的时间：       " <<  setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;
	cout << "冒泡排序交换次数：           " << num << endl;
}
void List::Selection_sort()
{
	copylist(list, temp);
	LARGE_INTEGER tick, begin, end;
	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数
	/* 此处是你的程序开始 */
	for (int i = 0; i < tempnum - 1; i++)
	{
		int best_num = 0;
		int best_data = 10000000;
		for (int j = i; j < tempnum; j++)
		{
			if (temp[j] < best_data)
			{
				best_data = temp[j];
				best_num = j;
			}
		}
		swap(i, best_num);
	}
	/* 此处是你的程序结束 */
	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数
	cout << "选择排序所用的时间：       " << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;
	cout << "选择排序交换次数：           " << num << endl;
}
void List::Insertion_sort()
{
	copylist(list, temp);
	LARGE_INTEGER tick, begin, end;
	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数
	/* 此处是你的程序开始 */
	for (int i = 1; i < tempnum; i++)
		for (int j = 0; j <i; j++)
			if (temp[i] < temp[j])
			{
				for(int m=i;m>j;m--)
				    swap(m-1, m);
			}
	/* 此处是你的程序结束 */
	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数
	cout << "直接插入排序所用的时间：       " << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;
	cout << "直接插入排序交换次数：           " << num << endl;
}
void List::Shell_sort()
{
	 copylist(list, temp);
	 LARGE_INTEGER tick, begin, end;
	 QueryPerformanceFrequency(&tick);	//获得计数器频率
	 QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数
	 /* 此处是你的程序开始 */
	 int gap = tempnum / 2;
	 while (gap) //循环,直到gap为零
	 { 
		 for (int i = gap; i < tempnum; i++)
		 {
			 int _temp = temp[i];
			 int j = i;
			 while (j >= gap && _temp > temp[j - gap])
			 {
				 temp[j] = temp[j - gap];
				 j -= gap;
				 num++;
			 }
			 temp[j] = _temp;
		 }
		 gap = gap == 2 ? 1 : (int)(gap / 2.2);
	 }
	/* 此处是你的程序结束 */
	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数
	std::cout << "希尔插入排序所用的时间：       " << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;
	cout << "希尔插入排序交换次数：           " << num << endl;
}
void List:: QKsort()
{
	 copylist(list, temp);
	 LARGE_INTEGER tick, begin, end;
	 QueryPerformanceFrequency(&tick);	//获得计数器频率
	 QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数
	 /* 此处是你的程序开始 */
	 QKsort(0, tempnum - 1);
	 /* 此处是你的程序结束 */
	 QueryPerformanceCounter(&end);		//获得终止硬件计数器计数
	 cout << "快速排序所用的时间：         " << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;
	 cout << "快速排序交换次数：           " << num << endl;
}
void List::QKsort(int start,int end)
{
	if (start >= end)
		return;
	int tag = 1;
	int i = start;
	int j = end;
	while (i < j)
	{
		if (tag == 1)
		{
			if (temp[j] > temp[i])
			{
				swap(i, j);
				tag = 0;
			}
			else
				j--;
		}
		else
		{
			if (temp[i] < temp[j])
			{
				swap(i, j);
				tag = 1;
			}
			else
				i++;
		}
	}
	QKsort(start, i-1);
	QKsort(i+1, end);
}
void List::Heap_sort()
{
	copylist(list, temp);
	LARGE_INTEGER tick, begin, end;
	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数
	/* 此处是你的程序开始 */
	for (int i = tempnum; i > 0; i--)
	{
		for (int j = 1; j <i; j++)//从i开始逐渐调整最小堆
			ajust_Max(j);//构造一个大根堆
		swap(0, i - 1);
	}
	/* 此处是你的程序结束 */
	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数
	cout << "堆排序所用的时间：         " << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;
	cout << "堆排序交换次数：           " << num << endl;
}
void List::ajust_Max(int i)
{
	if (i == 0)//如果比到根节点就
		return;
	if (temp[i] > temp[i / 2])//和双亲比，如果比双亲小就和他交换
	{
		swap(i, i / 2);
		ajust_Max(i / 2);
	}
}
void List::Merge_sort()
{
	copylist(list, temp);
	LARGE_INTEGER tick, begin, end;
	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数
	/* 此处是你的程序开始 */
	Merge_sort(0, tempnum - 1);
	/* 此处是你的程序结束 */
	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数
	cout << "归并排序所用的时间：         " << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;
	cout << "归并序交换次数：           " << num << endl;
}
void List::Merge_sort(int start,int end)//归并排序,将从start到end位置的数列对半分开，两份分别排成升序顺序
{
	if (start >= end)
		return;
 	Merge_sort(start, (start + end) / 2 );
	Merge_sort((start + end) / 2+1, end);
	sort_two_list(start, (start + end) / 2 , (start + end) / 2+1, end);
}
void List::sort_two_list(int start1, int end1, int start2, int end2)//对两个已经排好序的数列进行合并
{
	int i = start1;
	int j = start2;
	int _temp[10000];
	int count = 0;
	if (i >= j)
		return;
	while (1)
	{
		if (temp[i] > temp[j])//将元素j插入i的前面
		{
			_temp[count]=temp[j];
			count++;
			j++;
			num++;
		}
		else if(temp[i]< temp[j])
		{
			_temp[count] = temp[i];
			count++;
			i++;
			num++;
		}
		else
		{
			_temp[count] = temp[i];
			count++;
			i++;
			_temp[count] = temp[j];
			count++;
			j++;
			num++;
		}
		if (j > end2)
		{
			for (; i <= end1; i++)//把剩下的都加进去
			{
				_temp[count] = temp[i];
				count++;
			}
			num++;
			break;
		}
		if (i > end1)
			break;
	}
	//赋值数组
	for (int i = 0; i < count; i++)
		temp[start1 + i] = _temp[i];
}
int List::maxbit(int n)
{
	int m = 0;
	while (n > 0)
	{
		n = n / 10;
		m++;
	}
	return m;
}
void List::Radix_sort()//基数排序
{
	copylist(list, temp);
	LARGE_INTEGER tick, begin, end;
	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数
	/* 此处是你的程序开始 */
	int n = tempnum;
	int d = maxbit(tempnum);
	int* tmp = new int[n];
	int* count = new int[10]; //计数器
	int i, j, k;
	int radix = 1;
	for (i = 1; i <= d; i++) //进行d次排序
	{
		for (j = 0; j < 10; j++)
			count[j] = 0; //每次分配前清空计数器
		for (j = 0; j < n; j++)
		{
			k = (temp[j] / radix) % 10; //统计每个桶中的记录数
			count[k]++;
		}
		for (j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
		for (j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
		{
			k = (temp[j] / radix) % 10;
			tmp[count[k] - 1] = temp[j];
			count[k]--;
		}
		for (j = 0; j < n; j++) //将临时数组的内容复制到data中
			temp[j] = tmp[j];
		radix = radix * 10;
	}
	delete[]tmp;
	delete[]count;
	/* 此处是你的程序结束 */
	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数
	cout << "基数排序所用的时间：         " << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;
	cout << "基数排序交换次数：           " << num << endl;
}
void List :: copylist(int list[10000], int temp[10000])
{
	tempnum = 0;//重置参数
	for (int i = 0; i < listnum; i++)
	{
		temp[i] = list[i];
		tempnum++;
	}
}