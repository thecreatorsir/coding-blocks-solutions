#include<iostream>
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

Node * reverse_k(Node *head,int k){
	Node *curr = head;
	Node *prev = NULL;
	Node *next = NULL;
	int count=0;
	//process first k elements
	while(count<k){
		next = curr->next;
		curr->next=prev;
		prev = curr;
		curr = next;
		count++;
	}
	//process remaining elements
	if(next!=NULL){
		head->next = reverse_k(next,k);
	}
	return prev;
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
	int n,d,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>d;
	insert(head,d);	
	}
	head = reverse_k(head,k);
	print(head);
	return 0;
}
