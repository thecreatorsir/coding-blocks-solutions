#include<iostream>
#include<vector>	
using namespace std;
	void heapify(vector<int> &v,int idx){
	
		int left = 2*idx;
		int right = 2*idx+1;
		
		int max_idx = idx;
		int last = v.size()-1;
		
		if(left<=last and v[left] > v[idx]){
			max_idx = left;
		}	
		if(right<=last and v[right] > v[max_idx]){
			max_idx = right;
		}
		if(max_idx!=idx){
			swap(v[max_idx],v[idx]);
			heapify(v,max_idx);
		}
}

void buildHeapFromArrayOptimized(vector<int> &v){
	for(int i=v.size()-1/2;i>=1;i--){
		heapify(v,i);
	}
}

int main(){
	vector<int> v{-1,10,20,5,6,1,8,9,4};
	buildHeapFromArrayOptimized(v);
	for(auto x:v){
		cout<<x<<" ";
	}
	return 0;
}
