#include<bits/stdc++.h>
using namespace std;

void filter_char(string s,int n){
	int j=0;
	while(n>0){
		int last_bit = (n&1);
		if(last_bit){
			cout<<s[j];
		}
		j++;
		n=n>>1;
	}
	cout<<" ";
}

void get_subset(string s){
	int n = s.length();
	for(int i=0;i<pow(2,n);i++){
		filter_char(s,i);
	}
}


int main() {
	string s;
	cin>>s;
	get_subset(s);
	return 0;
}
