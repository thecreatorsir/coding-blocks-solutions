#include<bits/stdc++.h>
using namespace std;

void string_generator(char *ip,char *op,int i,int j){
	//base case
	if(ip[i]=='\0'){
		op[j]='\0';
		cout<<op<<endl;
		return;
	}
	//recursive call for single term
	int one_term = ip[i]-'0';
	op[j]=one_term + 'A' - 1;
	string_generator(ip,op,i+1,j+1);
	//recursive call for two terms
	if(ip[i+1]!='\0'){
	int two_term = one_term*10 + (ip[i+1]-'0');
	if(two_term<=26){
		op[j]=two_term + 'A' - 1;
	    string_generator(ip,op,i+2,j+1);	
	}
}
	return;
}

int main(){
	char ip[100];
	cin>>ip;
    char op[100];
    string_generator(ip,op,0,0); 
	return 0;
}

