#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<string,int> a,pair<string,int> b){
	if(a.second==b.second)
	 return b.first > a.first;
	return a.second > b.second;
}
int main() {
	int n,x;
	cin>>x>>n;
	pair<string,int> s[n];
	string name;
	int sal;
	for(int i=0;i<n;i++){
		cin>>name;
		cin.get();
		cin>>sal;
		s[i] = make_pair(name,sal);
	}
	sort(s,s+n,cmp);
	for(int i=0;i<n;i++){
		if(s[i].second>=x)
		cout<<s[i].first<<" "<<s[i].second<<endl;
	}
	return 0;
}
