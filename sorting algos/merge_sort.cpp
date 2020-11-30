#include<bits/stdc++.h>
using namespace std;

void merge(int *a,int s,int e){
	int mid = (s+e)>>1;
	int i=s;
	int j=mid+1;
	int k = s;
	int temp[1000];
	while(i<=mid and j<=e){
		if(a[i]<=a[j]){
			temp[k++]=a[i++];
		}else{
			temp[k++]=a[j++];	
		}
	}
	while(i<=mid){
			temp[k++]=a[i++];
	}
	while(j<=e){
			temp[k++]=a[j++];	
	}
	//copy the array
	
	for(int i=s;i<=e;i++){
		a[i]=temp[i];
	}
}

void merge_sort(int *a,int s,int e){
	//base case
	if(s>=e){
		return;
	}
	//devide array
	int mid = (s+e)>>1;
	
	//sort the array
	merge_sort(a,s,mid);
	merge_sort(a,mid+1,e);
	
	//merge the sorted two parts of array
	merge(a,s,e);
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	merge_sort(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
