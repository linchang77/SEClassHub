/* 2250420 �¾� �� */

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#include <iostream>
#include<iomanip>
#include "read_stulist.h"
using namespace std;
static int num = 0;
#define MAX_FILENAME_LEN		512	//�����ļ�������󳤶�
class stu_list;
/* stu_metge ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_merge {
private:
	friend stu_list;
	int  stu_no;					//ѧ��
	char stu_name[MAX_NAME_LEN];  //����
	bool round1 = 0;
	bool round2 = 0;
	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */

public:
	//���಻�������κεĹ������ݳ�Ա����Ա����
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	
	student list_round_1[MAX_STU_NUM];	//��һ��ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_1;						//��һ��ѡ�ε�ѧ������

	student list_round_2[MAX_STU_NUM];	//�ڶ���ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_2;						//�ڶ���ѡ�ε�ѧ������

	stu_merge list_merge[MAX_STU_NUM];	//�ϲ����ѧ��������ȥ�أ����������У�
	int list_merge_num;					//�ϲ����ѧ��������Ŀǰ����ӡ�����������ڲ������������Ҫ��Ҳ��Ҫɾ����

	/* ���������private���ݳ�Ա�ͳ�Ա����
	   ע�⣬���������array / set / map / vector��STL���� */

public:
	stu_list();										//���캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
	int read(const char* filename, const int round);	//���ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
	int print(const char* prompt = NULL);				//��ӡ���յ�ѡ������
	void merge();
	void sort();
	/* �������������public��Ա��������ʾ���ϲ���ȥ�ء�����ȣ�
	   �������幫�е����ݳ�Ա
	   �������ڳ�Ա������ʹ��array / set / map / vector��STL���� */

};

/* --- ������Ը���stu_merge/stu_list������ĳ�Ա����������ʵ�� --- */
void stu_list::merge()
{
	list_merge_num = 0;
	for (int i = 0; i < list_num_1; i++)//�ѵ�һ�ֵ�ȫ����
	{
		stu_merge stu;
		stu.stu_no = list_round_1[i].no;
		strcpy_s(stu.stu_name , list_round_1[i].name);
		stu.round1 = 1;
		list_merge[i] = stu;
		list_merge_num++;
	}
	for (int i = 0; i < list_num_2; i++)//�ѵڶ��ֵĺϲ�
	{
		int tag = 0;
		stu_merge stu;
		stu.stu_no = list_round_2[i].no;
		strcpy_s(stu.stu_name, list_round_2[i].name);
		for (int j = 0; j < list_num_1; j++)
			if (list_round_1[j].no == stu.stu_no)//������ֵ�һ��Ҳѡ��
			{
				list_merge[j].round2 = 1;
				tag = 1;
				num++;
			}
		if (tag == 0)//�����һ��ûѡ
		{
			stu.round2 = 1;
			list_merge[list_merge_num] = stu;
			list_merge_num++;
		}
	}
}
void stu_list::sort()
{
	for (int i = 0; i < list_merge_num; i++)
	{
		for(int j=list_merge_num-1;j>i;j--)
			if (list_merge[j].stu_no < list_merge[j - 1].stu_no)
			{
				stu_merge temp;
				strcpy_s(temp.stu_name , list_merge[j].stu_name);
				temp.stu_no = list_merge[j].stu_no;
				temp.round1 = list_merge[j].round1;
				temp.round2 = list_merge[j].round2;
				list_merge[j] = list_merge[j - 1];
				list_merge[j - 1] = temp;
			}
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ����ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
  ���������
  �� �� ֵ��
  ˵    �������캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
***************************************************************************/
stu_list::stu_list()
{

}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ��̬���ӿ��ʹ�ã��������е��þ�̬���ӿ��е�Ԥ�ú���
  ���������
  �� �� ֵ��
  ˵    ��������������Ҫ�޸�
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* ��ȡ��1/2�ֵ�ѡ����������ӡ */
	switch (round) {
	case 1:
		this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
		if (this->list_num_1 > 0)
			print_stulist("��һ��ѡ��������", this->list_round_1, this->list_num_1);
		else
			ret = -1;
		break;
	case 2:
		this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
		if (this->list_num_2 > 0)
			print_stulist("�ڶ���ѡ��������", this->list_round_2, this->list_num_2);
		else
			ret = -1;
		break;
	default:
		ret = -1;
		break;
	}

	return ret;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ������ӡ���յ�ѡ������
***************************************************************************/
int stu_list::print(const char* prompt)
{
	cout << prompt << endl;
	cout << "===========================================" << endl
		<< "��� ѧ��    ����             ��һ�� �ڶ���" << endl
		<< "===========================================" << endl;
	for (int i = 0; i < list_merge_num; i++)
	{
		cout << setiosflags(ios::left) << setw(5) << i+1 << list_merge[i].stu_no << " " << setw(17) << list_merge[i].stu_name;
		if (list_merge[i].round1 == 1)
			cout << "Y      ";
		else
			cout << "/      ";
		if (list_merge[i].round2 == 0)
		{
			cout << "�˿�" ;
		}
		else
		{
			if(list_merge[i].round1==0)
			     cout << "��ѡ" ;
			else
				cout << "Y      ";
		}
		cout << endl;
	}
	cout << "===========================================" << endl;
	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	gets_s(file1); //cin���ܶ��пո���ļ�

	cout << "�������һ��ѡ�ε������ļ� : ";
	gets_s(file2);

	stu_list list;

	/* �������� */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* �������� */
	list.merge();
	list.sort();

	/* ��ӡ */
	list.print("����ѡ������");

	return 0;
}
