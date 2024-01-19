#include <fstream>
#include <string>
#include <iostream>

using namespace std;
int main()
{
    //read a file
    char buff[1024];
    string message;
    
    ifstream infile;
    infile.open("input1.txt");
    
    if(infile.is_open())
    {
        while(!infile.eof())
        {
            memset(buff, 0, 1024);
            infile.getline(buff, 1024);
            message = buff;
            cout<<message<<endl;
        }  
                       
    }
    else
    {
        cout<<"Sorry, we cannot open the file!"<<endl;
    }
    infile.close(); 

  
    //write into a file
    ofstream outfile;
    outfile.open("output.txt");
    if(outfile.is_open())
    {
        outfile<<message<<endl;
        outfile.close();                     
    }
    else
        cout<<"Sorry, we cannot open the file!"<<endl;
 
    system("pause");
    return 0; 
}
