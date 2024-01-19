/*
三种情况下需要使用初始化成员列表：
一，需要初始化的数据成员是对象的情况；
二，需要初始化const修饰的类成员；
三，需要初始化引用成员数据；
*/

#include <iostream>
#include <cstdlib>

using namespace std;

class CMatrix
{
    public:
        CMatrix(int Row, int Col):m_iRow(Row),m_iCol(Col),size(Row*Col)
        {
 //       	m_iRow = Row;
 //       	m_iCol = Col; 
 //       	size = Row*Col;
 //       	temp = Row;
			cout<<"constructor"<<endl;
            m_pdMat = new double [Row*Col];
        }
        CMatrix& operator=(const CMatrix &rhs);
        ~CMatrix()
        {
            cout<<"deconstructor"<<endl;
            delete [] m_pdMat;
        }
        int getRow()
        {
        	return m_iRow;
        }
    private:
        int m_iRow, m_iCol;
        int size;
        //const int size;
 //       int & temp;
        double* m_pdMat;
};

CMatrix& CMatrix::operator=(const CMatrix &rhs)
{
	if(this != &rhs)
	{
		m_iRow = rhs.m_iRow;
		m_iCol = rhs.m_iCol;
		size = m_iRow*m_iCol;
		delete [] m_pdMat;
		m_pdMat = new double[size];
		for(int ix = 0; ix< size; ix++)
		{
			m_pdMat[ix] = rhs.m_pdMat[ix];
		}
		return *this;
	}
}

int main()
{
    CMatrix Mat(4,4);
    
    CMatrix mat2 = Mat;
    cout << Mat.getRow() << endl;
    cout << mat2.getRow() << endl;

    return 0;
    
}
