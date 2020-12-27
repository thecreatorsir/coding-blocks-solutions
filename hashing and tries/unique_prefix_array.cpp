//https://ide.codingblocks.com/s/393985

#include <iostream>
#include<unordered_map>
using namespace std;

class Node{
    public:
        char data;
        int freq;
        unordered_map<char,Node*> children;
        bool terminal;

        Node(char d){
            data = d;
            freq = 1;
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
                temp->freq++;
            }
            else{
                Node* n = new Node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }

    void prefix(char *w){
        Node* temp = root;
        string s = " ";
        for(int i=0;w[i]!='\0';i++){
            char ch = w[i];
            temp = temp->children[ch];
            s.push_back(ch);
           if(temp->freq == 1){
                cout<<s<<" ";
                break;
            }
    }
     //corner case
            if(temp->terminal and temp->freq > 1){
                cout<<"-1"<<" ";
            }
    }
};

int main(){
 char word[][10] = {"cobra","d","hello","apple","holy","diwali","cobras"};
 Trie p;
 for(int i=0;i<7;i++){
     p.insert(word[i]);
 }
 for(int i=0;i<7;i++){
     p.prefix(word[i]);
 }
return 0;    
}

