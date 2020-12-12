#include<iostream>
#include<stack>
using namespace std;


void place_temp(stack<int>&s,int temp){
	if(s.empty()){
		s.push(temp);
		return;
	}
	int t = s.top();
	s.pop();
	place_temp(s,temp);
	s.push(t);
	return;
}

void reverse(stack<int> &s){
	//base case
	if(s.size()==1){
      return;
	}
	//recursive case
	int temp = s.top();
	s.pop();
	reverse(s);
	place_temp(s,temp);
    return;
}
int main() {
	int n;
	cin>>n;
	stack<int> s;
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		s.push(temp);
	}
	reverse(s);
	while(!s.empty()){
		cout<<s.top()<<endl;
        s.pop();
	}
	return 0;
}
