#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 10000007
int p[MAX]={0};
int main() {
	ll n;
	cin>>n;
//make all the odd as prime
	for(ll i=3;i<MAX;i+=2){
		p[i]=1;
	}
	//if current odd number is marked as prime mark its all divisor as not prime
	for(ll i=3;i<MAX;i+=2){
		if(p[i]==1){
			for(ll j=i*i;j<MAX;j+=2*i){
				p[j]=0;
			}
		}
	
	}
	p[2] = 1;
	p[0]=p[1] = 0;
	
	vector <int> v;
	v.push_back(2);
	for(int i=3;i<MAX;i+=2){
		if(p[i]==1)
		v.push_back(i);
	}
	cout<<v[n-1]<<endl;
	return 0;
}
