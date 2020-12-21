#include<iostream>
#include<queue>
using namespace std;

int join_ropes(int *arr,int n){
	priority_queue<int,vector<int>,greater<int> > pq(arr,arr+n);
	int data = 0;
	while(pq.size() > 1){
		int A = pq.top();
		pq.pop();
		int B = pq.top();
		pq.pop();
		
		int new_node = A+B;
		data += new_node;
		pq.push(new_node);
	}
	return data;
}


int main(){
	int arr[] = {4,3,2,6};
	int n = sizeof(arr)/sizeof(int);
	cout<<join_ropes(arr,n);
	return 0;
}
