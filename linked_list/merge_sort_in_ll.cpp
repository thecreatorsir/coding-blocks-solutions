#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;
	Node *next;
	Node(int d){
		data = d;
		next = NULL;
	}	
};

void insert(Node *&head,int data){
	if(head==NULL){
		head = new Node(data);
		return;
	}
	Node *p = head;
	while(p->next!=NULL){
		p=p->next;
	}
	Node *temp = new Node(data);
	p->next = temp;
}

Node * get_mid(Node *head){
	if(head==NULL or head->next==NULL){
		return head;
	}
	Node *slow = head;
	Node *fast = head->next;
	while(fast!=NULL and fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
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


Node * merge_sort(Node*head){
	if(head == NULL or head ->next == NULL){
		return head;
	}
	Node * mid = get_mid(head);
    
	Node *a = head;
	Node *b = mid->next;	
    mid->next = NULL;
    
	//call mergesort on two parts
	a=merge_sort(a);
	b=merge_sort(b);
	
	//merge two sorted linked list
	head = merge(a,b);
	return head;
}

void print(Node*head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

int main(){
	Node*head = NULL;
	int n,d;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>d;
	insert(head,d);	
	}
    head = merge_sort(head);
	print(head);
	return 0;
}
