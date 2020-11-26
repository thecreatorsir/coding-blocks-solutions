#include<iostream>
#include<algorithm>
using namespace std;

int partition(int *a,int s,int e){
	int i = -1;
	int j = s;
	int p = a[e];
	for(j=s;j<=e-1;j++){
		if(a[j]<=p){
			//move it to smaller region else to lager region
			i = i+1;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[j]);
	return i+1;
}


void quick_sort(int *a,int s,int e){
	if(s>=e)
	 return;
	int p = partition(a,s,e);
	return quick_sort(a,s,p-1);
	return quick_sort(a,p+1,e); 
}


int main(){
	int a[]={5,9,2,6,3,9};
	int n = sizeof(a)/sizeof(int);
	
	quick_sort(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
