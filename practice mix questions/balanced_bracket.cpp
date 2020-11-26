#include<iostream>
using namespace std;

void solve(string op,int left_count,int right_count){
	if(left_count==0 and right_count==0){
		cout<<op<<endl;
		return;
	}

	if(left_count!=0){
			string op1 = op;
	op1.push_back('(');
	solve(op1,left_count-1,right_count);	
	}
	if(left_count<right_count){
	string op2 = op;
	op2.push_back(')');
	solve(op2,left_count,right_count-1);	
	}
	return;
}

int main(){
	
	int n;
    cin>>n;
    string op = "";
    solve(op,n,n);
	
}
