#include<bits/stdc++.h>
using namespace std;

void replace_pi(char *a,int i){
	if(a[i]=='\0')
	 return;
	if(a[i]=='p' and a[i+1]=='i'){
		int j = i+2;
		while(a[j]!='\0')
		j++;
		while(j>=i+2){
			a[j+2]=a[j];
			j--;
		}
		a[i]='3';
		a[i+1]='.';
		a[i+2]='1';
		a[i+3]='4';
		replace_pi(a,i+4);
	} else{
		replace_pi(a,i+1);
	}
	return;
}

int main() {
	char c[1000];
	cin>>c;
	replace_pi(c,0);
	int i=0;
	while(c[i]!='\0'){
		cout<<c[i];
		i++;
	}
	return 0;
}
