#include<iostream>
using namespace std;

void T_O_H(int n,char a,char b,char c){
	if(n==1){
		cout<<"move plate " <<n<< " from "<<a<<" to "<<c<<endl;
		return;
	}
	T_O_H(n-1,a,c,b);
			cout<<"move plate " <<n<< " from "<<a<<" to "<<c<<endl;
	T_O_H(n-1,b,a,c);		
}

int main(){
	int n;
	cin>>n;
	char a='A',b='B',c='C';
	
	T_O_H(n,a,b,c);
} 
