bool floydCycleRemoval(Node *head)
{   
    if(head==NULL or head->next==NULL){
        return false;
    }
     bool flag = false;
     Node *slow = head;
     Node *fast = head;
     while(fast!=NULL){
         slow=slow->next;
         fast = fast->next->next;
         if(slow==fast){
             flag = true;
             break;
         }
     }
     if(flag){
         fast = head;
         //finding the point where last node points
         while(fast!=slow){
             fast = fast->next;
             slow = slow->next;
         }
         while(fast->next!=slow){
             fast=fast->next;
         }
         fast->next=NULL;

     }
     return flag;
}

