#include<iostream>
#include<algorithm>
using namespace std;

int partition(int *a,int s,int e){
	int i = s-1;
	int j = s;
	int p = a[e];
	for(;j<=e-1;j++){
		if(a[j]<=p){
			//move it to smaller region else to lager region
			i = i+1;
			swap(a[i],a[j]);
		}
	}
	//moving the pivot element at the correct postion
	swap(a[i+1],a[e]);
	return i+1;
}


void quick_sort(int *a,int s,int e){
	if(s>=e)
	 return;
	 
	 //it will return the index of pivot element
	int p = partition(a,s,e);
	
    quick_sort(a,s,p-1);
	quick_sort(a,p+1,e); 
}


int main(){
	int a[]={3,6,4,1,2};
	int n = sizeof(a)/sizeof(int);
	
	quick_sort(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
