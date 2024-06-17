class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(-1);
        ListNode* dummy = temp;
        int sum = 0;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry != 0)
        {
            if(l1 != NULL)
            {
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2 != NULL)
            {
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            sum += carry;
            temp -> next = new ListNode(sum%10);
            temp = temp -> next;
            carry = sum/10;
            sum = 0;
        }
        return dummy -> next;
    }
};