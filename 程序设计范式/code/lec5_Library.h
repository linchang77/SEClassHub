#include <iostream>

using namespace std;

class LibMat{
	public:
		LibMat()
		{
			cout <<"LibMat Default Constructor!" <<endl;
		}
		virtual ~LibMat()
		{
			cout << "LibMat Destructor!" << endl;
		}
		virtual void print() const
		{
			cout << "This is a LibMat object!" << endl;
		}
}; 

class Book : public LibMat	//public inheritance
{
	public:
		Book(const string& title, const string& author) : m_szTitle(title), m_szAuthor(author)
		{
			cout << "Book( " << m_szTitle << ", "<< m_szAuthor << " ) Constructor!" << endl; 
		}
		virtual ~Book() 
	  	{ 
	  		cout << "Book Destructor!" << endl; 
		}
      	virtual void print() const 	
        {
			cout << "This is a Book object!" << endl;
            cout << "Title: " << m_szTitle << endl;
            cout << "Author: " << m_szAuthor << endl; }
      		const string& title() 
			{
				return m_szTitle; 
			}
      		const string& author() 
			{ 
				return m_szAuthor; 
			}
	protected:		//will be used in derived classes, so can¡¯t be private
		string m_szTitle, m_szAuthor;
};

class AudioBook:public Book
{
	public:
    	AudioBook(const string& title, const string& author, const string& narrator)
			:Book(title, author), m_szNarrator(narrator)
   		{
		   cout << "AudioBook( " << m_szTitle << ", "<< m_szAuthor  //inherited
                          << ", " << m_szNarrator << " ) Constructor!" << endl; 
		}  //from Book
      	virtual ~AudioBook()  
		{ 
			cout << "AudioBook Destructor!" << endl; 
		}
      	virtual void print() const 	
        { 
			cout << "This is an AudioBook object!" << endl;
            cout << "Title: " << m_szTitle << endl;
        	cout << "Author: " << m_szAuthor << endl;
	  		cout << "Narrator: " << m_szNarrator << endl; 
		}
      	const string& narrator() 
		{ 
			return m_szNarrator; 
		}//title() & author() have been inherited
	protected:
      	string m_szNarrator;
};



 
