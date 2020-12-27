#include<bits/stdc++.h>
using namespace std;

string sub_string(string s,string p){
	int pl = p.length();
	int sl = s.length();
	if(pl>sl){
		return "No String";
	}
	//hash the pattern string
	int fp[256] = {0};
	int fs[256] = {0};
	
	for(int i=0;i<pl;i++){
		char ch = p[i];
		fp[ch]++;
	}
	int count = 0;
	int start = 0;
	int start_ind = -1;
	int min_win = INT_MAX;
	for(int i=0;i<sl;i++){
		char ch = s[i];
		fs[ch]++;
		if(fp[ch]!=0 and fs[ch]<=fp[ch]){
			count++;
		}

		if(count==pl){
			//shrink from front
			char temp;
			temp  = s[start];
			while(fp[temp]==0 or fs[temp]>fp[temp]){
				    fs[temp]--;
				start++;
				temp = s[start];
			}

			int window = i-start + 1;
			if(window < min_win){
				min_win = window;
				start_ind = start;
			}
		}

	}
	if(start_ind == -1){
		return "No String";
	}
	return s.substr(start_ind,min_win);
}


int main() {
	string s,p;
    getline(cin,s); 
	getline(cin,p); 
	cout<<sub_string(s,p);
	return 0;
}
