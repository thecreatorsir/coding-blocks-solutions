#include<iostream>
#include<vector>
using namespace std;
vector <int> v;
vector <int> prime_factor(int n){
	
	for(int i=2;i*i<n;i++){
		
		if(n%i==0){
			while(n%i==0){
				n = n/i;
			}
			v.push_back(i);
		}
	}
	if(n!=1){
		v.push_back(n);
	}
	return v;
}


int main(){
	int n;
	cin>>n;
	prime_factor(n);
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	return 0;
}
