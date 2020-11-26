#include<bits/stdc++.h>
using namespace std;

int find(char *c,int n){
	return n==0?0:find(c,n-1)*10+(c[n-1]-'0');
}

int main() {
	char c[] = "1754";
	int n = strlen(c);
	cout<<find(c,n)<<endl;
	return 0;
}
