#include <iostream>                                 //����ͷ�ļ�
#include <cstdlib>
using namespace std;

double fuc(double x, double y)                        //���庯��
{
	if(y==0)
    {
	 	throw y;                                    //����Ϊ0���׳��쳣
	}
	return x/y;                                    //���򷵻�����������
}

int main()
{
	double res;
	try                                            //�����쳣
	{
		res=fuc(2,3);
		cout<<"The result of x/y is : "<<res<<endl;
		res=fuc(4,0);                                //�����쳣
	}
	catch(double)                                    //���񲢴����쳣
	{
		cerr<<"error of dividing zero.\n";
		exit(1);                                    //�쳣�˳�����
	}
	
	return 0;
}

