#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>a,pair<int,int> b){
	return a.second < b.second;
}
int main() {
	int t;
	cin>>t;
	int x,y,n;
	while(t--){
		vector < pair <int,int> > vect;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>x>>y;
			vect.push_back(make_pair(x,y));
		}
		sort(vect.begin(),vect.end(),cmp);
		int count = 1,prev = 0; 
		for(int i=1;i<n;i++){
			if(vect[i].first >= vect[prev].second){
			 count++;
		     prev = i;
			 }
		}
		cout<<count<<endl;
	}
	return 0;
}
