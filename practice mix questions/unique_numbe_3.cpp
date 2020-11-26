#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,no;
	cin>>n;
	int c[64] ={0};
	
	//store values in c[]
	for(int i=0;i<n;i++){
		cin>>no;
		int j=0;
		while(no > 0){
			if(no&1)
			 c[j]++;
			j++;
			no = no>>1; 	
		}
	
	}

	//taking mod by number of digit repeated and coverting into an integer
	int ans=0,p = 1;

	for(int i=0;i<64;i++){
		c[i]=c[i]%3;
		ans += p*c[i];
		p=2*p;
	}
	cout<<ans<<endl;
	
	return 0;
}
