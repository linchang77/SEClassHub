// test iterator
#include <iostream>
#include <vector>
#include <list>

using namespace std;


// iterator
template <typename elemType, typename IteratorType>
IteratorType find(IteratorType first, IteratorType last, elemType value); 

int main()
{
	const int SIZE = 8;
	int ia[SIZE] = {8, 34, 3, 13, 1, 21, 5, 2};

	
	vector<int> ivec(ia, ia+SIZE);	
	list<int> ilist(ia, ia+SIZE);
	
	//test iterator	
	vector<int>::iterator itv;
	itv = find(ivec.begin(), ivec.end(), 13);
	
	list<int>::iterator itl;
	itl = find(ilist.begin(), ilist.end(), 13);
	cout<<*itv <<' '<< *itl <<' ' << endl;
		
	return 0;
}


//using iterators
template <typename elemType, typename IteratorType>
IteratorType find(IteratorType first, IteratorType last, elemType value)
{
	for(; first != last; ++first)
	{
		if(*first == value)
			return first;
	}
	return last;
}



