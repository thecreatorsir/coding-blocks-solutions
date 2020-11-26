#include<bits/stdc++.h>
using namespace std;
bool is_one(int n,int pos){
	n = n>>pos;
	if(n&1)
	return true;
return false;	
}
int main(){
	int n;
	cin>>n;
	int a[n];
	int ans = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ans = ans^a[i];
	}
	int temp = ans;
	int pos = 0;
	
	while(temp > 0){
		if(temp&1)
		 break;
		pos++;
		temp>>1; 
	}
	int res = 0;
	for(int i=0;i<n;i++){
		if(is_one(a[i],pos)){
			res = res^a[i];
		}
	}
	int x = res;
	int y = res^ans;
    cout<<min(x,y)<<" "<<max(x,y)<<endl;
    return 0;
	
}
