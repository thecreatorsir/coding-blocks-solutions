#include<iostream>
using namespace std;

int solve(int **arr,int r,int c,int t){
	int smallest = arr[0][0], largest = arr[r - 1][c - 1]; 
    if (t < smallest || t > largest) 
        return 0; 
   int i=0;
   int j=c-1;
   while(i<r && j>	=0){
     if(arr[i][j]==t)
	  return 1;
	 else if(arr[i][j] < t)
	  i++;
	 else
	  j--;  
   }
   return 0;
}
int main() {
	int r,c,t;
	cin>>r>>c;
	int **arr = new int*[r];

	for(int i=0;i<r;i++){
		arr[i] = new int[c];
	}

	//taking input
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>arr[i][j];
		}
	}
	cin>>t;
	cout<<solve(arr,r,c,t)<<endl;
	return 0;
}
