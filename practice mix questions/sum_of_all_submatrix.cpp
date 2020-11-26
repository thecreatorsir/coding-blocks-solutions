#include<bits/stdc++.h>
using namespace std;
int submatrix_sum(int n,int m,int a[][100]){
	int sum = 0;
	for(int i=0;i<n;i++)
	  for(int j=0;j<m;j++){
	  	int weight = (i+1)*(j+1)*(n-i)*(m-j);
	  	sum += a[i][j]*weight;
	  }
	  return sum;
}


int main(){
    int n,m;
	cin>>n>>m;
	int a[100][100];
	for(int i=0;i<n;i++)
	  for(int j=0;j<m;j++)
	    cin>>a[i][j];    
	cout<<submatrix_sum(n,m,a)<<endl;
return 0;	
}
