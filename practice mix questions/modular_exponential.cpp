#include<iostream>
using namespace std;

int modular_exponentiation(int x,int y,int m){
	x=x%m;
	
	int res=1;
	
	while (y){
		if(y&1)
		    res= ( (res%m)*(x%m) )%m;
		x=( (x%m)*(x%m) )%m;
		y=y>>1;
	}

	return res;
}
int main() {
	int x,y;
	int m;
	cin>>x>>y;
	cin>>m;  

	cout<<modular_exponentiation(x,y,m)<<endl;

	return 0;
}
