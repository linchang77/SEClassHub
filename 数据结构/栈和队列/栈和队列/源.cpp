#include<iostream>

#include <assert.h>
template <class Type> class Stack
{
public:
	Stack(int = 10); //构造函数
	~Stack() { delete[] elements; } //析构函数
	void Push(const Type& item); //进栈
	Type Pop(); //出栈
	Type GetTop(); //取栈顶
	void MakeEmpty() { top = -1; } //置空栈
	int IsEmpty() const {
		return top == -1;
	}
	int IsFull() const
	{
		return top == maxSize - 1;
	}
private:
	int top; //栈顶数组指针
	Type* elements; //栈数组
	int maxSize; //栈最大容量
};
int main()
{

}