/* 1953609 ��� ���͢ */

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#include<iomanip>
#include <iostream>
#include<fstream>
using namespace std;

#define MAX_STU_NUM			150	//Լ���������Ϊ150�ˣ����ֵ��ܺͣ�������ѡ����ѡ��
#define MAX_NAME_LEN			20	//��������󳤶Ȳ�����9������
#define MAX_FILENAME_LEN		256	//�ļ�������󳤶�

/* stu_info ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_info {
private:
	int  stu_no;			//ѧ��
	char stu_name[MAX_NAME_LEN];	//����

	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */
	int condi_fro=0;
	int condi_aft=0;
	friend class stu_list;
public:
	/* ���಻�������κεĹ������ݳ�Ա����Ա���� */
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];
	
	/* ���������private���ݳ�Ա�ͳ�Ա���� */
	int sum = 0;
public:
	int read(const char* filename, const int append = 0);	//���ļ��ж���ѡ����Ϣ�����д�����2������ֵΪ0��ʾ���Ƿ�ʽ��1��ʾ׷�ӷ�ʽ
	int print(const char* prompt = NULL);			//��ӡ��ǰ�����ѡ������

	/* �������������public��Ա���� */
	void read_no(int i,int no)
	{
		stu[i].stu_no = no;
	}
	void read_name(int i, char name,int j)
	{
		stu[i].stu_name[j] = name;
	}
};

/* --- �˴���������������ĳ�Ա����������ʵ�� --- */
int stu_list::read(const char* filename, const int append)
{
	ifstream in;
	in.open(filename, ios::in);
	if (!in.is_open())
	{
		cout << "�ļ�[" << filename << "]��ʧ��" << endl;
		in.close();
		return -1;
	}
	if (append != 0)
	{
		int tag = 0;
		int i = 0;
		for (; tag != 1; i++)
		{
			int a;
			in >> a;
			if (in.fail())
				break;
			int seek = 0;
			for (int n = 0; n < sum; n++)
			{
				if (stu[n].stu_no == a)
				{
					stu[n].condi_aft = 1;
					seek = 1;
					break;
				}
			}
			int j = 0;
			in.get();
			for (;; j++)
			{
				char ch;
				ch = in.get();
				if (ch == '\n')
					break;
				else if (ch == EOF)
				{
					tag = 1;
					break;
				}
				else
				{
					if (seek == 0)
					{
						stu[sum].stu_name[j] = ch;
					}
				}
			}
			if (seek == 0)
			{
				stu[sum].stu_no = a;
				stu[sum].condi_aft = 1;
				stu[sum].stu_name[j] = '\0';
				sum++;
			}			
		}
	}	
	else
	{
		int tag = 0;
		int i = 0;
		for (; tag != 1; i++)
		{
			int a;
			in >> a;
			if (in.fail())
				break;
			read_no(i, a);
			int j = 0;
			in.get();
			for (;; j++)
			{
				char ch;
				ch = in.get();
				if (ch == '\n')
					break;
				else if (ch == EOF)
				{
					tag = 1;
					break;
				}
				else
				{
					read_name(i, ch, j);
				}
			}
			stu[i].stu_name[j] = '\0';
			stu[i].condi_fro = 1;
		}
		sum = i;
	}
	for (int k = 0; k < sum; k++)
	{
		for (int m = 0; m < sum - k - 1; m++)
		{
			if (stu[m].stu_no > stu[m + 1].stu_no)//�Ӻ��浽i��Ԫ�������Ƚϣ���С�Ĳ����϶�
			{
				stu_info tmp;
				tmp = stu[m];
				stu[m] = stu[m + 1];
				stu[m + 1] = tmp;
			}
		}
	}
	in.close();
	return 1;
}

int stu_list::print(const char* prompt)
{
	cout << prompt << endl;
	cout << "===========================================" << endl
		 << "��� ѧ��    ����             ��һ�� �ڶ���" << endl
		 << "===========================================" << endl;
	int num = 1;
	for (int i = 0; i < sum; i++,num++)
	{
		cout << setiosflags(ios::left)<< setw(5) << num << stu[i].stu_no << " " <<setw(17)<< stu[i].stu_name;
		if (stu[i].condi_fro == 1)
			cout << "Y      ";
		else
			cout << "/      ";
		if (stu[i].condi_aft == 0)
		{
			if (stu[i].condi_fro == 1)
				cout << "�˿�" << endl;
		}
		else
		{
			if (stu[i].condi_fro == 1)
				cout << "Y" << endl;
			else
				cout << "��ѡ" << endl;
		}
	}
	cout << "===========================================" << endl;
	return 0;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	cin >> file1;
	cout << "�������һ��ѡ�ε������ļ� : ";
	cin >> file2;

	stu_list list;
	
	/* �����һ�������ļ� */
	if (list.read(file1) < 0)
		return -1;

#if 0
	/* ������궨�壬���Դ�ӡ���ֶ����ѡ�����������ڵ��� */
	list.print("ǰһ��ѡ������");
	cout << endl << endl;
#endif

	/* ����ڶ��������ļ�������2��ֵΪ1��ʾ׷�ӷ�ʽ */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("����ѡ������");

	return 0;
}
