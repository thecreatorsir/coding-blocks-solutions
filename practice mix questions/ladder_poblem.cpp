//he can take 1,2,3 steps at a time

#include<iostream>
using namespace std;

int ladder(int n){
	if(n==0){
		return 1;
	}
	if(n<0)
	 return 0;
	return ladder(n-1)+ladder(n-2)+ladder(n-3);
}


int main(){
	int n;
	cin>>n;
	cout<<ladder(n)<<endl;
}
