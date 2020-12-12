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

Node * reverse(Node *head){
	//base case
	if(head== NULL or head->next==NULL){
		return head;
	}
	//rec case
	Node *shead = reverse(head->next);
	Node *temp = head->next;
	temp->next=head;
	head->next=NULL;
	return shead;
}

bool isPallindrome(Node *head){
	if(head== NULL or head->next==NULL){
		return true;
	}
	Node *p=head;
	Node *q=reverse(head);
	while(p!=NULL){
		if(p->data!=q->data){
			return false;
		}
		p=p->next;
		q=q->next;
	}
	return true;
}
int main(){
	Node*head = NULL;
	int n,d;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>d;
	insert(head,d);	
	}
	isPallindrome(head)?cout<<"true":cout<<"false";
	return 0;
}
