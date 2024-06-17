class Solution {
public:
    ListNode* reverse(ListNode* &head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL)
        {
            ListNode* fut = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = fut;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head->next == NULL) return true;

        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
 
        ListNode* temp = reverse(slow);
        prev -> next = NULL;

        ListNode* start = head;
        while(start != NULL)
        {
            if(start -> val != temp -> val) return false;
            start = start -> next;
            temp = temp -> next;  
        }

        return true;
    }
};