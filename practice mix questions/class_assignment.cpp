/*In a mathematics class, Teacher ask Alice to find the number of all n digit distinct integers 
which is formed by the two distinct digits ai and bi but there is a rule to form n digit integer.

Rule: She has to form n digit integer by using two digits ai and bi without consecutive bi.
*/

#include<iostream>
using namespace std;
int main() {
    int T;
    cin>>T;
    long long arr[26];
    arr[0]=1;
    arr[1]=2;
    for(int i=2;i<26;i++)
        arr[i]=arr[i-1]+arr[i-2];
    for(int i=1;i<=T;i++)
    {
        cout<<"#"<<i<<" : ";
        int N;
        cin>>N;
        cout<<arr[N]<<endl;
    }
	return 0;
}
