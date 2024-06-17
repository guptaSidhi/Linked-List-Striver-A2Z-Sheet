class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        // Your code here
        if(head == NULL) return NULL;
        if(x == 1) return head->next;
        
        int cnt = 1;
        Node* temp = head;
        while(cnt != x-1) 
        {
            temp = temp -> next;
            cnt++;
        }
        
        if(temp->next->next == NULL) temp -> next = NULL;
        else
        {
            temp -> next = temp -> next -> next;
            temp -> next -> prev = temp;
        }
        return head;
    }
};