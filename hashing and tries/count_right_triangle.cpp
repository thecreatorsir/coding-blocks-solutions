#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,x,y;
    cin>>n;
    vector < pair<int,int> > v;
    pair<int,int> p;
  
    for(int i=0;i<n;i++){
          cin>>x>>y;
        p = make_pair(x,y);
        v.push_back(p);
    }
    // hashing
    map<int, int> x_map;
    map<int, int> y_map;
    for(int i=0;i<v.size();i++){
        x_map[v[i].first]++;
        y_map[v[i].second]++;
    }
    int count = 0;
    // iterate to cheak if for the given point triangle is possible or not
    for(int i=0;i<v.size();i++){
        int x_count = x_map[v[i].first];
        int y_count = y_map[v[i].second];
        count += (x_count-1)*(y_count-1);
    }
    cout<<count<<endl;
    return 0;
}

