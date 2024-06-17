class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* odd = head;
        ListNode* temp1 = odd;
        ListNode* even = head->next;
        ListNode* temp2 = even;
        while(even -> next != NULL)
        {
            odd -> next = even -> next;
            odd = odd -> next;
            if(odd -> next != NULL)
            {
                even -> next = odd -> next;
                even = even -> next;
            }
            else 
            {
                even -> next = NULL;
            }
        }
        odd -> next = NULL;
        odd -> next = temp2;
        return temp1;
    }
};