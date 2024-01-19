#include "lec5_numsequence_virtual.h"

vector<int> Fibonacci::s_elems;
int num_sequence::max_elems()
{
	return 0;
}

int num_sequence::elem(int pos)
{
	return 0;
}

const char* num_sequence::what_am_I() const
{
	
}

ostream& num_sequence::print(ostream& os = cout) const
{
	
}

bool num_sequence::check_integrity(int pos) const
{
	/*
	if( !num_sequence::check_integrity(pos))
		return false;
	if( pos > s_elems.size())
		Fibonacci::gen_elems(pos);
		
	return true;*/
}



int Fibonacci::elem( int pos ) 
{
	if (! num_sequence::check_integrity(pos))
	  	return 0;
	
	if(pos > s_elems.size())
		Fibonacci::gen_elems(pos);
		
	return s_elems[pos-1];
	  		
}

ostream& Fibonacci::print(ostream& os = cout) const
{
	/*
	int elem_pos = m_iBeg_pos -1;
	int end_pos = elem_pos + m_iLength;
	if(end_pos > s_elems.size())
		Fibonacci::gen_elems(end_pos);
	while(elem_pos < end_pos)
		os << s_elems[elem_pos++] << ' ';
		
	return os;
	*/	
}

void Fibonacci::gen_elems(int pos)
{
	/*
	if(s_elems.empty())
	{
		s_elems.push_back(1);
		s_elems.push_back(1);
	}
	if(s_elems.size()<pos)
	{
		int ix = s_elems.size();
		int n_2 = s_elems[ix-2];
		int n_1 = s_elems[ix-1];
		
		for(; ix<= pos; ix++)
		{
			int elem = n_2 + n_1;
			s_elems.push_back(elem);
			n_2 = n_1;
			n_1 = elem;
		}
	}*/
}

int main()
{
	num_sequence* ps = new Fibonacci(12, 8);
	ps->what_am_I();
//	ps->max_elems();
//	ps->length();

	delete ps;
	
}
