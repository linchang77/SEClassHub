#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stack
{
	public:
	bool isEmpty() {
		return top <= 0;
	}
	int pop() {
		return values[--top];
	}
	void push(int i) {
		values[top++] = i;
	}
	void remove(int i) {
		while (i > 0) {
			pop();
			i--;
		}
	}
	int size()
	{
		return top;
	}
	int getvalue(int i)
	{
		return values[i];
	}
	private:
		int values[5];
        int top = 0;
};

int main()
{
	Stack s;
	s.push(6);
	for(int i = 0; i < s.size(); i++)
		cout << s.getvalue(i); 
	s.remove(3);
	return 0;
}
