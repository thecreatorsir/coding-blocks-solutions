#include<bits/stdc++.h>
using namespace std;
map<string,int>m;
void solver(int ip[],vector <int> op,int n,int target,int i){
	//base case
	if(target == 0){
      //print the op
      string s = "";
      //removing duplicates
      for(int k=0;k<op.size();k++){
      	s+=(op[k]-48);
	  }
      if(m.find(s)==m.end()){
      	 for(int k=0;k<op.size();k++){
		  cout<<op[k]<<" ";
	  }
	  cout<<endl;
	  }
	  m[s]++;
	  return;
	}
	
	if(i==n or target < 0 ){
		return;
	}
	
	
//	        recursive step
		    op.push_back(ip[i]);
		    target = target - ip[i];
	        solver(ip,op,n,target,i+1);
	        
//	        backtracking
	        target = target + ip[i];
	        op.pop_back();
	        solver(ip,op,n,target,i+1);
	   return;
}
int main() {
	int n;
	cin>>n;
	int ip[n];
	vector <int> op;
	for(int i=0;i<n;i++){
		cin>>ip[i];
	}
	sort(ip,ip+n);
	int target;
	cin>>target;
	solver(ip,op,n,target,0);
	return 0;
}
