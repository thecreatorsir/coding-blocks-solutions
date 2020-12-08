#include<iostream>
using namespace std;
class queue {
	private:
		int *arr;
		int cs,ms,f,r;
	
	public:
	queue(int ds = 5){
		arr = new int[ds];
		ms=ds;
		cs=0;
		f=0;
		r=ms-1;
	}
	bool full(){
		return cs==ms;
	}
	bool empty(){
		return cs==0;
	}
	void push(int data){
		if(!full()){
		   r = (r+1)%ms;
		   arr[r]=data;
		   cs++;	
		}
	}
	void pop(){
		if(!empty()){
			f=(f+1)%ms;
			cs--;
		}
	}
	
int front(){
	return arr[f];
}
		
};

int main(){
	queue q;
	q.push(2);
	q.push(5);
	q.push(7);
	q.push(19);
	q.push(3);
	cout<<q.front()<<" ";
	q.pop();
   cout<<q.front()<<" ";

	q.push(100);
	cout<<q.front()<<" ";
	
	while(!q.empty()){
	cout<<q.front()<<" ";
	q.pop();	
	}
	return 0;
}
