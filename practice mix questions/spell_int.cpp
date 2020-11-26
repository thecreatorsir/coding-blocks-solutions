#include<iostream>
using namespace std;
char w[][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
void find(int n){
	if(n==0)
	  return;
	int temp = n%10;
	find(n/10);
	cout<<w[temp]<<" ";
}
int main(){          
	int n;
	cin>>n;
	find(n);
}
