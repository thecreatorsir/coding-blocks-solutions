#include<iostream>
using namespace std;
#define ll long long int 
#define MAX 10000007

int p[MAX]={0};
int count[MAX]={0};

int main() {
	int n;
	cin>>n;

 for(ll i=3;i<MAX;i+=2){
	 p[i]=1;
 }
 for(ll i=3;i<MAX;i+=2){
	 if(p[i]==1){
	  for(ll j=i*i;j<MAX;j+=2*i){
		  p[j]=0;
	  }
}
}   
     p[2]=1;
 	p[0]=p[1]=0;
    
	
	for(ll i=1;i<MAX;i++){
		count[i]=count[i-1]+p[i];
	}
	while(n--){
	ll a,b;
	cin>>a>>b;
	cout<<count[b]-count[a-1]<<endl;
	}

	return 0;
}
