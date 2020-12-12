Node *intersectionOfTwoLinkedLists(Node *l1, Node *l2){
    if(length(l2)>=length(l1))
    {
    int diff = length(l2)-length(l1);
    while(diff--){
        l2=l2->next;
    }
    Node*p=l2;
    Node*q=l1;

    while(p->data != q->data){
        p=p->next;
        q=q->next;
    }
    return p;
    }
    else
    {
        int diff = length(l1)-length(l2);
    while(diff--){
        l1=l1->next;
    }
    Node*p=l1;
    Node*q=l2;

    while(p->data != q->data){
        p=p->next;
        q=q->next;
    }
    return p;
    }
}



