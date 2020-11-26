#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int kadene_algo(int a[],int n){
int mx = INT_MIN;
	int sum = 0;
	for(int i=0;i<n;i++){
		sum += a[i];
		if(sum < 0)
		 sum = 0;
	 mx = max(mx,sum);	 
	}
	return mx;
}
int solve(int a[],int n){
	int candi1 = kadene_algo(a,n);
		int total=0;
	for(int i=0;i<n;i++){
		total+=a[i];
		a[i]=-a[i];
	}
	int candi2 = total + kadene_algo(a,n);
	return (candi1>candi2)?candi1:candi2;
}
int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<solve(a,n)<<endl;
	}
	return 0;
}

