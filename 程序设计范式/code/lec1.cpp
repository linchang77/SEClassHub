#include <iostream>

using namespace std;

double getAverage(int numValue);

int main()
{
    for(int i = 0; i < 10; i++) 
        cout << "so welcome" << endl;
    
    double sum;
    sum = getAverage(3);
    cout << "sum="<< sum << endl;
    system("pause");
    return 0;   
    
}

double getAverage(int numbers)
{
    double sum;
    double value;
    for(int i = 0; i < numbers; i++)
    {
        cout << "input:";
        cin >> value;
        sum = sum + value;
    }
    return sum;
}
