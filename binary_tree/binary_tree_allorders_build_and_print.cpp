//https://ide.codingblocks.com/s/22738


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

node * binaryTree(){
	int d;
	cin>>d;
	if(d==-1){
		return NULL;
	}
	node *root = new node(d);
	root->left = binaryTree();
	root->right = binaryTree();
	return root;
}

//preorder traversal build
void printPre(node*root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	printPre(root->left);
	printPre(root->right);
	return;
}

//inorder traversal build
void printIn(node*root){
	if(root==NULL){
		return;
	}
	printIn(root->left);
	cout<<root->data<<" ";
	printIn(root->right);
	return;
}

//post order travelsal print
void printPst(node*root){
	if(root==NULL){
		return;
	}
	printPst(root->left);
	printPst(root->right);
	cout<<root->data<<" ";
	return;
}

//height of a tree
int height(node *root){
	if(root==NULL){
		return 0;
	}
	int leftH = height(root->left);
	int rightH = height(root->right);
	return max(leftH,rightH)+1;
}


//generic dia o(n^2)
int dia(node *root){
    if(root==NULL)
     return 0;
   int leftH = height(root->left);
	int rightH = height(root->right);
	int op1 = leftH+rightH;
    int op2 = dia(root->left);
    int op3 = dia(root->right);
    return max(op1,max(op2,op3));
}

//fast diameter o(n)
class Pair{
    public:
        int height;
        int diameter;
};

Pair fastDiameter(node*root){
    Pair p;
    if(root==NULL){
        p.diameter = p.height = 0;
        return p;
    }
    //Otherwise
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height = max(left.height,right.height) + 1;
    p.diameter = max(left.height+right.height, max(left.diameter,right.diameter));
    return p;
}

//counting the node
int count(node*root){
    if(root==NULL)
     return 0;
    return 1 + count(root->left) + count(root->right);
}

//sum the nodes
int sum(node *root){
    if(root==NULL){
        return 0;
    }
    return root->data + sum(root->left) + sum(root->right);
}

//print kth level
void print_kth_level(node *root,int k){
	if(root==NULL){
		return;
	}
	if(k==1){
		cout<<root->data<<" ";
		return;
	}
	print_kth_level(root->left,k-1);
	print_kth_level(root->right,k-1);
	return;
}


//print all the level
void print_all_level(node *root){
	int h = height(root);
	for(int i=0;i<=h;i++){
		print_kth_level(root,i);
		cout<<endl;
	}
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

//sum replacement of nodes from clild nodes
int sum_replacement(node *root){
     if(root==NULL){
        return 0;
    }
    if(root->left==NULL and root->right==NULL){
        return root->data;
    }
    int temp = root->data;
    root->data = sum_replacement(root->left) + sum_replacement(root->right);
    return root->data+temp;
}

//finding if tree is balanced or not, tree is balanced if h.left-h.right<=1
class pr{
	public:
		int height;
		bool balanced;
};

pr h_balanced(node*root){
	pr p;
	if(root==NULL){
		p.height=0;
		p.balanced=true;
		return p;
	}
	pr left = h_balanced(root->left);
	pr right = h_balanced(root->right);
	
	p.height = max(left.height,right.height)+1;
	if(abs(left.height-right.height)<=1 and left.balanced and right.balanced){
		p.balanced=true;
	}
	else{
		p.balanced=false;
	}
	return p;
}



//build tree from inorder and preorder array 
node * buildTreeFromTrav(int *in,int *pre,int s,int e){
    //variable does not change with the recursive call and uses its value from previous call
    static int i = 0;
    //base case
    if(s>e){
        return NULL;
    }
    //making root
    node * root = new node(pre[i]);

    //finding the element in in order
    int index = -1;
    for(int j=s;j<=e;j++){
        if(in[j]==pre[i]){
          index = j;
          break;
        }
    }
    
    i++;
    root->left = buildTreeFromTrav(in,pre,s,index-1);
    root->right = buildTreeFromTrav(in,pre,index+1,e);
return root;
}

int main(){
node *root = binaryTree();
// print_all_level(root);
 bfs(root);
	return 0;
} 
