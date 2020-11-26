#include<bits/stdc++.h>
using namespace std;

int solve(int ip){
	if(ip==0 or ip==1){
	 return ip+1;
    } 
    return solve(ip-1)+solve(ip-2);
}

int main(){
	int ip;
	cin>>ip;
    cout<<solve(ip)<<endl;
	return 0;
}
