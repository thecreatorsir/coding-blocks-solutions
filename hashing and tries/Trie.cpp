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
    Node* root;
    public:

    Trie(){
        root = new Node('\0');
    }

    void insert(char *w){

        Node* temp = root;
        for(int i=0;w[i]!='\0';i++){

            char ch = w[i];
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

    bool find(char *w){
        Node* temp = root;
        for(int i=0;w[i]!='\0';i++){
            char ch = w[i];
            if(temp->children.count(ch)==0){
                return false;
            }
            else{
                temp = temp->children[ch];
            }
        }
        return temp->terminal;
    }
};

int main(){
 char word[][10] = {"a","hello","apple","holy","diwali","lodu"};
 Trie p;
 char w[10];
 cin>>w;
 for(int i=0;i<6;i++){
     p.insert(word[i]);
 }
 if(p.find(w)){
     cout<<"Present"<<endl;
 }else{
     cout<<"Absent"<<endl;
 }
return 0;    
}

