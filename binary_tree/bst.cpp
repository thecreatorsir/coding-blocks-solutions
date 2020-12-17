#include <iostream>
#include<queue>
using namespace std;

class node {
	public:
		int data;
		node *left;
		node *right;
	node(int d){
		data=d;
		left = NULL;
		right = NULL;
	}	
};

node * BSTinsert(node *root,int d){
    //base case
    if(root==NULL){
        return new node(d);
    }
    //recursive case
    if(d<=root->data)
    root->left = BSTinsert(root->left,d);
    else
    root->right = BSTinsert(root->right,d);
return root;
}

node* build(){
  int d;
  cin>>d;
  node *root=NULL; 
  while(d!=-1){
    root = BSTinsert(root,d);
    cin>>d;
  }
  return root;
}

void bfs(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node * temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left){
           q.push(temp->left);
        }
        if(temp->right){
          q.push(temp->right);
        } 
		if(q.front()==NULL){
            q.pop();
			cout<<endl;
            if(!q.empty())
			q.push(NULL);
		}      
    }
}

void inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}


node *deleteInBst(node *root,int data){
    //base case
    if(root==NULL)
     return NULL;

    
    if(root->data==data){
        //elenemt is at leaf node
        if(root->left==NULL and root->right==NULL){
                delete root;
                return NULL;
            }
            //element is having right but not the left node
            else if(root->left==NULL and root->right!= NULL){
                    node *temp = root->right;
                    delete root;
                    return temp;
            }
            //element is having left but not the right node
            else if(root->left!=NULL and root->right== NULL){
                  node *temp = root->left;
                    delete root;
                    return temp;
            }
                  //element is having both left and right node
            else{
                node *temp = root->right;
                while(temp->left!=NULL){
                    temp = temp->left;
                }
                root->data = temp->data;
                root->right = deleteInBst(root->right,temp->data);
                return root;
            }
    }else if(data < root->data){
        root->left = deleteInBst(root->left,data);
        return root; 
    }else{
        root->right = deleteInBst(root->right,data);
        return root;
    } 
}

class LinkedList{
    public:
        node*head;
        node*tail;
};

LinkedList flatten(node*root){
    LinkedList l;

    if(root==NULL){
        l.head = l.tail = NULL;
        return l;
    }
    // Leaf Node
    if(root->left == NULL && root->right==NULL){
        l.head = l.tail = root;
        return l;
    }
    // Left is Not NULL
    if(root->left!=NULL && root->right==NULL){
        LinkedList leftLL = flatten(root->left);
        leftLL.tail->right = root;

        l.head = leftLL.head;
        l.tail = root;
        return l;
    }
    //Right is Not NULL
    if(root->left==NULL && root->right!=NULL){
        LinkedList rightLL = flatten(root->right);
        root->right = rightLL.head;

        l.head = root;
        l.tail  = rightLL.tail;
        return l;
    }
    //Both Sides are not NULL
    LinkedList leftLL = flatten(root->left);
    LinkedList rightLL = flatten(root->right);

    leftLL.tail->right = root;
    root->right = rightLL.head;

    l.head = leftLL.head;
    l.tail = rightLL.tail;
    return l;

}
bool is_bst(node *root,int minV=INT_MIN,int maxV=INT_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data >= minV and root->data < maxV and is_bst(root->left,minV,root->data) and is_bst(root->right,root->data,maxV)){
        return true;
    }else{
        return false;
    }
}

int main() {
    node * root = build();
       bfs(root);
    cout<<endl;
    root = deleteInBst(root,5);
    inorder(root);
    cout<<endl;
    bfs(root);
    return 0;
}

