//wall is 4xN and brickes will be if size(1,4) and size(4,1)


#include<iostream>
using namespace std;
int solve(int n){
	if(n<=3)
	 return 1;
	return solve(n-1)+solve(n-4); 
}

int main(){
	int n;
	cin>>n;
	cout<<solve(n)<<endl;
	return 0;
}
