#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
stack<char> s;

bool isBalanced(char *a,int i){
    //base case
    if(a[i]=='\0'){
        if(s.empty()){
            return true;
        }else{
            return false;
        }
    }
    //recusrive case
    if(a[i]=='{' or a[i]=='[' or a[i]=='('){
        s.push(a[i]);
        return isBalanced(a,i+1);
    }else{
        if(!s.empty()){
            if(s.top()=='{' and a[i]=='}')
               s.pop();
            else if(s.top()=='[' and a[i]==']')
               s.pop();
            else if(s.top()=='(' and a[i]==')')
               s.pop();      
            else
                s.push(a[i]);
        }else{
            s.push(a[i]);
        }
        return isBalanced(a,i+1);
    }
}

int main() {
   char a[100000];
   cin>>a;
   if(isBalanced(a,0)){
       cout<<"Yes";
   }else{
       cout<<"No";
   }
   return 0;
 }

