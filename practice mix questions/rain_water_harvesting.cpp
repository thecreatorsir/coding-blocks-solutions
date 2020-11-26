#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;


int solve(int a[],int n){
	int ans = 0;
	int leftmax[n];
    int rightmax[n];

//filling leftmax
leftmax[0] = a[0];
for(int i=1;i<n;i++)
	leftmax[i] = max(leftmax[i-1],a[i]);


//filling rightmax
rightmax[n-1] = a[n-1];
for(int i=n-2;i>=0;i--)
    rightmax[i] = max(a[i],rightmax[i+1]);
	for(int i = 1;i<n-1;i++ ){
		int current = a[i];
		int leftmx = leftmax[i];
		int rightmx = rightmax[i];
		ans += min(leftmx,rightmx)-current;
	}
	return ans;
}

int main() {

int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
 cin>>a[i];
cout<<solve(a,n)<<endl;
	return 0;
}
