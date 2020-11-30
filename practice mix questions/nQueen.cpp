#include<iostream>
using namespace std;

bool isPossible(int board[][10],int i,int j,int n){
	//cheak in the col
	for(int row=0;row<i;row++){
		if(board[row][j]==1){
			return false;
		}
	}
	//check for the right diagonal
	int x = i-1;
	int y = j+1;
	while(x>=0 and y<n){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y++;
	}
	//check for left diagonal
	
	x = i-1;
	y = j-1;
		while(x>=0 and y>=0){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y--;
	}
	return true;
}

bool nQueen(int board[][10],int i,int n){
	//base case
	if(i==n){
		//print the cofig 
		for(int k=0;k<n;k++){
			for(int l=0;l<n;l++){
				cout<<board[k][l]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return false;
	}

	//recursive case
	for(int j=0;j<n;j++){
		if(isPossible(board,i,j,n)){
			board[i][j] = 1;
			bool baakiRakhPaaye = nQueen(board,i+1,n);
			if(baakiRakhPaaye){
				return true;
			}
			//backtrack
			board[i][j]=0;
		}
	}
	//idhar ana matlb poori row me nahi rakh paaye
	return false;
}

int main(){
	int n;
	cin>>n;
	int board[10][10] = {0};
	bool ans = nQueen(board,0,n);
	if(!ans){
		cout<<"board should be larger the 4x4"<<endl;
	}	
}
