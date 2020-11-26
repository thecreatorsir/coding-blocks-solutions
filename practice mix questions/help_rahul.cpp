#include<bits/stdc++.h>
using namespace std;

int search_binary(int *a,int key,int n){
	int start = 0;
	int end = n-1;
	
	while(start<=end){
		int mid = (start+end)>>1;
		if(key == a[mid])
		 return mid;
		else if(a[start]<=a[mid]){
			if(key<=a[mid] and key>=a[start]){
				end = mid -1;
			}
			else{
				start = mid +1;
			}
		}
		else{
			if(key>=a[mid] and key<=a[end]){
				start = mid +1;
			}
			else{
				end = mid-1;
			}
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
int key;cin>>key;
cout<<search_binary(a,key,n)<<endl;
return 0;	
}


