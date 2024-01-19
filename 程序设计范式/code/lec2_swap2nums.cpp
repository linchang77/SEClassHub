#include <iostream>
#include <cstdlib> 

using namespace std;

void swap1(int *a, int *b)
{
    cout<<"in swap1"<<endl;
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swap2(int &a, int &b)
{
     cout<<"in swap2"<<endl;
     int temp;
     temp = a;
     a = b;
     b = temp;
}   

int & Fun(const int &x, int &y, int z)
{
   z++;
   y=x+y+z;
   cout<<"y ="<<y<<endl;
   return y;
}


int main()
{
    int a = 1, b = 2;
    cout<<"a="<<a<<" b="<<b<<endl;
    swap1(a, b);
    int *x;
    int *y;
    cout<<"a="<<a<<" b="<<b<<endl;
    swap2(&a, &b);
    cout<<"a="<<a<<" b="<<b<<endl;
//    int c = 3, d = 0;  
//    Fun(a, b, c) = 4;
//    cout<<"a="<<a<<" b="<<b<<" c="<<c<<" d="<<d<<endl;

      
    system("pause");
    return 0;
}
