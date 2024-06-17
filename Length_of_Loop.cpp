struct Node* detectCycle(struct Node *head) {
        struct Node* slow = head;
        struct Node* fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast)
            {
                slow = head;
                while(slow != fast) 
                {
                    slow = slow -> next;
                    fast = fast -> next;
                }
                return slow;
            }
        }
        return NULL;
    }

int countNodesinLoop(struct Node *head)
{
    // Code here
    struct Node* temp = detectCycle(head);
    if(temp == NULL) return 0;
    
    int cnt = 1;
    struct Node* dummy = temp->next;
    while(dummy != temp)
    {
        dummy = dummy -> next;
        cnt++;
    }
    return cnt;
}