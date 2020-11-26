//using recursion
#include<bits/stdc++.h>
using namespace std;

int solve(int n,int k){
	if(n==0)
	 return 0;
	if(n==1||n==2)
	 return 1;
    while(k<(n/2+1)){
    	k=2*k;
	}
	return 1+solve(n-k,1);   
}

int main(){
	int n;
	cin>>n;
	int res = solve(n,1);
	cout<<res;
}
