#include<iostream>
#include<fstream>
using namespace std;
int seach_key(char message[10000], char key[100]);
int main()
{
	char filename[100];
	char key[100];
	cout << "关键字检索系统";
	cout << "请输入文件名：";
	cin >> filename;
	cout << endl;
	cout << "请输入一段英文(^表示结尾)：" << endl;
	//建立文件并存储
	fstream f;
	f.open(filename, ios::out);
	while (1)
	{
		char ch = getchar(); f << ch;
		if (ch == '^')
			break;
	}
	f.close();
	cout << "本文段已保存在文本文件" << "“" << filename << "”" << "中。" << endl<<endl;
	cout << "请输入要检索的关键字" ;
	cin >> key;
	cout << "显示源文件" << "“" << filename << "”：" << endl;
	//输出文件内容
	f.open(filename, ios::in);
    while (!f.eof())
	{
		char buffer[100];
		f.getline(buffer, 100);
		cout << buffer << endl;
	}
	f.close();
	int n = seach_key(filename, key);
	cout << endl << "在源文件中共检索到：" << n << "个关键字" << "“" << key << "”" << endl;
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
		//一行一行检索
		for (int i = 0; message[i] != 0; i++)
		{
			if (message[i] == key[0])//如果第一个字符匹配开始看后面的字符
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