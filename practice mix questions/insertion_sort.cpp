#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
void insertion_sort(int *a,int n,bool(&cmp)(int a,int b)){
 for(int i=1;i<n;i++){
 	int j=i-1;
 	int e = a[i];
 	while(j>=0 and cmp(a[j],e)){
 		a[j+1] = a[j];
 		j--;
	 }
	 a[j+1] = e;
 }
}

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	insertion_sort(a,n,cmp);
	for(int i=0;i<n;i++)
	 cout<<a[i]<<endl;
	return 0;
}
