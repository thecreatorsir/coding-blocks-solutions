#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
stack<int> s;

void span(int a[],int n,int arr[]){
    s.push(0);
    arr[0]=1;
    for(int i=1;i<n;i++){
          while(!s.empty() and a[i]>=a[s.top()])
              s.pop();
          
          if(!s.empty())
            arr[i]=i-s.top();
          else
          	arr[i]=i+1;
         
		s.push(i);  	
        }
}
    

int main() {
   int n;
   cin>>n;
   int a[n];
   int arr[n]={0};
   for(int i=0;i<n;i++){
       cin>>a[i];
   }

   span(a,n,arr);
   for(int i=0;i<n;i++){
       cout<<arr[i]<<endl;
   }
   return 0;
 }

