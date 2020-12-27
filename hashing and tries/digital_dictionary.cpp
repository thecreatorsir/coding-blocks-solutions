#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        char data;
       map<char,Node*> children;
        bool terminal;

        Node(char d){
            data = d;
            terminal = false;
        }
};

class Trie{
    public:
    Node* root;
    Trie(){
        root = new Node('\0');
    }

    void insert(string s){

        Node* temp = root;
        for(int i=0;i<s.length();i++){

            char ch = s[i];
            if(temp->children.count(ch)){
                temp = temp->children[ch];
            }
            else{
                Node* n = new Node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }
};

void print(Node *temp,string l){
    if(temp->children.empty()){
        cout<<l<<endl;
        return;
    }
    if(temp->terminal){
        cout<<l<<endl;
    }
    Node * x;
    string w;
    for(auto p=temp->children.begin();p!=temp->children.end();p++){
        x = temp->children[p->first];
        w = l + x->data;
        print(x,w);
    }
}

bool find(Node *root,string l){
        Node* temp = root;
        for(int i=0;i<l.length();i++){
            char ch = l[i];
            if(temp->children.count(ch)==0){
                return false;
            }
            else{
                temp = temp->children[ch];
            }
        }
        print(temp,l);
        return true;
}

int main(){
int n;
cin>>n;
 string s;
 Trie p;
 for(int i=0;i<n;i++){
     cin>>s;
     p.insert(s);
 }
 int q;
 cin>>q;
 while(q--){
     string t;
     cin>>t;
if(find(p.root,t)==false){
     cout<<"No suggestions"<<endl;
     p.insert(t);
 }
 }
 
return 0;    
}
