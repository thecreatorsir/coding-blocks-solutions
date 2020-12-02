#include<iostream>
#include<string>
using namespace std;
void duplicate_formatting(string &s,int i){
	if(s[i]=='\0'){
		return;
	}
	if(s[i]==s[i+1]){
		//insert at n-1
     s.insert(i+1,"*");
	}
	duplicate_formatting(s,i+1);
	return;
}

using namespace std;
int main() {
	string s;
	cin>>s;
	duplicate_formatting(s,0);
	cout<<s<<endl;
	return 0;
}
