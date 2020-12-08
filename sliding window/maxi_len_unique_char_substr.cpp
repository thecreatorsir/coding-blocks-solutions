#include<bits/stdc++.h>
using namespace std;
int main(){
	char a[]="babbbbb";
	int n = strlen(a);
	int curr_length = 1;
	int max_length =1;
	int visited[256];
	for(int i=0;i<256;i++){
		visited[i]=-1;
	}
	
	visited[a[0]]=0;
	for(int i=1;i<n;i++){
		int last_occur = visited[a[i]];
		//expantion
		if(last_occur==-1 or i-curr_length>last_occur){
			curr_length++;
		}
		//expantion and contraction
		else{
			curr_length=i-last_occur;
		}
		visited[a[i]]=i;
		max_length = max(max_length,curr_length);
	}
	cout<<max_length<<endl;
	
	return 0;
}



