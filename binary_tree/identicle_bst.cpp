#include<iostream>
using namespace std;
class Node{
public:
int data;
Node * left;
Node * right;
Node(int d){
	data=d;
	left=NULL;
	right=NULL;
}

}; 

 Node* createTree(Node* root){
    int d;
    cin>>d;
    root=new Node(d);
    string x;
    cin>>x;
    if(x=="true"){
        root->left=createTree(root->left);
    }
    cin>>x;
    if(x=="true"){
        root->right=createTree(root->right);
    }
    return root;
 }

 bool isIdenticle(Node * root1,Node*root2){
  if(root1==NULL and root2==NULL){
	  return true;
  }
  else if(root1==NULL and root2!=NULL){
	  return false;
  }else if(root1!=NULL and root2==NULL){
	  return false;
  }else{
	  return (root1->data==root2->data and isIdenticle(root1->left,root2->left) and isIdenticle(root1->right,root2->right));
  }
 }

int main() {
	Node *root1=NULL;
	Node *root2=NULL;
	root1 = createTree(root1);
	root2 = createTree(root2);
	if(isIdenticle(root1,root2)){
		cout<<"true"<<endl;
	}else{
		cout<<"false"<<endl;
	}
	return 0;
}
