#include<bits/stdc++.h>
using namespace std;

bool possibe(int *a,int st,int c,int mid){
	int last_cow = a[0];
	int count = 1;
    for(int i=1;i<st;i++){
    	if(a[i]-last_cow>=mid){
    		last_cow = a[i];
    		count++;
    		if(count==c){
    			return true;
			}
		}
	}
	return false;
}

int aggrc(int *a,int st,int c){
	int s = 0;
	int e = a[st-1]-a[0];
	int ans = INT_MAX;
	while(s<=e){
		int mid = (s+e)>>1;
		if(possibe(a,st,c,mid)){
			ans = mid;
			s=mid+1;
		}else{
			e=mid-1;
		}
	}
	return ans;
}

int main(){
	int st,c;
	cin>>st>>c;
	int a[st];
	for(int i=0;i<st;i++)
	 cin>>a[i];
	sort(a,a+st);
	cout<<aggrc(a,st,c)<<endl; 

}
