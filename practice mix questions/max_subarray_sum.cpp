#include<iostream>
using namespace std;

//using kadanes algo

int max_subarray_sum(int a[],int len){
	int total_sum = 0;
	int mx = 0;
	for(int i=0;i<len;i++){
			total_sum+=a[i];
		if(total_sum<0)
			total_sum = 0;
		mx = max(mx,total_sum);	
	}
	return mx;
}


int main(){
	
	int a[]={-4,1,3,-2,16,2,-8,-9,4};
	
	int l = sizeof(a)/sizeof(int);
	
	int sum = max_subarray_sum(a,l);
	cout<<sum<<endl;
	
	return 0;
}
