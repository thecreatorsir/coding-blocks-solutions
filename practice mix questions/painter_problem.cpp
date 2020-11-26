#include<iostream>
#include<climits>
#define ll long long int 
using namespace std;
bool possible(ll *a,ll b,ll k,ll mid){
	ll curr_painter = 1;
    ll time_count = 0;
	for(int i=0;i<b;i++){
		if(time_count + a[i] > mid){
			curr_painter++;
			time_count = a[i];
			if(curr_painter > k)
			 return false;
		}
		else{
			time_count += a[i];
		}
	}
	return true;
}
ll solve(ll *a,ll b,ll k,ll mx,ll total){
ll s = mx;
ll e = total;
ll ans = INT_MAX;
while(s<=e){
	ll mid = ((s+e)>>1)%10000003;
	if(possible(a,b,k,mid)){
     ans = min(ans,mid);
	 e = mid-1;
	}else{
		s=mid+1;
	}
}
return ans%10000003;
}

int main() {
	ll b,k,t;
	cin>>b>>k>>t;
	ll a[b];
	ll total = 0;
	ll mx = 0;
    for(int i=0;i<b;i++){
	 cin>>a[i];
	 total += a[i];
	 mx = max(mx,a[i]);
	 }
	cout<<(solve(a,b,k,mx,total)*t)%10000003<<endl; 
	return 0;
}
