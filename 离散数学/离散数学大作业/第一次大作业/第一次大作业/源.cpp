#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	int a[4];
	int i = -1, j = -1;
	char s;
	while (1)
	{
		cout << "***************************************" << endl;
		cout << "**                                   **" << endl;
		cout << "**        ��ӭ�����߼��������       **" << endl;
		cout << "**                                   **" << endl;
		cout << "***************************************" << endl << endl;
		cout << endl;
		cout << "  ������P��ֵ��0��1��,�Իس�����:";
		cin >> i;
		if (i != 0 && i != 1)
		{
			cout << endl << "  P��ֵ��������,����������!";
			Sleep(2000);
			system("cls");  //����
			continue;
		}
		cout << endl << "  ������Q��ֵ��0��1��,�Իس�����:";
		cin >> j;
		if (j != 0 && j != 1)
		{
			printf("\n  Q��ֵ��������,����������!");
			Sleep(2000);
			system("cls");  //����
			continue;
		}
		a[0] = i && j;  //������
		a[1] = i || j;  //������
		a[2] = (!i) || j;  //�̺����㣬����ת��Ϊ������ʽ
		a[3] = ((!i) || j) && ((!j) || i);  //��ֵ���㣬����ת��Ϊ������ʽ
		cout << endl << endl << "  ��ȡ:" << endl << "       P/\\Q = " << a[0] << endl;
		cout << "  ��ȡ:" << endl << "       P\\/Q = " << a[1] << endl;
		cout << "  ����:" << endl << "       P->Q = " << a[2] << endl;
		cout << "  ˫����:" << endl << "       P<->Q = " << a[3] << endl;
		cout << endl;
		int tag = 0;
		while (1)
		{
			cout << "�Ƿ��������?��y/n��";//ѯ���Ƿ��������
			cin >> s;
			if (s == 'y' || s == 'n')
			{
				if (s == 'y')
				{
					system("cls");  //����
					tag = -1;
					break;
				}
				else
				{
					printf("��ӭ�´��ٴ�ʹ��!\n");  //�˳�
					tag == 1;
					exit(0);
				}
			}
			else
				cout << "�������,����������!" << endl;//����У��
		}
		if (tag == -1)
			continue;
		else if (tag == 1)
			break;
	}
	return 0;
}
