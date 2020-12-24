#include <bits/stdc++.h>
using namespace std;

int longest_subarray_with_k_sum(int *arr,int n,int k){
unordered_map<int,int> m;
int len = 0;
int pre = 0;
for(int i=0;i<n;i++){
   pre += arr[i];
   if(pre==k){
       len = max(len,i+1);
   }else if(m.find(pre-k)!=m.end()){
       len=max(len,i-arr[pre-k]);
   }else{
       //store the first occurence
       m[pre]=i;
   }
}
return len;
}

int main() {
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<longest_subarray_with_k_sum(arr,n,k);
    return 0;
}
