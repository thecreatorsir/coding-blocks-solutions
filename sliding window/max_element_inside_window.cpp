#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	  cin>>a[i];
	
	int k;
	cin>>k;
	deque<int> Q(k);
	//process the first k elements
	int i = 0;
	for(i=0;i<k;i++){
		while(!Q.empty() and a[i]>a[Q.back()]){
				Q.pop_back();
		}
		Q.push_back(i);
	}
	
	//process next k elements
	for(;i<n;i++){
		cout<<a[Q.front()]<<" ";
		//remove the element from the front of the window when it moves forword
		while(!Q.empty() and i-k>=Q.front()){
			Q.pop_front();
		}
		//removing unessory element inside the window
		while(!Q.empty() and a[i]>a[Q.back()]){
			Q.pop_back();
		}
		//push_the current element
		Q.push_back(i);
	} 
	cout<<a[Q.front()]<<endl; 
	return 0;
}
