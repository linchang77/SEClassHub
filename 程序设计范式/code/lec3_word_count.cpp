#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <fstream>

using namespace std;

const int MAX_SIZE = 1024;
void GetWords(vector<string> &vec)
{
	char str[ MAX_SIZE];
	ifstream InFile("article1.txt");
	while(!InFile.eof())
	{
		InFile.getline(str,MAX_SIZE);

		//const char * split = "/?:"; 
		char * p; 
		p = strtok(str, " "); 
		while(p!=NULL)
		{ 
			string str = p;
			vec.push_back(str);
			p = strtok(NULL," "); 
		} 
	}
	copy (vec.begin(),vec.end(),ostream_iterator<string>(cout,"  "));
}

void SortWords( vector<string> &vec, map<string,int> &words)
{
	vector<string>::iterator it = vec.begin();
	for(it; it != vec.end(); ++it)
	{
		if(words.find(*it) != words.end() )
		{
			int i = words[*it];
			++i;
			words[*it] = i;

		}
		else
		{
			words.insert(map<string,int>::value_type(*it,1));
		}
	}
}

int main()
{	
	vector<string> vec;
	map<string,int> words;
	GetWords(vec);
	SortWords(vec,words);

	cout<<endl<<"====After sort===="<<endl;
	map<string,int>::iterator mapit = words.begin();
	for(mapit;mapit != words.end();++mapit)
	{
		cout<< mapit->first<<"  "<<mapit->second<<endl;
	}

    system("pause");
	return 0;
}
