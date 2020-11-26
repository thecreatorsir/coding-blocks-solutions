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

int convert_to_int(string s){
	int ans = 0;
	int p = 1;
	for(int i=s.length()-1;i>=0;i--){
		ans+= ((s[i]-'0')*p);
		p =p*10;
	}
	return ans;
}

bool numericCompare(pair<string,string> s1,pair<string,string> s2){
	string key1,key2;
	key1 = s1.second;
	key2 = s2.second;
	return convert_to_int(key1)<convert_to_int(key2);
}

bool lexicalCompare(pair<string,string> s1,pair<string,string> s2){
	string key1,key2;
	key1 = s1.second;
	key2 = s2.second;
	return key1<key2;
}
int main(){
    int n;
    cin>>n;
    cin.get();
	string s[100];
	for(int i=0;i<n;i++){
		getline(cin,s[i]);
	}

	int key;
	string reversed,ordering;
	cin>>key;
	cin.get();
	cin>>reversed;
	cin.get();//consuming enter 
	cin>>ordering;
	
	pair<string,string> strm[100];
	
	for(int i=0;i<n;i++){
		strm[i].first = s[i];
		strm[i].second = token(s[i],key);
	}
	
	
	if(ordering=="numeric"){
		sort(strm,strm+n,numericCompare);
	}
	else{
		sort(strm,strm+n,lexicalCompare);
	}
	
	if(reversed == "true"){
		for(int i=0;i<n/2;i++){
			swap(strm[i],strm[n-i-1]);
		}
	}
	for(int i=0;i<n;i++){
		cout<<strm[i].first<<endl;
	}
	return 0;
}
