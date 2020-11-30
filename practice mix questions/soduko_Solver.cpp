//rules
//no two numbers are same in both row and col and also in same grid of size sqrt(n)xsqrt(n)
//author shubham sharma

#include<iostream>
#include<cmath>
using namespace std;

bool isPossible(int soduko[][10],int n,int i,int j,int num){

	//check for the row and col
	for(int k=0;k<n;k++){
		if(soduko[k][j]==num or soduko[i][k]==num){
			return false;
		}
	}
	//check for the perticular grid
	int nq = sqrt(n);
	i = (i/nq)*nq;
	j = (j/nq)*nq;
	
	for(int x = i;x<i+nq;x++){
		for(int y=j;y<j+nq;y++){
			if(soduko[x][y]==num){
				return false;
			}
		}
	}
	return true;
	
}


bool soduko_solver(int soduko[][10],int n,int i,int j){
	//base case
	if(i==n){
		//print the solution
			for(int k=0;k<n;k++){
		for(int l=0;l<n;l++){
			cout<<soduko[k][l]<<" ";
		}
		cout<<endl;
	}
		return true;
	}
	//if the perticular row is treversed
	if(j >= n){
		return soduko_solver(soduko,n,i+1,0);
	}
	
	//check if current position is occpied
	if(soduko[i][j]!=0){
		return soduko_solver(soduko,n,i,j+1);
	}
	
	//check for the correct value at current position
	
	for(int num = 1;num<=9;num++){
		if(isPossible(soduko,n,i,j,num)){
		soduko[i][j] = num;
		bool ans_of_remaining_part = soduko_solver(soduko,n,i,j+1);
		// if answer of remaining part is true the return true to the main 
		//else check for other number at the current location
		if(ans_of_remaining_part){
			return true;
		}
	}
	}
	//if the no number at the current location is found then
	//backtack
	soduko[i][j] = 0;
	return false;
}

int main(){
	
	int soduko[10][10]={
	{0,3,0,0,8,9,6,0,2},
	{0,7,0,3,0,0,0,0,1},
	{2,9,0,0,0,0,0,7,0},
	{0,2,0,0,0,6,0,0,7},
	{4,0,3,8,0,7,1,0,9},
	{1,0,0,2,0,0,0,6,0},
	{0,1,0,0,0,0,0,9,4},
	{3,0,0,0,0,2,0,1,0},
	{8,0,9,5,7,0,0,3,0},
	};
	
	int n = 9;
	
	bool solve = soduko_solver(soduko,n,0,0);
	
	return 0;
}
