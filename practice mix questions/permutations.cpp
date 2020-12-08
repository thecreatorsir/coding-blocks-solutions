#include<iostream>
#include<algorithm>
using namespace std;

void permutations(char *ip,int i){
	//recursive call
	if(ip[i]=='\0'){
		cout<<ip<<endl;
		return;
	}
	//recursive call
	for(int k=i;ip[k]!='\0';k++){
		swap(ip[i],ip[k]);
		permutations(ip,i+1);
		//backtracking to restore the original array
		swap(ip[i],ip[k]);
	}
	return;
}

int main(){
	char ip[10] = "abc";
	permutations(ip,0);
	return 0;
}
