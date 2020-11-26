#include<iostream>
#include<algorithm>
using namespace std;

void rotate_90(int a[][100],int n){
	for(int i=0;i<n;i++){
			reverse(a[i],a[i]+n);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i>j){
				swap(a[i][j],a[j][i]);
			}
		}
	}
}

int main(){
	int a[100][100];
	int n = 3;
	int val = 0;
	for(int row = 0;row<n;row++){
		for(int col =0;col<n;col++){
		val=val+1;
		a[row][col] = val;
	}
	}
	
	rotate_90(a,n);
	 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	
}
