#include<iostream>
#include<string>
using namespace std;

string solve(string a){
	if(a.length()==0){
		return "";
	}
	char ch = a[0];
	string temp = a.substr(1);
	string res = solve(temp);
	
	if(ch=='x'){
	return res + ch;
	}else{
		return ch + res;
	}
}
int main() {
	string a;
	cin>>a;
	cin.get();
	cout<<solve(a);

	return 0;
}
