// Appproach - 1

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL)
        {
            ListNode* fut = curr ->next;
            curr -> next = prev;
            prev = curr;
            curr = fut;
        }
        return prev;
    }
};

// Approach - 2

class Solution {
public:
    ListNode* reverse(ListNode* &prev, ListNode* &curr)
    {
        if(curr == NULL) return prev;
        ListNode* fut = curr->next;
        curr -> next = prev;
        return reverse(curr,fut);
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        return reverse(prev,curr);
    }
};