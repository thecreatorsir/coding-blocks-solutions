#include<iostream>
using namespace std;

int main(){
	int n,x;
	cin>>n>>x;
	
	int ans = 1;
	while(x > 0){
		if(x&1)
		 ans*=n;
		n = n*n;
		x = x>>1; 
	}
	cout<<ans<<endl;
	return 0;
}
