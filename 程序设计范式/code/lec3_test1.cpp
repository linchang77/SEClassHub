#include <iostream>

using namespace std;

int a[8] = {2, 34, 11, 7, 8, 12, 1, 9};

void bubble_sort(int a[]);

int main()
{
	cout <<"main: "<< sizeof(a);
	bubble_sort(a);
	return 0;	
}

void bubble_sort(int a[])
{
	cout << "bubble: " << sizeof(a);
}

