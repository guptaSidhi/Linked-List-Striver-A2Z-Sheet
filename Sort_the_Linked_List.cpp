class Solution {
public:
    ListNode* merge(ListNode* &head1,ListNode* &head2)
    {
        ListNode* newnode = new ListNode(-1);
        ListNode* dummy = newnode;

        while(head1 != NULL && head2 != NULL)
        {
            if(head1 -> val <= head2 -> val)
            {
                newnode -> next = new ListNode(head1 -> val);
                newnode = newnode -> next;
                head1 = head1 -> next;
            }
            else
            {
                newnode -> next = new ListNode(head2 -> val);
                newnode = newnode -> next;
                head2 = head2 -> next;
            }
        }

        while(head1 != NULL)
        {
            newnode -> next = new ListNode(head1 -> val);
            newnode = newnode -> next;
            head1 = head1 -> next;
        }

        while(head2 != NULL)
        {
            newnode -> next = new ListNode(head2 -> val);
            newnode = newnode -> next;
            head2 = head2 -> next;
        }

        return dummy->next;
    }

    ListNode* getmiddle(ListNode* &head)
    {
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast -> next != NULL)
        {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        prev -> next = NULL;
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* middle = getmiddle(head);

        ListNode* left = sortList(head);
        ListNode* right = sortList(middle);

        return merge(left, right);
    }
};