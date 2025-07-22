#include <iostream>
using namespace std;

const char* name = "abc";
char* q ;

int main(){
	char ch;
	cin>>ch;
	
	const char* p = name;
	cout<<p<<endl;
	
	char* arr = new char[5]{'d', 'e', 'f', '\0', '\0'};
	q = arr;
	cout<<q<<" "<<5<<endl;
	
	q[0] = p[0];
	q[1] = p[1];
	q[2] = p[2];
	q[3] = ch;
	cout<<q;
	
	return 0;
	
}














