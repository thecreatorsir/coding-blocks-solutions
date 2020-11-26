#include<bits/stdc++.h>
using namespace std;

void get_primes(int *p,int n){
	
	//make all the odd as prime
	for(int i=3;i<=n;i+=2){
		p[i]=1;
	}
	//if current odd number is marked as prime mark its all divisor as not prime
	for(int i=3;i<=n;i+=2){
		if(p[i]==1){
			for(int j=i*i;j<=n;j+=i){
				p[j]=0;
			}
		}
	}
	p[2] = 1;
	p[0]=p[1] = 0;
}


int main() {
	int n;
	cin>>n;
	int p[n]={0};
	get_primes(p,n);
	for(int i=0;i<=n;i++)
	if(p[i]==1)
	 cout<<i<<" ";
	return 0;
}
