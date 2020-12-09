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
	print(head);
	return 0;
}
