#include<bits/stdc++.h>
using namespace std;

int search_binary(int *a,int n){
	int start = 0;
	int end = n-1;
	
	while(start<=end){
		int mid = (start+end)>>1;

		if(a[mid]>a[mid+1])
		 return mid;
		if(a[mid]<a[mid-1]){
			return mid - 1;
		}if(a[start]>=a[mid]){
			end = mid-1;
		}
		else{
			start = mid+1;
		}
		
	}
	return -1;
}

int main(){
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++){
	cin>>a[i];
}
cout<<search_binary(a,n)<<endl;
return 0;	
}


