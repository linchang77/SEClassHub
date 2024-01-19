    #include <iostream>  
    using namespace std;  
      
    class CExample {  
    private:  
        int a;
		int b;  
    public:  
        //构造函数 
//		CExample(); 
//        CExample(int x);
		CExample(int x =2, int y=2);
 /*         
        //拷贝构造函数  
        CExample(const CExample& C)  
        {  
            a = C.a;  
        }  
 */     
        //一般函数  
        void Show ()  
        {  
            cout<<a<<endl;  
        }  
    };
	/*  
    CExample::CExample()
    {
    	a = 1;
    	b = 1;
    }
    CExample::CExample(int x)
    {
    	a = x;
    }  */
    CExample::CExample(int x, int y)
    {
    	a = x;
    	b = y;
    }   
	  
    int main()  
    {  
//        CExample A1(); 
//		CExample A1;
		CExample A2(12);
		CExample A3(8,11);
		
//        CExample B(A); // CExample B(A); 也是一样的  
//        B.Show (); 

        return 0;  
    }   
