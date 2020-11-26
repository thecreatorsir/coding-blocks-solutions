#include <iostream>
using namespace std;
// #define MAX 10000
 int multiply(int *res,int x, int res_size)
{   long long int carry=0,prod;
    for(int i=0;i<res_size;i++)
{
    prod=res[i]*x+carry;
    res[i]=prod%10;
    carry=prod/10;
}
while(carry)
{
    res[res_size]=carry%10;
    carry=carry/10;
    res_size++;
}
return res_size;
}
// void fact(int n){
//      int res[MAX]; 
// 	 int res_size=1;
//      res[0]=1;
//    for (int x=2;x<=n;x++) 
//         res_size=multiply( res, x,res_size);  
//     for (int i=res_size-1;i>=0;i--) 
//         cout<<res[i]; 
// }

int main() {
     int n;
     cin>>n;
	//  fact(n);
     int res[10000]; 
	 int res_size=1;
     res[0]=1;
   for (int x=2;x<=n;x++) 
        res_size=multiply( res, x,res_size);  
    for (int i=res_size-1;i>=0;i--) 
        cout<<res[i]; 
    return 0;
}

