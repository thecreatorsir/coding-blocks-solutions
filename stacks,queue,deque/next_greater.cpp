#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
int main() {
   int a[]={1,2,3};
   int n = sizeof(a)/sizeof(int);
   int arr[n];
   for(int i=0;i<n;i++){
       arr[i]=-1;
   }
   stack<int> s;
   for(int i=0;i<2*n;i++){ 
       while(!s.empty() and a[i%n]>a[s.top()]){
           arr[s.top()]=a[i%n];
           s.pop();
       }
       s.push(i%n);
   }
   for(int i=0;i<n;i++){
       cout<<arr[i]<<" ";
   } 
   return 0;
 }

