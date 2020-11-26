#include<iostream>
#include<math.h>
#define ll long long int
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
		 ll n,k;
		cin>>n>>k;
		ll s = 0,e=n;
		ll ans = -1;
		while(s<=e){
			ll mid = (s+e)/2;
			if(pow(mid,k)<=n){
             ans = mid;
			 s= mid+1;
			}else{
				e=mid-1;
			}
		}
    cout<<ans<<endl;
	}
	return 0;
}\
