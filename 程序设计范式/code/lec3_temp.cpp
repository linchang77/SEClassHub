#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

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

int main
{
     istream_iterator<string> is(cin);
     istream_iterator<string> eof;
     vector<string> text;
     copy(is, eof, back_inserter(text));
     sort(text.begin(), text.end());

     ostream_iterator<string> os(cout, " ");
     copy(text.begin(), text.end(), os);
}

