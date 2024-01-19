//: C15:ObjectSlicing.cpp
#include <iostream>
#include <string>
using namespace std;
class Pet {
	string pname;
public:
	Pet(const string& name) : pname(name) {}
	virtual string name() const { return pname; }
	// pure virtual function is for avoiding the slicing
	virtual string description() const
	{
		return "This is " + pname;
	}
};
class Dog : public Pet {
	string favoriteActivity;
public:
	Dog(const string& name, const string& activity)
		: Pet(name), favoriteActivity(activity) {}
	string description() const {
		return Pet::name() + " likes to " +
			favoriteActivity;
	}
};
// pass by value! prefer pass by reference!
void describe(Pet p) { // Slices the object
	cout << p.description() << endl;
}

void describeRef(Pet &p) { 
	cout << p.description() << endl;
}

int main() {
	Pet p("Alfred");
	Dog d("Fluffy", "sleep");
//	describe(p);
	describe(d);
//	describeRef(p);
//	describeRef(d);
	cout << p.description() <<endl;	//正常调用基类函数
	cout << d.description() << endl;	//对象切片
} 
