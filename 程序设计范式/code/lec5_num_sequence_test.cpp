#include <iostream>
#include "lec5_num_sequence.h"

using namespace std;

const char* num_sequence::what_am_i() const{
	static char* names[num_seq] = {
		"notSet", "fibonacci", "pell", "lucas", "triangular", "square", "pentagonal"
	};
	return names[_isa];
}

int main()
{
	num_sequence ns;
	/* calling the set_sequence()
	for(int ix = 1; ix < num_sequence::num_of_sequences(); ix++)
	{
		ns.set_sequence(num_sequence::nstype(ix));
		int elem_val = ns.elem(pos);
	}
	*/	
		
}
