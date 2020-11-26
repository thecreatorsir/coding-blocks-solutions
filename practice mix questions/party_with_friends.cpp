//he can take 1,2,3 steps at a time

#include<iostream>
using namespace std;

int party(int n){
	if(n==0){
		return 1;
	}
	if(n<0)
	 return 0;
	return 1*party(n-1)+(n-1)*party(n-2);
}


int main(){
	int n;
	cin>>n;
	cout<<party(n)<<endl;
}
