#include <iostream>
using namespace std;
int main()
{
	int A,B,C,D,E;
	/*
	A:ӪҵԱA͵���ֱ�
    B:ӪҵԱB͵���ֱ�
    C:��������Ӫҵʱ��
    D:B�ṩ��֤����ȷ
    E:����δ����
	*/
	cout<<"1��ʾ͵�˱�0��ʾû��͵��"<<endl; 
	for(A = 0;A <= 1;A++)//����ABCDE������ֵ 
		for(B = 0;B <= 1;B++)
			for(C = 0;C <= 1;C++)
				for(D = 0;D <= 1;D++)
					for(E = 0;E <= 1;E++)
						if ((A || B) && (!A || C) && (!D || E) && (D || !C) && !E)
							cout<<"A="<<A<<",B="<<B<<endl;
						getchar(); 
	return 0;
}

