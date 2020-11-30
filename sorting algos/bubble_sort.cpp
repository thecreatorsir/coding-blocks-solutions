#include<bits/stdc++.h>
using namespace std;
void sort(int a[],int n,int j){
	if(n==1){
		return;
	}
	//first round is over
	if(j==n-1){
	 return	sort(a,n-1,0);
	}
	if(a[j]>a[j+1])
	swap(a[j],a[j+1]);
	
	sort(a,n,j+1); 
}
void display(int a[],int n,int i){
  if(n==0)
  return;
  cout<<a[i]<<" ";
  display(a,n-1,i+1);	
}

int main(){
   int n;
  cin>>n;
  int a[n];
  printf("enter the elements of array\n");
  for(int i=0;i<n;i++){
  	cin>>a[i];
  }
  sort(a,n,0);
  display(a,n,0);
	return 0;
}
