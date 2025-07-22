#include <iostream>
using namespace std;

int main(){
	int n=0;
	cin>>n;
	
	int arr[n];
	
	int* p = new int[n];
	
	for(int i = 0;i < n;i++){
		cin>>p[i];
	}
	
	int num = 0;
	
	for(int i = 0;i < n;i++){
			num += p[i];
		}
	
	
	cout<<num;
	
	return 0;
}













