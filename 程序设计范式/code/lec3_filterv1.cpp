//filter the numbers in a vector that are less/greater than the filter_value
//pointer to function
// function object
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

vector<int> filter_ver1(const vector<int> &vec, int filter_value, bool (*pred)(int, int))
{
	vector<int> nvec;
	for(int ix = 0; ix< vec.size(); ix++)
	{
		if(pred(vec[ix], filter_value))
			nvec.push_back(vec[ix]);
	}
	return nvec;
}
bool less_than(int v1, int v2)
{
	return v1 < v2 ? true:false;
}
bool greater_than(int v1, int v2)
{
	return v1 > v2 ? true:false;
}

// generic algorithm: filter
template<typename InputIterator, typename OutputIterator, typename ElemType, typename Comp>
OutputIterator filter(InputIterator first, InputIterator last, OutputIterator at, const ElemType &val, Comp pred)
{
	while((first = find_if(first, last, bind2nd(pred, val))) != last)
	{
		cout << "found value: " << *first << endl;
		*at++ = *first++; 
	}
	return at;
}

int main()
{
	int ia[8] = {8, 34, 3, 13, 1, 21, 5, 2};
	vector<int> big_vec(ia, ia+8);
	/*
	int value = 13;
	vector<int> lt = filter_ver1(big_vec, value, less_than);
	for(int i = 0; i < lt.size(); i++)
		cout << lt[i] << ' '; 
	*/
	
	int ia2[8];
	vector<int> ivec2; //get error as iterator points to illegal positions
//	vector<int> ivec2(8);
	filter(ia, ia+8, ia2, 8, less<int>());
	cout<< "vector" << endl;
	// back_inserter(ivec2)
	filter(big_vec.begin(), big_vec.end(), back_inserter(ivec2), 8, greater<int>());
		
	return 0;
} 


