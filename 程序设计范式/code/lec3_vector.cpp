#include <iostream>
#include <vector>

using namespace std;

void comp(vector<int> &v1, vector<int> &v2)
{
	if( v1 == v2)
	{
		cout << "equality" << endl;
		return;
	}
		
	if( v1.empty() || v2.empty()) 
	{
		cout << "empty" << endl;
		return;
	}
	vector<int> t;
	t = v1.size() > v2.size()? v1:v2;
	for(int ix = 0; ix < t.size(); ix++)
	{
		cout << t[ix] << ' ';
	}
	// notice on t.erase(t.begin(), t.end());
	//t.erase(t.begin(), t.end()-2);
	t.clear();
	cout << endl;
//	t.push_back(3);
	t.insert(t.begin()+1, 3);
	for(int ix = 0; ix < t.size(); ix++)
	{
		cout << t[ix] << ' ';
	}
		
}

int main() 
{
	int ia[8] = {8, 34, 3, 13, 1, 21, 5, 2};
	vector<int> vec1(ia, ia+8);
	vector<int> vec2(ia+1, ia+7);
	
	comp(vec1, vec2);
	
	return 0;	
}
