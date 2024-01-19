#include<iostream>

#include <assert.h>
template <class Type> class Stack
{
public:
	Stack(int = 10); //���캯��
	~Stack() { delete[] elements; } //��������
	void Push(const Type& item); //��ջ
	Type Pop(); //��ջ
	Type GetTop(); //ȡջ��
	void MakeEmpty() { top = -1; } //�ÿ�ջ
	int IsEmpty() const {
		return top == -1;
	}
	int IsFull() const
	{
		return top == maxSize - 1;
	}
private:
	int top; //ջ������ָ��
	Type* elements; //ջ����
	int maxSize; //ջ�������
};
int main()
{

}