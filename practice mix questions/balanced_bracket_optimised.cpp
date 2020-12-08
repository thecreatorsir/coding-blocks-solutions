#include<iostream>
using namespace std;
void solver(int cnt,string op,int cr,int cl){
	//base case
	if(cr==cnt){
		cout<<op<<endl;
		return;
	}
	//recursive step
    if(cl>cr){
	        solver(cnt,op+')',cr+1,cl);
	}	
	if(cl<cnt){
			solver(cnt,op+'(',cr,cl+1);
	}
	return;
}
int main() {
	int n;
	cin>>n;
	string op="";
	solver(n,op,0,0);
	return 0;
}
