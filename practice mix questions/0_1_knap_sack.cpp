#include<iostream>
#include<algorithm>
using namespace std;

int knap_sack(int *w,int *price,int n,int c){
	if(n==0 or c==0)
	 return 0;
	
	int inc =0;
	if(c>=w[n-1])
	inc = price[n-1]+knap_sack(w,price,n-1,c-w[n-1]);
	int exc =  knap_sack(w,price,n-1,c);
	
	return max(inc,exc);
}

int main(){
int w[] = {1,2,3,5};
int price[]={40,200,30,100};
int N = 4;
int C = 6;
cout<<knap_sack(w,price,N,C)<<endl;
	
	return 0;
}
