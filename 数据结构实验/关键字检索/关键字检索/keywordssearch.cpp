#include<iostream>
#include<fstream>
using namespace std;
int seach_key(char message[10000], char key[100]);
int main()
{
	char filename[100];
	char key[100];
	cout << "�ؼ��ּ���ϵͳ";
	cout << "�������ļ�����";
	cin >> filename;
	cout << endl;
	cout << "������һ��Ӣ��(^��ʾ��β)��" << endl;
	//�����ļ����洢
	fstream f;
	f.open(filename, ios::out);
	while (1)
	{
		char ch = getchar(); f << ch;
		if (ch == '^')
			break;
	}
	f.close();
	cout << "���Ķ��ѱ������ı��ļ�" << "��" << filename << "��" << "�С�" << endl<<endl;
	cout << "������Ҫ�����Ĺؼ���" ;
	cin >> key;
	cout << "��ʾԴ�ļ�" << "��" << filename << "����" << endl;
	//����ļ�����
	f.open(filename, ios::in);
    while (!f.eof())
	{
		char buffer[100];
		f.getline(buffer, 100);
		cout << buffer << endl;
	}
	f.close();
	int n = seach_key(filename, key);
	cout << endl << "��Դ�ļ��й���������" << n << "���ؼ���" << "��" << key << "��" << endl;
	system("pause");
}
int seach_key(char filename[100], char key[100])
{
	int sum = 0;
	fstream f;
	f.open(filename, ios::in);
	while (!f.eof())
	{
		char message[100];
		f.getline(message, 100);
		//һ��һ�м���
		for (int i = 0; message[i] != 0; i++)
		{
			if (message[i] == key[0])//�����һ���ַ�ƥ�俪ʼ��������ַ�
			{
				int tag = 0;
				for (int j = 1; key[j] != 0; j++)
				{
					if (message[i + j] != key[j])
					{
						tag = 1;
						break;
					}
				}
				if (tag == 0)
					sum++;
			}
		}
	}	
	return sum;
}