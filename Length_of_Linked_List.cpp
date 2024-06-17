int getCount(struct Node* head){
    
        if(head == NULL) return 0;
        
        int cnt = 1;
        Node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp -> next;
            cnt++;
        }
        
        return cnt;
    }