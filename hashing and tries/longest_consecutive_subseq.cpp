#include <bits/stdc++.h>
using namespace std;

int largest_consecutive_seq_set(int *arr,int n){
unordered_set<int> s;
for(int i=0;i<n;i++){
  s.insert(arr[i]);
}
int max_len = 1;
for(int i=0;i<n;i++){
  int no = arr[i];
  if(s.find(no-1)==s.end()){
      //then the treak will begin
      int next_no = no+1;
      int len = 1;
      while(s.count(next_no)){
          next_no++;
        len++;
      }
    max_len = max(max_len,len);
  }
}
return max_len;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<largest_consecutive_seq_set(arr,n);
    return 0;
}
