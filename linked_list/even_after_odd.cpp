#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Node{
	public:
	ll data;
	Node *next;
	Node(ll d){
		data = d;
		next = NULL;
	}	
};

void insert(Node *&head,ll data){
	if(head==NULL){
		head = new Node(data);
		return;
	}
	Node *p = head;
	while(p->next!=NULL){
		p=p->next;
	}
	p->next = new Node(data);
}

Node *merge(Node *even,Node *odd){
	Node *temp = odd;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next = even;
	return odd;
}
void print(Node*head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}
Node *odd_even(Node *head){
	//base case
	if(head==NULL or head->next == NULL){
		return head;
	}
	//recursive case
	Node *c=NULL;
	Node *d=NULL;
	//even
	while(head!=NULL){
	if((head->data)%2==0){
		insert(c,head->data);
	}
	else{
	  insert(d,head->data);	
	}
	head=head->next;	
	}
	if(c!=NULL and d!=NULL){
		Node * temp=merge(c,d);
		return temp;
	}
	if(c==NULL) {
		return d;
	}
	return c;
}
int main(){
	Node*head = NULL;
	ll n,d;
	cin>>n;
    for(int i=0;i<n;i++){
    	cin>>d;	
    	insert(head,d);
	}
	head = odd_even(head);
	print(head);	
	return 0;
}
