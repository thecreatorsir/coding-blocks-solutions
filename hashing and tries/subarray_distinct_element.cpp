#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int output(int * a,int n){
	set<int> m;
	int j=0;
	int ans = 0;
	for(int i=0;i<n;i++){
         while(j<n and m.find(a[j])==m.end()){
			 m.insert(a[j]);
			 j++;
		 }
		 ans += ((j-i)%mod*(j-i+1)%mod)/2;
		 m.erase(a[i]);
	}
	return ans;
}
int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<output(a,n);
	return 0;
}