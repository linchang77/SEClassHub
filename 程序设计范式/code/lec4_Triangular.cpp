#include <iostream>
#include <vector>
#include "lec4_Triangular.h"

//if elems is static, define outside the class
vector<int> Triangular::elems;

Triangular::Triangular()
{
	_length = 1;
	_beg_pos = 1;
	_next = 0;
} 

Triangular::Triangular(int len, int bp)
{
	_length = len > 0? len:1;
	_beg_pos = bp > 0? bp:1;
	_next = _beg_pos - 1;
}

int Triangular::elem( int pos ) const
{
	return elems[pos-1];
}
// const member function
int sum_con( const Triangular &train)
{
	int _beg_pos = train.beg_pos();
	int length = train.length();
	int sum = 0;
	for( int ix = 0; ix < length; ix++)
	{
		sum += train.elem(_beg_pos + ix);
	}
	return sum;
}
// 
int sum_mut( const Triangular &train)
{
	if( !train.length() )
		return 0;
	int val, sum = 0;
	// next_reset() and next() is not const
	train.next_reset();
	while( train.next(val))
		sum += val;
		
	return sum;
}

bool Triangular::next(int &value) const
{
	if(_next < _beg_pos + _length-1)
	{
		value = elems[_next++];
		return true;
	}
	return false;
}

int main()
{
	Triangular tri(4, 3);
	cout << " sum: " << sum_con(tri) <<endl;
	 
	return 0;
}




