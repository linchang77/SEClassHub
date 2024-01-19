#include <iostream>
#include <vector>
using namespace std;

class num_sequence
{
public:
       virtual ~num_sequence(){}
       
       virtual int elem(int pos);
       virtual const char* what_am_I() const; 
       virtual ostream& print(ostream& os) const;  
       static int max_elems(); 
protected:
       virtual void gen_elems(int pos) = 0;	//pure virtual function
       bool check_integrity(int pos) const; 
//	   bool check_integrity(int pos, int size);   
};


class Fibonacci: public num_sequence
{
public:
       Fibonacci(int len = 1, int beg_pos = 1) 
              : m_iLength(len), m_iBeg_pos(beg_pos) {
			  }
       virtual int elem(int pos);  //definition is outside the class
       virtual const char* what_am_I() const 
	   { 
	   		return "Fibonacci"; 
	   }
       virtual ostream& print(ostream& os) const; 
       int length() { return m_iLength; }
       int beg_pos() { return m_iBeg_pos; }
protected:
       void gen_elems(int pos); 
       int m_iLength;
       int m_iBeg_pos;
       static vector<int> s_elems;
};


