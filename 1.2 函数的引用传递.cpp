#include <iostream>
using namespace std;

void change(int& x,int& y,int& z){
	bool f = true;
	while(f){
		f = false;
		int p=0;
		if(x>y){
			f = true;
			p=x;
			x=y;
			y=p;
		}
		if(y>z){
			f = true;
			p=y;
			y=z;
			z=p;
				}
		if(x>z){
			f = true;
			p=x;
			x=z;
			z=p;
				}	
	}
}



int main(){
	int p1=0;
	int p2=0;
	int p3=0;
	
	cin>>p1;
	cin>>p2;
	cin>>p3;
	
	change(p1,p2,p3);
	
	cout<<p1<<" "<<p2<<" "<<p3;
	
	return 0;
}




