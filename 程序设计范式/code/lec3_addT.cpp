#include <iostream>
#include <stdlib.h>
using namespace std;

template <typename T>
T add(T a, T b)
{
    return a+b;
} 

int main()
{
    int num1, num2;
    float sum;
    cin>>num1>>num2;
    sum = add(num1, num2);
    cout<<sum;
    system("pause");
    return 0;   
    
}
