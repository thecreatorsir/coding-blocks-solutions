#include<iostream>
using namespace std;

char keypad[][10]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void generate_names(int *ip,int *op,i,j){
	if(ip[i]=='\0'){
		op[j]='\0';
		cout<<op<<endl;
		return;
	}
	int temp = ip[i]-'0';
	for(int k=0;keypad[temp][k]!='\0';k++){
		op[j]=keypad[temp][k];
		//fill the remaining part
		generate_names(ip,op,i+1,j+1);
	}
	return;
}

int main(){
	char ip[100];
	cin>>ip;
	char op[100];
	
	generate_names(ip,op,0,0);
}
