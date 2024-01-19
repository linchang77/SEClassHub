#include "lec5_Library.h"

void global_print(const LibMat &mat)
{
	mat.print();
}

int main()
{
	cout << "Create a LibMat object!" << endl;
	LibMat libmat;
	global_print(libmat);
	cout << "========"<< endl;
	
	cout << "Create a Book object!" << endl;
	Book b("The Castle", "Franz Kafka");
	global_print(b);
	cout << "========"<< endl;
	
	cout << "Create an AudioBook object!"<< endl;
	AudioBook ab("Man Without Quarlities", "Robert Musil", "Kenneth Meyer");
	global_print(ab);
	
	return 0;
}
