class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL) return head;

        int cnt = 1;
        ListNode* temp = head;
        while(temp -> next != NULL) 
        {
            temp = temp -> next;
            cnt++;
        }

        ListNode* end = temp;
        k = k%cnt;
        if(k == 0) return head; 

        int pos = 1;
        temp = head;
        while(pos != cnt-k)
        {
            temp = temp -> next;
            pos++;
        }

        ListNode* nextnode = temp -> next;
        temp -> next = NULL;
        end -> next = head;
        return nextnode;
    }
};