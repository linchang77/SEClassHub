#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Stack;
class Queue;

class Stack
{
	public:
		bool push(const string&);
		bool pop(string &elem);
		bool peek(string &elem);
		
		bool empty();
		bool full();
		int size()
		{
			return stack.size(); // inline function
		}
	private:
		vector<string> stack;
};

class Queue
{
	public:
		bool isempty();
		int pop();
		void push(int i);
		void remove(int i);
	private:
		int value;
		int top; 	
};
