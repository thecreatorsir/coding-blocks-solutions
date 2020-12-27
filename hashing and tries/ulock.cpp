#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll * find(ll *a,unordered_map<ll,ll> m,ll k,ll n){
    //number will be from 1-n as given in question
    for(ll i=n;i>=1 &&k>0;i--){
       ll num = i;
       ll i_idx = m[num];
       ll b_idx = n-num;
       if(i_idx!=b_idx){
          swap(a[i_idx],a[b_idx]);
          k--;
       }
       m[a[b_idx]] = b_idx;
       m[a[i_idx]] = i_idx;  
    }
	return a;
}
int main() {
	ll n,k;
    cin>>n>>k;
	ll a[n];
	unordered_map <ll,ll> m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
		m[a[i]]=i;
}
ll * temp = find(a,m,k,n);
for(ll i=0;i<n;i++){
		cout<<a[i]<<" ";
}
	return 0;
}