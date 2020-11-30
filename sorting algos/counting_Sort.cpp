#include<bits/stdc++.h>
using namespace std;
void counting_sort(int *a,int n){
int max = *max_element(a,a+n);
int key = max+1;
int count[key] = {0};

//filling count array
for(int i=0;i<n;i++){
	count[a[i]]++;
}

//upading count array
for(int i=1;i<key;i++){
	count[i]+=count[i-1];
}

//making sorted temp array
int b[n]={0};
for(int i=n-1;i>=0;i--){
	b[count[a[i]]-1]=a[i];
	count[a[i]]--;
}

//copy in original array
for(int i=0;i<n;i++){
	a[i]=b[i];
}
}

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	counting_sort(a,n);
	for(int i=0;i<n;i++)
	 cout<<a[i]<<endl;
	return 0;
}
