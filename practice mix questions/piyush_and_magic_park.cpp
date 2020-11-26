#include<iostream>
using namespace std;
void solve(char **arr,int n,int m,int key,int &s){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s < key)
			 return;
			else if(arr[i][j]=='.')
			 s-=2;
			else if(arr[i][j]=='*')
			 s+=5;
			else if(arr[i][j]=='#')
			 break;
			if(j!=m-1) 
			 s--;    
		}
	}
}
int main() {
    int n,m,key,s;
	cin>>n>>m>>key>>s;
	char **arr = new char*[n];
	for(int i=0;i<n;i++){
		arr[i] = new char[n]; 
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
           cin>>arr[i][j];
		}
	}
	solve(arr,n,m,key,s);
	if(s > key){
		cout<<"Yes"<<endl;
		cout<<s<<endl;
	}else{
		cout<<"No"<<endl;
	}

	return 0;
}
