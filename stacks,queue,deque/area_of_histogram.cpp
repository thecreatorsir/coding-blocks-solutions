#include<bits/stdc++.h>
#include<stack>

#define ll long long int
using namespace std;
 
stack<ll> s;
ll getMaxArea(ll a[],ll n)
{   ll ans;
    ll max_ans = 0; 
    ll i;  
    for(i=0;i<n;i++){
        while(!s.empty() and a[s.top()]>a[i]){
            ll top=s.top();
            s.pop();
            ans=(s.empty())?a[top]*i:a[top]*(i-s.top()-1);
               if(ans>max_ans){
                 max_ans = ans;
        }
        }
        s.push(i);
    }
    while (!s.empty())
    {   ll top=s.top();
        s.pop();
        ans=(s.empty())?a[top]*i:a[top]*(i-s.top()-1);
        if(ans>max_ans){
            max_ans = ans;
        }
    }
 
    return max_ans;
}
 
int main(){
    ll n;
    cin>>n;
    
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<getMaxArea(a, n);
}
