#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

string token(string s,int key){
	
	char * p = strtok((char*)s.c_str()," ");
	while(key>1){
		p = strtok(NULL," ");
		key--;
	}
	return (string)p;
}

int main(){
	int key;
	cin>>key;
	cin.get();
	string s;
	getline(cin,s);
	
	cout<<token(s,key);
	
}
