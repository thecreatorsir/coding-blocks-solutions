#include<bits/stdc++.h>
using namespace std;
	int n,m;
void processed_matrix(int a[][100]){
	//col wise addition
	for(int i=n-1;i>=0;i--){
		for(int j=m-2;j>=0;j--){
			a[i][j] += a[i][j+1]; 
		}
	}
	//row wise addition
	for(int i=m-1;i>=0;i--){
		for(int j=n-2;j>=0;j--){
			a[j][i] += a[j+1][i]; 
		}
	}
}


int main(){
	

	cin>>n>>m;
	int a[100][100];
	for(int i=0;i<n;i++)
	  for(int j=0;j<m;j++)
	    cin>>a[i][j];
	    
	processed_matrix(a);  
	int mx = INT_MIN;
	for(int i=0;i<n;i++)
	  for(int j=0;j<m;j++)
	     mx = max(a[i][j],mx);
	     
	cout<<mx<<endl;     
	
return 0;	
}
