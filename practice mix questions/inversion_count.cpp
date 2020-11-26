#include<bits/stdc++.h>
using namespace std;

int merge(int *a,int s,int e){
	int mid = (s+e)>>1;
	int i=s;
	int j=mid+1;
	int k = s;
	int temp[1000];
	int count = 0;
	while(i<=mid and j<=e){
		if(a[i]<=a[j]){
			temp[k++]=a[i++];
		}else{
			temp[k++]=a[j++];
			count+=mid - i + 1;	
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
	return count;
}

int inversion_count(int *a,int s,int e){
	//base case
	if(s>=e){
		return 0;
	}
	//devide array
	int mid = (s+e)>>1;
	
	//sort the array
	int x = inversion_count(a,s,mid);
	int y = inversion_count(a,mid+1,e);
	
	//merge the sorted two parts of array
	int z = merge(a,s,e);
	return x+y+z;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<inversion_count(a,0,n-1)<<endl;

}
