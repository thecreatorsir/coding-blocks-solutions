#include<iostream>
using namespace std;

bool ispalindrome(int *a,int n,int left,int right){
	if(n<=0)
	 return true;
	if(a[left]==a[right])
		return ispalindrome(a,n-2,left+1,right-1); 
	else
	 return false;
}
int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	 cin>>a[i];
	(ispalindrome(a,n,0,n-1))?cout<<"true":cout<<"false"; 
	return 0;
}
