#include<iostream>
#include<algorithm>
using namespace std;

void sorrt(int *a,int n){
	int l,mid=0,h=n-1;
	while(mid<=h){
		if(a[mid]==0){
		 swap(a[mid],a[l]);
		mid++;l++;
		}
		else if(a[mid]==1)
		mid++;
		else{
         swap(a[mid],a[h]);
		 h--;
		 }
	}
}
int main() {
	int n;
	cin>>n;
    int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	sorrt(a,n);
	for(int i=0;i<n;i++)
	cout<<a[i]<<endl;
	return 0;
}
