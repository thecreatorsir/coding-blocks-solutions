#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
void selection_sort(int *a,int n,bool(&cmp)(int a,int b)){
 for(int i=0;i<n-1;i++){
 	int min_ind = i;
 	for(int j=i+1;j<n;j++){
 		if(cmp(a[min_ind],a[j]))
 		 min_ind = j;
	 }
	 if(min_ind!=i)
	 swap(a[i],a[min_ind]);
 }
}

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	selection_sort(a,n,cmp);
	for(int i=0;i<n;i++)
	 cout<<a[i]<<endl;
	return 0;
}
