#include<iostream>
using namespace std;

//function for count and all possible cases
bool rat_in_maze(char maze[10][10],int soln[][10],int i,int j,int m,int n,int &count){
	//base case
	if(i==m && j==n){
		soln[m][n]=1;
        count++;
		//print the sol;
		for(int k=0;k<=m;k++){
			for(int l=0;l<=n;l++){
				cout<<soln[k][l]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return true;
	}
	//several edge cases
	//if rat will come outof the maze in between
	if(i>m || j>n)
	 return false;
	//if the path is blocked
	if(maze[i][j]=='X')
	  return false;
	
	//let the current cell has a path included to it and check for the left and right side
	//if both are false the backtrack by making it 0
	soln[i][j]=1;
	bool rightside = rat_in_maze(maze,soln,i,j+1,m,n,count);
	bool downside = rat_in_maze(maze,soln,i+1,j,m,n,count);
	
	//backtracking
	soln[i][j]=0; 
	
	//ye backtracking k niche kyon
	if(rightside || downside)
	 return true;
	
	
	return false;    
}



//for single path
bool rat_in_maze_single(char maze[10][10],int soln[][10],int i,int j,int m,int n){
	//base case
	if(i==m && j==n){
		soln[m][n]=1;
		//print the sol;
		for(int k=0;k<=m;k++){
			for(int l=0;l<=n;l++){
				cout<<soln[k][l]<<" ";
			}
			cout<<endl;
		}
		return true;
	}
	//several edge cases
	//if rat will come outof the maze in between
	if(i>m || j>n)
	 return false;
	//if the path is blocked
	if(maze[i][j]=='X')
	  return false;
	
	//let the current cell has a path included to it and check for the left and right side
	//if both are false the backtrack by making it 0
	soln[i][j]=1;
	if(rat_in_maze_single(maze,soln,i,j+1,m,n)){
		return true;
	}
	else if(rat_in_maze_single(maze,soln,i+1,j,m,n)){
	return true;
	}

	//backtracking
	soln[i][j]=0;
	
	return false;    
}


int main(){
	
	char maze[10][10] = {
	                   "0000",
	                   "00X0",
	                   "000X",
	                   "0X00",
	};
	int m = 4;
	int n = 4;
	int count = 0;
	int soln[10][10] = {0}; 
	
	bool ans = rat_in_maze(maze,soln,0,0,m-1,n-1,count);
	if(!ans){
		cout<<"path not found"<<endl;
	}
    
    cout<<"number of paths "<<count<<endl;
    
    bool ans2 = rat_in_maze_single(maze,soln,0,0,m-1,n-1);
		if(!ans2){
		cout<<"path not found"<<endl;
	}
	return 0;
}
