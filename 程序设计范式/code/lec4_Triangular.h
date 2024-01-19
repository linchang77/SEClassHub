

using namespace std;

class Triangular{
	public: 
		Triangular();
		Triangular(int len);
		Triangular(int len, int beg_pos);
		//const member functions
		int length() const { return _length;}
		int beg_pos() const {return _beg_pos;}	
		int elem( int pos ) const;
		// non-const member functions
		bool next (int &val) const;
		void next_reset() const
		{
			_next = _beg_pos - 1;
		}
		
//		int sum_con( const Triangular &train);
//		int sum_mut( const Triangular &train);
		
	private:
		int _length;
		int _beg_pos;
		//int _next;
		mutable int _next;
		static vector<int> elems;
		
}; 
