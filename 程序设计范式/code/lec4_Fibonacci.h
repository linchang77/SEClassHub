#include <iostream>
#include <vector>

using namespace std;

class Fibonacci
{
	public:
		int getLength()
		{
			return length;
		} 
		int beginPos();
		static bool is_elem(int);  
		
	private:
		int length;
		int beg_pos;
		int next;
		// initialize the static data member inside a class is forbidden
		//static int initial_size = 8;
		static int initial_size;
		static vector<int> elems;	
};
