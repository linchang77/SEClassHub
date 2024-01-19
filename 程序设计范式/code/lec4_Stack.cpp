#include "lec4_Stack.h"

bool Stack::empty()
{
	return stack.empty();
}

bool Stack::full()
{
	return stack.size() == stack.max_size();
}

bool Stack::peek(string &elem)
{
	if( empty() )
		return false;
	elem = stack.back();
	return true;	
}

bool Stack::push(const string &elem)
{
	if(full())
		return false;
	stack.push_back(elem);
	return true;
}

int main()
{
	
	return 0;	
}
