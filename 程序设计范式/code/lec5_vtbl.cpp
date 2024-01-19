#include <iostream>

using namespace std;

class Base {
public:
	virtual void f() { cout << "Base::f" <<endl;}
	virtual void g() { cout << "Base::g" <<endl;}
	virtual void h() { cout << "Base::h" <<endl;}
}; 


int main() 
{
	typedef void(*Fun)(void);

	Base b;
	
	Fun pFun = NULL;
	
	cout << "�麯�����ַ��" << (int*)(&b) <<endl;
	
	cout << "�麯���� �� ��һ��������ַ��" << (int*)*(int*)(&b) <<endl;

	// Invoke the first virtual function
	
	pFun = (Fun)*((int*)*(int*)(&b)+1);
//(Fun)*((int*)*(int*)(&b)+0); // Base::f()

//(Fun)*((int*)*(int*)(&b)+1); // Base::g()

//(Fun)*((int*)*(int*)(&b)+2); // Base::h()	
	pFun(); 
}


