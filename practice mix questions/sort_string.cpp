#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool isSubstring(string s1, string s2) 
{ 
    int M = s1.length(); 
    int N = s2.length(); 
	//s1 is substring of s2?
    for (int i = 0; i <= N - M; i++) { 
        int j; 
        for (j = 0; j < M; j++) 
            if (s2[i + j] != s1[j]) 
                break; 
  
        if (j == M) 
            return true; 
    } 
  
    return false; 
}
bool cmp(string s1,string s2){
    //if s2 is substring of s1 and length of s1>s2 the s1 will come first
	if(isSubstring(s2,s1) || isSubstring(s1,s2))
	 return s1.length()>s2.length();
	 else
	  return s1<s2;
}
using namespace std;
int main() {
	int n;
	cin>>n;
	string s[n];
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	sort(s,s+n,cmp);
	for(int i=0;i<n;i++){
		cout<<s[i]<<endl;
	}
	return 0;
}
