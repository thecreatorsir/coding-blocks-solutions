#include<iostream>
#define mod 1000000007
using namespace std;
int solve(int n,int m){
	if(n<=1 or n<m){
		return 1;
	}
	if(n==m){
		return 2;
	}
	return (solve(n-1,m)+solve(n-m,m))%mod;
}



int main() {
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		cout<<solve(n,m)%mod<<endl;
	}
	return 0;
}
