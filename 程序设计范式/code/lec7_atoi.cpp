#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
//	char *str1 = "1", *str2 = "2";
	//case: atoi("a") = 0;
//	char *str1 = "1", *str2 = "a";
	//case: atoi(NULL)?
	char *str1 = "1", *str2 = "xy"; 
	int num1 = atoi(str1);
	int num2 = atoi(str2);
	cout << "sum is: "<< num1+num2 << endl;
	 
	return 0;
}
