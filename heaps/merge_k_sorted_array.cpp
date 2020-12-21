#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class node{
public:
 ll data;
 ll aindex;
 ll eindex;
};

class compare{
public:
  bool operator()(node a,node b){
      return a.data > b.data;
  }
};

vector<ll> mergeKelements(vector<vector<ll> > arr){
     vector<ll> v;
     priority_queue <node,vector<node>,compare > pq;
     for(ll i=0;i<arr.size();i++){
        node n;
        n.data = arr[i][0];
        n.aindex = i;
        n.eindex = 0;
        pq.push(n);
     }
     while(!pq.empty()){
         node temp = pq.top();
         v.push_back(temp.data);
         pq.pop();
         temp.eindex++;
         if(temp.eindex < arr[temp.aindex].size()){
                node n;
                n.data = arr[temp.aindex][temp.eindex];
                n.aindex = temp.aindex;
                n.eindex = temp.eindex;
                pq.push(n);
         }
     }
return v;
}


int main() {
    ll k,n;
    cin>>k>>n;
    vector<vector<ll> > arr(k);
    for(ll i=0;i<k;i++){
        arr[i] = vector<ll>(n);
        for(ll j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
      vector<ll> v = mergeKelements(arr);
      for(auto x:v){
          cout<<x<<" ";
      }                       
return 0;
}

