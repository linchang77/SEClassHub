#include <iostream>

using namespace std;

class CRef
{
public:
       CRef() { s_iObjectCnt++; }
       /* 
       CRef(const CRef& rhs )
		{
	        s_iObjectCnt++;
	        print("CRef(const CRef&)");
		}*/


       static void print(const string &str = " ")
       {     cout << str << ": Object Count = ";
              cout << s_iObjectCnt << endl;  }

       ~CRef()
       {     s_iObjectCnt--;
              print("~Cref()");   }
private:
       static int s_iObjectCnt;
};

int CRef::s_iObjectCnt = 0;

CRef copy(CRef X)
{
    X.print("X arguments inside cp()");
    return X;
}

int main()
{
     CRef r;
     CRef::print("after construction of r");
//     CRef r2 = copy(r);
     CRef r3 = r;
     CRef::print("after calling of cp");
}



