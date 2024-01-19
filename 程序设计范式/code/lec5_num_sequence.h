
class num_sequence{
	public:
		enum ns_type{
			ns_unset, ns_fibonacci, ns_pell, ns_lucas, 
			ns_triangular, ns_square, ns_pentagonal
		}; 
		
		static ns_type nstype(int num)
		{
			return num <= 0 || num >= num_seq? ns_unset // invalid
				: static_cast<ns_type> (num);
				//static_cast changes the int num to corresponding ns_type
		}

		void num_sequence::set_sequence( ns_type nst)
		{
			switch (nst)
			{
				default:
					cerr << "invalid type: setting to 0\n";
				case ns_unset:
					_pmf = 0;
					_elem = 0;
					_isa = ns_unset;
					break;
				case ns_fibonacci:
				case ns_pell:
				case ns_lucas:
				case ns_triangular:
				case ns_square:
				case ns_pentagonal:
					_pmf = func_tbl[nst];
					_elem = &seq[nst];
					_isa = nst;
					break;
			}
		}
		
		const char* what_am_i() const;
		
	
	private:
		vector<int> *elem;
		PtrType _pmf;
		ns_type _isa;
		
}; 
