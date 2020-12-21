#include<iostream>
#include<vector>
using namespace std;

class heap{
	vector<int> v;
	bool minheap;
	bool compare(int a,int b){
		if(minheap){
			return a < b;
		}else{
			return a > b;
		}
	}
	void heapify(int idx){
	
		int left = 2*idx;
		int right = 2*idx+1;
		
		int min_idx = idx;
		int last = v.size()-1;
		
		if(left<=last and compare(v[left],v[idx])){
			min_idx = left;
		}	
		if(right<=last and compare(v[right],v[min_idx])){
			min_idx = right;
		}
		if(min_idx!=idx){
			swap(v[min_idx],v[idx]);
			heapify(min_idx);
		}
	}
		
	public:
		heap(int default_size=10,bool type=true){
			v.reserve(default_size);
			v.push_back(-1);
			minheap = type;
		}
		void push(int d){
			v.push_back(d);
			int idx = v.size()-1;
			int parent = idx/2;
			while(idx>1 and compare(v[idx],v[parent])){
				swap(v[idx],v[parent]);
				idx = parent;
				parent = parent/2;	
			}
		}
		int top(){
			return v[1];
		}
		void pop(){
			int last_idx = v.size()-1;
			swap(v[last_idx],v[1]);
			v.pop_back();
			heapify(1);
		}
		bool empty(){
			return v.size()==1;
		}
};

int main(){
	heap h(10,false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int no;
	cin>>no;
	h.push(no);	
	}
	while(!h.empty()){
		cout<<h.top()<<" ";
		h.pop();
	}
	return 0;
}
