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

Node * k_front(Node*head,ll k,ll n){
	Node *prev = head;
	Node *curr = head->next;
	int count = 1;
	while(count<n-k){
		prev = prev->next;
		curr = curr->next;
		count++;
	}
	//link break
	prev->next = NULL;
//join both the list
   Node *temp = curr;
   while(temp->next!=NULL){
   	temp=temp->next;
   }	
   temp->next = head;
  return curr;
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
	ll n,d,k;
	cin>>n;
    for(int i=0;i<n;i++){
    	cin>>d;	
    	insert(head,d);
	}
	cin>>k;
	if(k==0 || k%n==0)  
		print(head);
	else
	{
	head = k_front(head,k%n,n);
	print(head);
	}	
	return 0;
}
