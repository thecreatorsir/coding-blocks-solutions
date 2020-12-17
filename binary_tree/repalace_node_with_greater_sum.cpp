#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* left;
		node* right;
		
		node(int d)
		{
			data=d;
			left=NULL;
			right=NULL;
		}
};
node* build(int arr[],int s,int e)
{
	if(s>e)
	{
		return NULL;
	}
	int mid=(s+e)/2;
	node* root=new node(arr[mid]);
	root->left=build(arr,s,mid-1);
	root->right=build(arr,mid+1,e);
    return root;
}
void preorder(node* root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void replacenode(node* root,int &sum)
{
	if(root==NULL)
	{
		return;
	}
	replacenode(root->right,sum);
	sum=sum + root->data;
	root->data=sum;
	replacenode(root->left,sum);

}
int main()
{
	node* root=NULL;
	int n,a[1000];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	root=build(a,0,n-1);
    int sum = 0;
	replacenode(root,sum);
	preorder(root);
    return 0;
}
