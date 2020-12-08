#include<iostream>
#include<bitset>
using namespace std;
bitset<20> col,dr,dl;

void solve(int board[][10],int n,int i,int &ans){
	//base case
	if(i==n){
		ans++;
		//print board
		for(int k=0;k<n;k++){
			for(int l=0;l<n;l++){
				cout<<board[k][l]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return;
	}
	//recursive case
	for(int j=0;j<n;j++){
		if(!col[j] and !dr[i+j] and !dl[i-j + n-1]){
			col[j] = dr[i+j] = dl[i-j + n-1] = board[i][j] = 1;
			solve(board,n,i+1,ans);
			//backtracking
			col[j] = dr[i+j] = dl[i-j + n-1] = board[i][j] = 0;
		}
	}
	return;	
}

int main(){
	int n;
	cin>>n;
	int ans = 0;
	int board[10][10]={0};
	solve(board,n,0,ans);
	cout<<ans<<endl;
	return 0;
}
