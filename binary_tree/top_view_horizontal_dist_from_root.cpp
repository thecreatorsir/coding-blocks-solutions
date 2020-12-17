#include<iostream>
#include<queue>
#include<map>
#include<climits>
#include<algorithm>
using namespace std;

class node {
	public:
		int data;
        int h_dist;
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
void TopView(node *root){
	if(root==NULL){
		return;
	}
    int h_dist = 0;
	queue<node *> q;
    map<int,int> m;
    root->h_dist = 0;
   
    q.push(root);
    while(!q.empty()){
     node * temp = q.front();
     h_dist = temp->h_dist;
     q.pop();
     if(m.count(h_dist)==0){
         m[h_dist] = temp->data;
     }
     if(temp->left){
         temp->left->h_dist = h_dist - 1;
         q.push(temp->left);
     }
     if(temp->right){
         temp->right->h_dist = h_dist+1;
         q.push(temp->right);
     } 
    }
    for(auto it = m.begin();it!=m.end();it++){
       cout<<it->second<<" ";
    }
	return;
}

int main(){
	node * root = buildtree();
	TopView(root);
	return 0;
}
