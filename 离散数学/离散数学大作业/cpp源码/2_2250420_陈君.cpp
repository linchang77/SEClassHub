#include <iostream>
using namespace std;
int main()
{
	int A,B,C,D,E;
	/*
	A:营业员A偷了手表
    B:营业员B偷了手表
    C:作案不在营业时间
    D:B提供的证据正确
    E:货柜未上锁
	*/
	cout<<"1表示偷了表，0表示没有偷表"<<endl; 
	for(A = 0;A <= 1;A++)//遍历ABCDE的所有值 
		for(B = 0;B <= 1;B++)
			for(C = 0;C <= 1;C++)
				for(D = 0;D <= 1;D++)
					for(E = 0;E <= 1;E++)
						if ((A || B) && (!A || C) && (!D || E) && (D || !C) && !E)
							cout<<"A="<<A<<",B="<<B<<endl;
						getchar(); 
	return 0;
}

