#include <bits/stdc++.h>
using namespace std;

string match_pattern(string s,string pat){
    int PL = pat.length();
    int SL = s.length();
    //corner case
    if(PL > SL){
        return "None";
    }
    char FS[256] = {0};
    char FP[256] = {0};
    int cnt = 0;
    int start = 0;
    int min_window = INT_MAX;
    int start_index = -1;
    //hashing 
    for(int i=0;i<PL;i++){
        char ch = pat[i];
        FP[ch]++;
    }
    //iterating over the input string
    for(int i=0;i<SL;i++){
        char ch = s[i];
        FS[ch]++;

        //maintaining the count of the char matched
        if(FP[ch]!=0 and FS[ch]<=FP[ch]){
            cnt++;
        }
         
        if(cnt == PL){
            //start shrinking the window
            char temp = s[start];
            //if not present or present more the required the remove it
            while(FP[temp]==0 or FS[temp]>FP[temp]){
                FS[temp]--;
                start = start + 1;
                temp = s[start];
            }
            //after this loop i will get my widow
            int window_size = i - start + 1;
            if(window_size < min_window){
                min_window = window_size;
                start_index = start;
            }
        } 
    }
    if(start_index == -1){
        return "None";
    }
    string ans = s.substr(start_index,min_window);
    return ans;
}

int main() {
    string s("helloelo");
    string p("elo");
    cout<<match_pattern(s,p);
}
