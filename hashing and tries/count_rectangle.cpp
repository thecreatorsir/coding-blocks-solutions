#include <bits/stdc++.h>
using namespace std;

int count_rec(vector<pair<int,int> > v){
   set<pair<int,int> > s;
   for(auto p:v){
       s.insert(p);
   }
   int ans = 0;
   for(auto it=s.begin();it!=prev(s.end());it++){
    for(auto jt=next(it);jt!=s.end();jt++){
        pair <int,int> p1 = *it;
        pair <int,int> p2 = *jt;
        if(p1.first==p2.first or p1.second==p2.second){
            continue;
        }
         pair <int,int> p3 = make_pair(p1.first,p2.second);
        pair <int, int> p4 = make_pair(p2.first,p1.second);
        if(s.find(p3)!=s.end() and s.find(p4)!=s.end()){
          ans++;
        }
    }
   }
   return ans/2;
}


int main() {
    int n,x,y;
    cin>>n;
    pair<int,int> p;
    vector<pair<int,int> > v;
   for(int i=0;i<n;i++){
       cin>>x>>y;
       p = make_pair(x,y);
       v.push_back(p);
   }
   cout<<count_rec(v);
}
