#include<bits/stdc++.h>
using namespace std;
bool compare(int a,int b){
	return a<=b;
}
int main() {
	int a[] = {1,2,3,5,10,100,200,500,2000};
    int size = sizeof(a)/sizeof(int);
    int money = 160;
    while(money > 0){
    	int lb = lower_bound(a,a+size,money,compare)-a-1;
    	cout<<a[lb]<<" ";
    	money = money-a[lb];
	}
	return 0;
}
