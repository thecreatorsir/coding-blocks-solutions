#include<iostream>
#include<cstring>
using namespace std;

void remove_duplicates(char a[]){
	int prev = 0;
	for(int curr=1;curr<strlen(a);curr++){
		if(a[curr]!=a[prev]){
			prev = prev +1;
	        a[prev] =a[curr];	
	}
	}
	a[prev+1]='\0';
}

int main(){
	char a[100];
	cin>>a;
	
	remove_duplicates(a);
	
	cout<<a<<endl;
}
