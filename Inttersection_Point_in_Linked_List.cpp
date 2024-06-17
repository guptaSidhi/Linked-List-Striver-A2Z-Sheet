// Approach - 1

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        unordered_map <ListNode* , bool> mp;
        while(head1 != NULL)
        {
            mp[head1] = true;
            head1 = head1 -> next;
        }

        while(head2 != NULL)
        {
            if(mp[head2] == true) return head2;
            head2 = head2 -> next;
        }

        return NULL;
    }
};

// Approach - 2

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;
        while(temp1 != temp2)
        {
            if(temp1 == NULL) temp1 = head2;
            else temp1 = temp1 -> next;
            if(temp2 == NULL) temp2 = head1;
            else temp2 = temp2 -> next;
        }
        return temp1;
    }
};