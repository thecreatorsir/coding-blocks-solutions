#include<iostream>
#include<algorithm>
using namespace std;

int lb(int *a,int n,int key){
	if(binary_search(a,a+n,key))
	return lower_bound(a,a+n,key)-a;;
return -1;
}
int ub(int *a,int n,int key){
	if(binary_search(a,a+n,key))
	return upper_bound(a,a+n,key)-a-1;;
return -1;
}


int main() {
	int n;
	cin>>n;
    int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
    int q;
	cin>>q;
	while(q--){
		int key;
		cin>>key;
		cout<<lb(a,n,key)<<" "<<ub(a,n,key)<<endl;
	}
	return 0;
}
