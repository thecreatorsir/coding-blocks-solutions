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


Node * merge(Node *a,Node*b){
	if(a==NULL){
		return b;
	}
	if(b==NULL){
		return a;
	}
    Node *c;
	if(a->data<=b->data){
		c = a;
		c->next = merge(a->next,b);
	}else{
		c = b;
		c->next = merge(a,b->next);
	}
	return c;
}


void print(Node*head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

int main(){
	ll t;
	cin>>t;
	while(t--){
	Node*head1 = NULL;
	Node*head2 = NULL;
	ll n1,n2,d;
	cin>>n1;
	for(ll i=0;i<n1;i++){
	cin>>d;
	insert(head1,d);	
	}
	cin>>n2;
	for(ll i=0;i<n2;i++){
	cin>>d;
	insert(head2,d);	
	}
    Node *head = merge(head1,head2);
	print(head);	
	}
	return 0;
}
