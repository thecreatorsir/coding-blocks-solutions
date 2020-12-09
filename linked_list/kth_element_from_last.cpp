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
Node * k_from_last(Node *head,int k){
	if(head==NULL or head->next==NULL){
		return head;
	}
	Node *slow = head;
	Node *fast = head;
	int count = 1;
	//move fast k steps
	while(count<k){
		fast = fast->next;
		count++;
	}
	//move both till fast reaches end
	while(fast->next!=NULL){
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
int main(){
	Node*head = NULL;
	ll d,k;
	cin>>d;
    while(d!=-1){
    insert(head,d);
	cin>>d;	
	}
	cin>>k;
	Node * temp = k_from_last(head,k);
	cout<<temp->data<<endl;	
	return 0;
}
