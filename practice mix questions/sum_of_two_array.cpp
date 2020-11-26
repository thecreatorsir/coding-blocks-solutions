#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	int m;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	cin>>m;
    int b[m];
	for(int i=0;i<m;i++)
	cin>>b[i];

    string s = "";
    
	int carry = 0;
    int sum = 0;
	int i= n-1;int j=m-1;
    string temp;
    
	while(i>=0 and j>=0){
		sum = (a[i] + b[j] + carry)%10;
		carry =  (a[i] + b[j] + carry)/10;
		temp = sum + 48;
		s+=temp;
		i--;j--;
	}
    while(i>=0){
		if(carry!=0){
			sum = (a[i]+carry)%10;
			carry = (a[i]+carry)/10;
			temp = sum + 48;
			s+=temp;
		}
		else{    temp = a[i] + 48;
				s+=temp;
		}
		i--;
	}
	while(j>=0){
		if(carry!=0){
			sum = (b[j]+carry)%10;
			carry = (b[j]+carry)/10;
			  	temp = sum + 48;
			s+=temp;
		}
		else{
			temp = b[j] + 48;
			s+=temp;
		}
		j--;
	}
		if(carry!=0){
					temp = carry + 48;
			         s+=temp;
		}
		reverse(s.begin(),s.end());
		for(int k=0;k<s.length();k++){
			cout<<s[k]<<", ";
		}
	    cout<<"END"<<endl;
		return 0;
}
