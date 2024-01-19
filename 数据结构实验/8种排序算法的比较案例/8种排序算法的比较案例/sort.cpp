#include<iostream>
#include<time.h>
#include <windows.h> //ȡϵͳʱ��
#include<iomanip>
using namespace std;
class List;
class List
{
public:
	List();//Ĭ����������
	List(int n);//��������
	void Bouble_sort();//ð������
	void Selection_sort();//ѡ������
	void Insertion_sort();//ֱ�Ӳ�������
	void Shell_sort();//ϣ������
	void Insertion_sort(int i, int j);
	void QKsort();//���õݹ麯���ĺ���
	void Merge_sort();
	void QKsort(int start, int end);
	void Heap_sort();//������
	void Merge_sort(int start, int end);//�鲢����
	void Radix_sort();//��������
	void sort_two_list(int start1, int start2, int end1, int end2);//�������Ѿ��ź�������н��кϲ�
	int maxbit(int n);
	void put();
	void ajust_Max(int i);//���ڹ�������
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
	double time;//��¼����ʱ��
	int num;//��¼����ʱ��
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
			cout << "�������"<<endl;
			cout << "������Ҫ������������ĸ�����";
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
		cout << "��ѡ�������㷨��";
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
	cout << "**          �����㷨�Ƚ�            **" << endl;
	cout << "======================================" << endl;
	cout << "**          1 --- ð������          **" << endl;
	cout << "**          2 --- ѡ������          **" << endl;
	cout << "**          3 --- ֱ�Ӳ�������      **" << endl;
	cout << "**          4 --- ϣ������          **" << endl;
	cout << "**          5 --- ��������          **" << endl;
	cout << "**          6 --- ������            **" << endl;
	cout << "**          7 --- �鲢����          **" << endl;
	cout << "**          8 --- ��������          **" << endl;
	cout << "**          9 --- �˳�����          **" << endl;
	cout << "======================================" << endl;
	cout << "������Ҫ������������ĸ�����";
}
List::List()//Ĭ����������
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
	QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������
	/* �˴�����ĳ���ʼ */
	 for(int i=0;i< tempnum -1;i++)
		for (int j= tempnum -1 ; j >i; j--)
			if (temp[j] < temp[j-1])
				swap(j, j-1);
	/* �˴�����ĳ������ */
	QueryPerformanceCounter(&end);		//�����ֹӲ������������
	cout << "ð���������õ�ʱ�䣺       " <<  setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;
	cout << "ð�����򽻻�������           " << num << endl;
}
void List::Selection_sort()
{
	copylist(list, temp);
	LARGE_INTEGER tick, begin, end;
	QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������
	/* �˴�����ĳ���ʼ */
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
	/* �˴�����ĳ������ */
	QueryPerformanceCounter(&end);		//�����ֹӲ������������
	cout << "ѡ���������õ�ʱ�䣺       " << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;
	cout << "ѡ�����򽻻�������           " << num << endl;
}
void List::Insertion_sort()
{
	copylist(list, temp);
	LARGE_INTEGER tick, begin, end;
	QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������
	/* �˴�����ĳ���ʼ */
	for (int i = 1; i < tempnum; i++)
		for (int j = 0; j <i; j++)
			if (temp[i] < temp[j])
			{
				for(int m=i;m>j;m--)
				    swap(m-1, m);
			}
	/* �˴�����ĳ������ */
	QueryPerformanceCounter(&end);		//�����ֹӲ������������
	cout << "ֱ�Ӳ����������õ�ʱ�䣺       " << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;
	cout << "ֱ�Ӳ������򽻻�������           " << num << endl;
}
void List::Shell_sort()
{
	 copylist(list, temp);
	 LARGE_INTEGER tick, begin, end;
	 QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	 QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������
	 /* �˴�����ĳ���ʼ */
	 int gap = tempnum / 2;
	 while (gap) //ѭ��,ֱ��gapΪ��
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
	/* �˴�����ĳ������ */
	QueryPerformanceCounter(&end);		//�����ֹӲ������������
	std::cout << "ϣ�������������õ�ʱ�䣺       " << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;
	cout << "ϣ���������򽻻�������           " << num << endl;
}
void List:: QKsort()
{
	 copylist(list, temp);
	 LARGE_INTEGER tick, begin, end;
	 QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	 QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������
	 /* �˴�����ĳ���ʼ */
	 QKsort(0, tempnum - 1);
	 /* �˴�����ĳ������ */
	 QueryPerformanceCounter(&end);		//�����ֹӲ������������
	 cout << "�����������õ�ʱ�䣺         " << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;
	 cout << "�������򽻻�������           " << num << endl;
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
	QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������
	/* �˴�����ĳ���ʼ */
	for (int i = tempnum; i > 0; i--)
	{
		for (int j = 1; j <i; j++)//��i��ʼ�𽥵�����С��
			ajust_Max(j);//����һ�������
		swap(0, i - 1);
	}
	/* �˴�����ĳ������ */
	QueryPerformanceCounter(&end);		//�����ֹӲ������������
	cout << "���������õ�ʱ�䣺         " << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;
	cout << "�����򽻻�������           " << num << endl;
}
void List::ajust_Max(int i)
{
	if (i == 0)//����ȵ����ڵ��
		return;
	if (temp[i] > temp[i / 2])//��˫�ױȣ������˫��С�ͺ�������
	{
		swap(i, i / 2);
		ajust_Max(i / 2);
	}
}
void List::Merge_sort()
{
	copylist(list, temp);
	LARGE_INTEGER tick, begin, end;
	QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������
	/* �˴�����ĳ���ʼ */
	Merge_sort(0, tempnum - 1);
	/* �˴�����ĳ������ */
	QueryPerformanceCounter(&end);		//�����ֹӲ������������
	cout << "�鲢�������õ�ʱ�䣺         " << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;
	cout << "�鲢�򽻻�������           " << num << endl;
}
void List::Merge_sort(int start,int end)//�鲢����,����start��endλ�õ����ж԰�ֿ������ݷֱ��ų�����˳��
{
	if (start >= end)
		return;
 	Merge_sort(start, (start + end) / 2 );
	Merge_sort((start + end) / 2+1, end);
	sort_two_list(start, (start + end) / 2 , (start + end) / 2+1, end);
}
void List::sort_two_list(int start1, int end1, int start2, int end2)//�������Ѿ��ź�������н��кϲ�
{
	int i = start1;
	int j = start2;
	int _temp[10000];
	int count = 0;
	if (i >= j)
		return;
	while (1)
	{
		if (temp[i] > temp[j])//��Ԫ��j����i��ǰ��
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
			for (; i <= end1; i++)//��ʣ�µĶ��ӽ�ȥ
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
	//��ֵ����
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
void List::Radix_sort()//��������
{
	copylist(list, temp);
	LARGE_INTEGER tick, begin, end;
	QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������
	/* �˴�����ĳ���ʼ */
	int n = tempnum;
	int d = maxbit(tempnum);
	int* tmp = new int[n];
	int* count = new int[10]; //������
	int i, j, k;
	int radix = 1;
	for (i = 1; i <= d; i++) //����d������
	{
		for (j = 0; j < 10; j++)
			count[j] = 0; //ÿ�η���ǰ��ռ�����
		for (j = 0; j < n; j++)
		{
			k = (temp[j] / radix) % 10; //ͳ��ÿ��Ͱ�еļ�¼��
			count[k]++;
		}
		for (j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j]; //��tmp�е�λ�����η����ÿ��Ͱ
		for (j = n - 1; j >= 0; j--) //������Ͱ�м�¼�����ռ���tmp��
		{
			k = (temp[j] / radix) % 10;
			tmp[count[k] - 1] = temp[j];
			count[k]--;
		}
		for (j = 0; j < n; j++) //����ʱ��������ݸ��Ƶ�data��
			temp[j] = tmp[j];
		radix = radix * 10;
	}
	delete[]tmp;
	delete[]count;
	/* �˴�����ĳ������ */
	QueryPerformanceCounter(&end);		//�����ֹӲ������������
	cout << "�����������õ�ʱ�䣺         " << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;
	cout << "�������򽻻�������           " << num << endl;
}
void List :: copylist(int list[10000], int temp[10000])
{
	tempnum = 0;//���ò���
	for (int i = 0; i < listnum; i++)
	{
		temp[i] = list[i];
		tempnum++;
	}
}