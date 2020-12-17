#include<iostream>
#include<queue>
#include<algorithm>
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

//building tree using bfs approach
node* buildtree(){
	int d;
	cin>>d;
	node*root=new node(d);
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
	node*f=q.front();
	q.pop();
	int c1,c2;
	cin>>c1>>c2;
	if(c1!=-1){
	f->left=new node(c1);
	q.push(f->left);
	}
	if(c2!=-1){
	f->right=new node(c2);
	q.push(f->right);
	}
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
void rightView(node *root,int level,int &maxlevel){
	if(root==NULL){
		return;
	}
	if(level>maxlevel){
		cout<<root->data<<" ";
		maxlevel=level;
	}
	rightView(root->right,level+1,maxlevel);
	rightView(root->left,level+1,maxlevel);
	return;
}

int main(){
	node * root = buildtree();
	int max_level = -1;
	rightView(root,0,max_level);
	return 0;
}
