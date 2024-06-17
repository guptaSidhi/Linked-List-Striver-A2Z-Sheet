class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head -> next == NULL) return NULL;
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast -> next != NULL)
        {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        prev -> next = slow -> next;
        return head;
    }
};