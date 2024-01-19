#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


int main()
{
    map<string, int> word;
    map<string, int>::iterator it;
    word.insert(map<string, int>::value_type("a",9));
    word.insert(map<string, int>::value_type("b",7));
    it = word.find("a");
    if(it!=word.end())
         cout<<it->second<<endl;
         
    int result = word.count("a");
    if(result)
         cout<<word["b"]<<endl;
    
    system("pause");
    return 0;
       
}
